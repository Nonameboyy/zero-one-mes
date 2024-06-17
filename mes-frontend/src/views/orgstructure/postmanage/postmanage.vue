<script setup>
import { ref } from "vue";
import "element-plus/theme-chalk/display.css";
// 搜索表单数据
const queryParams = ref({});
// 选项
const options = [
	{
		value: "",
		label: "所有",
	},
	{
		value: "Option1",
		label: "正常",
	},
	{
		value: "Option2",
		label: "停用",
	},
];
// 搜索相关事件
function handleClear() {
	console.log("清理");
}
function handleQuery() {
	console.log("查询操作");
}
function resetQuery() {
	queryParams.value = {};
}
// 临时演示表格数据
const tableData = [
	{
		postCode: 1,
		postId: 1,
		postName: "CEO",
		postSort: 1,
		remark: 1,
		status: 1,
		updateTime: "2024-05-17",
	},
];
const single = ref(true);
const multiple = ref(true);
function handleSelectionChange(selection) {
	single.value = selection.length !== 1;
	multiple.value = selection.length === 0;
}
</script>

<template>
	<div class="app-container">
		<el-card>
			<!-- 搜索表单 -->
			<el-form ref="queryForm" :model="queryParams" :inline="true" label-width="100px">
				<el-row :gutter="0">
					<el-col :span="6">
						<el-form-item label="岗位编码：" prop="posCode">
							<el-input v-model="queryParams.posCode" clearable />
						</el-form-item>
					</el-col>
					<el-col :span="6">
						<el-form-item label="岗位名称：" prop="clientName">
							<el-input v-model="queryParams.posName" clearable />
						</el-form-item>
					</el-col>
					<el-col :span="6">
						<el-form-item label="岗位状态" prop="clientNick">
							<el-select
								v-model="queryParams.value"
								:empty-values="[null, undefined]"
								:value-on-clear="null"
								clearable
								placeholder="Select"
								style="width: 240px"
								@clear="handleClear"
							>
								<el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
							</el-select>
						</el-form-item>
					</el-col>
					<el-col :span="6">
						<el-form-item>
							<el-button type="primary" @click="handleQuery">
								<el-icon>
									<Search />
								</el-icon>
								搜索
							</el-button>
							<el-button type="warning" @click="resetQuery">
								<el-icon>
									<Refresh />
								</el-icon>
								重置
							</el-button>
						</el-form-item>
					</el-col>
				</el-row>
			</el-form>
		</el-card>

		<el-card>
			<!-- 操作按钮 -->
			<el-row :gutter="10">
				<el-col :span="8">
					<el-button type="primary" @click="handleAdd">
						<el-icon>
							<Plus />
						</el-icon>
						新增
					</el-button>
					<el-button type="success" :disabled="single" @click="handleUpdate">
						<el-icon>
							<Edit />
						</el-icon>
						修改
					</el-button>
					<el-button type="danger" :disabled="multiple" @click="handleDelete">
						<el-icon>
							<Delete />
						</el-icon>
						删除
					</el-button>
					<el-button type="warning" :disabled="export" @click="handleExport">
						<el-icon>
							<Download />
						</el-icon>
						导出
					</el-button>
				</el-col>
			</el-row>
			<!-- 数据表格 -->
			<el-table :data="tableData" style="width: 100%" @selection-change="handleSelectionChange">
				<el-table-column type="selection" width="55" />
				<el-table-column prop="postCode" label="岗位编号" width="180" />
				<el-table-column prop="postId" label="岗位编码" width="180" />
				<el-table-column prop="postName" label="岗位名称" width="180" />
				<el-table-column prop="remark" label="显示顺序" />
				<el-table-column prop="status" label="状态" />
				<el-table-column prop="status" label="创建时间" />
			</el-table>
		</el-card>
	</div>
</template>

<style scoped></style>
