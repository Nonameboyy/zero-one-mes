<template>
	<div id="my-container"></div>
</template>
<script setup>
//导入PDFObject
import PDFObject from "pdfobject";
import { onMounted } from "vue";
onMounted(() => {
	let url = "https://pdfobject.com/pdf/sample-3pp.pdf";
	PDFObject.embed(url, "#my-container");
});
</script>
<style scoped>
/* 设置pdf样式，类名固定 */
.pdfobject-container {
	height: 680px;
	border: 1rem solid rgba(0, 0, 0, 0.1);
}
</style>
