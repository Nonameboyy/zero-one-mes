<template>
	<div class="app-container">
		<!-- Search Form -->
		<el-form :model="queryParams" ref="queryForm" size="small" inline>
			<el-form-item label="部门名称">
				<el-input v-model="queryParams.deptName" placeholder="请输入部门名称" clearable />
			</el-form-item>
			<el-form-item label="状态">
				<el-select v-model="queryParams.status" placeholder="部门状态" clearable>
					<el-option label="激活" value="active" />
					<el-option label="禁用" value="disabled" />
				</el-select>
			</el-form-item>
			<el-form-item>
				<el-button type="primary" size="small" @click="handleQuery">搜索</el-button>
				<el-button size="small" @click="resetQuery">重置</el-button>
			</el-form-item>
		</el-form>

		<!-- Action Buttons -->
		<el-row :gutter="10" class="mb8">
			<el-col :span="1.5">
				<el-button type="primary" size="small" @click="handleAdd">新增</el-button>
			</el-col>
			<el-col :span="1.5">
				<el-button type="info" size="small" @click="toggleExpandAll">展开/折叠</el-button>
			</el-col>
		</el-row>

		<!-- Department Table -->
		<el-table
			v-if="refreshTable"
			v-loading="loading"
			:data="deptList"
			row-key="deptId"
			:default-expand-all="isExpandAll"
			:tree-props="{ children: 'children', hasChildren: 'hasChildren' }"
		>
			<el-table-column prop="deptName" label="部门名称" :show-overflow-tooltip="true" width="260" />
			<el-table-column prop="orderNum" label="排序" width="200" />
			<el-table-column prop="status" label="状态" width="100">
				<template #default="{ row }">
					<el-tag :type="row.status === 'active' ? 'success' : 'danger'">
						{{ row.status === "active" ? "激活" : "禁用" }}
					</el-tag>
				</template>
			</el-table-column>
			<el-table-column label="创建时间" align="center" prop="createTime" width="200">
				<template #default="{ row }">
					<span>{{ formatDate(row.createTime) }}</span>
				</template>
			</el-table-column>
			<el-table-column label="操作" align="center" class-name="small-padding fixed-width">
				<template #default="{ row }">
					<el-button type="text" size="small" icon="edit" @click="handleUpdate(row)">修改</el-button>
					<el-button type="text" size="small" icon="plus" @click="handleAdd()">新增</el-button>
					<el-button type="text" size="small" icon="delete" @click="handleDelete(row)">删除</el-button>
				</template>
			</el-table-column>
		</el-table>

		<!-- Add/Edit Department Dialog -->
		<el-dialog :title="title" v-model="open" width="600px">
			<el-form ref="formRef" :model="form" :rules="rules" label-width="80px">
				<el-row>
					<el-col :span="24">
						<el-form-item label="上级部门" prop="parentId">
							<el-input v-model="form.parentId" placeholder="上级部门" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="12">
						<el-form-item label="部门名称" prop="deptName">
							<el-input v-model="form.deptName" placeholder="请输入部门名称" />
						</el-form-item>
					</el-col>
					<el-col :span="12">
						<el-form-item label="显示排序" prop="orderNum">
							<el-input-number v-model="form.orderNum" controls-position="right" :min="0" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="12">
						<el-form-item label="负责人" prop="leader">
							<el-input v-model="form.leader" placeholder="请输入负责人" maxlength="20" />
						</el-form-item>
					</el-col>
					<el-col :span="12">
						<el-form-item label="联系电话" prop="phone">
							<el-input v-model="form.phone" placeholder="请输入联系电话" maxlength="11" />
						</el-form-item>
					</el-col>
				</el-row>
				<el-row>
					<el-col :span="12">
						<el-form-item label="邮箱" prop="email">
							<el-input v-model="form.email" placeholder="请输入邮箱" maxlength="50" />
						</el-form-item>
					</el-col>
					<el-col :span="12">
						<el-form-item label="部门状态" prop="status">
							<el-radio-group v-model="form.status">
								<el-radio :value="'active'">激活</el-radio>
								<el-radio :value="'disabled'">禁用</el-radio>
							</el-radio-group>
						</el-form-item>
					</el-col>
				</el-row>
			</el-form>
			<div slot="footer" class="dialog-footer">
				<el-button type="primary" @click="submitForm">确 定</el-button>
				<el-button @click="cancel">取 消</el-button>
			</div>
		</el-dialog>
	</div>
</template>

<script setup lang="ts">
import { ref, reactive, onMounted } from "vue";
import axios from "axios";
import { ElMessage, ElMessageBox } from "element-plus";

// Reactive state
// 定义响应式状态变量
const loading = ref(false); // 控制加载状态的显示
const showSearch = ref(true); // 控制搜索表单的显示
const deptList = ref([]); // 存储部门列表数据
const deptOptions = ref([]); // 存储部门选项数据（用于下拉选择）
const title = ref(""); // 对话框标题
const open = ref(false); // 控制对话框的打开状态
const isExpandAll = ref(true); // 控制表格是否全部展开
const refreshTable = ref(true); // 控制表格是否刷新
const queryParams = reactive({
	deptName: "",
	status: "",
});
const form = reactive({
	deptId: undefined,
	parentId: undefined,
	deptName: "",
	orderNum: 0,
	leader: "",
	phone: "",
	email: "",
	status: "active",
});
const rules = reactive({
	parentId: [{ required: true, message: "上级部门不能为空", trigger: "blur" }],
	deptName: [{ required: true, message: "部门名称不能为空", trigger: "blur" }],
	orderNum: [{ required: true, message: "显示排序不能为空", trigger: "blur" }],
	email: [
		{
			type: "email",
			message: "请输入正确的邮箱地址",
			trigger: ["blur", "change"],
		},
	],
	phone: [
		{
			pattern: /^1[3|4|5|6|7|8|9][0-9]\d{8}$/,
			message: "请输入正确的手机号码",
			trigger: "blur",
		},
	],
});

// Methods
const getList = async () => {
	loading.value = true;
	try {
		const response = await axios.get("/api/departments", { params: queryParams });
		deptList.value = response.data;
	} catch (error) {
		ElMessage.error("获取列表失败");
	} finally {
		loading.value = false;
	}
};

const normalizer = (node) => {
	if (node.children && !node.children.length) {
		delete node.children;
	}
	return {
		id: node.deptId,
		label: node.deptName,
		children: node.children,
	};
};

const cancel = () => {
	open.value = false;
	reset();
};

const reset = () => {
	form.deptId = undefined;
	form.parentId = undefined;
	form.deptName = "";
	form.orderNum = 0;
	form.leader = "";
	form.phone = "";
	form.email = "";
	form.status = "active";
};

const handleQuery = () => {
	getList();
};

const resetQuery = () => {
	queryParams.deptName = "";
	queryParams.status = "";
	getList();
};

const handleAdd = () => {
	reset();
	open.value = true;
	title.value = "添加部门";
};

const toggleExpandAll = () => {
	isExpandAll.value = !isExpandAll.value;
};

const handleUpdate = (row) => {
	Object.assign(form, row);
	open.value = true;
	title.value = "修改部门";
};

const submitForm = () => {
	console.log("提交表单:", form);
	open.value = false;
};

const handleDelete = (row) => {
	console.log(`删除部门: ${row.deptName}`);
};

const formatDate = (date) => {
	return new Date(date).toLocaleDateString();
};

onMounted(() => {
	getList();
});
</script>

<style scoped lang="scss">
.app-container {
	background-color: aliceblue;
	width: auto;
	height: 400px;
}
</style>
