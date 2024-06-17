import Request from "api/request";
import http from "axios";
// import {  }  from "@/plugins/https";

/** 删除日志 */
export function removeOperLog({ operIds, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/sys/operlog/remove-operlog/{operIds}",
		{
			operIds,
		},
		http.upType.json,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("shibai1");
			}
		})
		.catch((err) => {
			fail(err);
		});
}

/** 导出操作日志。*/
export function downloadOperLogExcel({  success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sys/operlog/export-operlog",
		{
		},
		http.upType.file,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("shibai1");
			}
		})
		.catch((err) => {
			fail(err);
		});
}

/** 分页获取日志。*/
export function getOperationLogPage({ query, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sys/operlog/page",
		{
			query,
		},
		http.upType.json,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("shibai1");
			}
		})
		.catch((err) => {
			fail(err);
		});
}

/** 获取日志详情。*/
export function getOperationLogPage({ operId, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sys/operlog/{operId}",
		{
			operId,
		},
		http.upType.json,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("shibai1");
			}
		})
		.catch((err) => {
			fail(err);
		});
}

/** 导出操作日志到dfs。*/
export function exportToDfs({ success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sys/operlog/export-operlogtodfs",
		{
		},
		http.upType.file,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("shibai1");
			}
		})
		.catch((err) => {
			fail(err);
		});
}



