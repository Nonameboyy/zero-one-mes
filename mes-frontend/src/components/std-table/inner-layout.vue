<script lang="ts" setup>
import { computed, ref, watch } from "vue";

/**
 * 表格内部布局
 * @description
 * 专门用于定义声明表格组件内部的容器布局
 *
 * 未来实现表格的高度重设
 */
</script>

<template>
	<section class="table-inner-layout-root">
		<!-- <slot name="default"></slot> -->
		<slot name="tableInnerButtons"></slot>
		<slot name="tableInnerMain"></slot>
		<slot name="tableInnerPagination"></slot>
	</section>
</template>

<style lang="scss" scoped>
.table-inner-layout-root {
}
</style>
