<script setup>
import { ref } from "vue";

defineOptions({
	/** TODO: 重命名为标准表单弹框 */
	name: "StdFormDialog",
});

const dialogVisible = ref(false);
// 定义表单内容，现在有点bug,
// 1,判断不了是修改还是增加组件，两个的判断条件我这没有写好
const formRef = ref();

const formModel = ref({
	classify: "",
	product: "",
	sure: "",
	time: "",
});

// 提交
async function onSubmit() {
	await formRef.value.validate();
	// 中间要补充调用哪一个，根据接口的不同，如编辑和增加
	ElMessage.success("成功");
	dialogVisible.value = false;
}

function open(row) {
	console.log(row);
	dialogVisible.value = true;
	formModel.value = { ...row };
}
// 规则由接口文档来定，这里只供参考
const rules = {
	classify: [
		{ required: true, message: "分类名必须是 1-10 位的非空字符", trigger: "blur" },
		{
			pattern: /^\S{1,10}$/,
			message: "分类名必须是 1-10 位的非空字符",
			trigger: "blur",
		},
	],
	product: [
		{ required: true, message: "产品名必须是 1-10的非空字符", trigger: "blur" },
		{
			pattern: /^\S{1,10}$/,
			message: "产品名必须是 1-10的非空字符",
			trigger: "blur",
		},
	],
	time: [
		{ required: true, message: "请输入产品时间", trigger: "blur" },
		{
			pattern: /^\d{1,4}.\d{1,2}.\d{1,2}$/,
			message: "时间必须是 xxxx.xx.xx的非空字符",
			trigger: "blur",
		},
	],
};
defineExpose({
	open, // 对外暴露的方法
});
</script>

<template>
	<el-dialog v-model="dialogVisible" :title="formModel.sure !== undefined ? '添加分类' : '编辑分类'" width="500">
		<!-- :before-close="handleClose"//这个属性加上去要二次取消才可以 -->
		<el-form ref="formRef" :model="formModel" :rules="rules" label-width="100px" style="padding-right: 30px">
			<el-form-item label="分类名称" prop="classify">
				<el-input v-model="formModel.classify" placeholder="请输入分类名称"></el-input>
			</el-form-item>
			<el-form-item label="产品名字" prop="product">
				<el-input v-model="formModel.product" placeholder="请输入产品名"></el-input>
			</el-form-item>
			<el-form-item label="状态" prop="sure">
				<el-input v-model="formModel.sure" placeholder="请输入状态"></el-input>
			</el-form-item>
			<el-form-item label="时间" prop="time">
				<el-input v-model="formModel.time" placeholder="请输入时间"></el-input>
			</el-form-item>
		</el-form>
		<template #footer>
			<div class="dialog-footer">
				<el-button @click="dialogVisible = false">取消按钮</el-button>
				<el-button type="primary" @click="onSubmit"> 确定按钮 </el-button>
			</div>
		</template>
	</el-dialog>
</template>

<style lang="scss" scoped></style>
