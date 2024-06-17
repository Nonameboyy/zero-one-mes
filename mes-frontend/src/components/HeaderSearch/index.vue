<template>
	<div :class="{ show: show }" class="header-search">
		<svg-icon class-name="search-icon" icon-class="search" @click.stop="click" />
		<el-select
			ref="headerSearchSelect"
			v-model="search"
			:remote-method="querySearch"
			filterable
			default-first-option
			remote
			placeholder="Search"
			class="header-search-select"
			@change="change"
		>
			<el-option
				v-for="option in options"
				:key="option.item.path"
				:value="option.item"
				:label="option.item.title.join(' > ')"
			/>
		</el-select>
	</div>
</template>

<script setup>
import { ref, reactive, watch, onMounted, computed, nextTick } from "vue";
import Fuse from "fuse.js";
import path from "path";
import store from "@/store";
import { router } from "@/router";

const search = ref("");
const options = reactive([]);
const searchPool = reactive([]);
const show = ref(false);
let fuse = null;
const headerSearchSelect = ref(null);

const routes = computed(() => {
	return store.getters.permission_routes;
});

watch(routes, () => {
	searchPool.value = generateRoutes(routes.value);
});

watch(searchPool, (list) => {
	initFuse(list);
});

watch(show, (value) => {
	if (value) {
		document.body.addEventListener("click", close);
	} else {
		document.body.removeEventListener("click", close);
	}
});

onMounted(() => {
	searchPool.value = generateRoutes(routes.value);
});

const click = () => {
	show.value = !show.value;
	if (show.value) {
		headerSearchSelect.value && headerSearchSelect.value.focus();
	}
};

const close = () => {
	headerSearchSelect.value && headerSearchSelect.value.blur();
	options.value = [];
	show.value = false;
};

const change = (val) => {
	const path = val.path;
	const query = val.query;
	if (ishttp(val.path)) {
		const pindex = path.indexOf("http");
		window.open(path.substr(pindex, path.length), "_blank");
	} else {
		if (query) {
			router.push({ path: path, query: JSON.parse(query) });
		} else {
			router.push(path);
		}
	}
	search.value = "";
	options.value = [];

	nextTick(() => {
		show.value = false;
	});
};

const initFuse = (list) => {
	fuse = new Fuse(list, {
		shouldSort: true,
		threshold: 0.4,
		location: 0,
		distance: 100,
		minMatchCharLength: 1,
		keys: [
			{
				name: "title",
				weight: 0.7,
			},
			{
				name: "path",
				weight: 0.3,
			},
		],
	});
};

const generateRoutes = (routes, basePath = "/", prefixTitle = []) => {
	let res = [];

	for (const router of routes) {
		if (router.hidden) {
			continue;
		}

		const data = {
			path: !ishttp(router.path) ? path.resolve(basePath, router.path) : router.path,
			title: [...prefixTitle],
		};

		if (router.meta && router.meta.title) {
			data.title = [...data.title, router.meta.title];

			if (router.redirect !== "noRedirect") {
				res.push(data);
			}
		}

		if (router.query) {
			data.query = router.query;
		}

		if (router.children) {
			const tempRoutes = generateRoutes(router.children, data.path, data.title);
			if (tempRoutes.length >= 1) {
				res = [...res, ...tempRoutes];
			}
		}
	}
	return res;
};

const querySearch = (query) => {
	if (query !== "") {
		options.value = fuse.search(query);
	} else {
		options.value = [];
	}
};

const ishttp = (url) => {
	return url.indexOf("http://") !== -1 || url.indexOf("https://") !== -1;
};
</script>

<style lang="scss" scoped>
.header-search {
	font-size: 0 !important;

	.search-icon {
		cursor: pointer;
		font-size: 18px;
		vertical-align: middle;
	}

	.header-search-select {
		font-size: 18px;
		transition: width 0.2s;
		width: 0;
		overflow: hidden;
		background: transparent;
		border-radius: 0;
		display: inline-block;
		vertical-align: middle;

		::v-deep .el-input__inner {
			border-radius: 0;
			border: 0;
			padding-left: 0;
			padding-right: 0;
			box-shadow: none !important;
			border-bottom: 1px solid #d9d9d9;
			vertical-align: middle;
		}
	}

	&.show {
		.header-search-select {
			width: 210px;
			margin-left: 10px;
		}
	}
}
</style>
