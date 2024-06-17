#pragma once

#ifndef _REMOVEWORKREPORT_CONTROLLER_H
#define _REMOVEWORKREPORT_CONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/prodmgmt/DeleteWorkReportDTO.h"
#include "../../domain/vo/prodmgmt/DeleteWorkReportVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class RemoveWorkReportController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(RemoveWorkReportController);

public: // 定义接口
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeWorkReport) {
		// 定义标题和返回类型以及授权支持
		//API_DEF_ADD_COMMON(ZH_WORDS_GETTER("prodmgmt.delete.describe.name"), Uint64JsonVO::Wrapper);
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prodmgmt.delete.describe.name"), Uint64JsonVO::Wrapper);

		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "recordId", ZH_WORDS_GETTER("prodmgmt.delete.fields.recordId"), 1, false);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/prodmgmt/prodreport/delete/{recordId}", removeWorkReport, PATH(UInt64, recordId), execRemoveWorkReport(recordId));




private: // 定义接口执行函数
	Uint64JsonVO::Wrapper execRemoveWorkReport(const UInt64& recordId);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _REMOVEWORKREPORT_CONTROLLER_H