import Request from "api/request";
import http from "axios";
// import {  }  from "@/plugins/https";

/** 删除单位 */
export function deleteUnitMeasure({ measureIds, success = () => {}, fail = () => {} }) {
	return Request.request(
		Request.DELETE,
		"/basicdata/md-unit-measure/delete-by-measureIds",
		{
			measureIds,
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


// 导出单位
export function exportUnitMeasure(unitExcelSelectDTO, success = () => {}, fail = () => {}) {
	return Request.get('/basicdata/md-unit-measure/download-unitMeasure', {
		params: unitExcelSelectDTO,
		responseType: 'arraybuffer' // 根据实际情况选择响应类型
	})
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('导出失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}

// 根据单位ID获取单位信息
export function getInfo(measureId, success = () => {}, fail = () => {}) {
	return Request.get(`/basicdata/md-unit-measure/`+measureId)
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('获取信息失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}

// 查询单位分页列表
export function list(unitMeasureDTO, pageIndex = 1, pageSize = 10, success = () => {}, fail = () => {}) {
	return Request.get('/basicdata/md-unit-measure/list', {
		params: {
			...unitMeasureDTO,
			pageIndex,
			pageSize
		}
	})
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('查询失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}

// 添加单位
export function addUnitMeasure(unitAddDTO, success = () => {}, fail = () => {}) {
	return Request.post('/basicdata/md-unit-measure/add', unitAddDTO)
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('添加失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}

// 修改单位
export function modifyUnitMeasure(unitUpdateDTO, success = () => {}, fail = () => {}) {
	return Request.post('/basicdata/md-unit-measure/modify', unitUpdateDTO)
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('修改失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}