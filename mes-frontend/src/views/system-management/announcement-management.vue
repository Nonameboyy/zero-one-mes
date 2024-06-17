<script setup lang="ts">
import { onMounted, reactive, ref, toRefs } from "vue";
import { ElMessage } from "element-plus";
 import { addMessage, delMessage, getMessage, listMessage, updateMessage } from "@/apis/system/message";
import UserSingleSelect from "@/components/userSelect/single.vue";
import { error } from "console";
import { ElPagination } from 'element-plus';
// 响应式状态
const state = reactive({
	loading: true,
	ids: [],
	single: true,
	multiple: true,
	showSearch: true,
	total: 0,
	messageList: [],
	title: "",
	open: false,
	queryParams: {
		pageNum: 1,
		pageSize: 10,
		messageType: null,
		messageLevel: null,
		messageTitle: null,
		messageContent: null,
		senderId: null,
		senderName: null,
		senderNick: null,
		recipientId: null,
		recipientName: null,
		recipientNick: null,
		processTime: null,
		callBack: null,
		status: null,
		deletedFlag: null,
	},
	form: {
		messageId: null,
		messageType: null,
		messageLevel: null,
		messageTitle: null,
		messageContent: null,
		senderId: null,
		senderName: null,
		senderNick: null,
		recipientId: null,
		recipientName: null,
		recipientNick: null,
		processTime: null,
		callBack: null,
		status: "0",
		deletedFlag: null,
		remark: null,
		attr1: null,
		attr2: null,
		attr3: null,
		attr4: null,
		createBy: null,
		createTime: null,
		updateBy: null,
		updateTime: null,
	},
	rules: {
		messageType: [{ required: true, message: "消息类型不能为空", trigger: "change" }],
		messageLevel: [{ required: true, message: "消息级别不能为空", trigger: "blur" }],
		messageTitle: [{ required: true, message: "消息标题不能为空", trigger: "blur" }],
		messageContent: [{ required: true, message: "消息内容不能为空", trigger: "blur" }],
		recipientName: [{ required: true, message: "接收人不能为空", trigger: "blur" }],
	},
});

// 将响应式状态转换为refs
const { loading, ids, single, multiple, showSearch, total, messageList, title, open, queryParams, form, rules } =
	toRefs(state);

// 生命周期钩子
onMounted(() => {
	getList();
});

// 方法
function getList() {
	loading.value = true;
	listMessage(queryParams.value).then((response) => {
		messageList.value = response.rows;
		total.value = response.total;
		loading.value = false;
	}).catch(() => ElMessage('获取数据异常'));
}

function handleQuery() {
	queryParams.value.pageNum = 1;
	getList();
}

function resetQuery() {
	queryParams.value = {
		pageNum: 1,
		pageSize: 10,
		messageType: null,
		messageLevel: null,
		messageTitle: null,
		messageContent: null,
		senderId: null,
		senderName: null,
		senderNick: null,
		recipientId: null,
		recipientName: null,
		recipientNick: null,
		processTime: null,
		callBack: null,
		status: null,
		deletedFlag: null,
	};
	getList();
}

function handleSelectionChange(selection) {
	ids.value = selection.map((item) => item.messageId);
	single.value = selection.length !== 1;
	multiple.value = !selection.length;
}

function handleAdd() {
	form.value = {
		messageId: null,
		messageType: null,
		messageLevel: null,
		messageTitle: null,
		messageContent: null,
		senderId: null,
		senderName: null,
		senderNick: null,
		recipientId: null,
		recipientName: null,
		recipientNick: null,
		processTime: null,
		callBack: null,
		status: "0",
		deletedFlag: null,
		remark: null,
		attr1: null,
		attr2: null,
		attr3: null,
		attr4: null,
		createBy: null,
		createTime: null,
		updateBy: null,
		updateTime: null,
	};
	title.value = "添加消息";
	open.value = true;
}

function handleUpdate(row) {
	const messageId = row.messageId || ids.value;
	getMessage(messageId).then((response) => {
		form.value = response.data;
		title.value = "修改消息";
		open.value = true;
	});
}

function submitForm() {
	if (form.value.messageId) {
		updateMessage(form.value).then(() => {
			ElMessage.success("修改成功");
			open.value = false;
			getList();
		});
	} else {
		addMessage(form.value).then(() => {
			ElMessage.success("新增成功");
			open.value = false;
			getList();
		});
	}
}

function handleDelete(row) {
	const messageIds = row.messageId || ids.value;
	delMessage(messageIds).then(() => {
		ElMessage.success("删除成功");
		getList();
	});
}

// 字典数据
const messageTypes = ref([
	{ label: "通知", value: "1" },
	{ label: "警告", value: "2" },
	// ... 其他字典项 ...
]);

const messageLevels = ref([
	{ label: "一般", value: "1" },
	{ label: "重要", value: "2" },
	// ... 其他字典项 ...
]);

const messageStatuses = ref([
	{ label: "未处理", value: "0" },
	{ label: "处理中", value: "1" },
	{ label: "已处理", value: "2" },
	// ... 其他字典项 ...
]);

