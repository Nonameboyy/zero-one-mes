<script setup lang="ts">
import { ref } from "vue";
import { TableFrame } from "components/std-table";
import request from "@/apis/request.js";

// 搜索表单
const recptCode = ref("");
const recptName = ref("");
const vendorName = ref("");
const poCode = ref("");
const recptDate = ref(null);
//对话框标题
const dialogTitle = ref("");
// 表格数据
const tableList = ref([
	{
		recptCode: "R001",
		recptName: "入库单1",
		vendorName: "供应商1",
		poCode: "PO001",
		recptDate: "2023-10-01",
		status: "PREPARE",
	},
	{
		recptCode: "R002",
		recptName: "入库单2",
		vendorName: "供应商2",
		poCode: "PO002",
		recptDate: "2023-10-02",
		status: "CONFIRMED",
	},
	{
		recptCode: "R003",
		recptName: "入库单3",
		vendorName: "供应商3",
		poCode: "PO003",
		recptDate: "2023-10-03",
		status: "PREPARE",
	},
	{
		recptCode: "R004",
		recptName: "入库单4",
		vendorName: "供应商4",
		poCode: "PO004",
		recptDate: "2023-10-04",
		status: "CONFIRMED",
	},
	{
		recptCode: "R005",
		recptName: "入库单5",
		vendorName: "供应商5",
		poCode: "PO005",
		recptDate: "2023-10-05",
		status: "PREPARE",
	},
	{
		recptCode: "R006",
		recptName: "入库单6",
		vendorName: "供应商6",
		poCode: "PO006",
		recptDate: "2023-10-06",
		status: "CONFIRMED",
	},
]);

// 对话框
const dialogVisible = ref(false);
const formRef = ref();
const formModel = ref({
	recptCode: "",
	recptName: "",
	recptDate: "",
	poCode: "",
	status: "",
	vendorName: "",
	warehouseInfo: [],
	remark: "",
});

const rules = {
	recptCode: [{ required: true, message: "请输入入库单编号", trigger: "blur" }],
	recptName: [{ required: true, message: "请输入入库单名称", trigger: "blur" }],
	recptDate: [{ required: true, message: "请选择入库日期", trigger: "change" }],
	poCode: [{ required: true, message: "请输入订单编号", trigger: "blur" }],
	status: [{ required: true, message: "请选择单据状态", trigger: "change" }],
	vendorName: [{ required: true, message: "请输入供应商名称", trigger: "blur" }],
	warehouseInfo: [{ required: true, message: "请选择入库仓库", trigger: "change" }],
	remark: [{ required: true, message: "请输入备注", trigger: "blur" }],
};
// 提交表单
const submitForm = () => {
	formRef.value.validate((valid) => {
		if (valid) {
			console.log("提交成功", formModel.value);
			dialogVisible.value = false;
		} else {
			console.log("提交失败");
			return false;
		}
	});
};
//取消提交
const cancelForm = () => {
	dialogVisible.value = false;
};

// 分页
const loading = ref(false);
const parms = ref({
	pagenum: 1,
	pagesize: 5,
});
const total = ref(tableList.value.length);

const originalTableList = ref([...tableList.value]);
const getPageList = () => {
	loading.value = true;
	const start = (parms.value.pagenum - 1) * parms.value.pagesize;
	const end = start + parms.value.pagesize;
	tableList.value = originalTableList.value.slice(start, end);
	loading.value = false;
};

const onSizeChange = (size) => {
	parms.value.pagenum = 1;
	parms.value.pagesize = size;
	getPageList();
};
const onCurrentChange = (page) => {
	parms.value.pagenum = page;
	getPageList();
};

// 表格上面新增操作
const handleAdd = () => {
	formModel.value = {
		recptCode: "",
		recptName: "",
		recptDate: "",
		poCode: "",
		status: "",
		vendorName: "",
		warehouseInfo: [],
		remark: "",
	};
	dialogTitle.value = "新增物料入库单";
	dialogVisible.value = true;
};
//表格上面修改操作
const handleUpdate = (row) => {
	formModel.value = { ...row };
	dialogTitle.value = "修改物料入库单";
	dialogVisible.value = true;
};

