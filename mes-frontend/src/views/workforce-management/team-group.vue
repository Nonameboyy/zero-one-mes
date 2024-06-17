<script setup>
import { ref } from "vue";
import http from "axios";
import { onMounted } from "vue";
import  TableFrame  from 'components/std-table/src/table-frame.vue' 
import Request from "@/apis/request.js";

const tableList = ref([
	{
		calendarType: "机加工",
		endDate: "2023-12-13",
		planCode: "PL12345",
		planId: 1,
		planName: "年度计划",
		shiftMethod: "按月",
		shiftType: "白班",
		startDate: "2023-01-01",
		status: "已确认",
	},

	{
		calendarType: "机加工",
		endDate: "2024-6-7",
		planCode: "PY2899",
		planId: 2,
		planName: "五年计划",
		shiftMethod: "按年",
		shiftType: "夜班",
		startDate: "2019-01-01",
		status: "已完成",
	},
]);

//dialog联系到表格弹窗
const dialog = ref();

//定义总条数
const total = ref(13);

//定义查询的数据
let myInput = ref("");
//计划编号
let unitName = ref("");
//计划名称

const loading = ref(false); //loading状态

//定义请求参数,后期完善
const parms = ref({
	pagenum: 1, //页数
	pagesize: 5, //当前每页面大小
	code: 404, //状态码
	message: "",
});

const teamSelect = ref();

const getPageList = async (data) => {
	//不知道跟着接口写的对不对，希望大佬看一看
	loading.value = true;
	const res = "";
	try {
		const res = await Request.request(Request.GET, "/sch-manage/sch-plan/query-all", data, http.upType.json);
		tableList.value = res.data.rows.data;
		parms.value.pagenum = res.data.pageIndex;
		parms.value.pagesize = res.data.pageSize;
		parms.value.code = res.code;
		parms.message = res.messsage;
		total.value = res.data.total;
	} catch (error) {
		console.log("错误或者超时");
	}
	if (res.code === 10000) {
		console.log("调数据成功");
	}
	loading.value = false;
};

onMounted(async ()=>{
await	getPageList(null); //进来就加载一遍
})

//处理分页逻辑
//改变大小
const onSizeChange = (size) => {
	loading.value = true;
	//console.log('当前每页面条数',size);
	parms.value.pagenum = 1;
	parms.value.pagesize = size;
	//再利用接口渲染数据getPageList
	const Data = { pageSize: "parms.pagesize", pageIndex: 1 };
	getPageList(Date);
	loading.value = false;
};

//改变页数
const onCurrentChange = (page) => {
	// console.log('页面变化了',page);
	parms.value.pagenum = page;
	//基于当前最新页渲染数据
	const Data = { pageIndex: "parms.pagenum" };
	getPageList(Data);
};

//导出计划
const onSortChannel = async () => {
	try {
		const res = await Request.request(Request.GET, "/sch-manage/sch-plan/export-schedule-plan", null, http.upType.json);
	} catch (error) {
		console.log("错误或者超时");
	}
	if (res.code === 200) {
		ElMessage.success("导出成功");
	}
};

