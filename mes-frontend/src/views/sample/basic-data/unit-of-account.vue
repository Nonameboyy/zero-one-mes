<script setup>
import { ref } from "vue";
import http from "axios";
import { onMounted } from "vue";
import  TableFrame  from 'components/std-table/src/table-frame.vue' ;
import popUp from "components/std-table/src/pop-up.vue";
import Request from "@/apis/request.js";
// defineOptions();

//每一列数据，例子，后期接口对上再调整
const tableList = ref([
	{
		attr1: "自定义值1",
		attr2: "自定义值2",
		attr3: 100,
		attr4: 200,
		changeRate: 1,
		enableFlag: "Y",
		measureCode: "METER",
		measureName: "米",
		primaryFlag: "Y",
		primaryId: 1,
		remark: "这是主单位",
	},

	{
		attr1: "自定义值1",
		attr2: "自定义值2",
		attr3: 100,
		attr4: 200,
		changeRate: 1,
		enableFlag: "Y",
		measureCode: "METER",
		measureName: "米",
		primaryFlag: "Y",
		primaryId: 1,
		remark: "这是主单位",
	},
]);

//dialog联系到表格弹窗
const dialog = ref();

//定义总条数
const total = ref(13);

//定义查询的数据
let myInput = ref("");
let unitName = ref("");
const loading = ref(false); //loading状态

//定义请求参数,后期完善
const parms = ref({
	pagenum: 1, //页数
	pagesize: 5, //当前每页面大小
	state: "", //状态
	classfiy: "",
});

const getPageList = async (data) => {
	//不知道跟着接口写的对不对，希望大佬看一看
	loading.value = true;
	const res = "";
	try {
		const res = await Request.request(Request.GET, "/basicdata/md-unit-measure/list", data, http.upType.json);
		tableList.value = res.data.rows.data;
		parms.value.pagenum = res.data.pageIndex;
		parms.value.pagesize = res.data.pageSize;
		total.value = res.data.total;
	} catch (error) {
		console.log("错误或者超时");
	}

	loading.value = false;
};
onMounted(async ()=>{
await	getPageList(null); //进来就加载一遍
})

//处理分页逻辑
//改变大小
const onSizeChange = (size) => {
	//console.log('当前每页面条数',size);
	parms.value.pagenum = 1;
	parms.value.pagesize = size;
	//再利用接口渲染数据getPageList
	const Data = { pageSize: "parms.pagesize" };
	getPageList(Date);
};

//改变页数
const onCurrentChange = (page) => {
	// console.log('页面变化了',page);
	parms.value.pagenum = page;
	//基于当前最新页渲染数据
	const Data = { pageIndex: "parms.pagenum" };
	getPageList(Data);
};

//导出单位
const onSortChannel = async () => {
	try {
		const res = await Request.request(
			Request.GET,
			"/basicdata/md-unit-measure/download-unitMeasure",
			null,
			http.upType.json,
		);
	} catch (error) {
		console.log("错误或者超时");
	}
	if (res.code === 200) {
		ElMessage.success("导出成功");
	}
};

