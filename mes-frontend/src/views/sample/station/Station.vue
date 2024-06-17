<template>
	<el-container>
		<el-header>
			<el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal">
				<el-menu-item index="1">首页</el-menu-item>
				<el-menu-item index="2">工作站管理</el-menu-item>
			</el-menu>
		</el-header>

		<el-main>
			<el-row :gutter="20" class="input-row">
				<el-col :span="5">
					<span class="input-label">工作站编码：</span>
					<el-input v-model="workstationCode" placeholder="请输入工作站编码" class="input-size" />
				</el-col>
				<el-col :span="5">
					<span class="input-label">工作站名称：</span>
					<el-input v-model="workstationName" placeholder="请输入工作站名称" class="input-size" />
				</el-col>
				<el-col :span="5">
					<span class="input-label">车间名称：</span>
					<el-select v-model="selectedWorkshop" placeholder="请选择车间" class="input-size">
						<el-option label="车间1" value="车间1"></el-option>
						<el-option label="车间2" value="车间2"></el-option>
					</el-select>
				</el-col>
				<el-col :span="5">
					<span class="input-label">所属工序：</span>
					<el-select v-model="selectedOrder" placeholder="请选择所属工序" class="input-size">
						<el-option label="工序1" value="工序1"></el-option>
						<el-option label="工序2" value="工序2"></el-option>
					</el-select>
				</el-col>
				<el-col :span="4" class="button-container">
					<el-button type="primary" @click="search">查询</el-button>
					<el-button @click="reset">重置</el-button>
				</el-col>
			</el-row>

			<el-row :gutter="20" class="action-row">
				<el-col :span="6">
					<el-button type="primary" @click="handleHumanResource" class="action-button">人力资源</el-button>
				</el-col>
				<el-col :span="6">
					<el-button type="primary" @click="handleEquipment" class="action-button">设备资源</el-button>
				</el-col>
				<el-col :span="6">
					<el-button type="primary" @click="handleTools" class="action-button">工装夹具</el-button>
				</el-col>
			</el-row>

			<el-row :gutter="20" style="margin-top: 20px">
				<el-col :span="24">
					<el-button type="danger" @click="batchDelete">批量删除</el-button>
					<el-button type="success" @click="exportData">导出</el-button>
					<el-button type="primary" @click="addNew">新增</el-button>
				</el-col>
			</el-row>

			<el-row :gutter="20" style="margin-top: 20px">
				<el-col :span="24">
					<el-table
						:data="tableData"
						@selection-change="handleRowSelectionChange"
						:default-sort="{ prop: 'code', order: 'ascending' }"
						style="width: 100%"
					>
						<el-table-column type="selection" width="40" />
						<el-table-column prop="code" label="工作站编号" width="180" />
						<el-table-column prop="name" label="工作站名称" width="180" />
						<el-table-column prop="location" label="工作站地点" width="180" />
						<el-table-column prop="workshop" label="所在车间名称" width="180" />
						<el-table-column prop="order" label="所属工序" width="180" />
						<el-table-column prop="enabled" label="是否启用" width="100" />
						<el-table-column prop="note" label="备注" />
						<el-table-column label="操作" width="180">
							<template v-slot="scope">
								<el-button type="text" size="small" @click="handleEdit(scope.row)">修改</el-button>
								<el-button type="text" size="small" @click="handleDelete(scope.row)">删除</el-button>
							</template>
						</el-table-column>
					</el-table>
				</el-col>
			</el-row>

			<el-dialog title="编辑工作站信息" v-model="editDialogVisible">
				<el-form label-width="80px">
					<el-form-item label="工作站编号">
						<el-input v-model="editingRow.code" />
					</el-form-item>
					<el-form-item label="工作站名称">
						<el-input v-model="editingRow.name" />
					</el-form-item>
					<el-form-item label="工作站地点">
						<el-input v-model="editingRow.location" />
					</el-form-item>
					<el-form-item label="所在车间名称">
						<el-input v-model="editingRow.workshop" />
					</el-form-item>
					<el-form-item label="所属工序">
						<el-input v-model="editingRow.order" />
					</el-form-item>
					<el-form-item label="是否启用">
						<el-switch v-model="editingRow.enabled" />
					</el-form-item>
					<el-form-item label="备注">
						<el-input v-model="editingRow.note" type="textarea" />
					</el-form-item>
				</el-form>
				<div slot="footer" class="dialog-footer">
					<el-button @click="cancelEdit">取消</el-button>
					<el-button type="primary" @click="saveEdit">保存</el-button>
				</div>
			</el-dialog>

			<el-pagination
				:current-page="currentPage"
				:page-sizes="[6, 12, 24, 48]"
				:page-size="pageSize"
				layout="total, sizes, prev, pager, next, jumper"
				:total="tableData.length"
				@size-change="handleSizeChange"
				@current-change="handleCurrentChange"
			></el-pagination>
		</el-main>
	</el-container>
