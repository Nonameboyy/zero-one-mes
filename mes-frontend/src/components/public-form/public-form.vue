<template>
	<div class="form-public">
		<!-- element plus 组件 -->
		<el-form :model="formData" label-width="auto" :rules="formRules" ref="formRef">
			<!-- 循环配置项得到 -->
			<el-form-item v-for="obj of formSet" :key="obj.propName" :label="obj.text" :prop="obj.propName">
				<!-- 输入框展示 -->
				<el-input
					v-if="obj.showType === 'input'"
					v-model="formData[obj.propName]"
					:placeholder="obj.placeholder"
					v-bind="obj.addSetProp || {}"
					v-on="obj.methodsSetProp || {}"
					:style="obj.styleSet"
				/>

				<!-- 下拉框展示 -->
				<el-select
					v-if="obj.showType === 'select'"
					v-model="formData[obj.propName]"
					:placeholder="obj.placeholder"
					v-bind="obj.addSetProp || {}"
					v-on="obj.methodsSetProp || {}"
					:style="obj.styleSet"
				>
					<el-option
						v-for="optionObj of obj.optionListSet.optionsList"
						:key="optionObj[obj.optionListSet.valueProp]"
						:value="optionObj[obj.optionListSet.valueProp]"
						:label="optionObj[obj.optionListSet.labelProp]"
						:disabled="optionObj[obj.optionListSet.disabledProp]"
					/>
				</el-select>

				<!-- 日期选择器/日期时间选择器展示 -->
				<el-date-picker
					v-if="obj.showType === 'datePicker'"
					v-model="formData[obj.propName]"
					v-bind="obj.addSetProp || {}"
					v-on="obj.methodsSetProp || {}"
					:style="obj.styleSet"
				/>

				<!-- 多选框组展示 -->
				<el-checkbox-group
					v-if="obj.showType === 'checkboxGroup'"
					v-model="formData[obj.propName]"
					v-bind="obj.addSetProp || {}"
					v-on="obj.methodsSetProp || {}"
					:style="obj.styleSet"
				>
					<el-checkbox
						v-for="optionObj of obj.optionListSet.optionsList"
						:key="optionObj[obj.optionListSet.valueProp] || optionObj[obj.optionListSet.labelProp]"
						:label="optionObj[obj.optionListSet.labelProp]"
						:value="optionObj[obj.optionListSet.valueProp]"
						:disabled="optionObj[obj.optionListSet.disabledProp]"
					/>
				</el-checkbox-group>

				<!-- 单选框组展示 -->
				<el-radio-group
					v-if="obj.showType === 'radioGroup'"
					v-model="formData[obj.propName]"
					v-bind="obj.addSetProp || {}"
					v-on="obj.methodsSetProp || {}"
					:style="obj.styleSet"
				>
					<el-radio
						v-for="optionObj of obj.optionListSet.optionsList"
						:key="optionObj[obj.optionListSet.valueProp] || optionObj[obj.optionListSet.labelProp]"
						:value="optionObj[obj.optionListSet.valueProp]"
						:disabled="optionObj[obj.optionListSet.disabledProp]"
					>
						{{ optionObj[obj.optionListSet.labelProp] }}
					</el-radio>
				</el-radio-group>

				<!-- switch展示 -->
				<el-switch
					v-if="obj.showType === 'switch'"
					v-model="formData[obj.propName]"
					v-bind="obj.addSetProp || {}"
					v-on="obj.methodsSetProp || {}"
					:style="obj.styleSet"
				/>
			</el-form-item>
		</el-form>
	</div>
</template>

<script setup>
import { reactive, ref } from "vue";

let model = defineModel({});

// 获取父组件传来的参数
let props = defineProps({
	// 表单配置项
	formSet: {
		type: Object,
		default() {
			return {};
		},
	},
	// 表单数据存储对象
	formData: {
		type: Object,
		default() {
			return {};
		},
	},
	// 表单校验规则配置项
	formRules: {
		type: Object,
		default() {
			return {};
		},
	},
});
// 将父组件传来的参数解构到变量中 供本组件使用
let { formSet, formData } = props;
// 将数据存储对象的地址进行转存 并将转存后的地址直接用于本组件的各表单项双向绑定值处(不能直接使用父组件中传来的对象地址的原因是 有时直接使用并修改里面的属性值 es-lint会报错)
// 这样用户对表单的修改 就会直接同步到父组件内的数据存储对象中去 前端不需要再做额外的传值处理 nice
formData = reactive(formData); // 使用reactive包裹已经是代理对象的对象时 只会返回代理对象的原地址

// 获取表单实例
const formRef = ref(formData);

// 表单的校验方法 会在父组件中被调用
const checkForm = () => {
	return new Promise((resolve, reject) => {
		(async () => {
			if (!formRef.value) {
				reject(false);
				return;
			}
			// 调用element plus表单组件自带的校验方法
			await formRef.value.validate((valid) => {
				if (valid) {
					resolve(true);
				} else {
					reject(false);
				}
			});
		})();
	});
};

// 重置表单 会在父组件中被调用
const resetForm = () => {
	if (!formRef.value) {
		return;
	}
	formRef.value.resetFields();
};
</script>

<style lang="scss" scoped>
.form-public {
	width: 100%;

	// 将date组件的宽度调整为100% 和其他组件一样(不需要可以去掉)
	:deep(.el-date-editor.el-input) {
		width: 100%;
	}
}
</style>
