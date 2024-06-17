<script setup>
import { onMounted, reactive, ref, watch } from "vue";
import { ElNotification, ElTree } from "element-plus";

// 假设的静态用户数据
const mockUserList = [
	{
		userId: 1,
		userName: "张三",
		nickName: "zhangsan",
		dept: { deptId: 1, deptName: "技术部" },
		phonenumber: "13000000000",
		status: "0",
		createTime: "2024-06-01 08:30:00",
	},
	{
		userId: 2,
		userName: "李四",
		nickName: "lisi",
		dept: { deptId: 2, deptName: "市场部" },
		phonenumber: "13100000000",
		status: "1",
		createTime: "2024-06-02 09:00:00",
	},
	// 更多用户数据...
];

// 假设的静态部门数据
const mockDeptOptions = [
	{
		id: 1,
		label: "技术部",
		children: [
			{ id: 3, label: "后端组" },
			{ id: 4, label: "前端组" },
		],
	},
	{
		id: 2,
		label: "市场部",
		children: [
			{ id: 5, label: "国内市场" },
			{ id: 6, label: "国际市场" },
		],
	},
	// 更多部门数据...
];

// 组件状态
const state = reactive({
	showFlag: false,
	loading: false,
	selectedId: null,
	selectedRow: null,
	single: true,
	multiple: true,
	showSearch: true,
	total: 0,
	userList: mockUserList,
	title: "",
	deptOptions: mockDeptOptions,
	open: false,
	deptName: "",
	dateRange: [],
	postOptions: [],
	roleOptions: [],
	form: {},
	defaultProps: {
		children: "children",
		label: "label",
	},
	queryParams: {
		pageNum: 1,
		pageSize: 10,
		userName: "",
		phonenumber: "",
		status: "",
		deptId: "",
	},
	columns: [
		{ key: 0, label: `用户编号`, visible: true },
		// 其他列定义
	],
	deptTreeData: mockDeptOptions,
});

// 监听部门名称的变化
watch(
	() => state.deptName,
	(newVal) => {
		// 这里可以添加逻辑来处理部门名称的变化
	},
);

// 挂载时的逻辑
onMounted(() => {
	getList(); // 这里可以添加初始化逻辑
});

// 方法定义
function getList() {
	// 替换为获取静态数据的逻辑
	state.userList = mockUserList;
	state.total = mockUserList.length;
}

function getTreeselect() {
	// 替换为获取静态数据的逻辑
	state.deptOptions = mockDeptOptions;
}

function filterNode(value, data) {
	if (!value) return true;
	return data.label.includes(value);
}

function handleNodeClick(data) {
	state.queryParams.deptId = data.id;
	getList();
}

function handleQuery() {
	state.queryParams.pageNum = 1;
	getList();
}

function resetQuery() {
	state.dateRange = [];
	// 重置查询表单的逻辑
	getList();
}

function handleCurrent(row) {
	if (row) {
		state.selectedRow = row;
	}
}

function handleRowDbClick(row) {
	if (row) {
		state.selectedRow = row;
		// 触发事件
		state.showFlag = false;
	}
}

function handleRowChange(row) {
	if (row) {
		state.selectedRow = row;
	}
}

function confirmSelect() {
	if (state.selectedId == null || state.selectedId === 0) {
		ElNotification({
			title: "提示",
			type: "warning",
			message: "请至少选择一条数据!",
		});
		return;
	}
	// 触发事件
	state.showFlag = false;
}
</script>

<template>
	<el-dialog v-if="showFlag" v-model:visible="showFlag" title="人员选择" :modal="false" width="80%" center>
		<el-row :gutter="20">
			<!-- 部门数据 -->
			<el-col :span="4" :xs="24">
				<div class="head-container">
					<el-input v-model="deptName" placeholder="请输入部门名称" clearable size="small"
						prefix-icon="el-icon-search" style="margin-bottom: 20px" />
				</div>
				<div class="head-container">
					<el-tree ref="tree" :data="state.deptTreeData" :props="state.defaultProps"
						:expand-on-click-node="false" :filter-node-method="filterNode" default-expand-all
						@node-click="handleNodeClick" />
				</div>
			</el-col>
			<!-- 用户数据 -->
			<el-col :span="20" :xs="24">
				<el-form v-show="showSearch" ref="queryForm" :model="queryParams" size="small" :inline="true"
					label-width="68px">
					<el-form-item label="用户名称" prop="userName">
						<el-input v-model="queryParams.userName" placeholder="请输入用户名称" clearable style="width: 240px"
							@keyup.enter.enter="handleQuery" />
					</el-form-item>
					<el-form-item label="手机号码" prop="phonenumber">
						<el-input v-model="queryParams.phonenumber" placeholder="请输入手机号码" clearable style="width: 240px"
							@keyup.enter.enter="handleQuery" />
					</el-form-item>
					<el-form-item>
						<el-button type="primary" icon="el-icon-search" size="mini" @click="handleQuery">搜索</el-button>
						<el-button icon="el-icon-refresh" size="mini" @click="resetQuery">重置</el-button>
					</el-form-item>
				</el-form>
				<el-table v-loading="loading" :data="userList" @current-change="handleCurrent"
					@row-dblclick="handleRowDbClick">
					<el-table-column width="55" align="center">
						<template #default="scope">
							<el-radio v-model="selectedId" :label="scope.row.userId"
								@change="handleRowChange(scope.row)">{{
								""
								}}</el-radio>
						</template>
					</el-table-column>
					<el-table-column v-if="columns[1].visible" key="userName" label="用户名称" align="center"
						prop="userName" :show-overflow-tooltip="true" />
					<el-table-column v-if="columns[2].visible" key="nickName" label="用户昵称" align="center"
						prop="nickName" :show-overflow-tooltip="true" />
					<el-table-column v-if="columns[3].visible" key="deptName" label="部门" align="center"
						prop="dept.deptName" :show-overflow-tooltip="true" />
					<el-table-column v-if="columns[4].visible" key="phonenumber" label="手机号码" align="center"
						prop="phonenumber" width="120" />
					<el-table-column v-if="columns[5].visible" key="status" label="状态" align="center">
						<template #default="scope">
							<el-switch v-model="scope.row.status" active-value="0" inactive-value="1"
								@change="handleStatusChange(scope.row)"></el-switch>
						</template>
					</el-table-column>
					<el-table-column v-if="columns[6].visible" label="创建时间" align="center" prop="createTime"
						width="160">
						<template #default="scope">
							<span>{{ parseTime(scope.row.createTime) }}</span>
						</template>
					</el-table-column>
				</el-table>

				<pagination v-show="total > 0" v-model:page="queryParams.pageNum" v-model:limit="queryParams.pageSize"
					:total="total" @pagination="getList" />
			</el-col>
		</el-row>
		<template #footer>
			<div class="dialog-footer">
				<el-button type="primary" @click="confirmSelect">确 定</el-button>
				<el-button @click="showFlag = false">取 消</el-button>
			</div>
		</template>
	</el-dialog>
</template>
