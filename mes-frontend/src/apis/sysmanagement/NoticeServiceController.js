import Request from "api/request";
import http from "axios";
// import {  }  from "@/plugins/https";

/**
 * 删除公告
 * @param ids 数据ID集合
 * @return
 */

export function removeNotice({ ids, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/sys-manager/notice/remove-notice",
		{
			ids,
		},
		http.upType.json,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("公告删除失败！");
			}
		})
		.catch((err) => {
			fail(err);
		});
}

/**
 * 查询公告详情
 * @param id 查询对象ID
 * @return
 */

export function queryNoticeById({ id, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.POST,
		"/sys-manager/notice/query-notice-by-id",
		{
			id,
		},
		http.upType.json,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("获取公告详情失败！");
			}
		})
		.catch((err) => {
			fail(err);
		});
}

/**
 * 添加公告
 * @param dto 新增的数据
 * @return
 */
export function addNotice({ AddNoticeDTO, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.POST,
		"/sys-manager/notice/add-notice",
		{
			AddNoticeDTO,
		},
		http.upType.json,
	)
		.then((res) => {
			if (res.status === 200) {
				success(res);
			} else {
				fail("添加公告失败！");
			}
		})
		.catch((err) => {
			fail(err);
		});
}