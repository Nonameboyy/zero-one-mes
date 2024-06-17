<template>
	<el-container>
		<el-main>
			<!-- 搜索条件 -->
			<el-row :gutter="20" class="input-row">
				<el-col :span="4">
					<el-form-item label="工单编码">
						<el-input v-model="workOrderCode" placeholder="请输入工单编码" class="input-size" />
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="工单名称">
						<el-input v-model="workOrderName" placeholder="请输入工单名称" class="input-size" />
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="工单类型">
						<el-select v-model="workOrderType" placeholder="请选择工单类型" class="input-size">
							<el-option label="自产" value="自产"></el-option>
							<el-option label="外购" value="外购"></el-option>
						</el-select>
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="产品编号">
						<el-input v-model="productCode" placeholder="请输入产品编号" class="input-size" />
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="产品名称">
						<el-input v-model="productName" placeholder="请输入产品名称" class="input-size" />
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="来源单据">
						<el-input v-model="sourceOrder" placeholder="请输入来源单据" class="input-size" />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row :gutter="20" class="input-row">
				<el-col :span="4">
					<el-form-item label="客户编码">
						<el-input v-model="customerCode" placeholder="请输入客户编码" class="input-size" />
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="客户名称">
						<el-input v-model="customerName" placeholder="请输入客户名称" class="input-size" />
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="单据状态">
						<el-select v-model="orderStatus" placeholder="请选择单据状态" class="input-size">
							<el-option label="已确认" value="已确认"></el-option>
							<el-option label="未确认" value="未确认"></el-option>
						</el-select>
					</el-form-item>
				</el-col>
				<el-col :span="4">
					<el-form-item label="需求日期">
						<el-date-picker
							v-model="demandDate"
							placeholder="请选择需求日期"
							type="date"
							value-format="YYYY-MM-DD"
							class="input-size"
						/>
					</el-form-item>
				</el-col>
				<el-col :span="4" class="button-container">
					<el-button type="primary" @click="search">搜索</el-button>
					<el-button @click="reset">重置</el-button>
				</el-col>
			</el-row>

			<!-- 操作按钮 -->
			<el-row :gutter="20" style="margin-top: 20px">
				<el-col :span="24">
					<el-button type="primary" @click="addNew">新增</el-button>
					<el-button type="success" @click="exportData">导出</el-button>
					<el-button type="danger" @click="batchDelete">批量删除</el-button>
				</el-col>
			</el-row>

			<!-- 数据表格 -->
			<el-row :gutter="20" style="margin-top: 20px">
				<el-col :span="24">
					<el-table :data="paginatedData" @selection-change="handleRowSelectionChange" style="width: 100%">
						<el-table-column type="selection" width="40"></el-table-column>
						<el-table-column prop="workOrderCode" label="工单编码" width="180"></el-table-column>
						<el-table-column prop="workOrderName" label="工单名称" width="180"></el-table-column>
						<el-table-column prop="workOrderType" label="工单类型" width="100"></el-table-column>
						<el-table-column prop="sourceOrder" label="来源单据" width="100"></el-table-column>
						<el-table-column prop="productCode" label="产品编号" width="180"></el-table-column>
						<el-table-column prop="productName" label="产品名称" width="180"></el-table-column>
						<el-table-column prop="unit" label="单位" width="80"></el-table-column>
						<el-table-column prop="workOrderQty" label="工单数量" width="120"></el-table-column>
						<el-table-column prop="adjustedQty" label="调整数量" width="120"></el-table-column>
						<el-table-column prop="producedQty" label="已生产量" width="120"></el-table-column>
						<el-table-column prop="batchNo" label="批次号" width="150"></el-table-column>
						<el-table-column prop="customerCode" label="客户编码" width="150"></el-table-column>
						<el-table-column prop="customerName" label="客户名称" width="180"></el-table-column>
						<el-table-column prop="demandDate" label="需求日期" width="150"></el-table-column>
						<el-table-column prop="orderStatus" label="单据状态" width="100"></el-table-column>
						<el-table-column label="操作" width="180">
							<template v-slot="scope">
								<el-button type="text" size="small" @click="handleEdit(scope.row)">修改</el-button>
								<el-button type="text" size="small" @click="handleDelete(scope.row)">删除</el-button>
							</template>
						</el-table-column>
					</el-table>
				</el-col>
			</el-row>

			<!-- 分页 -->
			<el-pagination
				:current-page="currentPage"
				:page-sizes="[10, 20, 30, 40]"
				:page-size="pageSize"
				layout="total, sizes, prev, pager, next, jumper"
				:total="tableData.length"
				@size-change="handleSizeChange"
				@current-change="handleCurrentChange"
			></el-pagination>
		</el-main>

		<!-- 编辑弹窗 -->
		<el-dialog title="编辑工单" v-model="editDialogVisible">
			<el-form :model="editingRow">
				<el-form-item label="工单编码">
					<el-input v-model="editingRow.workOrderCode"></el-input>
				</el-form-item>
				<el-form-item label="工单名称">
					<el-input v-model="editingRow.workOrderName"></el-input>
				</el-form-item>
				<el-form-item label="工单类型">
					<el-select v-model="editingRow.workOrderType">
						<el-option label="自产" value="自产"></el-option>
						<el-option label="外购" value="外购"></el-option>
					</el-select>
				</el-form-item>
				<el-form-item label="来源单据">
					<el-input v-model="editingRow.sourceOrder"></el-input>
				</el-form-item>
				<el-form-item label="产品编号">
					<el-input v-model="editingRow.productCode"></el-input>
				</el-form-item>
				<el-form-item label="产品名称">
					<el-input v-model="editingRow.productName"></el-input>
				</el-form-item>
				<el-form-item label="单位">
					<el-input v-model="editingRow.unit"></el-input>
				</el-form-item>
				<el-form-item label="工单数量">
					<el-input v-model="editingRow.workOrderQty" type="number"></el-input>
				</el-form-item>
				<el-form-item label="调整数量">
					<el-input v-model="editingRow.adjustedQty" type="number"></el-input>
				</el-form-item>
				<el-form-item label="已生产量">
					<el-input v-model="editingRow.producedQty" type="number"></el-input>
				</el-form-item>
				<el-form-item label="批次号">
					<el-input v-model="editingRow.batchNo"></el-input>
				</el-form-item>
				<el-form-item label="客户编码">
					<el-input v-model="editingRow.customerCode"></el-input>
				</el-form-item>
				<el-form-item label="客户名称">
					<el-input v-model="editingRow.customerName"></el-input>
				</el-form-item>
				<el-form-item label="需求日期">
					<el-date-picker
						v-model="editingRow.demandDate"
						type="date"
						value-format="YYYY-MM-DD"
						class="input-size"
					></el-date-picker>
				</el-form-item>
				<el-form-item label="单据状态">
					<el-select v-model="editingRow.orderStatus">
						<el-option label="已确认" value="已确认"></el-option>
						<el-option label="未确认" value="未确认"></el-option>
					</el-select>
				</el-form-item>
			</el-form>
			<span slot="footer" class="dialog-footer">
				<el-button @click="cancelEdit">取消</el-button>
				<el-button type="primary" @click="saveEdit">保存</el-button>
			</span>
		</el-dialog>
	</el-container>
