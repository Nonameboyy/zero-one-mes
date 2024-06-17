<template>
	<div class="app-container">
		<!-- 搜索表单 -->
		<el-form :model="queryParams" ref="queryForm" size="small" :inline="true" label-width="100px">
			<el-row>
				<el-col :span="8">
					<el-form-item label="检测项编码" prop="clientCode">
						<el-input v-model="queryParams.clientCode" placeholder="请输入检测项编码" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="检测项名称" prop="clientName">
						<el-input v-model="queryParams.clientName" placeholder="请输入检测项名称" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="检测项类型" prop="clientNick">
						<el-input v-model="queryParams.clientNick" placeholder="请输入检测项" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item>
						<el-button type="primary" @click="handleQuery">搜索</el-button>
						<el-button @click="resetQuery">重置</el-button>
					</el-form-item>
				</el-col>
			</el-row>
		</el-form>

		<!-- 操作按钮 -->
		<el-row :gutter="10">
			<el-col :span="8">
				<el-button type="primary" @click="handleAdd">新增</el-button>
				<el-button type="success" :disabled="single" @click="handleUpdate">修改</el-button>
				<el-button type="danger" :disabled="multiple" @click="handleDelete">删除</el-button>
				<el-button type="danger" :disabled="export" @click="handleExport">导出</el-button>
			</el-col>
		</el-row>

		<!-- 数据表格 -->
		<el-table v-loading="loading" :data="clientList" @selection-change="handleSelectionChange">
			<el-table-column type="selection" width="55"></el-table-column>
			<el-table-column prop="clientCode" label="检测项编码" align="center" class="sizeFont"></el-table-column>
			<el-table-column prop="clientName" label="检测项名称" align="center"></el-table-column>
			<el-table-column prop="clientType" label="检测项类型" align="center"></el-table-column>
			<el-table-column prop="clientNick" label="检测工具" align="center"></el-table-column>
			<el-table-column fixed="right" label="操作" align="center">
				<template v-slot="{ row }">
					<el-button size="mini" type="text" @click="handleUpdate(row)">修改</el-button>
					<el-button size="mini" type="text" @click="handleDelete(row)">删除</el-button>
				</template>
			</el-table-column>
		</el-table>

		<!-- 新增对话框 -->
		
	</div>
</template>

