<template>
	<el-button plain @click="dialogVisible = true"> 新建 </el-button>
	<el-dialog v-model="dialogVisible" title="Tips" width="500" draggable>
		<public-form ref="formPublicRef" :formSet="formSet" :formData="formData" :formRules="formRules"> </public-form>
		<!-- 按钮区域 -->
		<template #footer>
			<div class="dialog-footer">
				<el-button @click="dialogVisible = false">取消</el-button>
				<el-button type="primary" @click="clickToSubmit = false"> 新建 </el-button>
			</div>
		</template>
	</el-dialog>
</template>
<script setup>
import { reactive, ref } from "vue";

// element plus相关
import { ElMessage } from "element-plus";

// 引入公共表单组件
import reform from "@/components/public-form/public-form.vue";

const dialogVisible = ref(false);
// 需要使用到的正则(仅为当前示例表单内进行自定义校验所需 实际开发过程中若不需要可去掉)
const regAll = {
	// 属性名就是需要被校验项在表单中对应存储的属性名
	code: /^\d{0,3}-/,
};

// 公共方法 使用正则对文本进行校验(仅为当前示例表单内进行自定义校验所需 实际开发过程中若不需要可去掉)
const checkTextByReg = (rule, value, callback) => {
	if (regAll[rule.field]?.test(value)) {
		callback();
	} else {
		// 若校验不通过
		callback(new Error(rule.message));
	}
};

// 公共方法 将选项列表数据放入到表单配置项的对应位置
const pushListToFormSet = (list, propName) => {
	for (let obj of formSet) {
		if (obj.propName === propName && obj.optionListSet) {
			obj.optionListSet.optionsList = list;
		}
	}
};

// 表单配置项及校验规则配置项在定义后一般不会整个改变 使用reactive声明即可
// 若业务需求特殊 存在表单或校验规则配置项可能整个改变并且需要页面响应式更新的情况 可以使用ref声明
// 按需设置表单配置项
const formSet = reactive([
	{
		text: "行动代号",
		showType: "input",
		propName: "code",
		placeholder: "请输入数字编号-代号",
		addSetProp: {
			// 输入的最大长度
			maxlength: 20,
		},
	},
	{
		text: "成员",
		showType: "input",
		propName: "leader",
		placeholder: "请输入成员",
	},
	{
		text: "初次登记时间",
		showType: "datePicker",
		propName: "createTime",
		// 其他关于日期选择器的配置项(根据开发需求 按照element plus中给出的配置项名称及对应属性值 添加即可 下述配置项都会被添加到当前表单控件的组件上)
		addSetProp: {
			// 关于属性名: element组件中给出的属性有的带有- 我们这里要写为小驼峰
			// 日期选择器
			type: "date",
			// 获取到的绑定值的格式
			valueFormat: "YYYY/MM/DD",
			// 判断面板内日期是否被禁用的函数
			disabledDate(date) {
				// 将今天及今天之前的时间禁用
				let dateNow = new Date();
				return date <= dateNow;
			},
		},
	},
	{
		text: "行动时间",
		showType: "datePicker",
		propName: "timeFrame",
		// 其他关于日期时间选择器的配置项(根据开发需求 按照element plus中给出的配置项规则 添加即可 下述配置项都会被添加到当前表单控件的组件上)
		addSetProp: {
			// 关于属性名: element组件中给出的属性有的带有- 我们这里要写为小驼峰
			// 日期时间选择器(范围选择)
			type: "datetimerange",
			// 占位文字
			startPlaceholder: "开始的开始",
			endPlaceholder: "最后的最后",
			// 获取到的绑定值的格式
			valueFormat: "YYYY/MM/DD HH:mm:ss",
		},
	},
	{
		text: "行动级别",
		showType: "select",
		propName: "level",
		optionListSet: {
			// 存储下拉框数据
			optionsList: [],
			// 配置选项的展示和存储取值(根据实际需要的属性名配置即可)
			labelProp: "levelText",
			valueProp: "level",
		},
		// 想要在当前组件上绑定的事件
		methodsSetProp: {
			// 选中值改变时触发
			change(value) {
				ElMessage({
					message: `对应的级别是：${value}`,
					grouping: true,
					type: "success",
				});
			},
		},
	},
	{
		text: "关联项目",
		showType: "select",
		propName: "project",
		optionListSet: {
			// 存储下拉框数据
			optionsList: [],
			// 配置选项的展示和存储取值(根据实际需要的属性名配置即可)
			labelProp: "projectText",
			valueProp: "project",
			// 配置单个选项禁用的判断取值对应的属性名
			disabledProp: "stop",
		},
	},
	{
		text: "设备需求",
		showType: "checkboxGroup",
		propName: "equipment",
		optionListSet: {
			// 存储多选框组数据
			optionsList: [],
			// 配置选项的展示和存储取值(根据实际需要的属性名配置即可)
			labelProp: "equipmentText",
			valueProp: "equipment",
			// 配置单个选项禁用的判断取值对应的属性名
			disabledProp: "repair",
		},
	},
	{
		text: "汇报方式",
		showType: "radioGroup",
		propName: "report",
		optionListSet: {
			// 存储单选框组数据
			optionsList: [],
			// 配置选项的展示和存储取值(根据实际需要的属性名配置即可)
			labelProp: "reportText",
			valueProp: "report",
			// 配置单个选项禁用的判断取值对应的属性名
			disabledProp: "cannot",
		},
	},
	{
		text: "组内公开",
		showType: "switch",
		propName: "public",
		// 其他关于switch的配置项(根据开发需求 按照element plus中给出的配置项名称及对应属性值 添加即可 下述配置项都会被添加到当前表单控件的组件上)
		addSetProp: {
			// 关于属性名: element组件中给出的属性有的带有- 我们这里要写为小驼峰
			activeText: "公开",
			inactiveText: "保密",
		},
		// 自定义行内样式 设置修改开关颜色
		styleSet: {
			"--el-switch-on-color": "#13ce66",
			"--el-switch-off-color": "#6000f9",
		},
	},
]);