const onDelChannel = async (row) => {
	//删除
	await ElMessageBox.confirm("你确认要删除该班组么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	});
	try {
		const res = await Request.request(
			Request.DELETE,
			"/sch-manage/sch-plan/delete-schedule-plan",
			{ res: row.data.teamId },
			http.upType.json,
		);
	} catch (error) {
		console.log("错误或者超时");
	}
	if (res.code === 200) {
		ElMessage.success("删除成功");
		//删除后再渲染数据
		getPageList(null);
	}
};

const onEditchannel = (row, $index) => {
	//编辑
	dialogTitle.value = "修改班组";
	formModel.value = { ...row };
	testDialogVisible.value = true;
};

const onSubmit = () => {
  const Sub={planNumber:myInput,planName:unitName}
  getPageList(Sub)
	console.log("查询提交");
};

//添加
const onAddChannel = () => {};

const reFresh = () => {
	myInput = "";
	unitName = "";
};

//------批量删除有关
const sels = ref([]); //当前选框中选择的值

//获取选中的值
function handleSelectionChange (sels) {
	this.sels.value = sels;
};

const arrDelet=async ()=>{
	let ids = this.sels.map((item) => item. planId);
    try {
		const res= await Request.request(Request.DELETE,
		 "/sch-manage/sch-plan/delete-schedule-plan", {rems:ids}, http.upType.json);
  if( res.code == '10000'){
	ElMessage.success("删除成功");
    getPageList(null);
    }else{
     ElMessage.warning("删除失败");
	}
	} catch (error) {
		console.log("错误或者超时");
	}
};

//表单--------------------------
const dialogTitle = ref("");
const formModel = ref({
	calendarType: "机加工",
	endDate: "2024-6-7",
	planCode: "PY2899",
	planId: 2,
	planName: "五年计划",
	shiftMethod: "按年",
	shiftType: "夜班",
	startDate: "2019-01-01",
	status: "已完成",
});
const formRef = ref(null);
const testDialogVisible = ref(false);

const openTestDialog = () => {
	dialogTitle.value = "添加班组";
	formModel.value = {
		calendarType: "",
		endDate: "",
		planCode: "",
		planId: 0,
		planName: "",
		shiftMethod: "",
		shiftType: "",
		startDate: "",
		status: "",
	};
	testDialogVisible.value = true;
};

const rules = {
	startDate: [{ required: true, message: "开始日期不能为空", trigger: "blur" }],
	planId: [{ required: true, message: "计划Id不能为空", trigger: "change" }],
	endDate: [{ required: true, message: "截止日期不可以为空", trigger: "blur" }],
};
const submitForm = () => {
	formRef.value.validate((valid) => {
		if (valid) {
			console.log("提交成功", formModel.value);
			testDialogVisible.value = false;
		} else {
			console.log("提交失败");
			return false;
		}
	});
};

const cancelForm = () => {
	testDialogVisible.value = false;
};
</script>

<template>
	<!--分类，页面只有基本的表现，没有实现数据绑定-->
	<TableFrame title="排班设计">
		<template #extra>
			<el-button @click="onSortChannel"
				>导出数据
				<el-icon :size="20"> <UploadFilled /><!--排序图标--> </el-icon>
			</el-button>
		</template>

		<!--表单区域-->

		<el-form :inline="true" class="demo-form-inline">
			<el-form-item label="班组类型">
				<el-select v-model="teamSelect">
					<el-option label="机加工" value="1"></el-option>
					<el-option label="组装" value="2"></el-option>
					<el-option label="仓库" value="3"></el-option>
				</el-select>
			</el-form-item>
			<el-form-item label="计划编号：" padding="50px">
				<!--label是用户看，value是收集给后台的-->
				<el-input v-model="myInput" clearable />
			</el-form-item>
			<el-form-item label="计划名称">
				<el-input v-model="unitName" clearable />
			</el-form-item>
			<el-form-item>
				<el-date-picker class="data" v-model="myStartData" type="date" padding="20px" placeholder="请选择开始时间" />
			</el-form-item>
			<el-form-item>
				<el-date-picker class="data" v-model="myEndData" type="date" padding="20px" placeholder="请选择结束时间" />
			</el-form-item>

			<el-form-item>
				<el-button type="primary" @click="onSubmit"
					><el-icon><Search /></el-icon>查询
				</el-button>
			</el-form-item>
			<el-form-item>
				<el-button plain @click="reFresh"
					><el-icon><RefreshLeft /></el-icon>重置</el-button
				>
			</el-form-item>
		</el-form>

		<el-button type="primary" @click="openTestDialog" plain
			><el-icon><Plus /></el-icon>新增</el-button
		>
		<el-button type="success" @click="onEditchannel(row)" plain
			><el-icon><EditPen /></el-icon>修改</el-button
		>
		<el-button type="danger" @click="arrDelet" plain
			><el-icon><Delete /></el-icon>删除</el-button
		>

		<!--表格区-->
		<el-table
			:data="tableList"
			style="width: 100%"
			v-loading="loading"
			@selection-change="handleSelectionChange"
			ref="multipleTable"
		>
			<el-table-column type="selection" width="55" />
			<el-table-column prop="calendarType" label="班组类型"></el-table-column>
			<el-table-column prop="endDate" label="截止时间" width="150"></el-table-column>
			<el-table-column prop="planCode" label="计划编号" width="100"></el-table-column>
			<el-table-column prop="planId" label="计划ID" width="100"></el-table-column>
			<el-table-column prop="planName" label="计划名字" width="100"></el-table-column>
			<el-table-column prop="shiftMethod" label="倒班方式" width="100"></el-table-column>
			<el-table-column prop="shiftType" label="轮班方式" width="100"></el-table-column>
			<el-table-column prop="startDate" label="开始时间" width="100"></el-table-column>
			<el-table-column prop="status" label="单据状态" width="100"></el-table-column>
			<el-table-column label="操作" width="100">
				<!-- row是当前一行数据 index是下标-->
				<template #default="{ row, $index }">
					<el-button @click="onEditchannel(row, $index)" circle type="primary">
						<el-icon :size="20"> <Edit /><!--修改图标--> </el-icon>
					</el-button>
					<el-button @click="onDelChannel(row, $index)" type="danger" circle>
						<el-icon> <Delete /><!--删除图标--> </el-icon>
					</el-button>
				</template>
			</el-table-column>
		</el-table>
		<el-pagination
			v-model:current-page="parms.pagenum"
			v-model:page-size="parms.pagesize"
			:page-sizes="[2, 3, 5, 10]"
			:background="true"
			layout="total, sizes, prev, pager, next, jumper"
			:total="total"
			@size-change="onSizeChange"
			@current-change="OnCurrentChange"
			style="margin-top: 20px; justify-content: flex-end"
		/>
		<!---->

		<!--空处理-->
		<template #empty>
			<el-empty description="没有数据"></el-empty>
		</template>
	</TableFrame>

	<!-- 引入的弹窗
	<pop-Up ref="dialog"> </pop-Up> -->

	<el-dialog v-model="testDialogVisible" :title="dialogTitle" width="500">
		<!--:before-close="handleClose"//这个属性加上去要二次取消才可以-->
		<el-form ref="formRef" :model="formModel" :rules="rules" label-width="100px" style="padding-right: 30px">
			<el-form-item label="班组类型" prop="calendarType">
				<el-input v-model="formModel.calendarType" placeholder="请输入班组类型"></el-input>
			</el-form-item>
			<el-form-item label="截止时间" prop=" endDate">
				<el-input v-model="formModel.endDate" placeholder="请输入截止时间"></el-input>
			</el-form-item>
			<el-form-item label="计划编号" prop=" planCode">
				<el-input v-model="formModel.planCode" placeholder="请输入计划编号"></el-input>
			</el-form-item>
			<el-form-item label="计划名字" prop="planName">
				<el-input v-model="formModel.planName" placeholder="请输入计划名字"></el-input>
			</el-form-item>
			<el-form-item label="倒班方式" prop="shiftMethod">
				<el-input v-model="formModel.shiftMethod" placeholder="请输入倒班方式"></el-input>
			</el-form-item>
			<el-form-item label="轮班方式" prop="shiftType">
				<el-input v-model="formModel.shiftType" placeholder="请输入轮班方式"></el-input>
			</el-form-item>
			<el-form-item label="开始时间" prop="startDate">
				<el-input v-model="formModel.startDate" placeholder="请输入开始时间"></el-input>
			</el-form-item>
			<el-form-item label="单据状态" prop="status">
				<el-input v-model="formModel.status" placeholder="请输入单据状态"></el-input>
			</el-form-item>
		</el-form>
		<template #footer>
			<el-button @click="cancelForm">取消</el-button>
			<el-button type="primary" @click="submitForm">确定</el-button>
		</template>
	</el-dialog>
</template>

<style lang="scss" scoped>
.demo-form-inline {
	.el-input {
		--el-input-width: 220px;
	}
	.data {
		width: 220px;
		padding: 20%;
	}
	.el-select {
		--el-select-width: 220px;
	}
}
</style>
