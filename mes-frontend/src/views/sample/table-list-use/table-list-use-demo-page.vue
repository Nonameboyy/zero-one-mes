<script lang="ts" setup>
import { computed, onMounted, ref, watch } from "vue";
import { ElButton, ElCard } from "element-plus";
import { StdTable, TableFrame } from "components/std-table";
import type { StdTableProps } from "components/std-table";

import { type UnitMeasureDTO, mdUnitMeasureController } from "views/sample/basic-data/tests/MdUnitMeasureController";

defineOptions({
	/** 列表页用的表格组件 演示页 */
	name: "TableListUseDemoPage",
});

const tableFrameTitle = ref("列表页用的表格组件-阮喵喵");

const { getInfo, addUnitMeasure, list } = mdUnitMeasureController;

const measureId = ref(100);

const tableRows = ref<UnitMeasureDTO[]>([]);

const query = ref<UnitMeasureDTO>({
	changeRate: -0.114514,
	createBy: "",
});

const stdTableProps = ref<StdTableProps<UnitMeasureDTO>>({
	unifySize: "large",

	data: [],

	buttons: [
		{
			buttonName: "新增",
			size: "small",
			round: true,
			type: "danger",
			clickCallBack() {
				console.log("新增");
			},
		},

		{
			buttonName: "导出",
			size: "default",
			type: "success",
			clickCallBack() {
				console.log("导出数据");
			},
		},
	],

	operations: [
		{
			buttonName: "修改",
			clickCallBack(row) {
				console.log(row);
			},
		},

		{
			buttonName: "编辑",
			clickCallBack(row) {
				console.log(row);
			},
		},

		{
			buttonName: "标记了好玩",
			clickCallBack(row) {
				console.log(row);
			},
		},
	],
});

onMounted(async () => {
	// await getInfo(measureId.value);
	await getlist();
});

const form = ref<UnitMeasureDTO>({
	changeRate: 0,
	createBy: "",
});

const isLoading = ref<boolean>(false);

async function add() {
	await addUnitMeasure(form.value);
}

async function getlist() {
	isLoading.value = true;
	await list(query.value)
		.then((response) => {
			// tableRows.value = response.data.data.rows;
			// @ts-expect-error
			tableRows.value = response.data.rows;
		})
		.finally(() => {
			isLoading.value = false;
		});
}
</script>

<template>
	<section class="table-list-use-demo-page-root">
		<h1>你好，这是阮喵喵正在制作的组件。</h1>

		<ElButton @click="getlist()"> 点击加载数据 </ElButton>

		<ElCard v-loading="isLoading">
			{{ tableRows }}
		</ElCard>

		<TableFrame :title="tableFrameTitle">
			<template #tableFrameMain>
				<StdTable v-bind="stdTableProps">
					<!-- <template #> </template> -->
				</StdTable>
			</template>
		</TableFrame>
	</section>
</template>

<style lang="scss" scoped>
.table-list-use-demo-page-root {
}
</style>