</template>

<script>
export default {
	name: "Station",
	data() {
		return {
			activeIndex: "1",
			workstationCode: "",
			workstationName: "",
			selectedWorkshop: "",
			selectedOrder: "",
			pageSize: 6,
			currentPage: 1,

			tableData: [
				{
					code: "WS0707",
					name: "组装1号站",
					location: "--",
					workshop: "生产车间",
					order: "涂胶",
					enabled: "是",
					note: "--",
				},
				{
					code: "WS0720",
					name: "151541515",
					location: "4545",
					workshop: "生产车间",
					order: "涂胶",
					enabled: "是",
					note: "--",
				},
				{
					code: "WS0734",
					name: "111",
					location: "111",
					workshop: "方大二",
					order: "开料",
					enabled: "是",
					note: "1-111",
				},
				{ code: "WS0802", name: "包娟", location: "莆", workshop: "一车间", order: "安装", enabled: "是", note: "--" },
				{
					code: "WS0831",
					name: "AGV接驳",
					location: "--",
					workshop: "二车间",
					order: "AGV与舱段2、3接驳",
					enabled: "是",
					note: "--",
				},
				{
					code: "WS0835",
					name: "宣家机架中心",
					location: "--",
					workshop: "二车间",
					order: "工序1",
					enabled: "是",
					note: "--",
				},
			],
			selectedRows: [],
			editingRow: null, // 用于存储当前编辑的行数据
			editDialogVisible: false, // 控制编辑对话框的显示状态
		};
	},
	computed: {
		paginatedData() {
			const start = (this.currentPage - 1) * this.pageSize;
			const end = this.currentPage * this.pageSize;
			return this.tableData.slice(start, end);
		},
	},
	methods: {
		search() {
			const filters = {
				workstationCode: this.workstationCode.trim(), // 去除输入内容两端的空白字符
				workstationName: this.workstationName.trim(), // 去除输入内容两端的空白字符
				selectedWorkshop: this.selectedWorkshop,
				selectedOrder: this.selectedOrder,
			};
			// 如果两个输入框都为空，则恢复显示所有数据
			//if (!filters.workstationCode && !filters.workstationName) {
			//this.reset();
			//return;
			//	}
			// 对表格数据进行过滤
			const filteredData = this.tableData.filter((item) => {
				// 根据工作站编码进行过滤
				if (filters.workstationCode && !item.code.includes(filters.workstationCode)) {
					return false;
				}
				// 根据工作站名称进行过滤
				if (filters.workstationName && !item.name.includes(filters.workstationName)) {
					return false;
				}
				// 根据车间名称进行过滤
				if (filters.selectedWorkshop && item.workshop !== filters.selectedWorkshop) {
					return false;
				}
				// 根据所属工序进行过滤
				if (filters.selectedOrder && item.order !== filters.selectedOrder) {
					return false;
				}

				return true; // 如果都符合过滤条件，则返回 true
			});

			// 更新表格数据为过滤后的数据
			this.tableData = filteredData;
		},
		reset() {
			this.workstationCode = "";
			this.workstationName = "";
			this.selectedWorkshop = "";
			this.selectedOrder = "";
			console.log("已重置所有输入");
		},
		resetTableData() {
			// 恢复表格数据为原始数据
			this.tableData = [
				{
					code: "WS0707",
					name: "组装1号站",
					location: "--",
					workshop: "生产车间",
					order: "涂胶",
					enabled: "是",
					note: "--",
				},
				{
					code: "WS0720",
					name: "151541515",
					location: "4545",
					workshop: "生产车间",
					order: "涂胶",
					enabled: "是",
					note: "--",
				},
				{
					code: "WS0734",
					name: "111",
					location: "111",
					workshop: "方大二",
					order: "开料",
					enabled: "是",
					note: "1-111",
				},
				{ code: "WS0802", name: "包娟", location: "莆", workshop: "一车间", order: "安装", enabled: "是", note: "--" },
				{
					code: "WS0831",
					name: "AGV接驳",
					location: "--",
					workshop: "二车间",
					order: "AGV与舱段2、3接驳",
					enabled: "是",
					note: "--",
				},
				{
					code: "WS0835",
					name: "宣家机架中心",
					location: "--",
					workshop: "二车间",
					order: "工序1",
					enabled: "是",
					note: "--",
				},
			];
		},
		handleHumanResource() {
			console.log("处理人力资源");
		},
		handleEquipment() {
			console.log("处理设备资源");
		},
		handleTools() {
			console.log("处理工装夹具");
		},
		handleEdit(row) {
			this.editingRow = { ...row };
			// 打开修改对话框
			this.editDialogVisible = true;
			// 这里可以编写打开修改对话框的逻辑
		},
		saveEdit() {
			// 根据编辑对话框中的数据更新表格中对应行的数据
			const index = this.tableData.findIndex((item) => item.code === this.editingRow.code);
			if (index !== -1) {
				this.tableData.splice(index, 1, this.editingRow);
			} else {
				this.tableData.push({ ...this.editingRow });
			}
			// 关闭对话框
			this.editDialogVisible = false;
		},
		cancelEdit() {
			// 关闭对话框
			this.editDialogVisible = false;
		},
		handleDelete(row) {
			console.log("删除", row);
			// 在这里实现单行删除的逻辑
			const index = this.tableData.indexOf(row);
			this.tableData.splice(index, 1);
		},
		handleSizeChange(val) {
			this.pageSize = val;
			this.currentPage = 1;
		},
		handleCurrentChange(val) {
			this.currentPage = val;
		},

		batchDelete() {
			if (this.selectedRows.length === 0) {
				this.$message.warning("请先选择要删除的行");
				return;
			}

			// 执行批量删除逻辑
			this.selectedRows.forEach((row) => {
				const index = this.tableData.indexOf(row);
				if (index !== -1) {
					this.tableData.splice(index, 1);
				}
			});

			this.selectedRows = []; // 清空选中行
		},

		exportData() {
			console.log("导出");
			// 在这里实现导出数据的逻辑
		},
		addNew() {
			// 打开编辑对话框
			this.editingRow = {
				code: "", // 根据需求设置默认值
				name: "", // 根据需求设置默认值
				location: "", // 根据需求设置默认值
				workshop: "", // 根据需求设置默认值
				order: "", // 根据需求设置默认值
				enabled: true, // 根据需求设置默认值
				note: "", // 根据需求设置默认值
			};
			this.editDialogVisible = true;
		},

		handleRowSelectionChange(rows) {
			this.selectedRows = rows;
		},
	},
};
</script>

<style scoped>
.el-header {
	background-color: #b3c0d1;
	color: #333;
	line-height: 60px;
}

.action-row {
	margin-top: 20px;
}

.input-label {
	font-weight: bold;
}

.input-row .el-input {
	width: calc(35% - 10px);
}

.action-row .el-button,
.input-row .el-select {
	width: calc(25% - 10px);
}

.input-size {
	width: 100%;
}

.action-row .el-button {
	margin-right: 10px;
}
</style>
