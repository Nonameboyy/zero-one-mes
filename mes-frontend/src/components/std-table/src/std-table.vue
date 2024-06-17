<script setup lang="ts" generic="TableRow extends Record<string, unknown>">
import { computed, ref, onMounted } from "vue";
import { merge, isEmpty } from "lodash-es";
import { reactify } from "@vueuse/core";
import { ElButton } from "element-plus";

import { TableFrame, TableInnerLayout } from "components/std-table";
import popUp from "components/std-table/src/pop-up.vue";
import request from "api/request.js"; //加入请求

import type { Prettify } from "utils/Prettify.ts";
import type { ComputedRef } from "vue";
import type { TableProps } from "element-plus";
import type { RequiredPick } from "type-plus";
import type { Operations, StdTableProps } from "./std-table.ts";

defineOptions({
	/** 表格组件 */
	name: "StdTable",
});

// FIXME: [@vue/compiler-sfc] Failed to resolve index type into finite keys
// 这里出现无限递归了
// type Props = Prettify<StdTableProps<TableRow>>;
type Props = Readonly<StdTableProps<TableRow>>;

const props = withDefaults(defineProps<Props>(), {
	data: () => [] as TableRow[],
});

const defaultPropsKeys = ["data", "operations", "size", "border"] as const;
type DefaultPropsKeys = (typeof defaultPropsKeys)[number];
type DefaultProps = Prettify<Readonly<RequiredPick<Props, DefaultPropsKeys>>>;

type MergeReactify = <TObject, TSource>(object: TObject, source: TSource) => ComputedRef<TObject & TSource>;
const mergeReactify = reactify(merge) as MergeReactify;

/**
 * 默认的 props 配置对象
 * @description
 * 未来，如果表格组件需要配置很多预设的行为 在此配置即可
 */
const defaultProps: DefaultProps = {
	data: [] as TableRow[],
	operations: [],
	unifySize: "small",
	border: true,
};

/**
 * 创建一个全新的默认props对象
 * @description
 * ### *设计理由*
 * 用于确保生成的默认值是独一无二的对象，确保不会和其他表格组件实例共用对象
 */
function createDefaultProps() {
	return merge({}, defaultProps);
}

/** 本组件实际有的全部可用props值 */
const stdTableProps = mergeReactify(createDefaultProps(), props);

/**
 * 按钮栏配置对象
 * @description
 * 及时不提供任何值 在此处也是默认提供一个空数组
 *
 * 不考虑将该空数组设置成默认值
 */
const buttons = computed(() => stdTableProps.value.buttons ?? []);

/** 操作栏配置对象 */
const operations = computed(() => stdTableProps.value.operations);

const unifySize = computed(() => stdTableProps.value.unifySize);

// ElButtonSize

onMounted(async () => {
	await stdTableProps.value.init?.();
});

// stdTableProps.value.

//没有中文国际化
//每一列数据，例子，后期接口对上再调整
const tableList = ref([
	{
		classify: "金属",
		product: "螺丝",
		sure: "正常",
		time: "2024.5.22",
	},
]);

const multipleSelection = ref([]);
//dialog联系到表格弹窗
const dialog = ref();

//定义总条数
const total = ref(0);
const loading = ref(false); //loading状态

//定义请求参数,后期完善
const parms = ref({
	pagenum: 1, //页数
	pagesize: 5, //当前每页面大小
	state: "成功", //状态
	classfiy: "时间",
});

const getPageList = async () => {
	loading.value = true;
	//里面改接口，可以加个try-catch
	// const res= await Request.request('GET','/basicdata/md-unit-measure/list',null)
	// tableList.value=res.data.rows.data
	// parms.value.pagenum=res.data.pageIndex
	// parms.value.pagesize=res.data.pageSize
	loading.value = false;
};
getPageList(); //进来就加载一遍
//处理分页逻辑
//改变大小
const onSizeChange = (size) => {
	//console.log('当前每页面条数',size);
	parms.value.pagenum = 1;
	parms.value.pagesize = size;
	//再利用接口渲染数据getPageList
	getPageList();
};
//改变页数
const onCurrentChange = (page) => {
	// console.log('页面变化了',page);
	parms.value.pagenum = page;
	//基于当前最新页渲染数据
	getPageList();
};

