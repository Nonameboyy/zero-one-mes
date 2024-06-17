<script lang="ts" setup generic="DataType extends Record<string, unknown>">
import { ref, computed, watch } from "vue";

import { ElForm, ElInput, ElSelect, ElOption } from "element-plus";

type ElInputPropsType = InstanceType<typeof ElInput>["props"];

const formType = <const>[
	"input",
	"select",
	"date",
	"range",
	"cascader",
	"radio",
	"checkbox",
	"switch",
	"slider",
	"rate",
	"color-picker",
	"time-picker",
	"date-picker",
	"upload",
	"input-number",
	"autocomplete",
	"checkbox-button",
	"radio-button",
	"time-select",
	"time-range-picker",
	"date-range-picker",
	"select-tree",
	"transfer",
	"form",
];

type FormType = (typeof formType)[number];

type FormConfigMap = {
	input: ElInputPropsType;
	[k: string]: any;
};

defineOptions({
	name: "SearchBar",
});

type KeyDataType = keyof DataType;

type FormItems<T extends FormType = "input"> = {
	type: T;
	label: string;
	prop: KeyDataType;
	config: FormConfigMap[T];
};

// FormConfigMap['input']

type SearchBarConfig = {
	formItems: FormItems[];
};

type SearchBarProps<T = DataType, K = KeyDataType> = {
	/** 表格配置 */
	config: {};

	/** 双向绑定的表格数据 */
	data: T;
	// data: string
};

const props = withDefaults(defineProps<SearchBarProps<DataType>>(), {
	config: function () {
		return {};
	},
});

const data = defineModel<DataType>(<keyof SearchBarProps>"data");

type OptionsItem = {
	label: string;
	value: string;
	id?: string | number;
};

const options = ref<OptionsItem[]>([
	{
		label: "选项1",
		value: "1",
	},

	{
		label: "选项2",
		value: "2",
		id: 2,
	},

	{
		label: "选项agsgsd",
		value: "3",
		id: 2,
	},

	{
		label: "选项4444",
		value: "5",
		id: 2,
	},
]);
</script>

<template>
	<section class="search-bar-root">
		<!-- <ElForm> </ElForm> -->

		<!-- <ElInput v-model="data.input"></ElInput> -->

		<ElSelect v-model="data.input" placeholder="请选择内容" size="large" style="width: 240px">
			<ElOption v-for="(item, index) in options" :key="index" :label="item.label" :value="item.value" />
		</ElSelect>
	</section>
</template>

<style lang="scss" scoped>
.search-bar-root {
	background-color: #f3f3f3;
}
</style>
