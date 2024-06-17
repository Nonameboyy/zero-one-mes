<script lang="ts" setup>
import { ref, computed, watch } from "vue";
import { ElBadge } from "element-plus";
// import SearchBar from '@/components/search-bar/search-bar.vue'

defineOptions({
	name: "SearchBarPage",
});

const searchBarConfig1 = ref({});
const searchBarData1 = ref({
	input: "",
});
</script>

<template>
	<section class="search-bar-page-root">
		<h1>你好，这是搜索栏演示页</h1>

		<SearchBar :config="searchBarConfig1" v-model:data="searchBarData1" />

		<ElBadge :value="searchBarData1.input"></ElBadge>
	</section>
</template>

<style lang="scss" scoped>
.search-bar-page-root {
}
</style>