// const tableList=ref([])
const onSortChannel = () => {
	console.log("排序");
};
const onEditchannel = (row, $index) => {
	//编辑
	dialog.value.open({ row });
	console.log(row);
};
const onDelChannel = async (row) => {
	//删除
	await ElMessageBox.confirm("你确认要删除该分类么", "温馨提示", {
		type: "warning",
		confirmButtonText: "确认",
		cancelButtonText: "取消",
	});
	ElMessage.success("删除成功");
	console.log(row);
	//删除后再渲染数据
	getPageList();
};
const onSubmit = () => {
	console.log("查询提交");
};
//添加
const onAddChannel = () => {
	dialog.value.open({});
};
//选择组件
const handleSelectionChange = (val) => {
	this.multipleSelection = val;
};
</script>

<template>
	<section class="std-table-root">
		<slot name="stdTableSearch"> </slot>

		<TableInnerLayout>
			<template #tableInnerButtons>
				<slot name="stdTableButtons">
					<template v-if="!isEmpty(buttons)">
						<template v-for="(button, indx) in buttons" :key="indx">
							<ElButton v-bind="button" :size="unifySize">
								<section>
									{{ button.buttonName }}
								</section>
							</ElButton>
						</template>
					</template>
				</slot>
			</template>

			<template #tableInnerMain>
				<slot name="stdTableMain"> </slot>
			</template>

			<template #tableInnerPagination>
				<slot name="stdTablePagination"> </slot>
			</template>
		</TableInnerLayout>
	</section>

	<!--分类，页面只有基本的表现，没有实现数据绑定-->
	<tableFrame title="实验表格">
		<slot name="extra">
			<!-- 具名插槽例子实现 -->
			<el-button @click="onSortChannel"
				>排序顺序
				<el-icon :size="20"> <Sort /><!--排序图标--> </el-icon>
			</el-button>
			<el-button @click="onAddChannel"
				>添加
				<el-icon :size="20"> <Plus /><!--排序图标--> </el-icon>
			</el-button>
		</slot>

		<!--表单区域-->
		<el-form :inline="true" class="demo-form-inline">
			<el-form-item label="表格分类：" padding="50px">
				<!--label是用户看，value是收集给后台的-->
				<el-select v-model="parms.classfiy">
					<el-option label="按产品" value="001"> </el-option>
					<el-option label="按时间" value="002"> </el-option>
				</el-select>
			</el-form-item>
			<el-form-item label="状态">
				<el-select v-model="parms.state"
					><!--后台标记状态-->
					<el-option label="正常" value="正常"></el-option>
					<el-option label="失败" value="失败"></el-option>
				</el-select>
			</el-form-item>
			<el-form-item>
				<el-button type="primary" @click="onSubmit">查询</el-button>
			</el-form-item>
		</el-form>

		<!--表格区-->
		<el-table
			:data="tableList"
			style="width: 100%"
			v-loading="loading"
			@selection-change="handleSelectionChange"
			ref="multipleTable"
		>
			<el-table-column type="selection" width="55" />
			<el-table-column prop="classify" label="分类" width="100"></el-table-column>
			<el-table-column type="index" label="排序" width="50"></el-table-column>
			<el-table-column prop="product" label="物料/产品" width="150"></el-table-column>
			<el-table-column prop="sure" label="是否启用"></el-table-column>
			<el-table-column prop="time" label="创建时间"></el-table-column>
			<el-table-column label="操作">
				<!-- row是当前一行数据 index是下标-->
				<template #default="{ row, $index }">
					<el-button @click="onEditchannel(row, $index)" circle type="primary">
						<el-icon :size="20"> <Edit /><!--修改图标--> </el-icon>
					</el-button>
					<el-button @click="onDelChannel(row, $index)" type="danger" circle>
						<el-icon> <Delete /><!--删除图标--> </el-icon>
					</el-button>
				</template>
			</el-table-column>
		</el-table>

		<el-pagination
			v-model:current-page="parms.pagenum"
			v-model:page-size="parms.pagesize"
			:page-sizes="[2, 3, 5, 10]"
			:background="true"
			layout="total, sizes, prev, pager, next, jumper"
			:total="11"
			@size-change="onSizeChange"
			@current-change="OnCurrentChange"
			style="margin-top: 20px; justify-content: flex-end"
		/>

		<!--空处理-->
		<slot name="#empty">
			<el-empty description="没有数据"></el-empty>
		</slot>
	</tableFrame>

	<!--引入的弹窗-->
	<pop-Up ref="dialog"> </pop-Up>
</template>

<style lang="scss" scoped>
.std-table-root {
}

.demo-form-inline {
	.el-input {
		--el-input-width: 220px;
	}
	.el-select {
		--el-select-width: 220px;
	}
}
</style>
