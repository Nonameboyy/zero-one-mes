<!-- eslint-disable antfu/top-level-function -->
<template>
	<el-row :gutter="20">
		<!-- 栏1 -->
		<el-col :span="8">
			<div class="grid-content ep-bg-purple">
				<!-- 用户信息栏 -->
				<el-card style="max-width: 480px">
					<template #header>
						<div class="card-header">
							<span style="font-size: large">个人信息</span>
						</div>
					</template>
					<!-- 用户信息展示 -->
					<el-row justify="center">
						<div class="demo-type">
							<el-avatar :size="100" fit="cover" @error="false" :src="url">
								<img src="https://cube.elemecdn.com/e/fd/0fc7d20532fdaf769a25683617711png.png" />
							</el-avatar>
						</div>
					</el-row>
					<el-divider />
					<el-row justify="space-between">
						<span>用户名称</span>
						<span>{{ infoform.nickName }}</span>
					</el-row>
					<el-divider />
					<el-row justify="space-between">
						<span>手机号码</span>
						<span>{{ infoform.phoneNum }}</span>
					</el-row>
					<el-divider />
					<el-row justify="space-between">
						<span>用户邮箱</span>
						<span>{{ infoform.email }}</span>
					</el-row>
					<el-divider />
					<span>所属部门</span>
					<div>****</div>
					<span>所属角色</span>
					<div>****</div>
					<el-row justify="space-between">
						<span>创建日期</span>
						<span>2023-11-20 21:19:01</span>
					</el-row>
				</el-card>
			</div>
		</el-col>
		<el-col :span="16">
			<div class="grid-content ep-bg-purple">
				<el-card>
					<template #header>
						<div class="card-header">
							<span style="font-size: large">基本信息</span>
						</div>
					</template>
					<!-- 基本资料/修改密码 -->
					<el-tabs v-model="activeName" class="demo-tabs" @tab-click="handleClick">
						<el-tab-pane label="基本资料" name="first">
							<!-- 基本资料表单 -->
							<el-form ref="infoRulesRef" :model="infoform" :rules="inforules" label-width="80px" status-icon>
								<el-form-item label="用户名称" prop="nickName">
									<el-input v-model="infoform.nickName"></el-input>
								</el-form-item>
								<!-- 手机验证 -->
								<el-form-item label="手机号码" prop="phoneNum">
									<el-input v-model="infoform.phoneNum" placeholder="123-1234-1234" maxlength="11">
										<template #append>
											<el-button type="primary" @click="getphoneCode">获取验证码</el-button>
										</template>
									</el-input>
								</el-form-item>
								<el-form-item label="验证码" prop="phoneCode">
									<el-input v-model="infoform.phoneCode"></el-input>
								</el-form-item>
								<!-- 邮箱验证 -->
								<el-form-item label="邮箱" prop="email">
									<el-input v-model="infoform.email" placeholder="****@exmaple.com">
										<template #append>
											<el-button type="primary" @click="getemailCode">获取验证码</el-button>
										</template>
									</el-input>
								</el-form-item>
								<el-form-item label="验证码" prop="emailCode">
									<el-input v-model="infoform.emailCode"></el-input>
								</el-form-item>

								<el-form-item label="性别" prop="gender">
									<el-radio-group v-model="infoform.gender">
										<el-radio value="男">男</el-radio>
										<el-radio value="女">女</el-radio>
									</el-radio-group>
								</el-form-item>
								<el-form-item>
									<el-button type="primary" @click="onInfoSubmit">保存</el-button>
									<el-button type="danger">关闭</el-button>
								</el-form-item>
							</el-form>
						</el-tab-pane>

						<el-tab-pane label="修改密码" name="second">
							<!-- 修改密码表单 -->
							<el-form ref="passRulesRef" :rules="passRules" :model="passwd" label-width="80px" status-icon>
								<el-form-item label="旧密码" prop="old">
									<el-input v-model="passwd.old" show-password></el-input>
								</el-form-item>
								<el-form-item label="新密码" prop="new">
									<el-input v-model="passwd.new" show-password></el-input>
								</el-form-item>
								<el-form-item label="确认密码" prop="confirm">
									<el-input v-model="passwd.confirm" show-password></el-input>
								</el-form-item>
								<el-form-item>
									<el-button type="primary" @click="onPassSubmit">保存</el-button>
									<el-button type="danger">关闭</el-button>
								</el-form-item>
							</el-form>
						</el-tab-pane>
					</el-tabs>
				</el-card>
			</div>
		</el-col>
	</el-row>
