import Request from "api/request";
import http from "axios";
// import {  }  from "@/plugins/https";

/** 日志分页查询 */
export function querySysLoginInfos({ query, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/monitor/logininfo/query-list",
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

