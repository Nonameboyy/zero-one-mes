<script setup lang="ts">
import { ref } from "vue";
import { TableFrame } from "components/std-table";
import request from "@/apis/request.js";

// 搜索表单
const issueCode = ref("");
const issueName = ref("");
const warehouseName = ref("");
const issueDate = ref(null);
const status = ref("");
//对话框标题
const dialogTitle = ref("");
// 表格数据
const tableList = ref([
	{
		issueCode: "I001",
		issueName: "领料单1",
		workorderCode: "WO001",
		clientCode: "C001",
		clientName: "客户1",
		issueDate: "2023-10-01",
		status: "PREPARE",
	},
	{
		issueCode: "I002",
		issueName: "领料单2",
		workorderCode: "WO002",
		clientCode: "C002",
		clientName: "客户2",
		issueDate: "2023-10-02",
		status: "CONFIRMED",
	},
	{
		issueCode: "I003",
		issueName: "领料单3",
		workorderCode: "WO003",
		clientCode: "C003",
		clientName: "客户3",
		issueDate: "2023-10-03",
		status: "PREPARE",
	},
	{
		issueCode: "I004",
		issueName: "领料单4",
		workorderCode: "WO004",
		clientCode: "C004",
		clientName: "客户4",
		issueDate: "2023-10-04",
		status: "CONFIRMED",
	},
	{
		issueCode: "I005",
		issueName: "领料单5",
		workorderCode: "WO005",
		clientCode: "C005",
		clientName: "客户5",
		issueDate: "2023-10-05",
		status: "PREPARE",
	},
	{
		issueCode: "I006",
		issueName: "领料单6",
		workorderCode: "WO006",
		clientCode: "C006",
		clientName: "客户6",
		issueDate: "2023-10-06",
		status: "CONFIRMED",
	},
]);

// 对话框
const dialogVisible = ref(false);
const formRef = ref();
const formModel = ref({
	issueCode: "",
	issueName: "",
	issueDate: "",
	workorderCode: "",
	status: "",
	clientCode: "",
	clientName: "",
	warehouseInfo: [],
	remark: "",
});

const rules = {
	issueCode: [{ required: true, message: "请输入领料单编号", trigger: "blur" }],
	issueName: [{ required: true, message: "请输入领料单名称", trigger: "blur" }],
	issueDate: [{ required: true, message: "请选择领料日期", trigger: "change" }],
	workorderCode: [{ required: true, message: "请输入生产工单", trigger: "blur" }],
	status: [{ required: true, message: "请选择单据状态", trigger: "change" }],
	clientCode: [{ required: true, message: "请输入客户编号", trigger: "blur" }],
	clientName: [{ required: true, message: "请输入客户名称", trigger: "blur" }],
	warehouseInfo: [{ required: true, message: "请选择领料仓库", trigger: "change" }],
	remark: [{ required: true, message: "请输入备注", trigger: "blur" }],
};

// 提交表单,用 Promise 链式操作
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
};
//后端   const submitForm = () => {
// formRef.value.validate()
//      .then(() => {
//        // 替换为后端请求
//        request.post('/api/submit', formModel.value)
//          .then(response => {
//            console.log("提交成功", response.data);
//            dialogVisible.value = false;
//            // 添加提交表单后的其他逻辑
//            getPageList(); // 重新获取分页数据
//          })
//          .catch(error => {
//            console.log("提交失败", error);
//          });
//      })
//      .catch(() => {
//        console.log("提交失败");
//      });
//  };

//取消提交

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
// 原始表格数据的副本，用于分页和过滤操作,模拟后端获取数据
const originalTableList = ref([...tableList.value]);
// 模拟计算，获取当前页的数据列表
const getPageList = () => {
	loading.value = true; // 显示加载动画
	const start = (parms.value.pagenum - 1) * parms.value.pagesize;
	const end = start + parms.value.pagesize;
	tableList.value = originalTableList.value.slice(start, end);
	loading.value = false; // 隐藏加载动画
};
//后端   const getPageList = () => {
// loading.value = true;
//    // 替换为后端请求
//    request.get('/api/page', { params: { pagenum: parms.value.pagenum, pagesize: parms.value.pagesize } })
//      .then(response => {
//        tableList.value = response.data.list;
//        total.value = response.data.total;
//      })
//      .finally(() => {
//        loading.value = false;
//      });
//  };

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
// 后端获取数据分页
// const getPageList = async () => {
//   loading.value = true; // 显示加载动画
//   try {
//     // 调用后端接口获取分页数据
//     const response = await request.get('/api/issues', {
//       params: {
//         page: parms.value.pagenum,
//         size: parms.value.pagesize,
//       },
//     });
//     tableList.value = response.data.items; // 当前页的数据
//     total.value = response.data.total; // 总条数
//   } catch (error) {
//     console.error("获取分页数据失败", error);
//   } finally {
//     loading.value = false; // 隐藏加载动画
//   }
// };

