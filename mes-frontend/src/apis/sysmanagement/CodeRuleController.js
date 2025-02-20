import Request from "api/request";
import http from "axios";
// import {  }  from "@/plugins/https";

/** 删除编码规则 */
export function removeCodeRule({ ruleIds, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/sysmanagement/remove-code-rule/{ruleIds}",
		{
			ruleIds,
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

/** 查询单个编码规则 */
export function queryCodeRule({ ruleId, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sysmanagement/query-code-rule/{ruleId}",
		{
			ruleId,
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


/** 分页查询 */
export function queryCodeRules({ codeRuleQuery, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sysmanagement/query-code-rules",
		{
			codeRuleQuery,
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

/** 新增编码规则 */
export function addCodeRule({ CodeRuleDTO, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.POST,
		"/sysmanagement/add-code-rule",
		{
			CodeRuleDTO,
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

/** 修改编码规则 */
export function modifyCodeRule({ CodeRuleDTO, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.PUT,
		"/sysmanagement/modify-code-rule",
		{
			CodeRuleDTO,
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

/** 获取唯一编码 */
export function getAutoCode({ ruleCode,inputCharacter, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sysmanagement/get-auto-code/{ruleCode}",
		{
			getAutoCode,inputCharacter,
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