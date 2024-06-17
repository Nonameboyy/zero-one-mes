<template>
	<div class="material-classification">
		<template class="search-bar">
			<span>分类名称:</span>
			<el-input
				v-model="searchClassValue"
				placeholder="请输入分类名称"
				clearable
				style="width: 17%; margin: 0 10px"
			></el-input>
			<span>是否启用:</span>
			<el-select v-model="searchIsLaunchedValue" placeholder="选择是或否" style="width: 12%; margin: 0 10px">
				<el-option v-for="item in options" :key="item.label" :label="item.label" :value="item.value" />
			</el-select>
			<el-button size="medium" type="primary" @click="search" :icon="Search">搜索</el-button>
			<el-button type="text" @click="resetSearch">重置</el-button>
		</template>
		<template class="material-table"> </template>
		<el-table :data="demo" style="width: 100%; margin-bottom: 20px" row-key="id">
			<el-table-column prop="name" label="物料产品分类" />
			<el-table-column prop="sort" label="排序" sortable />
			<el-table-column prop="class" label="物料/产品" />
			<el-table-column prop="isLaunched" label="是否启用">
				<template #default="scope">
					<el-tag :type="scope.row.isLaunched ? 'success' : 'warning'" disable-transitions>{{
						scope.row.isLaunched ? "是" : "否"
					}}</el-tag>
				</template>
			</el-table-column>
			<el-table-column prop="date" label="创建时间" />
			<el-table-column fixed="right" label="Operations">
				<template #default="scope">
					<el-button size="small" @click="handleEdit(scope.$index, scope.row.id)"> Edit </el-button>
					<el-button size="small" @click="handleAdd(scope.$index, scope.row.id)"> Add </el-button>
					<el-button size="small" type="danger" @click="handleDelete(scope.$index, scope.row.id)"> Delete </el-button>
				</template>
			</el-table-column>
		</el-table>
	</div>
</template>

<script setup lang="ts">
//@ts-nocheck
import { ref } from "vue";
import { Search } from "@element-plus/icons-vue";

let searchClassValue = ref("");
let searchIsLaunchedValue = ref("");

const priDemo = [
	{
		id: "1",
		name: "原材料",
		sort: 1,
		class: "产品",
		isLaunched: true,
		date: "2016-05-02 12:00:00",
		children: [
			{
				id: "1-1",
				name: "五金类",
				sort: 1,
				class: "物料",
				isLaunched: true,
				date: "2016-05-02 12:00:00",
			},
			{
				id: "1-2",
				name: "电子类",
				sort: 2,
				class: "物料",
				isLaunched: true,
				date: "2016-05-02 12:00:00",
			},
			{
				id: "1-3",
				name: "塑料类",
				sort: 3,
				class: "物料",
				isLaunched: true,
				date: "2016-05-02 12:00:00",
			},
		],
	},
	{
		id: "2",
		name: "产品",
		sort: 2,
		class: "产品",
		isLaunched: true,
		date: "2016-05-02 12:00:00",
		children: [
			{
				id: "2-1",
				name: "手机",
				sort: 1,
				class: "产品",
				isLaunched: true,
				date: "2016-05-02 12:00:00",
			},
			{
				id: "2-2",
				name: "电视",
				sort: 2,
				class: "产品",
				isLaunched: true,
				date: "2016-05-02 12:00:00",
			},
			{
				id: "2-3",
				name: "电脑",
				sort: 3,
				class: "产品",
				isLaunched: true,
				date: "2016-05-02 12:00:00",
			},
		],
	},
];
let demo = ref(JSON.parse(JSON.stringify(priDemo)));

const options = [
	{
		value: true,
		label: "是",
	},
	{
		value: false,
		label: "否",
	},
];
const resetSearch = () => {
	searchClassValue.value = "";
	searchIsLaunchedValue.value = "";
	demo.value = JSON.parse(JSON.stringify(priDemo));
};
const search = () => {
	const searchClass = searchClassValue.value;
	const searchIsLaunched = searchIsLaunchedValue.value;
	demo.value = priDemo.filter((item) => {
		return (
			(!searchClass || item.name.includes(searchClass)) &&
			(searchIsLaunched === "" || item.isLaunched === searchIsLaunched)
		);
	});
};
const handleEdit = (index: number, id: string) => {
	console.log(index, id);
};
const handleDelete = (index: number, id: string) => {
	//PriDemo.splice(index, 1)
	const deleteItem = (arr, id) => {
		for (let i = 0; i < arr.length; i++) {
			if (arr[i].id === id) {
				arr.splice(i, 1);
				return true;
			}
			if (arr[i].children && arr[i].children.length > 0) {
				const result = deleteItem(arr[i].children, id);
				if (result) {
					return true;
				}
			}
		}
		return false;
	};

	deleteItem(demo.value, id);
};
const handleAdd = (index: number, id: string) => {
	console.log(index, id);
	//代处理
};
</script>

<style scoped lang="scss">
.material-classification {
	.search-bar {
		display: flex;
		justify-content: flex-start;
		margin: 20px;
		color: #606266;
		font-size: medium;
	}
}
</style>
