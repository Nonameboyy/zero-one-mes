<template>
	<!-- 表单 -->
	<el-form :model="form" label-width="auto" class="myForm">
		<el-row>
			<el-col :span="6">
				<div class="grid-content ep-bg-purple">
					<el-form-item label="检验单编号">
						<el-input v-model="inspectionCode" placeholder="供应商编码" clearable />
					</el-form-item>
				</div>
			</el-col>
			<el-col :span="6">
				<div class="grid-content ep-bg-purple">
					<el-form-item label="检验类型">
						<el-select v-model="type" placeholder="请输入检验类型" style="width: 240px">
							<el-option v-for="item in typeOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</el-form-item>
				</div>
			</el-col>
			<el-col :span="6">
				<div class="grid-content ep-bg-purple">
					<el-form-item label="工单编号">
						<el-input v-model="workCode" placeholder="请输入工单编号" clearable />
					</el-form-item>
				</div>
			</el-col>
			<el-col :span="6">
				<div class="grid-content ep-bg-purple">
					<el-form-item label="产品物料编码">
						<el-input v-model="productmaterialCode" placeholder="请输入产品物料编码" clearable />
					</el-form-item>
				</div>
			</el-col>
		</el-row>
		<el-row>
			<el-col :span="6">
				<div class="grid-content ep-bg-purple">
					<el-form-item label="产品物料名称">
						<el-input v-model="productName" placeholder="请输入产品物料名称" clearable />
					</el-form-item>
				</div>
			</el-col>
			<el-col :span="6">
				<div class="grid-content ep-bg-purple">
					<el-form-item label="检验结果">
						<el-select v-model="result" placeholder="请输入检验结果" style="width: 240px">
							<el-option v-for="item in resultOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</el-form-item>
				</div>
			</el-col>
			<el-col :span="6">
				<el-form-item>
					<el-button type="primary" @click="onSubmit">
						<el-icon>
							<Search />
						</el-icon>
						搜索
					</el-button>
					<el-button @click="reFresh">
						<el-icon>
							<Refresh />
						</el-icon>
						重置
					</el-button>
				</el-form-item>
			</el-col>
		</el-row>
	</el-form>
	<el-button type="primary" plain @click="openTestDialog">
		<el-icon>
			<Plus />
		</el-icon>
		新增
	</el-button>
	<el-button type="success" plain @click="onEditchannel(row)">
		<el-icon>
			<EditPen />
		</el-icon>
		修改
	</el-button>
	<el-button type="danger" plain>
		<el-icon>
			<Delete />
		</el-icon>
		删除
	</el-button>
	<!-- 表单 -->
	<el-table :data="processList" stripe style="width: 100%">
		<el-table-column type="selection" width="55"></el-table-column>
		<el-table-column prop="inspectionCode" label="检验单编号" />
		<el-table-column prop="type" label="检验类型" />
		<el-table-column prop="workCode" label="工单编号" />
		<el-table-column prop="productmaterialCode" label="产品物料编码" />
		<el-table-column prop="productName" label="产品物料名称" />
		<el-table-column prop="model" label="规格型号" />
		<el-table-column prop="unit" label="单位" />
		<el-table-column prop="checkNum" label="检测数量" />
		<el-table-column prop="result" label="检测结果" />
		<el-table-column prop="date" label="检测日期" />
		<el-table-column prop="personnel" label="检测人员" />
		<el-table-column prop="state" label="状态" />
	</el-table>
	<!-- 对话框 -->
	<el-dialog v-model="dialogFormVisible" :title="dialogTitle" style="width: 700px">
		<el-form :model="process" :rules="rules">
			<el-row>
				<el-col :span="12">
					<el-form-item label="检验单编号" prop="inspectionCode">
						<el-input v-model="process.inspectionCode" placeholder="请输入检验单编号" autocomplete="off" />
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="检验单名称">
						<el-input v-model="process.inspectionName" placeholder="请输入检验单名称" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="检验类型" prop="type">
						<el-select v-model="process.type" placeholder="请选择检验类型">
							<el-option v-for="item in typeOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="工单编码" prop="workCode">
						<el-input v-model="process.workCode" placeholder="请选择生产工单" autocomplete="off" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="工单名称">
						<el-input v-model="process.productName" placeholder="请输入工单名称" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="工作站编号" prop="workstationCode">
						<el-input v-model="process.workstationCode" placeholder="请输入工作站编号" autocomplete="off" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="工作站名称">
						<el-input v-model="process.workstationName" placeholder="请输入工作站名称" autocomplete="off" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="检测数量" prop="checkNum">
						<el-input v-model="process.checkNum" placeholder="请输入检测数量" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="24">
					<el-collapse class="demo-collapse" v-model="activeNames" @change="handleChange">
						<el-collapse-item title="更多信息" name="1">
							<el-row>
								<el-col :span="8">
									<el-form-item label="工作站编号" prop="workstationCode">
										<el-input v-model="process.workstationCode" placeholder="请输入工作站编号" autocomplete="off" />
									</el-form-item>
								</el-col>
								<el-col :span="8">
									<el-form-item label="工作站名称">
										<el-input v-model="process.workstationName" placeholder="请输入工作站名称" autocomplete="off" />
									</el-form-item>
								</el-col>
								<el-col :span="8">
									<el-form-item label="检测数量" prop="checkNum">
										<el-input v-model="process.checkNum" placeholder="请输入检测数量" autocomplete="off" />
									</el-form-item>
								</el-col>
							</el-row>
						</el-collapse-item>
					</el-collapse>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="检测日期">
						<div class="demo-date-picker">
							<div class="block">
								<el-date-picker v-model="process.checkDate" type="date" placeholder="请选择检测日期" :size="size" />
							</div>
						</div>
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="检测结果">
						<el-select v-model="result" placeholder="请选择检验结果">
							<el-option v-for="item in resultOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="检测人员">
						<el-input v-model="process.personnel" placeholder="请输入检测人员" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="24">
					<el-form-item label="备注">
						<el-input v-model="process.remark" placeholder="请输入内容" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
		</el-form>
		<div class="dialog-footer">
			<el-button @click="dialogFormVisible = false">取消</el-button>
			<el-button type="primary" @click="dialogFormVisible = false">确定</el-button>
		</div>
	</el-dialog>