// 注册组件
const UserSingleSelectComponent = UserSingleSelect;

// 取消操作
function cancel() {
	open.value = false;
}

// 注册字典数据
const dicts = reactive({
	type: {
		sys_message_type: messageTypes,
		sys_message_level: messageLevels,
		sys_message_status: messageStatuses,
	},
});

// 用户选择组件的事件处理
function handleUserSelect() {
	// 此处应触发用户选择组件的显示逻辑
}

function onUserSelected(user) {
	if (user) {
		form.value.recipientId = user.userId;
		form.value.recipientName = user.userName;
		form.value.recipientNick = user.nickName;
	}
}

function formatMessageType(value) {
	const type = messageTypes.value.find((type) => type.value === value);
	return type ? type.label : value;
}

function formatMessageLevel(value) {
	const level = messageLevels.value.find((level) => level.value === value);
	return level ? level.label : value;
}

function formatStatus(value) {
	const status = messageStatuses.value.find((status) => status.value === value);
	return status ? status.label : value;
}
</script>

<template>
	<div class="app-container">
		<!-- 搜索表单 -->
		<el-form v-show="showSearch" ref="queryForm" :model="queryParams" size="small" :inline="true"
			label-width="100px">
			<!-- 消息类型选择 -->
			<el-form-item label="消息类型" prop="messageType">
				<el-select v-model="queryParams.messageType" placeholder="请选择消息类型" clearable>
					<el-option v-for="item in messageTypes" :key="item.value" :label="item.label" :value="item.value" />
				</el-select>
			</el-form-item>
			<!-- 消息级别选择 -->
			<el-form-item label="消息级别" prop="messageLevel">
				<el-select v-model="queryParams.messageLevel" placeholder="请选择消息级别" clearable>
					<el-option v-for="item in messageLevels" :key="item.value" :label="item.label"
						:value="item.value" />
				</el-select>
			</el-form-item>
			<!-- 发送人输入 -->
			<el-form-item label="发送人" prop="senderNick">
				<el-input v-model="queryParams.senderNick" placeholder="请输入发送人" clearable />
			</el-form-item>
			<!-- 接收人输入 -->
			<el-form-item label="接收人" prop="recipientNick">
				<el-input v-model="queryParams.recipientNick" placeholder="请输入接收人" clearable />
			</el-form-item>
			<!-- 状态选择 -->
			<el-form-item label="状态" prop="status">
				<el-select v-model="queryParams.status" placeholder="请选择状态" clearable>
					<el-option v-for="item in messageStatuses" :key="item.value" :label="item.label"
						:value="item.value" />
				</el-select>
			</el-form-item>
			<!-- 搜索和重置按钮 -->
			<el-form-item>
				<el-button type="primary" size="small" @click="handleQuery">搜索</el-button>
				<el-button size="small" @click="resetQuery">重置</el-button>
			</el-form-item>
		</el-form>

		<!-- 消息列表表格 -->
		<el-table v-loading="loading" :data="messageList" @selection-change="handleSelectionChange">
			<el-table-column type="selection" width="55"></el-table-column>
			<el-table-column prop="messageTitle" label="消息标题" sortable></el-table-column>
			<el-table-column prop="messageType" label="消息类型" :formatter="formatMessageType"></el-table-column>
			<el-table-column prop="messageLevel" label="消息级别" :formatter="formatMessageLevel"></el-table-column>
			<el-table-column prop="senderName" label="发送人"></el-table-column>
			<el-table-column prop="recipientName" label="接收人"></el-table-column>
			<el-table-column prop="status" label="状态" :formatter="formatStatus"></el-table-column>
			<el-table-column prop="createTime" label="创建时间" sortable></el-table-column>
			<el-table-column label="操作" fixed="right" width="120">
				<template #default="{ row }">
					<el-button type="text" size="small" @click="handleUpdate(row)">编辑</el-button>
					<el-button type="text" size="small" @click="handleDelete(row)">删除</el-button>
				</template>
			</el-table-column>
		</el-table>

		<!-- 分页组件 -->
		<el-pagination v-show="total > 0" v-model:page="queryParams.pageNum" v-model:limit="queryParams.pageSize"
			:total="total" @pagination="getList" />

		<!-- 添加或修改消息对话框 -->
		<el-dialog v-model:visible="open" :title="title" width="960px" append-to-body>
			<el-form ref="form" :model="form" :rules="rules" label-width="100px">
				<!-- 表单内容 -->
				<el-form-item label="消息标题" prop="messageTitle">
					<el-input v-model="form.messageTitle" placeholder="请输入消息标题"></el-input>
				</el-form-item>
				<el-form-item label="消息内容" prop="messageContent">
					<el-input type="textarea" v-model="form.messageContent" placeholder="请输入消息内容"></el-input>
				</el-form-item>
				<!-- 其他表单项 -->
			</el-form>
			<template #footer>
				<div class="dialog-footer">
					<el-button type="primary" @click="submitForm">确 定</el-button>
					<el-button @click="cancel">取 消</el-button>
				</div>
			</template>
		</el-dialog>
	</div>
</template>
