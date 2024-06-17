<template>
	<el-upload action="no-action" :show-file-list="false" :http-request="uploadUseFormData">
		<el-button size="small" type="primary">
			<el-icon style="vertical-align: middle">
				<icon-upload />
			</el-icon>
			<span style="vertical-align: middle">FormData上传文件</span>
		</el-button>
	</el-upload>
	<div class="wrap-space"></div>
	<el-upload ref="upload" action="no-action" :show-file-list="false" :http-request="uploadUseStream">
		<el-button size="small" type="primary">
			<el-icon style="vertical-align: middle">
				<icon-upload />
			</el-icon>
			<span style="vertical-align: middle">Stream上传文件</span>
		</el-button>
	</el-upload>
</template>

<script setup>
import Request from "@/apis/request";
import { ElMessage } from "element-plus";

// 使用FormData的方式上传文件
function uploadUseFormData(params) {
	// 执行文件上传
	Request.postFile(
		"/file/upload",
		{
			nickname: "小米",
			age: 18,
			file: params.file,
		},
		{ baseURL: "http://localhost:8090" },
	)
		.then((res) => {
			console.log(res);
			ElMessage.success("上传成功");
		})
		.catch((res) => {
			console.log(res);
			ElMessage.error("上传失败");
		});
}

// 使用Stream方式上传
function uploadUseStream(params) {
	// 执行文件上传
	Request.postFileStream(
		"/user/modify-user?nickname=莉莉丝&age=10",
		params.file,
		(res) => {
			console.log(res);
			ElMessage.success("上传成功");
		},
		(err) => {
			console.log(err);
			ElMessage.error("上传失败");
		},
		{ baseURL: "http://localhost:8090" },
	);
}
</script>

<style scoped>
.wrap-space {
	padding: 5px;
}
</style>
