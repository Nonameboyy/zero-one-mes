<script setup lang="ts">
import { ref } from "vue";
import { TableFrame } from "components/std-table";
import request from "@/apis/request.js";

// 搜索表单
const clientCode = ref("");
const clientName = ref("");
const clientNick = ref("");
const clientEn = ref("");
const enableFlag = ref("");

// 对话框标题
const dialogTitle = ref("");
// 表格数据
const tableList = ref([
	{
		clientCode: "C001",
		clientName: "广州科技有限公司",
		clientNick: "广科",
		clientEn: "Guangzhou Tech Co., Ltd.",
		clientType: "科技",
		clientDes: "科技公司",
		address: "广州市天河区",
		website: "http://www.guangzhou-tech.com",
		email: "info@guangzhou-tech.com",
		tel: "020-12345678",
		clientLogo: "logo1.png",
		contact1: "张三",
		contact1Tel: "13812345678",
		contact1Email: "zhangsan@guangzhou-tech.com",
		contact2: "李四",
		contact2Tel: "13987654321",
		contact2Email: "lisi@guangzhou-tech.com",
		creditCode: "91440101MA5DXXXXXX",
		enableFlag: "yes",
		remark: "备注信息1",
		isEnabled: true,
	},
	{
		clientCode: "C002",
		clientName: "深圳创新科技有限公司",
		clientNick: "深创",
		clientEn: "Shenzhen Innovation Tech Co., Ltd.",
		clientType: "创新",
		clientDes: "创新公司",
		address: "深圳市南山区",
		website: "http://www.shenzhen-innovation.com",
		email: "info@shenzhen-innovation.com",
		tel: "0755-87654321",
		clientLogo: "logo2.png",
		contact1: "王五",
		contact1Tel: "13987654321",
		contact1Email: "wangwu@shenzhen-innovation.com",
		contact2: "赵六",
		contact2Tel: "13876543210",
		contact2Email: "zhaoliu@shenzhen-innovation.com",
		creditCode: "91440300MA5DXXXXXX",
		enableFlag: "no",
		remark: "备注信息2",
		isEnabled: false,
	},
	{
		clientCode: "C003",
		clientName: "北京网络科技有限公司",
		clientNick: "北网",
		clientEn: "Beijing Network Tech Co., Ltd.",
		clientType: "网络",
		clientDes: "网络公司",
		address: "北京市海淀区",
		website: "http://www.beijing-network.com",
		email: "info@beijing-network.com",
		tel: "010-12344321",
		clientLogo: "logo3.png",
		contact1: "孙七",
		contact1Tel: "13712344321",
		contact1Email: "sunqi@beijing-network.com",
		contact2: "周八",
		contact2Tel: "13612344321",
		contact2Email: "zhouba@beijing-network.com",
		creditCode: "91110108MA5DXXXXXX",
		enableFlag: "yes",
		remark: "备注信息3",
		isEnabled: true,
	},
	{
		clientCode: "C004",
		clientName: "上海信息技术有限公司",
		clientNick: "上信",
		clientEn: "Shanghai Info Tech Co., Ltd.",
		clientType: "信息",
		clientDes: "信息公司",
		address: "上海市浦东新区",
		website: "http://www.shanghai-info.com",
		email: "info@shanghai-info.com",
		tel: "021-87654321",
		clientLogo: "logo4.png",
		contact1: "吴九",
		contact1Tel: "13687654321",
		contact1Email: "wuj@shanghai-info.com",
		contact2: "郑十",
		contact2Tel: "13587654321",
		contact2Email: "zhengshi@shanghai-info.com",
		creditCode: "91310115MA5DXXXXXX",
		enableFlag: "yes",
		remark: "备注信息4",
		isEnabled: true,
	},
	{
		clientCode: "C005",
		clientName: "杭州电子商务有限公司",
		clientNick: "杭电",
		clientEn: "Hangzhou E-commerce Co., Ltd.",
		clientType: "电子",
		clientDes: "电子商务公司",
		address: "杭州市西湖区",
		website: "http://www.hangzhou-ecommerce.com",
		email: "info@hangzhou-ecommerce.com",
		tel: "0571-12345678",
		clientLogo: "logo5.png",
		contact1: "冯十一",
		contact1Tel: "13512345678",
		contact1Email: "fengshiyi@hangzhou-ecommerce.com",
		contact2: "陈十二",
		contact2Tel: "13412345678",
		contact2Email: "chenshiyi@hangzhou-ecommerce.com",
		creditCode: "91330108MA5DXXXXXX",
		enableFlag: "no",
		remark: "备注信息5",
		isEnabled: false,
	},
	{
		clientCode: "C006",
		clientName: "南京软件开发有限公司",
		clientNick: "南软",
		clientEn: "Nanjing Software Dev Co., Ltd.",
		clientType: "软件",
		clientDes: "软件开发公司",
		address: "南京市鼓楼区",
		website: "http://www.nanjing-software.com",
		email: "info@nanjing-software.com",
		tel: "025-87654321",
		clientLogo: "logo6.png",
		contact1: "褚十三",
		contact1Tel: "13487654321",
		contact1Email: "chushisan@nanjing-software.com",
		contact2: "卫十四",
		contact2Tel: "13387654321",
		contact2Email: "weishisi@nanjing-software.com",
		creditCode: "91320108MA5DXXXXXX",
		enableFlag: "yes",
		remark: "备注信息6",
		isEnabled: true,
	},
]);

