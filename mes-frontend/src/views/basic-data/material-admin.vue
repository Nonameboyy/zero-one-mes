<script setup>
import { ref, watch } from "vue";
import http from "axios";
import { onMounted } from "vue";
import  TableFrame  from 'components/std-table/src/table-frame.vue' 
import Request from "@/apis/request.js";

const tableList = ref([
	{
		ancestors: "1",
		createBy: "阿伟",
		enableFlag: "T",
		itemOrProduct: "os",
		itemTypeCode: "awnb",
		itemTypeId: 114514,
		itemTypeName: "金属",
		orderNum: 1,
		parentTypeId: 0,
		remark: "0x3f",
		updateBy: "东东哥",
	},
]);

//dialog联系到表格弹窗
const dialog = ref();

//定义总条数
const total = ref(13);

//定义查询的数据
const myInput = ref();

const loading = ref(false); //loading状态

//定义分类的请求参数
const parms = ref({
	// pagenum:1,//页数
	// pagesize: 5,//当前每页面大小
	// state:'',//状态
	// classfiy:''
	enableFlag: "",
	itemOrProduct: "os",
	itemTypeCode: "awnb",
	itemTypeId: "",
	itemTypeName: "金属",
	orderNum: "",
	page: "",
	parentTypeId: "",
	size: "",
});

