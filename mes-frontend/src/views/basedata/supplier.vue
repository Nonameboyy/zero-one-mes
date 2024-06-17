<template>
	<!--表单-->
	<el-form :inline="true" class="demo-form-inline">
		<el-row>
			<el-col :span="8">
				<el-form-item label="供应商编码：">
					<el-input v-model="supplierCode" placeholder="请输入供应商编码" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="8">
				<el-form-item label="供应商名称：">
					<el-input v-model="supplierName" placeholder="请输入供应商名称" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="8">
				<el-form-item label="供应商简称：">
					<el-input v-model="supplierForshort" placeholder="请输入供应商简称" clearable />
				</el-form-item>
			</el-col>
		</el-row>
		<el-row>
			<el-col :span="8">
				<el-form-item label="供应商英文名称：">
					<el-input v-model="supplierEn" placeholder="请输入供应商英文名称" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="8">
				<el-form-item label="是否启用：">
					<el-select v-model="enableFlag" placeholder="请选择">
						<el-option label="是" :value="true"></el-option>
						<el-option label="否" :value="false"></el-option>
					</el-select>
				</el-form-item>
			</el-col>
			<el-col :span="8">
				<el-form-item>
					<el-button type="primary" @click="onSubmit">
						<el-icon>
							<Search />
						</el-icon>
						查询
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
	<!-- 表格 -->
	<el-table v-loading="loading" :data="supplierList" @selection-change="handleSelectionChange">
		<el-table-column type="selection" width="55"></el-table-column>
		<el-table-column prop="supplierCode" label="供应商编码" align="center"></el-table-column>
		<el-table-column prop="supplierName" label="供应商名称" align="center"></el-table-column>
		<el-table-column prop="supplierForshort" label="供应商简称" align="center"></el-table-column>
		<el-table-column prop="supplierGrade" label="供应商等级" align="center"></el-table-column>
		<el-table-column prop="supplierScore" label="供应商评分" align="center"></el-table-column>
		<el-table-column prop="supplierTel" label="供应商电话" align="center"></el-table-column>
		<el-table-column prop="enableFlag" label="是否启用" align="center">
			<template #default="{ row }">
				<el-tag :class="row.isEnabled ? 'status-enabled' : 'status-disabled'" @click="toggleStatus(row)"
					style="cursor: pointer" class="status-tag">
					{{ row.isEnabled ? "是" : "否" }}
				</el-tag>
			</template>
		</el-table-column>

		<el-table-column label="操作" width="150" align="center">
			<template #default="{ row, $index }">
				<el-button @click="onEditchannel(row, $index)" circle type="primary">
					<el-icon :size="20">
						<Edit />
					</el-icon>
				</el-button>
				<el-button @click="onDelChannel(row, $index)" type="danger" circle>
					<el-icon>
						<Delete />
					</el-icon>
				</el-button>
			</template>
		</el-table-column>
	</el-table>

	<!-- </TableFrame> -->
	<!-- 对话框 -->
	<el-dialog v-model="dialogFormVisible" :title="dialogTitle" style="width: 700px">
		<el-form :model="formModel" :rules="rules" label-width="120px">
			<el-row>
				<el-col :span="12">
					<el-form-item label="供应商编码" prop="supplierCode">
						<el-input v-model="formModel.supplierCode" placeholder="请输入供应商编码" />
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="供应商名称" prop="supplierName">
						<el-input v-model="formModel.supplierName" placeholder="请输入供应商名称" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="12">
					<el-form-item label="供应商简称" prop="supplierForshort">
						<el-input v-model="formModel.supplierForshort" placeholder="请输入供应商简称" />
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="供应商英文名称" prop="supplierEn">
						<el-input v-model="formModel.supplierEn" placeholder="请输入供应商英文名称" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="24">
					<el-form-item label="供应商简介" prop="supplierDes">
						<el-input v-model="formModel.supplierDes" placeholder="请输入内容" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="24">
					<el-form-item label="供应商官网地址" prop="website">
						<el-input v-model="formModel.website" placeholder="请输入内容" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="12">
					供应商等级
					<div class="flex flex-wrap gap-4 items-center">
						<el-select v-model="GradeValue" :placeholder="GradeSelect" style="width: 240px">
							<el-option v-for="item in GradeOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</div>
				</el-col>
				<el-col :span="12">
					供应商评分<el-input-number v-model="num" :min="0" :max="100" @change="handleChange" />
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="供应商官网地址" prop="email">
						<el-input v-model="formModel.email" placeholder="请输入供应商邮箱地址" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="供应商邮箱地址" prop="email">
						<el-input v-model="formModel.email" placeholder="请输入供应商邮箱地址" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="供应商电话" prop="call">
						<el-input v-model="formModel.call" placeholder="请输入供应商电话" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="联系人1" prop="contact1">
						<el-input v-model="formModel.contact1" placeholder="请输入联系人1" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="联系人1-电话" prop="contact1Tel">
						<el-input v-model="formModel.contact1Tel" placeholder="请输入联系人1-电话" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="联系人1-邮箱" prop="contact1Email">
						<el-input v-model="formModel.contact1Email" placeholder="请输入联系人1-邮箱" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="联系人2" prop="contact2">
						<el-input v-model="formModel.contact2" placeholder="请输入联系人2" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="联系人2-电话" prop="contact2Tel">
						<el-input v-model="formModel.contact2Tel" placeholder="请输入联系人2-电话" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="联系人2-邮箱" prop="contact2Email">
						<el-input v-model="formModel.contact2Email" placeholder="请输入联系人2-邮箱" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="统一社会信用代码" prop="creditCode">
						<el-input v-model="formModel.creditCode" placeholder="请输入社会信用代码" />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="是否启用" prop="enableFlag">
						<el-radio-group v-model="formModel.enableFlag">
							<el-radio label="是" :value="true">是</el-radio>
							<el-radio label="否" :value="false">否</el-radio>
						</el-radio-group>
					</el-form-item>
				</el-col>

				<el-col :span="8">
					<el-form-item label="供应商LOGO" prop="supplierLogo">
						<el-input v-model="formModel.supplierLogo" placeholder="请输入供应商LOGO" />
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
		<div class="dialog-footer">
			<el-button @click="dialogFormVisible = false">取消</el-button>
			<el-button type="primary" @click="dialogFormVisible = false">确定</el-button>
		</div>
	</el-dialog>