// 对话框
const dialogVisible = ref(false);
const formRef = ref();
const formModel = ref({
	clientCode: "",
	clientName: "",
	clientNick: "",
	clientEn: "",
	clientType: "",
	clientDes: "",
	address: "",
	website: "",
	email: "",
	tel: "",
	clientLogo: "",
	contact1: "",
	contact1Tel: "",
	contact1Email: "",
	contact2: "",
	contact2Tel: "",
	contact2Email: "",
	creditCode: "",
	enableFlag: true,
	remark: "",
});

const rules = {
	clientCode: [{ required: true, message: "请输入客户编码", trigger: "blur" }],
	clientName: [{ required: true, message: "请输入客户名称", trigger: "blur" }],
	clientNick: [{ required: true, message: "请输入客户简称", trigger: "blur" }],
	clientEn: [{ required: true, message: "请输入客户英文名称", trigger: "blur" }],
	clientType: [{ required: true, message: "请选择客户类型", trigger: "change" }],
	tel: [{ required: true, message: "请输入客户电话", trigger: "blur" }],
	contact1Tel: [{ required: true, message: "请输入联系人1电话", trigger: "blur" }],
	enableFlag: [{ required: true, message: "请选择是否启用", trigger: "change" }],
	remark: [{ required: true, message: "请输入备注", trigger: "blur" }],
};

// 提交表单
const submitForm = () => {
	formRef.value
		.validate()
		.then(() => {
			console.log("提交成功", formModel.value);
			dialogVisible.value = false;
			// 添加提交表单后的其他逻辑
		})
		.catch(() => {
			console.log("提交失败");
		});
	// 后端提交
	// request.post('/api/submit', formModel.value)
	//   .then(response => {
	//     console.log("提交成功", response.data);
	//     dialogVisible.value = false;
	//     getPageList(); // 重新获取分页数据
	//   })
	//   .catch(error => {
	//     console.log("提交失败", error);
	//   });
};

// 取消提交
const cancelForm = () => {
	dialogVisible.value = false;
};