const onEditchannel = (row, $index) => {
	//编辑
	dialogTitle.value = "修改信息";
	formModel.value = { ...row };
	testDialogVisible.value = true;
};
const onDelChannel = async (row) => {
	//删除
	await ElMessageBox.confirm("你确认要删除该单位么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	});
	try {
		const res = await Request.request(
			Request.DELETE,
			"/basicdata/md-unit-measure/delete-by-measureIds",
			{ measureIds: row.data.primaryId },
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

const onSubmit = () => {
	const Sub={measureCode:myInput,measureName:unitName}
	getPageList(Sub);
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

//批量删除
async function arrDelet(){
	let ids = this.sels.map((item) => item.primaryId);
    try {
		const res= await Request.request(Request.DELETE,
		 "/basicdata/md-unit-measure/delete-by-measureIds", {primaryId:ids}, http.upType.json);
  if( res.code == '10000'){
	ElMessage.success("删除成功");
	getPageList(null);
    }else{
     ElMessage.warning("删除失败");
	}
	} catch (error) {
		console.log("错误或者超时");
	}
	//测试的
};

//表单--------------------------
const dialogTitle = ref("");
const formModel = ref({
	attr1: "自定义值1",
	attr2: "自定义值2",
	attr3: 100,
	attr4: 200,
	changeRate: 1,
	enableFlag: "Y",
	measureCode: "METER",
	measureName: "米",
	primaryFlag: "Y",
	primaryId: 1,
	remark: "这是主单位",
});
const formRef = ref(null);
const testDialogVisible = ref(false);

const openTestDialog = () => {
	dialogTitle.value = "添加信息";
	formModel.value = {
		attr1: "",
		attr2: "",
		attr3: 0,
		attr4: 0,
		changeRate: 0,
		enableFlag: "",
		measureCode: "",
		measureName: "",
		primaryFlag: "",
		primaryId: 0,
		remark: "",
	};
	testDialogVisible.value = true;
};

const rules = {
	primaryId: [{ required: true, message: "请输入主编码", trigger: "blur" }],
	enableFlag: [{ required: true, message: "请选择是否有效", trigger: "change" }],
	remark: [{ required: true, message: "请输入备注", trigger: "blur" }],
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
	<TableFrame title="计算单位">
		<template #extra>
			<el-button @click="onSortChannel"
				>导出数据
				<el-icon :size="20"> <UploadFilled /><!--排序图标--> </el-icon>
			</el-button>
			<el-button @click="onAddChannel"
				>添加
				<el-icon :size="20"> <Plus /><!--添加图标--> </el-icon>
			</el-button>
		</template>

		<!--表单区域-->
		<el-form :inline="true" class="demo-form-inline">
			<el-form-item label="单位编码：" padding="50px">
				<!--label是用户看，value是收集给后台的-->
				<el-input v-model="myInput" clearable />
			</el-form-item>
			<el-form-item label="单位名称">
				<el-input v-model="unitName" clearable />
			</el-form-item>
			<el-form-item>
				<el-button type="primary" @click="onSubmit"
					><el-icon><Search /></el-icon>查询</el-button
				>
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
			<el-table-column type="index" label="序号"></el-table-column>
			<el-table-column prop="attr1" label="预留字段1" width="100"></el-table-column>
			<el-table-column prop="attr2" label="预留字段2" width="100"></el-table-column>
			<el-table-column prop="attr3" label="预留字段3" width="100"></el-table-column>
			<el-table-column prop="attr4" label="预留字段4" width="100"></el-table-column>
			<el-table-column prop="changeRate" label="与主单位换算比例" width="100"></el-table-column>
			<el-table-column prop="enableFlag" label="是否启用">
				<template v-slot="{ row }">
					<el-tag :type="row.enableFlag === 'Y' ? 'success' : 'info'">{{
						row.enableFlag === "Y" ? "启用" : "未启用"
					}}</el-tag>
				</template>
			</el-table-column>
			<el-table-column prop="measureCode" label="单位编码"></el-table-column>
			<el-table-column prop="measureName" label="单位名称"></el-table-column>
			<el-table-column prop="primaryFlag" label="是否是主单位">
				<template v-slot="{ row }">
					<el-tag :type="row.enableFlag === 'Y' ? 'success' : 'info'">{{
						row.enableFlag === "Y" ? "主单位" : "非主单位"
					}}</el-tag>
				</template>
			</el-table-column>
			<el-table-column prop="primaryId" label="主单位ID"></el-table-column>
			<el-table-column prop="remark" label="备注"></el-table-column>
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
			<el-form-item label="自定义值1" prop="attr1">
				<el-input v-model="formModel.attr1" placeholder="请输入自定义值1"></el-input>
			</el-form-item>
			<el-form-item label="自定义值2" prop="attr2">
				<el-input v-model="formModel.attr2" placeholder="请输入自定义值2"></el-input>
			</el-form-item>
			<el-form-item label="自定义值3" prop="attr3">
				<el-input v-model="formModel.attr3" placeholder="自定义值3"></el-input>
			</el-form-item>
			<el-form-item label="自定义值4" prop="attr4">
				<el-input v-model="formModel.attr4" placeholder="自定义值4"></el-input>
			</el-form-item>
			<el-form-item label="与主单位换算比例" prop="changeRate">
				<el-input v-model="formModel.changeRate" placeholder="与主单位换算比例"></el-input>
			</el-form-item>
			<el-form-item label="是否启用" prop="enableFlag">
				<el-input v-model="formModel.enableFlag" placeholder="是否启用"></el-input>
			</el-form-item>
			<el-form-item label="单位编码" prop="measureCode">
				<el-input v-model="formModel.measureCode" placeholder="单位编码"></el-input>
			</el-form-item>
			<el-form-item label="单位名称" prop="measureName">
				<el-input v-model="formModel.measureName" placeholder="单位名称"></el-input>
			</el-form-item>
			<el-form-item label="是否是主单位" prop="primaryFlag">
				<el-input v-model="formModel.primaryFlag" placeholder="是否是主单位"></el-input>
			</el-form-item>
			<el-form-item label="主单位ID" prop="primaryId">
				<el-input v-model="formModel.primaryId" placeholder="主单位ID"></el-input>
			</el-form-item>
			<el-form-item label="备注" prop="remark">
				<el-input v-model="formModel.remark" placeholder="备注"></el-input>
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

	.el-select {
		--el-select-width: 220px;
	}
}
</style>
