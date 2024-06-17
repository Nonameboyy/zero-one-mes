<template>
	<div class="app-container">
		<StdTable :data="filteredData">
			<template #extra>
				<div class="wareHouseSearchDiv">
					<el-form size="small" :inline="true" label-width="82px">
						<el-form-item label="仓库编码" size="default">
							<el-input placeholder="请输入仓库编码" v-model="warehouseCode" />
						</el-form-item>
						<el-form-item label="仓库名称" size="default">
							<el-input placeholder="请输入仓库名称" v-model="warehouseName" />
						</el-form-item>

						<el-form-item>
							<el-button type="primary" size="default" @click="handleQuery">搜索</el-button>
							<el-button size="default" @click="resetQuery">重置</el-button>
						</el-form-item>
					</el-form>
				</div>
			</template>

			<!-- 想实现自定义表格字段但是没成功 -->
			<template #empty> &ensp; </template>
		</StdTable>
	</div>
</template>

<script lang="ts" setup>
import { ref, computed } from "vue";
import { StdTable, TableText } from "components/std-table";

// 定义数据
const warehouseCode = ref("");
//对应"classify": "金属",
const warehouseName = ref("");
//对应"product": '螺丝',
const allData = ref([
	{
		classify: "金属",
		product: "螺丝",
		sure: "正常",
		time: "2024.5.22",
	},
]);
// 原始数据
// 计算属性来筛选数据
const filteredData = computed(() => {
	return allData.value.filter((item) => {
		return item.classify.includes(warehouseCode.value) && item.product.includes(warehouseName.value);
	});
});
const handleQuery = () => {
	console.log("执行搜索");
	// 在这里添加搜索逻辑
};

const resetQuery = () => {
	console.log("重置查询条件");
	// 在这里添加重置逻辑
	warehouseCode.value = "";
	warehouseName.value = "";
};
</script>

<style scoped>
.app-container {
	background-color: aliceblue;
	width: auto;
	height: 400px;
}
.body {
	margin: 0;
	padding: 0;
}
.el-input {
	--el-input-width: 220px;
	height: 35px;
}
.el-button {
	display: flex;
	justify-content: center;
	align-items: center;
}
</style>
