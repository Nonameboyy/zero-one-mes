<template>
	<!-- 表单内容的搜索限制条件 -->
	<div class="table-ranking-container">
		<el-form :inline="true" :model="formInline" class="demo-form-inline">
			<el-form-item label="缺陷描述">
				<el-input v-model="formInline.describe" placeholder="请输入缺陷描述" clearable />
			</el-form-item>
			<el-form-item label="检测项类型">
				<el-select v-model="formInline.region" placeholder="请选择检测项类型" clearable>
					<el-option label="尺寸" value="size" />
					<el-option label="外观" value="appearance" />
				</el-select>
			</el-form-item>
			<el-form-item label="缺陷等级">
				<el-select v-model="formInline.level" placeholder="请选择缺陷等级" clearable>
					<el-option label="致命缺陷" value="critical" />
					<el-option label="严重缺陷" value="serious" />
					<el-option label="轻微缺陷" value="light" />
				</el-select>
			</el-form-item>
			<el-form-item>
				<el-button type="primary" icon="search" class="btn-size">搜索</el-button>
				<el-button icon="refresh" class="btn-size">重置</el-button>
			</el-form-item>
		</el-form>
	</div>
	<!-- 一行按钮 -->
	<el-row>
		<div class="table-btn">
			<el-button type="primary" class="btn-style" icon="plus" @click="dialogVisible = true">新增</el-button>
			<el-button type="success" class="btn-style" icon="EditPen">修改</el-button>
			<el-button type="danger" class="btn-style" icon="DeleteFilled">删除</el-button>
		</div>
	</el-row>
	<!-- 表单内容 -->
	<div class="table-container">
		<el-table ref="multipleTableRef" :data="tableData" style="width: 100%" @selection-change="handleSelectionChange">
			<el-table-column type="selection" width="auto" />
			<el-table-column label="缺陷描述" width="auto" align="center">
				<template #default="scope">{{ scope.row.describe }}</template>
			</el-table-column>
			<el-table-column property="name" label="检测项类型" width="auto" align="center" />
			<el-table-column property="address" label="缺陷等级" show-overflow-tooltip align="center" />
			<el-table-column label="操作" width="auto" align="center">
				<template #default="scope">
					<el-button size="small" icon="EditPen"> 修改 </el-button>
					<el-button size="small" icon="DeleteFilled" type="danger"> 删除 </el-button>
				</template>
			</el-table-column>
		</el-table>
	</div>
	<!-- 分页 -->
	<div class="table-pagination">
		<el-pagination
			v-model:current-page="currentPage4"
			v-model:page-size="pageSize4"
			:page-sizes="[10, 20, 30, 50]"
			small="true"
			:disabled="disabled"
			:background="background"
			layout="total, sizes, prev, pager, next, jumper"
			:total="10"
			@size-change="handleSizeChange"
			@current-change="handleCurrentChange"
		/>
	</div>
	<!-- 弹窗新增内容 -->
	<div class="add-fromData">
		<el-dialog v-model="dialogVisible" title="添加常见缺陷" width="800" draggable>
			<span class="addForm-container">
				<el-form label-width="auto" style="max-width: 600px">
					<el-row>
						<el-col>
							<el-form-item label="缺陷描述" width="auto" required class="textarea-size">
								<el-input v-model="addFormData.describe" type="textarea" />
							</el-form-item>
						</el-col>
					</el-row>
					<el-row style="width: 700px">
						<el-col :span="10" style="margin-right: 114px">
							<el-form-item label="检测项类型" required>
								<el-select v-model="addFormData.region" placeholder="请选择检测项类型" clearable>
									<el-option label="尺寸" value="size" />
									<el-option label="外观" value="appearance" />
								</el-select>
							</el-form-item>
						</el-col>
						<el-col :span="10">
							<el-form-item label="缺陷等级" required>
								<el-select v-model="addFormData.level" placeholder="请选择缺陷等级" clearable>
									<el-option label="致命缺陷" value="critical" />
									<el-option label="严重缺陷" value="serious" />
									<el-option label="轻微缺陷" value="light" />
								</el-select>
							</el-form-item>
						</el-col>
					</el-row>
				</el-form>
			</span>
			<template #footer>
				<div class="dialog-footer">
					<el-button @click="dialogVisible = false">取消</el-button>
					<el-button type="primary" @click="dialogVisible = false"> 确定 </el-button>
				</div>
			</template>
		</el-dialog>
	</div>
</template>

<script setup>
import { ref, reactive } from "vue";
const dialogVisible = ref(false);
const formInline = reactive({
	describe: "",
	region: "",
	level: "",
});

const handleSelectionChange = (val) => {
	multipleSelection.value = val;
};

const tableData = [
	{
		describe: "外观缺陷",
		name: "外观",
		address: "致命缺陷",
	},
	{
		describe: "气孔和夹渣",
		name: "外观",
		address: "轻微缺陷",
	},
	{
		describe: "裂纹",
		name: "外观",
		address: "严重缺陷",
	},
	{
		describe: "未焊透",
		name: "外观",
		address: "致命缺陷",
	},
	{
		describe: "未熔合",
		name: "尺寸",
		address: "致命缺陷",
	},
	{
		describe: "测试人员太差",
		name: "外观",
		address: "轻微缺陷",
	},
];

const addFormData = reactive({
	describe: "",
	type: "",
	level: "",
});
</script>

<style lang="scss" scoped>
.el-form-item .el-form-item__label {
	font-weight: bold !important;
}

.btn-size {
	font-size: 12px;
}

.btn-style {
	width: 66px;
	height: 30px;
	font-size: 12px;
}
.demo-form-inline .el-input {
	--el-input-width: 220px;
}

.demo-form-inline .el-select {
	--el-select-width: 220px;
}

//分页样式
.table-pagination {
	margin-top: 20px;
}

//新增表单样式
.addForm-container .el-form {
	padding: 0 20px;
}
.textarea-size {
	width: 700px !important;
}
</style>