<script>
export default {
	data() {
		return {
			open: true,
			queryParams: {
				clientCode: "",
				clientName: "",
				clientNick: "",
				clientEn: "",
				enableFlag: "",
				pageNum: 1,
				pageSize: 10,
			},
			clientList: [
				{
					clientCode: "001",
					clientName: "客户A",
					clientNick: "A公司",
					clientType: "类型1",
					tel: "1234567890",
					contact1: "张三",
					contact1Tel: "1234567890",
					enableFlag: "Y",
				},
				{
					clientCode: "002",
					clientName: "客户B",
					clientNick: "B公司",
					clientType: "类型2",
					tel: "0987654321",
					contact1: "李四",
					contact1Tel: "0987654321",
					enableFlag: "N",
				},
				{
					clientCode: "003",
					clientName: "客户A",
					clientNick: "A公司",
					clientType: "类型1",
					tel: "1234567890",
					contact1: "张三",
					contact1Tel: "1234567890",
					enableFlag: "Y",
				},
				{
					clientCode: "004",
					clientName: "客户B",
					clientNick: "B公司",
					clientType: "类型2",
					tel: "0987654321",
					contact1: "李四",
					contact1Tel: "0987654321",
					enableFlag: "N",
				},
				{
					clientCode: "005",
					clientName: "客户A",
					clientNick: "A公司",
					clientType: "类型1",
					tel: "1234567890",
					contact1: "张三",
					contact1Tel: "1234567890",
					enableFlag: "Y",
				},
				{
					clientCode: "006",
					clientName: "客户B",
					clientNick: "B公司",
					clientType: "类型2",
					tel: "0987654321",
					contact1: "李四",
					contact1Tel: "0987654321",
					enableFlag: "N",
				},
				{
					clientCode: "007",
					clientName: "客户A",
					clientNick: "A公司",
					clientType: "类型1",
					tel: "1234567890",
					contact1: "张三",
					contact1Tel: "1234567890",
					enableFlag: "Y",
				},
				{
					clientCode: "008",
					clientName: "客户B",
					clientNick: "B公司",
					clientType: "类型2",
					tel: "0987654321",
					contact1: "李四",
					contact1Tel: "0987654321",
					enableFlag: "N",
				},
				{
					clientCode: "009",
					clientName: "客户A",
					clientNick: "A公司",
					clientType: "类型1",
					tel: "1234567890",
					contact1: "张三",
					contact1Tel: "1234567890",
					enableFlag: "Y",
				},
				{
					clientCode: "010",
					clientName: "客户B",
					clientNick: "B公司",
					clientType: "类型2",
					tel: "0987654321",
					contact1: "李四",
					contact1Tel: "0987654321",
					enableFlag: "N",
				},
			],
			total: 10,
			loading: false,
			single: true,
			multiple: true,
		};
	},
	methods: {
		handleQuery() {
			console.log("查询操作");
		},
		resetQuery() {
			this.queryParams = {
				clientCode: "",
				clientName: "",
				clientNick: "",
				clientEn: "",
				enableFlag: "",
				pageNum: 1,
				pageSize: 10,
			};
		},
		handleSelectionChange(selection) {
			this.single = selection.length !== 1;
			this.multiple = selection.length === 0;
		},
		reset() {
			// 假设一个表单数据对象叫做 form
			this.form = {
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
				enableFlag: "",
				remark: "",
			};
		},
		cancel() {
			this.open = false;
			this.reset();
		},
		// submitForm() {
		//   this.$refs['form'].validate(valid => {
		//     if (valid) {
		//       // 假设有一个提交表单的方法submitForm
		//       submitForm(this.form).then(response => {
		//         // 处理响应
		//         this.open = false;
		//         this.getList();
		//       });
		//     }
		//   });
		// },

		// 这是一个模拟的异步请求，实际应用中应该是一个 API 调用
		getClient(clientId) {
			return new Promise((resolve, reject) => {
				if (!clientId) {
					reject("Client ID is undefined");
					return;
				}
				const clientData = this.clientList.find((client) => client.clientCode === clientId);
				if (clientData) {
					resolve({ data: clientData });
				} else {
					reject("No data found for client with ID: " + clientId);
				}
			});
		},
		handleAdd() {
			//触发新增操作
			this.open = true;
			this.reset();

			// 重置表单到初始状态
			console.log("新增操作");
			this.title = "添加客户";
			this.optType = "add";
		},

		// this.form = Object.assign({}, row);

		// handleUpdate(row) {
		//   console.log('Triggering handleUpdate with row:', row);
		//   this.reset();
		//   const clientId = row.clientCode; // 属性来获取 clientId
		//   this.getClient(clientId).then(response => {
		//     console.log('Data received from getClient:', response.data);
		//     if (response.data) {
		//       this.form = response.data;
		//       this.open = true;
		//       this.title = "修改客户";
		//       this.optType = "edit";
		//     } else {
		//       console.error('No data found for client with ID:', clientId);
		//     }
		//   }).catch(error => {
		//     console.error('Failed to fetch client data:', error);
		//   });
		// },
		handleUpdate(row) {
			this.open = true;
			console.log("Triggering handleUpdate with row:", row);
			this.reset();
			const clientId = row.clientCode;
			this.getClient(clientId)
				.then((response) => {
					console.log("Data received from getClient:", response.data);
					this.form = response.data;
					this.open = true;
					this.title = "修改客户";
					this.optType = "edit";
				})
				.catch((error) => {
					console.error("Failed to fetch client data:", error);
				});
		},
		handleDelete(row) {
			console.log("删除操作", row);
			// 模拟删除操作
			this.clientList = this.clientList.filter((client) => client.clientCode !== row.clientCode);
		},
		getList() {
			console.log("页面加载和查询列表");
			// 模拟数据加载
			this.loading = false;
		},
	},
	created() {
		this.getList();
	},
};
</script>

<style>
.sizeFont {
	font-weight: bold;
}
</style>