// 表格上面新增操作
const handleAdd = () => {
	formModel.value = {
		issueCode: "",
		issueName: "",
		issueDate: "",
		workorderCode: "",
		status: "",
		clientCode: "",
		clientName: "",
		warehouseInfo: [],
		remark: "",
	};
	dialogTitle.value = "新增生产领料单";
	dialogVisible.value = true;
};
//表格修改操作
const handleUpdate = (row) => {
	formModel.value = { ...row };
	dialogTitle.value = "修改生产领料单";
	dialogVisible.value = true;
};

//模拟删除操作
const handleDelete = (row) => {
	ElMessageBox.confirm("你确认要删除该领料单么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	})
		.then(() => {
			// 模拟删除操作
			const index = tableList.value.findIndex((item) => item.issueCode === row.issueCode);
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
};
//   const handleDelete = (row) => {
// 	ElMessageBox.confirm("你确认要删除该领料单么", "温馨提示", {
//      type: "warning",
//      confirmButtonText: "确认",
//      cancelButtonText: "取消",
//    })
//      .then(() => {
//        // 替换为后端请求
//        request.delete(`/api/delete/${row.issueCode}`)
//          .then(response => {
//            console.log("删除成功", response.data);
//            ElMessage.success("删除成功");
//            getPageList(); // 重新获取分页数据
//          })
//          .catch(error => {
//            console.log("删除失败", error);
//            ElMessage.error("删除失败");
//          });
//      })
//      .catch(() => {
//        ElMessage.info("已取消删除");
//      });
//  };

//导出数据逻辑
const handleExport = () => {
	console.log("导出数据");
};

//模拟查询提交
const handleQuery = () => {
	new Promise((resolve) => {
		tableList.value = originalTableList.value.filter((item) => {
			return (
				(!issueCode.value || item.issueCode.includes(issueCode.value)) &&
				(!issueName.value || item.issueName.includes(issueName.value)) &&
				(!warehouseName.value || item.warehouseName.includes(warehouseName.value)) &&
				(!issueDate.value || item.issueDate === issueDate.value) &&
				(!status.value || item.status === status.value)
			);
		});
		resolve();
	}).then(() => {
		getPageList();
	});
};
//后端   const handleQuery = () => {
//    loading.value = true;
//    // 替换为后端请求
//    request.get('/api/query', { params: { issueCode: issueCode.value, issueName: issueName.value, warehouseName: warehouseName.value, issueDate: issueDate.value, status: status.value } })
//      .then(response => {
//        tableList.value = response.data;
//        originalTableList.value = [...response.data];
//        getPageList();
//      })
//      .finally(() => {
//        loading.value = false;
//      });
//  };

//重置
const resetQuery = () => {
	issueCode.value = "";
	issueName.value = "";
	warehouseName.value = "";
	issueDate.value = null;
	status.value = "";
	handleQuery();
};

const handleSelectionChange = (val) => {
	console.log("选中项变化", val);
};

//执行领出
const handleExecute = (row) => {
	ElMessageBox.confirm("你确认要执行领出么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	})
		.then(() => {
			ElMessage.success("执行领出成功");
			console.log("执行领出", row);
			// 执行领出的逻辑
		})
		.catch(() => {
			console.log("取消执行领出");
		});
};

// 自定义排序逻辑
function handleSortChange({ prop, order }) {
	tableList.value.sort((a, b) => {
		if (order === "ascending") {
			return a[prop] > b[prop] ? 1 : -1;
		} else if (order === "descending") {
			return a[prop] < b[prop] ? 1 : -1;
		} else {
			return 0;
		}
	});
}
// 隐藏搜索栏
const showSearchBar = ref(true);
function toggleSearchBar() {
	showSearchBar.value = !showSearchBar.value;
}
// 模拟刷新数据，使用 async/await，并在 finally 中处理加载动画的隐藏
const refreshData = () => {
	loading.value = true; // 显示加载动画
	new Promise((resolve) => {
		setTimeout(() => {
			tableList.value = [
				...tableList.value,
				{
					issueCode: "I007",
					issueName: "领料单7",
					workorderCode: "WO007",
					clientCode: "C007",
					clientName: "客户7",
					issueDate: "2023-10-07",
					status: "PREPARE",
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
};
//后端   const refreshData = () => {
// loading.value = true;
//    // 替换为后端请求
//    request.get('/api/refresh')
//      .then(response => {
//        tableList.value = response.data;
//        originalTableList.value = [...response.data];
//        getPageList();
//      })
//      .finally(() => {
//        loading.value = false;
//      });
//  };
</script>

<template>
	<TableFrame title="生产领料管理">
		<template #extra>
			<el-button @click="handleExport"
				>导出数据<el-icon :size="22"><UploadFilled /></el-icon
			></el-button>
		</template>

		<!-- 搜索表单 -->
		<el-form v-if="showSearchBar" :inline="true" class="demo-form-inline">
			<el-row>
				<el-col :span="8">
					<el-form-item label="领料单编号：">
						<el-input v-model="issueCode" placeholder="请输入领料单编号" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="领料单名称：">
						<el-input v-model="issueName" placeholder="请输入领料单名称" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="仓库名称：">
						<el-input v-model="warehouseName" placeholder="请输入仓库名称" clearable />
					</el-form-item>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="8">
					<el-form-item label="领料日期：">
						<el-date-picker v-model="issueDate" type="date" placeholder="请选择领料日期" clearable />
					</el-form-item>
				</el-col>
				<el-col :span="8">
					<el-form-item label="单据状态：">
						<el-select v-model="status" placeholder="请选择单据状态" clearable>
							<el-option label="已完成" value="PREPARE"></el-option>
							<el-option label="草稿" value="CONFIRMED"></el-option>
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
			<el-button type="primary" plain @click="handleAdd">
				<el-icon><Plus /></el-icon>新增
			</el-button>
			<el-button type="success" plain @click="handleUpdate(row)">
				<el-icon><EditPen /></el-icon>修改
			</el-button>
			<el-button type="danger" plain @click="handleDelete(row)">
				<el-icon><Delete /></el-icon>删除
			</el-button>
			<div class="search-icons">
				<el-tooltip content="隐藏搜索栏" placement="top">
					<el-button @click="toggleSearchBar" plain>
						<el-icon><Search /></el-icon>
					</el-button>
				</el-tooltip>
				<el-tooltip content="刷新" placement="top">
					<el-button @click="refreshData" plain>
						<el-icon><Refresh /></el-icon>
					</el-button>
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
			@sort-change="handleSortChange"
		>
			<el-table-column type="selection" width="55" />
			<!-- <el-table-column type="index" label="序号" width="55"></el-table-column> -->
			<el-table-column
				prop="issueCode"
				label="领料单编号"
				width="120"
				align="center"
				sortable="custom"
			></el-table-column>
			<el-table-column prop="issueName" label="领料单名称" width="175" align="center"></el-table-column>
			<el-table-column prop="workorderCode" label="生产工单" width="125" align="center"></el-table-column>
			<el-table-column
				prop="clientCode"
				label="客户编号"
				width="120"
				align="center"
				sortable="custom"
			></el-table-column>
			<el-table-column
				prop="clientName"
				label="客户名称"
				width="150"
				align="center"
				sortable="custom"
			></el-table-column>
			<el-table-column prop="issueDate" label="领料日期" width="120" align="center" sortable="custom"></el-table-column>
			<el-table-column prop="status" label="单据状态" width="80" align="center">
				<template #default="{ row }">
					<el-tag :class="row.status === 'PREPARE' ? 'status-enabled' : 'status-disabled'" style="cursor: pointer">
						{{ row.status === "PREPARE" ? "已完成" : "草稿" }}
					</el-tag>
				</template>
			</el-table-column>
			<el-table-column label="操作" width="270" align="center">
				<template #default="{ row, $index }">
					<el-button @click="handleUpdate(row, $index)" circle type="primary">
						<el-icon :size="20"> <Edit /></el-icon>
					</el-button>
					<el-button @click="handleDelete(row, $index)" type="danger" circle>
						<el-icon :size="20"> <Delete /></el-icon>
					</el-button>
					<el-button @click="handleExecute(row, $index)" type="text">
						<el-icon :size="10"><VideoPlay /></el-icon>执行领出
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

		<!-- 添加或修改生产领料单对话框 -->
		<el-dialog v-model="dialogVisible" :title="dialogTitle">
			<el-form ref="formRef" :model="formModel" :rules="rules" label-width="120px">
				<el-row>
					<el-col :span="8">
						<el-form-item label="领料单编号" prop="issueCode">
							<el-input v-model="formModel.issueCode" placeholder="请输入领料单编号" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="领料单名称" prop="issueName">
							<el-input v-model="formModel.issueName" placeholder="请输入领料单名称" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="领料日期" prop="issueDate">
							<el-date-picker v-model="formModel.issueDate" type="date" placeholder="请选择领料日期" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="生产工单" prop="workorderCode">
							<el-input v-model="formModel.workorderCode" placeholder="请输入生产工单" />
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="单据状态" prop="status">
							<el-select v-model="formModel.status" placeholder="请选择单据状态">
								<el-option label="已完成" value="PREPARE"></el-option>
								<el-option label="草稿" value="CONFIRMED"></el-option>
							</el-select>
						</el-form-item>
					</el-col>
					<el-col :span="8">
						<el-form-item label="客户编号" prop="clientCode">
							<el-input v-model="formModel.clientCode" placeholder="请输入客户编号" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="8">
						<el-form-item label="客户名称" prop="clientName">
							<el-input v-model="formModel.clientName" placeholder="请输入客户名称" />
						</el-form-item>
					</el-col>
					<el-col :span="16">
						<el-form-item label="领料仓库" prop="warehouseInfo">
							<el-cascader v-model="formModel.warehouseInfo" :options="[]" placeholder="请选择领料仓库" />
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