// 存储表单内的双向绑定值(内部属性名可以直接按照后端传出的要求来设置 在传出数据的时候就可以直接将本对象传出)
const formData = reactive({
	code: "",
	leader: "",
	createTime: "",
	timeFrame: [],
	level: "",
	project: "",
	equipment: [],
	report: "",
	public: false,
});

// 按element plus给出的规则 设置校验规则配置项
const formRules = reactive({
	code: [
		{
			required: true,
			message: "请输入行动代号",
			trigger: "blur",
		},
		// 自定义校验规则
		{
			validator: checkTextByReg,
			message: "请输入数字编号-代号",
			trigger: "blur",
		},
	],
	createTime: [
		{
			required: true,
			message: "请选择初次登记时间",
			trigger: "blur",
		},
	],
	timeFrame: [
		{
			type: "array",
			required: true,
			message: "请选择行动时间",
			// trigger: 'change'
		},
	],
	level: [
		{
			required: true,
			message: "请选择行动级别",
		},
	],
	equipment: [
		{
			type: "array",
			required: true,
			message: "请选择设备需求",
			trigger: "change",
		},
	],
	report: [
		{
			required: true,
			message: "请选择汇报方式",
			trigger: "change",
		},
	],
});

// 获取表单组件实例
const formPublicRef = ref(null);

// 点击表单提交按钮时触发
const clickToSubmit = async () => {
	try {
		// 调用子组件中的校验方法
		let pass = await formPublicRef.value?.checkForm();
		// 若校验通过 提交数据
		if (pass) {
			// 此处模拟数据的提交 将数据进行存储 以实现在点击编辑按钮时回显(实际开发过程中会将formData内数据直接提交到后端 不需要本步骤)
			submittedData = JSON.parse(JSON.stringify(formData));
			// 成功提示
			ElMessage({
				message: "sir，创建成功！",
				grouping: true,
				type: "success",
			});
			// 表单重置
			formPublicRef.value?.resetForm();
		}
	} catch (error) {
		ElMessage({
			message: "sir，请正确填写表单",
			grouping: true,
			type: "warning",
		});
	}
};

// 点击编辑时触发 (模拟编辑场景 实际开发中 回显数据通常从后端直接获取)
const clickToEdit = () => {
	if (!submittedData) {
		ElMessage({
			message: "sir，先创建行动才可以回显",
			grouping: true,
			type: "warning",
		});
		return;
	}
	// 放入双向绑定容器中 以实现回显
	for (let key in formData) {
		formData[key] = submittedData[key] ?? "";
	}
};

// 点击取消按钮时触发
const clickToCancel = () => {
	ElMessage({
		message: "Yes sir！那你再想想吧",
		grouping: true,
		type: "warning",
	});
	// 表单重置
	formPublicRef.value?.resetForm();
};

// 下述内容仅为当前示例表单内所需 表单内选项的模拟数据及放入对应容器以供展示 实际开发过程中按需添加即可

// 模拟数据 级别下拉框数据
const levelOptions = [
	{
		levelText: "汉堡级",
		level: 0,
	},
	{
		levelText: "双层汉堡级",
		level: 1,
	},
	{
		levelText: "套餐级",
		level: 2,
	},
];

// 模拟数据 关联项目下拉框数据
const projectOptions = [
	{
		projectText: "猎豹计划",
		project: "cheetah",
	},
	{
		projectText: "猫头鹰计划",
		project: "owl",
	},
	{
		projectText: "野狼计划",
		project: "wolf",
	},
	{
		projectText: "躺平计划",
		project: "lieFlat",
		// 本选项禁用
		stop: true,
	},
];

// 模拟数据 设备需求多选框组数据
const equipmentOptions = [
	{
		equipmentText: "实时通讯",
		equipment: "communication",
	},
	{
		equipmentText: "位置获取支持",
		equipment: "position",
	},
	{
		equipmentText: "匿名搭档",
		equipment: "partner",
	},
	{
		equipmentText: "交通工具",
		equipment: "traffic",
	},
	{
		equipmentText: "科技与狠活",
		equipment: "highTech",
	},
	{
		equipmentText: "旋转木马",
		equipment: "carousel",
		// 本选项禁用
		repair: true,
	},
];

// 模拟数据 汇报方式单选框组数据
const reportOptions = [
	{
		reportText: "按阶段汇报",
		report: "stage",
	},
	{
		reportText: "固定时间汇报",
		report: "regular",
	},
	{
		reportText: "不汇报",
		report: "noReport",
		// 本选项禁用
		cannot: true,
	},
];

// 将下拉框/多选框组/单选框组 数据放入表单配置项的对应位置
pushListToFormSet(levelOptions, "level");
pushListToFormSet(projectOptions, "project");
pushListToFormSet(equipmentOptions, "equipment");
pushListToFormSet(reportOptions, "report");

// 为模拟数据提交效果 定义一个存储提交数据的容器(实际开发过程中数据会直接提交到后端 不需要本容器)
let submittedData = null;
</script>

<style lang="scss" scoped>
.form-page {
	// 外层容器 宽度固定
	width: 800px;
	padding: 20px;

	// 去除部分浏览器中可能出现的按钮边框(不需要可以去掉)
	button:focus {
		outline: 0;
	}

	// 按钮行样式设置
	.button-row {
		margin-top: 20px;
		text-align: center;
	}
}
</style>
