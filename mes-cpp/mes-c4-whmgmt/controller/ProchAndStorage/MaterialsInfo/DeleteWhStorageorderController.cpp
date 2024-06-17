#include "stdafx.h"
#include "DeleteWhStorageorderController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/ProchAndStorage/MaterialsInfo/WhStorageorderService.h"


//执行删除操作
Uint64JsonVO::Wrapper DeleteWhStorageorderController::execDeleteWhStorageorder(const List<UInt64>& ids)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数校验
	if (!ids->empty()) {
		for (auto it = ids->begin(); it != ids->end(); it++) {
			if (*it <= 0) {
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
				return jvo;
			}
		}
	}
	else {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//定义一个service
	WhStorageorderService service;
	//将列表ids中的每个id执行数据删除
	if (service.deleteWhStorageorder(ids)) {
		for (auto it = ids->begin(); it != ids->end(); ++it) {
			jvo->success(*it);
		}
	}
	else {
		for (auto it = ids->begin(); it != ids->end(); ++it) {
			jvo->fail(*it);
		}
	}
	//响应结果
	return jvo;
}