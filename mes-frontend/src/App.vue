<script setup>
import zhCn from 'element-plus/dist/locale/zh-cn.mjs'
//element组件语言改为中文，中文国际化
</script>

<template>
	<el-config-provider :locale="zhCn">
		<router-view />
	</el-config-provider>
	
</template>