</template>

<script setup>
import { reactive, ref } from "vue";

const inspectionCode = ref(""); //检验单编号
const type = ref(""); //检验类型
const workCode = ref(""); //工单编号
const productmaterialCode = ref(""); //产品物料编码
const productName = ref(""); //产品物料名称
const result = ref(""); //检验结果
const typeOptions = [
	{
		value: "Option1",
		label: "首检",
	},
	{
		value: "Option2",
		label: "未检",
	},
	{
		value: "Option3",
		label: "自检",
	},
	{
		value: "Option4",
		label: "巡检",
	},
	{
		value: "Option5",
		label: "点检",
	},
	{
		value: "Option6",
		label: "终检",
	},
];
const resultOptions = [
	{
		value: "Option1",
		label: "检验通过",
	},
	{
		value: "Option2",
		label: "检验不通过",
	},
];
const dialogTitle = ref("");
const process = reactive({
	inspectionCode: "", //检验单编号
	inspectionName: "", //检验单名称
	type: "", //检验类型
	workCode: "", //工单编码
	productmaterialCode: "", //产品物料编码
	productName: "", //工单名称
	workstationCode: "", //工作站编号
	workstationName: "", //工作站名称
	checkNum: "", //检测数量
	productName: "", //产品物料名称
	checkDate: "", //检测日期
	result: "", //检验结果
	personnel: "", //检测人员
	remark: "", //备注
});
const rules = {
	inspectionCode: [{ required: true, message: "请输入生产检验单编号" }], //检验单编号
	type: [{ required: true }], //检验类型
	workCode: [{ required: true, message: "请选择生产工单" }], //工单编码
	workstationCode: [{ required: true, message: "请选择工作站" }], //工作站编号
	checkNum: [{ required: true, message: "检测数量不能为空" }], //检测数量
};
const processList = reactive([
	{
		inspectionCode: "IPQC202406090001",
		type: "首检",
		workCode: "MO202405310004",
		productmaterialCode: "IF2022082403",
		productName: "色粉【蓝色】",
		model: "蓝色",
		unit: "g",
		checkNum: 5,
		result: "检验通过",
		date: "2024-06-09",
		personnel: "1110",
		state: "已完成",
	},
	{
		inspectionCode: "IPQC202406060009",
		type: "未检",
		workCode: "MO202406060019",
		productmaterialCode: "IF20240603066",
		productName: "独轮自行车",
		model: "直径50毫米",
		unit: "PCS",
		checkNum: 10,
		result: "检验通过",
		date: "2024-06-06",
		personnel: "",
		state: "已完成",
	},
]);
const dialogFormVisible = ref(false);
const openTestDialog = function () {
	dialogFormVisible.value = true;
	dialogTitle.value = "添加过程检验单";
	process.value = {
		inspectionCode: "",
		type: "",
		workCode: "",
		productmaterialCode: "",
		productName: "",
		model: "",
		unit: "",
		checkNum: 0,
		result: "",
		date: "",
		personnel: "",
		state: "",
	};
};
const reFresh = function () {
	inspectionCode.value = ""; //检验单编号
	type.value = ""; //检验类型
	workCode.value = ""; //工单编号
	productmaterialCode.value = ""; //产品物料编码
	productName.value = false; //产品物料名称
	result.value = ""; //检验结果
};
const onEditchannel = function (row) {
	dialogTitle.value = "修改过程检验单";
	type.value = { ...row };
	dialogFormVisible.value = true;
};
</script>

<style lang="scss" scoped>
.myForm {
	.el-input {
		--el-input-width: 220px;
	}

	.el-select {
		--el-select-width: 220px;
	}

	.el-row {
		margin-bottom: 20px;
	}

	.el-row:last-child {
		margin-bottom: 0;
	}

	.el-col {
		border-radius: 4px;
	}

	.grid-content {
		border-radius: 4px;
		min-height: 36px;
	}
}

.demo-date-picker {
	display: flex;
	width: 100%;
	padding: 0;
	flex-wrap: wrap;
}

.demo-date-picker .block {
	padding: 30px 0;
	text-align: center;
	border-right: solid 1px var(--el-border-color);
	flex: 1;
}

.demo-date-picker .block:last-child {
	border-right: none;
}

.demo-date-picker .demonstration {
	display: block;
	color: var(--el-text-color-secondary);
	font-size: 14px;
	margin-bottom: 20px;
}
</style>
