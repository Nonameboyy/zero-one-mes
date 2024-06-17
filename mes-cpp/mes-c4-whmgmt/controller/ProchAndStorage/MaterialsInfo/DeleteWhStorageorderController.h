#pragma once
#ifndef _DELETEWHSTORAGEORDERCONTROLLER_H_
#define _DELETEWHSTORAGEORDERCONTROLLER_H_
#include "../../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDTO.h"
#include "../../../domain/vo/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DeleteWhStorageorderController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteWhStorageorderController);
	// 3 定义接口
public:
	//3.1 定义删除接口描述
	ENDPOINT_INFO(deleteWhStorageorders) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("whstorageorder.delete.summary"), Uint64JsonVO::Wrapper);
		// 添加安全验证
		API_DEF_ADD_AUTH();
	}
	// 3.2 定义批量删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/whmgmt/purchase/delete1", deleteWhStorageorders, BODY_DTO(List<UInt64>, ids), execDeleteWhStorageorder(ids));

private:
	//3.3 演示删除入库单行
	Uint64JsonVO::Wrapper execDeleteWhStorageorder(const List<UInt64>& ids);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _DELETEWHSTORAGEORDERCONTROLLER_H_