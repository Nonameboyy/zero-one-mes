<script>
import { computed, ref } from "vue";
import { ElButton } from "element-plus";

export default {
	setup() {
		const tableData = ref([
			{
				date: "2016-05-03",
				name: "王小虎",
				address: "上海市普陀区金沙江路 1518 弄",
			},
			{
				date: "2016-05-02",
				name: "王小虎",
				address: "上海市普陀区金沙江路 1517 弄",
			},
			{
				date: "2016-05-04",
				name: "王小虎",
				address: "上海市普陀区金沙江路 1519 弄",
			},
			{
				date: "2016-05-01",
				name: "王小虎",
				address: "上海市普陀区金沙江路 1516 弄",
			},
		]);
		const search = ref("");
		const currentPage = ref(1);
		const pageSize = ref(5);

		const filteredData = computed(() => {
			let result = tableData.value;
			if (search.value) {
				result = result.filter((row) => row.name.includes(search.value) || row.address.includes(search.value));
			}
			const start = (currentPage.value - 1) * pageSize.value;
			const end = start + pageSize.value;
			return result.slice(start, end);
		});

		const handleEdit = (index, row) => {
			console.log("编辑", index, row);
		};

		const handleDelete = (index) => {
			const start = (currentPage.value - 1) * pageSize.value;
			tableData.value.splice(start + index, 1);
		};

		const handleSizeChange = (val) => {
			pageSize.value = val;
		};

		const handleCurrentChange = (val) => {
			currentPage.value = val;
		};

		const handleClear = () => {
			search.value = "";
		};

		return {
			tableData,
			search,
			filteredData,
			currentPage,
			pageSize,
			handleEdit,
			handleDelete,
			handleSizeChange,
			handleCurrentChange,
			handleClear,
		};
	},
};
</script>

<template>
	<div>
		<el-input v-model="search" placeholder="请输入内容" clearable @clear="handleClear"></el-input>
		<el-table :data="filteredData" style="width: 100%">
			<el-table-column prop="date" label="日期" width="180"></el-table-column>
			<el-table-column prop="name" label="姓名" width="180"></el-table-column>
			<el-table-column prop="address" label="地址"></el-table-column>
			<el-table-column label="操作">
				<template #default="scope">
					<el-button type="primary" size="small" @click="handleEdit(scope.$index, scope.row)">编辑</el-button>
					<el-button type="danger" size="small" @click="handleDelete(scope.$index)">删除2222</el-button>
				</template>
			</el-table-column>
		</el-table>
		<el-pagination
			:current-page="currentPage"
			:page-sizes="[5, 10, 15, 20]"
			:page-size="pageSize"
			layout="total, sizes, prev, pager, next, jumper"
			:total="filteredData.length"
			@size-change="handleSizeChange"
			@current-change="handleCurrentChange"
		></el-pagination>
	</div>
	<!-- layout中具有jumper导致ElementPlusError: [el-input] [API] label is about to be deprecated in version 2.8.0, please use
    aria-label instead.更新elementplus即可消除 -->
</template>
