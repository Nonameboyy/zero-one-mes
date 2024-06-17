import Request from "api/request.js";

/** 添加编码生成规则组成表 */
export function addCodeRulePart({ sysAutoCodePartDTO, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.POST,
		"/sysmanagement/sys-auto-code-part/add-code-rule-part",
		{
			sysAutoCodePartDTO,
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

/** 修改编码生成规则组成表 */
export function modifyCodeRulePart({ sysAutoCodePartDTO, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.PUT,
		"/sysmanagement/sys-auto-code-part/modify-code-rule-part",
		{
			sysAutoCodePartDTO,
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

/** 删除编码生成规则组成表 */
export function removeCodeRulePart({ partIds, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/sysmanagement/sys-auto-code-part/remove-code-rule-part/{partIds}",
		{
			partIds,
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

/** 根据分段Id查询编码生成规则组成表 */
export function queryCodeRulePart({ partId, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sysmanagement/sys-auto-code-part/query-code-rule-part/{partId}",
		{
			partId,
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

/** 分页查询编码生成规则组成表 */
export function queryCodeRuleParts({ sysAutoCodePartQuery, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.GET,
		"/sysmanagement/sys-auto-code-part/query-code-rule-parts",
		{
			sysAutoCodePartQuery,
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