const getPageList= async (data)=>{
  //不知道跟着接口写的对不对，希望大佬看一看
  loading.value=true
 try {
  const res=await Request.request(Request.GET,'/mes/md/itemtype/{itemTypeId}',data,http.upType.json)
  tableList.value=res.data.data
 } catch (error) {
  console.log('错误或者超时');
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
const onCurrentChange = async (page) => {
	parms.value.page = page;
	//基于当前最新页渲染数据
	loading.value = true;
	try {
		const res = await request(request.GET, "/mes/md/itemtype/list", { page: page });
		tableList.value = res.data.data;
	} catch (error) {
		console.log("错误或者超时");
	}
	loading.value = false;
};

const onEditchannel = (row, $index) => {
	//编辑
	dialog.value.open({ row });
	console.log(row);
};

const onDelChannel = async (row) => {
	//删除
	await ElMessageBox.confirm("你确认要删除该单位么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	});
	try {
		const res = await Request.request(Request.DELETE, "/mes/md/itemtype/{itemTypeId}", {
			itemTypeId: row.data.itemTypeId,
		});
	} catch (error) {
		console.log("错误或者超时");
	}
	if (res.code === 200) {
		ElMessage.success("删除成功");
	}

	//  console.log(row)
	//删除后再渲染数据
	getPageList();
};
const onSubmit = () => {
	getPageList(myInput);
	console.log("查询提交");
};
//添加
const onAddChannel = () => {
	dialog.value.open({});
};

const reFresh = () => {
	myInput.value = "";
};

//树形组件相关配置
//定义子节点
const defaultProps = {
	children: "children",
	label: "label",
};

//定义树形组件中查询分类的名字
const filterText = ref("");

//定义下个节点有没有值
const filterNode = (value, data) => {
	if (!value) return true;
	return data.label.indexOf(value) !== -1;
};

//监听过滤器
const treeRef = ref();
watch(filterText, (val) => {
	this.$refs.treeRef.filter(val);
});

const data =ref([
  {
    id: 1,
    label: '物料产品分类',
    children: [
      {
        id: 4,
        label: '原材料',
        children: [
          {
            id: 9,
            label: '金属',
          },
          {
            id: 10,
            label: '纸屑',
          },
        ]   
      },
      {
        id:11,
        label:'产品',
        children:[
          {
            id:2,
            label:'完美品'
          },
          {
            id:3,
            label:'瑕疵品'
          },
          {
            id:5,
            label:'普通品'
          }
        ]
      },
      {
        id:6,
        label:'其它'
      }
    ],
  },
  
]) 
//定义请求树形数据函数·1、
const getTreeDate=async ()=>{
  try {
  const res=await Request.request(Request.GET,'/mes/md/itemtype/treeselect',{},http.upType.json)
  data.value=res.data.data
 } catch (error) {
  console.log('错误或者超时');
 } 
}
//-----------------多删
const sels = ref([]); //当前选框中选择的值

//获取选中的值
function handleSelectionChange (sels) {
	this.sels.value = sels;
  console.log("选中的值",sels.map((item) => item.id));
};

//批量删除
async function arrDelet(){
	let ids = this.sels.map((item) => item.itemTypeId);
    try {
		const res= await Request.request(Request.DELETE,
		 "/basicdata/md-unit-measure/delete-by-measureIds", {itemTypeId:ids}, http.upType.json);
  if( res.code == '10000'){
	ElMessage.success("删除成功");
    }else{
     ElMessage.warning("删除失败");
	}
	} catch (error) {
		console.log("错误或者超时");
	}
	//测试的
	ElMessage.success("删除成功");
};

//表单--------------------------
const dialogTitle = ref("");
const formModel = ref({
	ancestors: "1",
	createBy: "阿伟",
	enableFlag: "T",
	itemOrProduct: "os",
	itemTypeCode: "awnb",
	itemTypeId: 114514,
	itemTypeName: "金属",
	orderNum: 1,
	parentTypeId: 0,
	remark: "0x3f",
	updateBy: "东东哥",
});
const formRef = ref(null);
const testDialogVisible = ref(false);

const openTestDialog = () => {
	dialogTitle.value = "添加信息";
	formModel.value = {
		ancestors: "",
		createBy: "",
		enableFlag: "",
		itemOrProduct: "",
		itemTypeCode: "",
		itemTypeId: 0,
		itemTypeName: "",
		orderNum: 0,
		parentTypeId: 0,
		remark: "",
		updateBy: "",
	};
	testDialogVisible.value = true;
};

const rules = {
	itemTypeId: [{ required: true, message: "请输入主编码", trigger: "blur" }],
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
	<el-container>
		<el-aside width="200px" style="padding-top: 20px">
			<el-input v-model="filterText" style="width: 200px" placeholder="请输入分类名称">
				<!--prefix插槽使用，将搜索图标放在输入前面-->
				<template #prefix>
					<el-icon class="el-input__icon"><search /></el-icon>
				</template>
			</el-input>

			<el-tree
				ref="treeRef"
				style="max-width: 200px"
				class="filter-tree"
				:data="data"
				:props="defaultProps"
				default-expand-all
				:filter-node-method="filterNode"
			/>
		</el-aside>

		<el-main>
			<TableFrame title="物料产品管理">
				<!--表单区域-->
				<el-form :inline="true" class="demo-form-inline">
					<el-form-item label="分类名称：" padding="50px">
						<!--label是用户看，value是收集给后台的.这个输入框输入查询分类的ID-->
						<el-input v-model="myInput" clearable />
					</el-form-item>
					<el-form-item label="是否启用">
						<el-select v-model="parms.state"
							><!--后台标记状态-->
							<el-option label="正常" value="true"></el-option>
							<el-option label="失败" value="false"></el-option>
						</el-select>
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
					<el-table-column prop="ancestors" label="祖先节点列表" width="100"></el-table-column>
					<el-table-column prop="createBy" label="创建者" width="100"></el-table-column>
					<el-table-column prop="enableFlag" label="启用标识" width="100">
						<template v-slot="{ row }">
							<el-tag :type="row.enableFlag === 'T' ? 'success' : 'info'">{{
								row.enableFlag === "T" ? "启用" : "未启用"
							}}</el-tag>
						</template>
					</el-table-column>
					<el-table-column prop="itemOrProduct" label="产品物料标识" width="100"></el-table-column>
					<el-table-column prop="itemTypeCode" label="分类编码" width="100"></el-table-column>
					<el-table-column prop="itemTypeId" label="分类ID"></el-table-column>
					<el-table-column prop="itemTypeName" label="分类名称"></el-table-column>
					<el-table-column prop="orderNum" label="排序号"></el-table-column>
					<el-table-column prop="parentTypeId" label="父分类ID"></el-table-column>
					<el-table-column prop="remark" label="备注"></el-table-column>
					<el-table-column prop="updateBy" label="更新者"></el-table-column>
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
			<!--引入的弹窗-->
			<!-- <pop-Up ref="dialog"> </pop-Up> -->

			<el-dialog v-model="testDialogVisible" :title="dialogTitle" width="500">
				<!--:before-close="handleClose"//这个属性加上去要二次取消才可以-->
				<el-form ref="formRef" :model="formModel" :rules="rules" label-width="100px" style="padding-right: 30px">
					<el-form-item label="祖先节点列表" prop="ancestors">
						<el-input v-model="formModel.ancestors" placeholder="请输入祖先节点列表"></el-input>
					</el-form-item>
					<el-form-item label="创建者" prop="createBy">
						<el-input v-model="formModel.createBy" placeholder="请输入创建者"></el-input>
					</el-form-item>
					<el-form-item label="启用标识" prop="enableFlag">
						<el-input v-model="formModel.enableFlag" placeholder="请输入启用标识"></el-input>
					</el-form-item>
					<el-form-item label="产品物料标识" prop="itemOrProduct">
						<el-input v-model="formModel.itemOrProduct" placeholder="请输入产品物料标识"></el-input>
					</el-form-item>
					<el-form-item label="分类编码" prop="itemTypeCode">
						<el-input v-model="formModel.itemTypeCode" placeholder="请输入分类编码"></el-input>
					</el-form-item>
					<el-form-item label="分类ID" prop="itemTypeId">
						<el-input v-model="formModel.itemTypeId" placeholder="请输入分类ID"></el-input>
					</el-form-item>
					<el-form-item label="分类名称" prop="itemTypeName">
						<el-input v-model="formModel.itemTypeName" placeholder="请输入分类名称"></el-input>
					</el-form-item>
					<el-form-item label="排序号" prop="orderNum">
						<el-input v-model="formModel.orderNum" placeholder="请输入排序号"></el-input>
					</el-form-item>
					<el-form-item label="父分类ID" prop="parentTypeId">
						<el-input v-model="formModel.parentTypeId" placeholder="请输入父分类ID"></el-input>
					</el-form-item>
					<el-form-item label="更新者" prop="updateBy">
						<el-input v-model="formModel.updateBy" placeholder="请输入更新者"></el-input>
					</el-form-item>
					<el-form-item label="备注" prop="remark">
						<el-input v-model="formModel.remark" placeholder="请输入备注"></el-input>
					</el-form-item>
				</el-form>
				<template #footer>
					<el-button @click="cancelForm">取消</el-button>
					<el-button type="primary" @click="submitForm">确定</el-button>
				</template>
			</el-dialog>
		</el-main>
	</el-container>
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
