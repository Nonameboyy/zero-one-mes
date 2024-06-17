<template>
	<!-- 表单 -->
	<el-form class="demo-form-inline">
		<el-row>
			<el-col :span="8">
				<el-form-item label="工装夹具编码">
					<el-input v-model="equipmentLedgerCode" style="width: 260px" placeholder="请输入编码类型" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="8">
				<el-form-item label="工装夹具名称">
					<el-input v-model="equipmentLedgerName" style="width: 260px" placeholder="请输入类型名称" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="8">
				<el-form-item label="工装夹具类型" prop="equipmentLedgerType">
					<div class="flex flex-wrap gap-4 items-center">
						<el-select v-model="equipmentLedgerType" placeholder="请选择类型" style="width: 240px">
							<el-option v-for="item in selectOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</div>
				</el-form-item>
			</el-col>
		</el-row>
	</el-form>
	<el-form>
		<el-row>
			<el-col :span="6">
				<el-form-item label="品牌">
					<el-input v-model="brand" style="width: 260px" placeholder="请输入编码类型" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="6">
				<el-form-item label="型号">
					<el-input v-model="model" style="width: 260px" placeholder="请输入型号" clearable />
				</el-form-item>
			</el-col>
			<el-col :span="6">
				<el-form-item label="状态">
					<div class="flex flex-wrap gap-4 items-center">
						<el-select v-model="state" placeholder="请选择状态" style="width: 240px">
							<el-option v-for="item in stateOptions" :key="item.value" :label="item.label" :value="item.value" />
						</el-select>
					</div>
				</el-form-item>
			</el-col>
			<el-col :span="6">
				<el-form-item>
					<el-button type="primary" @click="search">
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
	<!-- 表格 -->
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
	<el-table :data="equipmentLedgerList" @selection-change="handleSelectionChange">
		<el-table-column type="selection" width="55"></el-table-column>
		<el-table-column prop="equipmentLedgerCode" label="编号" align="center"></el-table-column>
		<el-table-column prop="equipmentLedgerName" label="名称" align="center"></el-table-column>
		<el-table-column prop="brand" label="品牌" align="center"></el-table-column>
		<el-table-column prop="equipmentLedgerType" label="型号" align="center"></el-table-column>
		<el-table-column prop="type" label="类型" align="center"></el-table-column>
		<el-table-column prop="num" label="存货数量" align="center"></el-table-column>
		<el-table-column prop="usable" label="可用数量" align="center"></el-table-column>
		<el-table-column prop="maintenance" label="保养维护类型" align="center"></el-table-column>
		<el-table-column prop="maintenanceWeek" label="下次保养周期" align="center"></el-table-column>
		<el-table-column prop="maintenanceDay" label="下次保养日期" align="center"></el-table-column>
		<el-table-column prop="state" label="状态" align="center"></el-table-column>
		<el-table-column prop="handle" label="操作" align="center"></el-table-column>
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
	<!-- 对话框 -->
	<el-dialog v-model="dialogFormVisible" :title="dialogTitle" style="width: 700px">
		<el-form :model="equipmentLedger" :rules="rules">
			<el-row>
				<el-col :span="12">
					<el-form-item label="工装夹具类型" prop="equipmentLedgerType">
						<div class="flex flex-wrap gap-4 items-center">
							<el-select v-model="equipmentLedgerType" placeholder="请选择类型" style="width: 240px">
								<el-option v-for="item in selectOptions" :key="item.value" :label="item.label" :value="item.value" />
							</el-select>
						</div>
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="工装夹具名称" prop="equipmentLedgerName">
						<el-input v-model="equipmentLedger.equipmentLedgerName" placeholder="请输入工装夹具名称" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="12">
					<el-form-item label="品牌">
						<el-input v-model="equipmentLedger.brand" placeholder="请输入品牌" autocomplete="off" />
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="型号">
						<el-input v-model="equipmentLedger.brand" placeholder="请输入型号" autocomplete="off" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="12">
					<el-form-item label="工装夹具编号">
						<el-input v-model="equipmentLedger.type" placeholder="请输入工装夹具编号" />
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="数量" prop="num">
						<el-input-number v-model="num" :min="0" :max="100000000" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="12">
					<el-form-item label="可用数量">
						<el-input v-model="equipmentLedger.usable" />
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="保养维护类型">
						<div class="flex flex-wrap gap-4 items-center">
							<el-select v-model="equipmentLedger.maintenance" placeholder="定期维护" style="width: 240px">
								<el-option v-for="item in maintenanceOptions" :key="item.value" :label="item.label"
									:value="item.value" />
							</el-select>
						</div>
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="12">
					<el-form-item label="下一次保养日期">
						<div class="demo-date-picker">
							<div class="block">
								<el-date-picker v-model="equipmentLedger.maintenanceDay" type="date" placeholder="请选择下一次保养日期"
									:size="size" />
							</div>
						</div>
					</el-form-item>
				</el-col>
				<el-col :span="12">
					<el-form-item label="状态">
						<div class="flex flex-wrap gap-4 items-center">
							<el-radio v-model="state" disabled value="zaiku">在库</el-radio>
							<el-radio v-model="state" disabled value="beilingyong"> 被领用 </el-radio>
							<el-radio v-model="state" disabled value="baofei">报废</el-radio>
							<el-radio v-model="state" disabled value="weixiuzhong"> 维修中 </el-radio>
						</div>
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="24">
					<el-form-item label="备注">
						<el-input v-model="equipmentLedger.remark" placeholder="请输入内容" />
					</el-form-item>
				</el-col>
			</el-row>
		</el-form>
		<div class="dialog-footer">
			<el-button @click="dialogFormVisible = false">取消</el-button>
			<el-button type="primary" @click="dialogFormVisible = false"> 确定 </el-button>
		</div>
	</el-dialog>