// 分页
const loading = ref(false);
const parms = ref({
	pagenum: 1,
	pagesize: 5,
});
// 总条数
const total = ref(tableList.value.length);
// 原始表格数据的副本，用于分页和过滤操作
const originalTableList = ref([...tableList.value]);
// 获取当前页的数据列表
const getPageList = () => {
	loading.value = true; // 显示加载动画
	const start = (parms.value.pagenum - 1) * parms.value.pagesize;
	const end = start + parms.value.pagesize;
	tableList.value = originalTableList.value.slice(start, end);
	loading.value = false; // 隐藏加载动画
	// 后端获取数据分页
	// request.get('/api/page', { params: { pagenum: parms.value.pagenum, pagesize: parms.value.pagesize } })
	//   .then(response => {
	//     tableList.value = response.data.list;
	//     total.value = response.data.total;
	//   })
	//   .finally(() => {
	//     loading.value = false;
	//   });
};

// 当页面大小改变时触发，重新获取分页数据
const onSizeChange = (size) => {
	parms.value.pagenum = 1; // 重置当前页码为1
	parms.value.pagesize = size; // 更新页面大小
	getPageList(); // 重新获取分页数据
};
// 当页码改变时触发，重新获取分页数据
const onCurrentChange = (page) => {
	parms.value.pagenum = page; // 更新当前页码
	getPageList(); // 重新获取分页数据
};

// 表格上面新增操作
const handleAdd = () => {
	formModel.value = {
		clientCode: "",
		clientName: "",
		clientNick: "",
		clientEn: "",
		clientType: "",
		clientDes: "",
		address: "",
		website: "",
		email: "",
		tel: "",
		clientLogo: "",
		contact1: "",
		contact1Tel: "",
		contact1Email: "",
		contact2: "",
		contact2Tel: "",
		contact2Email: "",
		creditCode: "",
		enableFlag: true,
		remark: "",
	};
	dialogTitle.value = "新增客户";
	dialogVisible.value = true;
};
// 表格修改操作
const handleUpdate = (row) => {
	formModel.value = { ...row };
	dialogTitle.value = "修改客户";
	dialogVisible.value = true;
};