</template>

<script>
export default {
	data() {
		return {
			workOrderCode: "",
			workOrderName: "",
			workOrderType: "",
			demandDate: "",
			productCode: "",
			productName: "",
			sourceOrder: "",
			customerCode: "",
			customerName: "",
			orderStatus: "",
			pageSize: 10,
			currentPage: 1,
			tableData: [
				{
					workOrderCode: "MO202406020003",
					workOrderName: "test.洛斯达",
					workOrderType: "自产",
					sourceOrder: "库存备货",
					productCode: "IF2022082439",
					productName: "螺丝刀",
					unit: "PCS",
					workOrderQty: 400,
					adjustedQty: 0,
					producedQty: 0,
					batchNo: "BN20240602",
					customerCode: "C20240602",
					customerName: "客户A",
					demandDate: "2024-06-02",
					orderStatus: "已确认",
				},
				// 其他数据...
			],
			editDialogVisible: false,
			editingRow: null,
			selectedRows: [],
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
			// 搜索逻辑
			const filters = {
				workOrderCode: this.workOrderCode.trim(),
				workOrderName: this.workOrderName.trim(),
				workOrderType: this.workOrderType,
				productCode: this.productCode.trim(),
				productName: this.productName.trim(),
				sourceOrder: this.sourceOrder.trim(),
				customerCode: this.customerCode.trim(),
				customerName: this.customerName.trim(),
				orderStatus: this.orderStatus,
				demandDate: this.demandDate,
			};

			const filteredData = this.tableData.filter((item) => {
				return (
					(!filters.workOrderCode || item.workOrderCode.includes(filters.workOrderCode)) &&
					(!filters.workOrderName || item.workOrderName.includes(filters.workOrderName)) &&
					(!filters.workOrderType || item.workOrderType === filters.workOrderType) &&
					(!filters.productCode || item.productCode.includes(filters.productCode)) &&
					(!filters.productName || item.productName.includes(filters.productName)) &&
					(!filters.sourceOrder || item.sourceOrder.includes(filters.sourceOrder)) &&
					(!filters.customerCode || item.customerCode.includes(filters.customerCode)) &&
					(!filters.customerName || item.customerName.includes(filters.customerName)) &&
					(!filters.orderStatus || item.orderStatus === filters.orderStatus) &&
					(!filters.demandDate || item.demandDate === filters.demandDate)
				);
			});

			this.tableData = filteredData;
		},
		reset() {
			this.workOrderCode = "";
			this.workOrderName = "";
			this.workOrderType = "";
			this.demandDate = "";
			this.productCode = "";
			this.productName = "";
			this.sourceOrder = "";
			this.customerCode = "";
			this.customerName = "";
			this.orderStatus = "";
		},
		addNew() {
			this.editingRow = {
				workOrderCode: "",
				workOrderName: "",
				workOrderType: "",
				sourceOrder: "",
				productCode: "",
				productName: "",
				unit: "",
				workOrderQty: 0,
				adjustedQty: 0,
				producedQty: 0,
				batchNo: "",
				customerCode: "",
				customerName: "",
				demandDate: "",
				orderStatus: "",
			};
			this.editDialogVisible = true;
		},
		exportData() {
			// 导出逻辑
			console.log("导出");
		},
		batchDelete() {
			this.selectedRows.forEach((row) => {
				const index = this.tableData.indexOf(row);
				if (index !== -1) {
					this.tableData.splice(index, 1);
				}
			});
		},
		handleRowSelectionChange(selectedRows) {
			this.selectedRows = selectedRows;
		},
		handleSizeChange(size) {
			this.pageSize = size;
		},
		handleCurrentChange(page) {
			this.currentPage = page;
		},
		handleEdit(row) {
			this.editingRow = { ...row };
			this.editDialogVisible = true;
		},
		saveEdit() {
			const index = this.tableData.findIndex((item) => item.workOrderCode === this.editingRow.workOrderCode);
			if (index !== -1) {
				this.tableData.splice(index, 1, this.editingRow);
			} else {
				this.tableData.push({ ...this.editingRow });
			}
			this.editDialogVisible = false;
		},
		cancelEdit() {
			this.editDialogVisible = false;
		},
		handleDelete(row) {
			const index = this.tableData.indexOf(row);
			if (index !== -1) {
				this.tableData.splice(index, 1);
			}
		},
	},
};
</script>

<style scoped>
.input-row {
	margin-bottom: 20px;
}
.input-size {
	width: 100%;
}
.button-container {
	display: flex;
	justify-content: flex-start;
	align-items: center;
}
.dialog-footer {
	text-align: right;
}
</style>