</template>

<script setup>
import { reactive, ref } from "vue";

const dialogTitle = ref("");
const selectOptions = [
	{
		value: "Option1",
		label: "刀具",
	},
	{
		value: "Option2",
		label: "模具",
	},
	{
		value: "Option3",
		label: "夹具",
	},
];
const maintenanceOptions = [
	{
		value: "Option1",
		label: "定期维护",
	},
	{
		value: "Option2",
		label: "按使用次数维护",
	},
];
const stateOptions = [
	{
		value: "Option1",
		label: "在线",
	},
	{
		value: "Option2",
		label: "被领用",
	},
	{
		value: "Option3",
		label: "报废",
	},
	{
		value: "Option4",
		label: "维修中",
	},
];
const equipmentLedgerCode = ref("");
const equipmentLedgerName = ref("");
const equipmentLedgerType = ref("");
const brand = ref("");
const model = ref("");
const state = ref("");
const num = ref(1);
const dialogFormVisible = ref(false);
const equipmentLedger = reactive({
	equipmentLedgerCode: "",
	equipmentLedgerName: "",
	equipmentLedgerType: "",
	brand: "",
	model: "",
	type: "",
	num: "",
	maintenance: "",
	usable: 0,
	state: "zaiku",
	maintenanceDay: "",
	state: "",
	remark: "",
});
const reFresh = function () {
	equipmentLedgerCode.value = "";
	equipmentLedgerName.value = "";
	equipmentLedgerType.value = "";
	brand.value = "";
	model.value = "";
	state.value = "";
};
const onEditchannel = function (row) {
	dialogTitle.value = "修改工装夹具清单";
	equipmentLedger.value = { ...row };
	dialogFormVisible.value = true;
};
const rules = {
	equipmentLedgerType: [{ required: true, trigger: "blur" }],
	equipmentLedgerName: [{ required: true, message: "工装夹具名称不能为空", trigger: "blur" }],
	num: [{ required: true, trigger: "blur" }],
};
const equipmentLedgerList = [
	{
		equipmentLedgerCode: "T00074",
		equipmentLedgerName: "XX刀具",
		brand: "XX品牌",
		equipmentLedgerType: "XXX型号",
		type: "刀具",
		num: 70, //库存数量
		usable: 60, //可用数量
		maintenance: "定期维护",
		maintenanceWeek: "",
		maintenanceDay: "2025-05-16",
		state: "在库",
		handle: "",
	},
	{
		equipmentLedgerCode: "T00060",
		equipmentLedgerName: "XX模具",
		brand: "XXX牌",
		equipmentLedgerType: "XXX型号",
		type: "模具",
		num: 1,
		usable: 1,
		maintenance: "定期维护",
		maintenanceWeek: "",
		maintenanceDay: "2025-05-20",
		state: "在库",
		handle: "",
	},
];
//函数
const openTestDialog = function () {
	dialogTitle.value = "新增工装夹具清单";
	dialogFormVisible.value = true;
	equipmentLedger.value = {
		equipmentLedgerCode: "",
		equipmentLedgerName: "",
		equipmentLedgerType: "",
		brand: "",
		type: "",
		num: "",
		usable: "",
		maintenance: "",
		maintenanceWeek: "",
		maintenanceDay: "",
		state: "",
		handle: "",
	};
};
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
