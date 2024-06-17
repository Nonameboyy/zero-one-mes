import Request from "api/request";
import http from "axios";
// import {  }  from "@/plugins/https";

/** 删除登录日志列表 */
export function removeLoginLog({ ids, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/LoginInfo/remove-LoginLog/{ids}",
		{
			ids,
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

/** 清空登录日志列表 */
export function clearLoginLog({  success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/LoginInfo/clean-LoginLog",
		{
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

/** 导出登录日志列表 */
export function exportLoginLog({  success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/LoginInfo/export-LoginLog",
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