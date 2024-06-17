import Request from "api/request";
import http from "axios";

/** 添加供应商 */
export function addVendor({ vendorAddDTO, success = () => {}, fail = () => {} }) {
	return Request.request(Request.POST, "/basicdata/md-vendor/add-vendor", { vendorAddDTO }, http.upType.json)
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

/** 导入供应商 */
export function importVendors({ MultipartFile, success = () => {}, fail = () => {} }) {
	return Request.request(Request.POST, "/basicdata/md-vendor/importVendors", { MultipartFile }, http.upType.file)
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
// 导出供应商
export function exportVendor(vendorExcelSelectDTO, success = () => {}, fail = () => {}) {
	return Request.get('/basicdata/md-vendor/download-vendor', {
		params: vendorExcelSelectDTO,
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
//修改供应商
export function updateVendor({ vendorModifyDTO, success = () => {}, fail = () => {} }) {
	return Request.request(Request.POST, "/basicdata/md-vendor/update-vendor", { vendorModifyDTO }, http.upType.json)
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
// 供应商分页查询
export function getVendorsPage(page = 1, pageSize = 10, success = () => {}, fail = () => {}) {
	return Request.get('/basicdata/md-vendor/page', {
		params: { page, pageSize }
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

// 查询供应商详情
export function getVendorDetail(vendorId, success = () => {}, fail = () => {}) {
	return Request.get(`/basicdata/md-vendor/`+vendorId)
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

// 批量删除供应商
export function deleteVendors(ids, success = () => {}, fail = () => {}) {
	return Request.delete('/basicdata/md-vendor', {
		params: { ids }
	})
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('删除失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}

// 下载供应商导入模板
export function downloadImportTemplate(success = () => {}, fail = () => {}) {
	return Request.get('/basicdata/md-vendor/downloadImportTemplate', {
		responseType: 'arraybuffer' // 根据实际情况选择响应类型
	})
		.then(res => {
			if (res.status === 200) {
				success(res);
			} else {
				fail('下载失败');
			}
		})
		.catch(err => {
			fail(err);
		});
}