</template>

<script setup>
import { reactive, ref } from "vue";
import Request from "@/apis/request.js";

//tabs配置
const activeName = ref("first");
function handleClick(tab, event) {
	console.log(tab, event);
}

//基本资料 表单
const infoform = ref({
	nickName: "usertester",
	phoneNum: "13312341234",
	phoneCode: "",
	email: "user@example.com",
	emailCode: "",
	gender: "男",
});
//修改密码 表单
const passwd = ref({
	old: "12345",
	new: "",
	confirm: "",
});

// 手机号码 自定义验证规则
function phoneCheck(rule, value, callback) {
	const phone_regex = /^1[3-9]\d{9}$/;
	if (value !== "") {
		if (!phone_regex.test(value)) {
			callback(new Error("手机号码不正确！"));
		} else {
			callback();
		}
	}
}
// 密码 自定义验证规则(待解决)
function passCheck(rule, value, callback) {
	const pass_regex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[\s\S]{5,16}$/;
	if (value !== "") {
		if (!pass_regex.test(value)) {
			callback(new Error("5-16个字符(包含大小写字母数字)"));
		} else {
			callback();
		}
	}
}

//基本资料表单 验证规则
const inforules = reactive({
	nickName: [
		{ required: true, message: "请输入用户名", trigger: "change" },
		{ min: 1, max: 20, message: "长度 1 至 20", trigger: "change" },
	],
	phoneNum: [
		{ required: true, message: "请输入手机号", trigger: "change" },
		{ validator: phoneCheck, trigger: "change" },
	],
	email: [
		{ required: true, message: "请输入邮箱", trigger: "change" },
		{ type: "email", message: "邮箱不正确", trigger: "change" },
	],
	gender: [{ required: true, message: "请选择你的性别", trigger: "change" }],
});
//密码表单 验证规则(待解决)
const passRules = reactive({
	old: [
		{ required: true, message: "请输入原有密码", trigger: "change" },
		{ validator: passCheck, trigger: "change" },
	],
	new: [{ validdator: passCheck, trigger: "change" }],
	confirm: [{ validdator: passCheck, trigger: "change" }],
});

const infoRulesRef = ref("");
const passRulesRef = ref("");

// 基本资料表单 校验完成发送
async function onInfoSubmit(formEl) {
	if (!formEl) return;
	infoRulesRef.value.validate((valid, fields) => {
		if (valid) {
			console.log("Info submit!", fields);
		} else {
			console.log("error submit!", fields);
		}
	});
}
// 修改密码表单 校验完成发送
async function onPassSubmit(formEl) {
	if (!formEl) return;
	passRulesRef.value.validate((valid, fields) => {
		if (valid) {
			console.log("Pass submit!", fields);
		} else {
			console.log("error submit!", fields);
		}
	});
}

//获取 手机验证码
function getphoneCode() {
	// Request.request(
	// 	Request.POST,
	// 	"/mycenter/get-phoneCode",
	// 	{ phone: infoform.phoneNum }
	// ).then((res) => {
	// 	console.log(res);
	ElMessage.success("验证码发送成功");
	// }).catch((res) => {
	// 	console.log(res)
	// 	ElMessage.error("发送失败")
	// })
}

//获取 邮箱验证码
function getemailCode() {
	console.log("邮箱验证成功！");
}
// 图片上传
const url = ref("");
</script>

<style lang="scss" scoped>
/* layout样式 */
.el-row {
	margin-bottom: 20px;

	:last-child {
		margin-bottom: 0;
	}
}

.el-col {
	border-radius: 4px;
}

.grid-content {
	border-radius: 4px;
	min-height: 36px;
}

/* 头像样式 */
.demo-type {
	display: flex;

	> div {
		flex: 1;
		text-align: center;

		:not(:last-child) {
			border-right: 1px solid var(--el-border-color);
		}
	}
}
</style>