//模拟删除
const handleDelete = async (row) => {
	await ElMessageBox.confirm("你确认要删除该入库单么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	});
	const index = tableList.value.findIndex((item) => item.recptCode === row.recptCode);
	if (index !== -1) {
		tableList.value.splice(index, 1);
		originalTableList.value = [...tableList.value];
		getPageList();
	}
	ElMessage.success("删除成功");
	console.log(row);
	getPageList();
};

const handleExport = () => {
	console.log("导出数据");
};
//查询提交
const handleQuery = () => {
	console.log("查询提交");
};

const resetQuery = () => {
	recptCode.value = "";
	recptName.value = "";
	vendorName.value = "";
	poCode.value = "";
	recptDate.value = null;
	handleQuery();
};

const handleSelectionChange = (val) => {
	console.log("选中项变化", val);
};
//执行入库
const handleExecute = async (row) => {
	try {
		await ElMessageBox.confirm("你确认要执行入库么", "温馨提示", {
			type: "warning",
			confirmButtonText: "确认",
			cancelButtonText: "取消",
		});
		ElMessage.success("执行入库成功");
		console.log("执行入库", row);
		// 执行入库的逻辑
	} catch (error) {
		console.log("取消执行入库");
	}
};
// 自定义排序逻辑
function handleSortChange({ prop, order }) {
	tableList.value.sort((a, b) => {
		if (order === "ascending") {
			return a[prop] > b[prop] ? 1 : -1;
		} else if (order === "descending") {
			return a[prop] < b[prop] ? 1 : -1;
		} else {
			return 0;
		}
	});
}
// 隐藏搜索栏
const showSearchBar = ref(true);
function toggleSearchBar() {
	showSearchBar.value = !showSearchBar.value;
}
// 模拟刷新数据
function refreshData() {
	loading.value = true; // 显示加载动画
	// 模拟刷新数据
	setTimeout(() => {
		// 调用后端接口获取最新数据
		// request.get('/api/refresh-data').then(response => {
		//   tableList.value = response.data;
		//   originalTableList.value = [...tableList.value];
		//   getPageList();
		// }).finally(() => {
		//   loading.value = false; // 隐藏加载动画
		// });

		// 模拟数据刷新
		tableList.value = [
			...tableList.value,
			{
				recptCode: "R007",
				recptName: "入库单7",
				vendorName: "供应商7",
				poCode: "PO007",
				recptDate: "2023-10-06",
				status: "CONFIRMED",
			},
		];
		originalTableList.value = [...tableList.value];
		getPageList();
		loading.value = false; // 隐藏加载动画
	}, 1000);
}
</script>

<template>
	<TableFrame title="采购入库管理">
		<template #extra>
			<el-button @click="handleExport"
				>导出数据<el-icon :size="22"><UploadFilled /></el-icon
			></el-button>
		</template>

		<!-- 搜索表单 -->
		<el-form v-if="showSearchBar" :inline="true" class="demo-form-inline">
			<el-row>
				<el-col :span="8">
					<el-form-item label="入库单编号：">
						<el-input v-model="recptCode" placeholder="请输入入库单编号" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="入库单名称：">
						<el-input v-model="recptName" placeholder="请输入入库单名称" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="供应商名称：">
						<el-input v-model="vendorName" placeholder="请输入供应商名称" clearable />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="订单编号：">
						<el-input v-model="poCode" placeholder="请输入订单编号" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="入库日期：">
						<el-date-picker v-model="recptDate" type="date" placeholder="请选择入库日期" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item>
						<el-button type="primary" @click="handleQuery"
							><el-icon><Search /></el-icon>查询</el-button
						>
						<el-button @click="resetQuery"
							><el-icon><Refresh /></el-icon>重置</el-button
						>
					</el-form-item>
				</el-col>
			</el-row>
		</el-form>

		<!-- 操作按钮 -->
		<el-button type="primary" plain @click="handleAdd">
			<el-icon><Plus /></el-icon>新增
		</el-button>
		<el-button type="success" plain @click="handleUpdate(row)">
			<el-icon><EditPen /></el-icon>修改
		</el-button>
		<el-button type="danger" plain @click="handleDelete(row)">
			<el-icon><Delete /></el-icon>删除
		</el-button>

		<!-- 数据表格 -->
		<el-table
			:data="tableList"
			style="width: 100%"
			v-loading="loading"
			@selection-change="handleSelectionChange"
			ref="multipleTable"
		>
			<el-table-column type="selection" width="55" />
			<el-table-column type="index" label="序号" width="55"></el-table-column>
			<el-table-column prop="recptCode" label="入库单编号" width="100" align="center"></el-table-column>
			<el-table-column prop="recptName" label="入库单名称" width="185" align="center"></el-table-column>
			<el-table-column prop="vendorName" label="供应商名称" width="125" align="center"></el-table-column>
			<el-table-column prop="recptDate" label="入库日期" width="150" align="center"></el-table-column>
			<el-table-column prop="poCode" label="采购订单号" width="150" align="center"></el-table-column>
			<el-table-column prop="status" label="单据状态" width="80" align="center">
				<template #default="{ row }">
					<el-tag :class="row.status === 'PREPARE' ? 'status-enabled' : 'status-disabled'" style="cursor: pointer">
						{{ row.status === "PREPARE" ? "已完成" : "草稿" }}
					</el-tag>
				</template>
			</el-table-column>
			<el-table-column label="操作" width="270" align="center">
				<template #default="{ row, $index }">
					<el-button @click="handleUpdate(row, $index)" circle type="primary">
						<el-icon :size="20"> <Edit /></el-icon>
					</el-button>
					<el-button @click="handleDelete(row, $index)" type="danger" circle>
						<el-icon :size="20"> <Delete /></el-icon>
					</el-button>
					<el-button @click="handleExecute(row, $index)" type="text">
						<el-icon :size="10"><VideoPlay /></el-icon>执行入库
					</el-button>
				</template>
			</el-table-column>
		</el-table>

		<!-- 分页组件 -->
		<el-pagination
			v-model:current-page="parms.pagenum"
			v-model:page-size="parms.pagesize"
			:page-sizes="[2, 3, 5, 10]"
			:background="true"
			layout="total, sizes, prev, pager, next, jumper"
			:total="total"
			@size-change="onSizeChange"
			@current-change="onCurrentChange"
			style="margin-top: 20px; justify-content: flex-end"
		/>

		<!-- 添加或修改物料入库单对话框 -->
		<el-dialog v-model="dialogVisible" title="dialogTitle">
			<el-form ref="formRef" :model="formModel" :rules="rules" label-width="120px">
				<el-row>
					<el-col :span="8">
						<el-form-item label="入库单编号" prop="recptCode">
							<el-input v-model="formModel.recptCode" placeholder="请输入入库单编号" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="入库单名称" prop="recptName">
							<el-input v-model="formModel.recptName" placeholder="请输入入库单名称" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="入库日期" prop="recptDate">
							<el-date-picker v-model="formModel.recptDate" type="date" placeholder="请选择入库日期" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="采购订单号" prop="poCode">
							<el-input v-model="formModel.poCode" placeholder="请输入采购订单号" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="单据状态" prop="status">
							<el-select v-model="formModel.status" placeholder="请选择单据状态">
								<el-option label="已完成" value="PREPARE"></el-option>
								<el-option label="草稿" value="CONFIRMED"></el-option>
							</el-select>
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="供应商" prop="vendorName">
							<el-input v-model="formModel.vendorName" placeholder="请输入供应商名称" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="24">
						<el-form-item label="入库仓库" prop="warehouseInfo">
							<el-cascader v-model="formModel.warehouseInfo" :options="[]" placeholder="请选择入库仓库" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="24">
						<el-form-item label="备注" prop="remark">
							<el-input v-model="formModel.remark" type="textarea" placeholder="请输入备注" />
						</el-form-item>
					</el-col>
				</el-row>
			</el-form>
			<template #footer>
				<el-button @click="cancelForm">取消</el-button>
				<el-button type="primary" @click="submitForm">确定</el-button>
			</template>
		</el-dialog>
	</TableFrame>
</template>

<style lang="scss" scoped>
.demo-form-inline {
	.el-input {
		--el-input-width: 220px;
	}

	.el-select {
		--el-select-width: 220px;
	}
}
.status-enabled {
	background-color: rgba(64, 158, 255, 0.2);
	color: #409eff;
	padding: 5px;
	text-align: center;
}

.status-disabled {
	background-color: rgba(245, 108, 108, 0.2);
	color: #f56c6c;
	padding: 5px;
	text-align: center;
}
.search-icons {
	display: flex;
	justify-content: flex-end;
	align-items: center;
	margin-left: auto;

	.el-button {
		margin-left: 10px;
		border: none;
		box-shadow: none;
	}

	&.fixed {
		position: absolute;
		top: 10px;
		right: 10px;
	}
}
</style>