</template>

<script setup>
import { ref } from "vue";
// import { TableFrame } from "components/std-table";
// import { constants } from "os";
const supplierCode = ref("");
const supplierName = ref("");
const supplierForshort = ref("");
const supplierEn = ref("");
const enableFlag = ref("");
const reFresh = function () {
	supplierCode.value = "";
	supplierName.value = "";
	supplierForshort.value = "";
	supplierEn.value = "";
	enableFlag.value = "";
};
const supplierList = [
	{
		supplierCode: "V0060",
		supplierName: "大特点",
		supplierForshort: "迪飞斯",
		supplierGrade: "正常",
		supplierScore: "0",
		supplierTel: "",
		comment: "",
		enableFlag: true,
	},
	{
		supplierCode: "V0063",
		supplierName: "瑞丽物资有限公司",
		supplierForshort: "",
		supplierGrade: "正常",
		supplierScore: "0",
		supplierTel: "",
		comment: "",
		enableFlag: true,
	},
	{
		supplierCode: "V0067",
		supplierName: "DB供应商",
		supplierForshort: "",
		supplierGrade: "正常",
		supplierScore: "0",
		supplierTel: "",
		comment: "",
		enableFlag: false,
	},
];
//对话框标题
const dialogTitle = ref("");
const loading = false;
const formModel = ref({
	supplierCode: "",
	supplierName: "",
	supplierForshort: "",
	supplierEn: "",
	supplierType: "",
	supplierDes: "",
	address: "",
	website: "",
	email: "",
	tel: "",
	supplierLogo: "",
	contact1: "",
	contact1Tel: "",
	contact1Email: "",
	contact2: "",
	contact2Tel: "",
	contact2Email: "",
	creditCode: "",
	enableFlag: "",
	remark: "",
});
const num = ref(0);
const toggleStatus = function (row) {
	row.isEnabled = !row.isEnabled;
};
const dialogFormVisible = ref(false);
const openTestDialog = function () {
	dialogTitle.value = "添加供应商";
	formModel.value = {
		supplierCode: "",
		supplierName: "",
		supplierForshort: "",
		supplierEn: "",
		supplierDes: "",
		website: "",
		email: "",
		call: "",
		tel: "",
		supplierLogo: "",
		contact1: "",
		contact1Tel: "",
		contact1Email: "",
		contact2: "",
		contact2Tel: "",
		contact2Email: "",
		creditCode: "",
		enableFlag: "",
		remark: "",
	};
	dialogFormVisible.value = true;
};
//修改供应商信息对话框
const onEditchannel = function (row) {
	dialogTitle.value = "修改供应商信息";
	formModel.value = { ...row };
	dialogFormVisible.value = true;
};
const rules = {
	supplierCode: [{ required: true, message: "请输入供应商编码", trigger: "blur" }],
	supplierName: [{ required: true, message: "请输入供应商名称", trigger: "blur" }],
	supplierForshort: [{ required: false, message: "请输入供应商简称", trigger: "blur" }],
	supplierEn: [{ required: false, message: "请输入供应商英文名称", trigger: "blur" }],
	// supplierType: [{ required: false, message: "请选择供应商类型", trigger: "change" }],
	supplierDes: [{ required: false, message: "请输入内容", trigger: "blur" }],
	address: [{ required: false, message: "请输入内容", trigger: "blur" }],
	website: [{ required: false, message: "请输入供应商官网地址", trigger: "blur" }],
	email: [{ required: false, message: "请输入供应商邮箱地址", trigger: "blur" }],
	tel: [{ required: false, message: "请输入供应商电话", trigger: "blur" }],
	supplierLogo: [{ required: false, message: "请输入供应商LOGO", trigger: "blur" }],
	contact1: [{ required: false, message: "请输入联系人1", trigger: "blur" }],
	contact1Tel: [{ required: false, message: "请输入联系人1-电话", trigger: "blur" }],
	contact1Email: [{ required: false, message: "请输入联系人1-邮箱", trigger: "blur" }],
	contact2: [{ required: false, message: "请输入联系人2", trigger: "blur" }],
	contact2Tel: [{ required: false, message: "请输入联系人2-电话", trigger: "blur" }],
	contact2Email: [{ required: false, message: "请输入联系人2-邮箱", trigger: "blur" }],
	creditCode: [{ required: false, message: "请输入社会信用代码", trigger: "blur" }],
	enableFlag: [{ required: true, message: "请选择是否启用", trigger: "change" }],
	remark: [{ required: false, message: "请输入备注", trigger: "blur" }],
};
const GradeValue = ref("");
const GradeSelect = "正常";
const GradeOptions = [
	{
		value: "Option1",
		label: "优质供应商",
	},
	{
		value: "Option2",
		label: "正常",
	},
	{
		value: "Option3",
		label: "重点关注",
	},
	{
		value: "Option4",
		label: "劣质供应商",
	},
	{
		value: "Option5",
		label: "黑名单",
	},
];
</script>

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

.status-tag {
	display: inline-flex;
	align-items: center;
	justify-content: center;
	width: 35px;
	height: 35px;
	cursor: pointer;
}

.el-table th,
.el-table td {
	text-align: center;
}
</style>