// 模拟删除操作
const handleDelete = (row) => {
	ElMessageBox.confirm("你确认要删除该客户么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	})
		.then(() => {
			// 模拟删除操作
			const index = tableList.value.findIndex((item) => item.clientCode === row.clientCode);
			if (index !== -1) {
				tableList.value.splice(index, 1);
				originalTableList.value = [...tableList.value];
				ElMessage.success("删除成功");
				getPageList(); // 重新请求列表数据
			}
		})
		.catch(() => {
			ElMessage.info("已取消删除");
		});
	// 后端删除
	// request.delete(`/api/delete/${row.clientCode}`)
	//   .then(response => {
	//     console.log("删除成功", response.data);
	//     ElMessage.success("删除成功");
	//     getPageList(); // 重新获取分页数据
	//   })
	//   .catch(error => {
	//     console.log("删除失败", error);
	//     ElMessage.error("删除失败");
	//   });
};

// 导出数据逻辑
const handleExport = () => {
	console.log("导出数据");
};

// 模拟查询提交
const handleQuery = () => {
	new Promise((resolve) => {
		tableList.value = originalTableList.value.filter((item) => {
			return (
				(!clientCode.value || item.clientCode.includes(clientCode.value)) &&
				(!clientName.value || item.clientName.includes(clientName.value)) &&
				(!clientNick.value || item.clientNick.includes(clientNick.value)) &&
				(!clientEn.value || item.clientEn.includes(clientEn.value)) &&
				(enableFlag.value === "" || item.enableFlag === enableFlag.value)
			);
		});
		resolve();
	}).then(() => {
		getPageList();
	});
	// 后端查询
	// request.get('/api/query', { params: { clientCode: clientCode.value, clientName: clientName.value, clientNick: clientNick.value, clientEn: clientEn.value, enableFlag: enableFlag.value } })
	//   .then(response => {
	//     tableList.value = response.data;
	//     originalTableList.value = [...response.data];
	//     getPageList();
	//   })
	//   .finally(() => {
	//     loading.value = false;
	//   });
};

// 重置
const resetQuery = () => {
	clientCode.value = "";
	clientName.value = "";
	clientNick.value = "";
	clientEn.value = "";
	enableFlag.value = "";
	handleQuery();
};

const handleSelectionChange = (val) => {
	console.log("选中项变化", val);
};

// 隐藏搜索栏
const showSearchBar = ref(true);
const toggleSearchBar = () => {
	showSearchBar.value = !showSearchBar.value;
};

// 模拟刷新数据
const refreshData = () => {
	loading.value = true; // 显示加载动画
	new Promise((resolve) => {
		setTimeout(() => {
			tableList.value = [
				...tableList.value,
				{
					clientCode: "C007",
					clientName: "南京软件开发有限公司",
					clientNick: "南软",
					clientEn: "Nanjing Software Dev Co., Ltd.",
					clientType: "软件",
					clientDes: "软件开发公司",
					address: "南京市鼓楼区",
					website: "http://www.nanjing-software.com",
					email: "info@nanjing-software.com",
					tel: "025-87654321",
					clientLogo: "logo6.png",
					contact1: "褚十三",
					contact1Tel: "13487654321",
					contact1Email: "chushisan@nanjing-software.com",
					contact2: "卫十四",
					contact2Tel: "13387654321",
					contact2Email: "weishisi@nanjing-software.com",
					creditCode: "91320108MA5DXXXXXX",
					enableFlag: "yes",
					remark: "备注信息7",
					isEnabled: true,
				},
			];
			originalTableList.value = [...tableList.value];
			resolve();
		}, 500);
	})
		.then(() => {
			getPageList();
		})
		.finally(() => {
			loading.value = false; // 隐藏加载动画
		});
	// 后端刷新数据
	// request.get('/api/refresh')
	//   .then(response => {
	//     tableList.value = response.data;
	//     originalTableList.value = [...response.data];
	//     getPageList();
	//   })
	//   .finally(() => {
	//     loading.value = false;
	//   });
};
</script>

<template>
	<TableFrame title="客户管理">
		<template #extra>
			<el-button @click="handleExport"
				>导出数据<el-icon :size="22"><UploadFilled /></el-icon
			></el-button>
		</template>

		<!-- 搜索表单 -->
		<el-form v-if="showSearchBar" :inline="true" class="demo-form-inline">
			<el-row>
				<el-col :span="8">
					<el-form-item label="客户编码：">
						<el-input v-model="clientCode" placeholder="请输入客户编码" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="客户名称：">
						<el-input v-model="clientName" placeholder="请输入客户名称" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="客户简称：">
						<el-input v-model="clientNick" placeholder="请输入客户简称" clearable />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="客户英文名称：">
						<el-input v-model="clientEn" placeholder="请输入客户英文名称" clearable />
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
		<div class="action-buttons">
			<el-button type="primary" plain @click="handleAdd"
				><el-icon><Plus /></el-icon>新增</el-button
			>
			<el-button type="success" plain @click="handleUpdate(row)"
				><el-icon><EditPen /></el-icon>修改</el-button
			>
			<el-button type="danger" plain @click="handleDelete(row)"
				><el-icon><Delete /></el-icon>删除</el-button
			>
			<div class="search-icons">
				<el-tooltip content="隐藏搜索栏" placement="top">
					<el-button @click="toggleSearchBar" plain
						><el-icon><Search /></el-icon
					></el-button>
				</el-tooltip>
				<el-tooltip content="刷新" placement="top">
					<el-button @click="refreshData" plain
						><el-icon><Refresh /></el-icon
					></el-button>
				</el-tooltip>
			</div>
		</div>

		<!-- 数据表格 -->
		<el-table
			:data="tableList"
			style="width: 100%"
			v-loading="loading"
			@selection-change="handleSelectionChange"
			ref="multipleTable"
		>
			<el-table-column type="selection" width="55" />
			<el-table-column
				prop="clientCode"
				label="客户编码"
				width="120"
				align="center"
				sortable="custom"
			></el-table-column>
			<el-table-column prop="clientName" label="客户名称" width="175" align="center"></el-table-column>
			<el-table-column prop="clientNick" label="客户简称" width="125" align="center"></el-table-column>
			<el-table-column
				prop="clientType"
				label="客户类型"
				width="120"
				align="center"
				sortable="custom"
			></el-table-column>
			<el-table-column prop="tel" label="客户电话" width="150" align="center"></el-table-column>
			<el-table-column prop="contact1Tel" label="联系人电话" width="150" align="center"></el-table-column>
			<el-table-column prop="enableFlag" label="是否启用" width="84" align="center">
				<template #default="{ row }">
					<el-tag :class="row.enableFlag ? 'status-enabled' : 'status-disabled'" style="cursor: pointer">
						{{ row.enableFlag ? "是" : "否" }}
					</el-tag>
				</template>
			</el-table-column>
			<el-table-column label="操作" width="270" align="center">
				<template #default="{ row, $index }">
					<el-button @click="handleUpdate(row, $index)" circle type="primary">
						<el-icon :size="20"><Edit /></el-icon>
					</el-button>
					<el-button @click="handleDelete(row, $index)" type="danger" circle>
						<el-icon :size="20"><Delete /></el-icon>
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

		<!-- 添加或修改客户对话框 -->
		<el-dialog v-model="dialogVisible" :title="dialogTitle">
			<el-form ref="formRef" :model="formModel" :rules="rules" label-width="120px">
				<el-row>
					<el-col :span="8">
						<el-form-item label="客户编码" prop="clientCode">
							<el-input v-model="formModel.clientCode" placeholder="请输入客户编码" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户名称" prop="clientName">
							<el-input v-model="formModel.clientName" placeholder="请输入客户名称" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户简称" prop="clientNick">
							<el-input v-model="formModel.clientNick" placeholder="请输入客户简称" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="客户英文名称" prop="clientEn">
							<el-input v-model="formModel.clientEn" placeholder="请输入客户英文名称" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户类型" prop="clientType">
							<el-select v-model="formModel.clientType" placeholder="请选择客户类型">
								<el-option label="类型1" value="类型1"></el-option>
								<el-option label="类型2" value="类型2"></el-option>
							</el-select>
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户电话" prop="tel">
							<el-input v-model="formModel.tel" placeholder="请输入客户电话" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="联系人1电话" prop="contact1Tel">
							<el-input v-model="formModel.contact1Tel" placeholder="请输入联系人1电话" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="联系人1邮箱" prop="contact1Email">
							<el-input v-model="formModel.contact1Email" placeholder="请输入联系人1邮箱" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="联系人2电话" prop="contact2Tel">
							<el-input v-model="formModel.contact2Tel" placeholder="请输入联系人2电话" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="联系人2邮箱" prop="contact2Email">
							<el-input v-model="formModel.contact2Email" placeholder="请输入联系人2邮箱" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户LOGO" prop="clientLogo">
							<el-input v-model="formModel.clientLogo" placeholder="请输入客户LOGO" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户官网地址" prop="website">
							<el-input v-model="formModel.website" placeholder="请输入客户官网地址" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="客户邮箱地址" prop="email">
							<el-input v-model="formModel.email" placeholder="请输入客户邮箱地址" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="社会信用代码" prop="creditCode">
							<el-input v-model="formModel.creditCode" placeholder="请输入社会信用代码" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="是否有效" prop="enableFlag">
							<el-select v-model="formModel.enableFlag" placeholder="请选择是否有效">
								<el-option label="是" :value="true"></el-option>
								<el-option label="否" :value="false"></el-option>
							</el-select>
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="24">
						<el-form-item label="客户简介" prop="clientDes">
							<el-input v-model="formModel.clientDes" type="textarea" placeholder="请输入客户简介" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="24">
						<el-form-item label="客户地址" prop="address">
							<el-input v-model="formModel.address" type="textarea" placeholder="请输入客户地址" />
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
