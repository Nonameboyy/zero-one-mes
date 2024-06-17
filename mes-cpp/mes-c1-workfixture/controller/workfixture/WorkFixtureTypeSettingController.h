#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _WORKFIXTURETYPESETTINGCONTROLLER_H_
#define _WORKFIXTURETYPESETTINGCONTROLLER_H_

#include "ExcelComponent.h"
//查类型列表
#include "../../domain/query/workfixture/WorkFixtureTypeListQuery.h"
#include "../../domain/dto/workfixture/WorkFixtureTypeListDTO.h"
#include "../../domain/vo/workfixture/WorkFixtureTypeListVO.h"
//查类型名称列表
#include "../../domain/query/workfixture/WorkFixtureTypeNameListQuery.h"
#include "../../domain/dto/workfixture/WorkFixtureTypeNameListDTO.h"
#include "../../domain/vo/workfixture/WorkFixtureTypeNameListVO.h"
//增
#include "../../domain/query/workfixture/WorkFixtureTypeCreateQuery.h"
#include "../../domain/dto/workfixture/WorkFixtureTypeCreateDTO.h"
#include "../../domain/vo/workfixture/WorkFixtureTypeCreateVO.h"
//删
#include "../../domain/query/workfixture/WorkFixtureTypeDeleteQuery.h"
#include "../../domain/dto/workfixture/WorkFixtureTypeDeleteDTO.h"
#include "../../domain/vo/workfixture/WorkFixtureTypeDeleteVO.h"
//改
#include "../../domain/query/workfixture/WorkFixtureTypeUpdateQuery.h"
#include "../../domain/dto/workfixture/WorkFixtureTypeUpdateDTO.h"
#include "../../domain/vo/workfixture/WorkFixtureTypeUpdateVO.h"
//导出
#include "../../domain/query/workfixture/WorkFixtureTypeExportQuery.h"
#include "../../domain/dto/workfixture/WorkFixtureTypeExportDTO.h"
#include "../../domain/vo/workfixture/WorkFixtureTypeExportVO.h"
#include <boost/core/noinit_adaptor.hpp>

#include "domain/vo/BaseJsonVO.h"
//结束头文件导入
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 工装夹具 类型设置 获取类型列表 控制器
 */
class WorkFixtureTypeSettingController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(WorkFixtureTypeSettingController);
	// 3 定义接口
public:
	// 3.1 定义Type查询接口描述
	ENDPOINT_INFO(queryWorkFixtureType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workfixture.type.query.summaryT"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkFixtureTypeListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//唯一标识
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "toolTypeID", ZH_WORDS_GETTER("workfixture.type.fields.id"), 1, true);
		//类型编码
		API_DEF_ADD_QUERY_PARAMS(String, "typeCode", ZH_WORDS_GETTER("workfixture.type.fields.code"),"",false);
		//类型名称
		API_DEF_ADD_QUERY_PARAMS(String, "typeName", ZH_WORDS_GETTER("workfixture.type.fields.name"),"",false);
		//是否编码管理N/Y
		//API_DEF_ADD_QUERY_PARAMS(String, "codeFlag", ZH_WORDS_GETTER("workfixture.type.fields.codeflag"),"",false);
		//保养维护类型 REGULAR USAGE
		API_DEF_ADD_QUERY_PARAMS(String, "maintenType", ZH_WORDS_GETTER("workfixture.type.fields.mtype"), "",false );
		//保养周期
		//API_DEF_ADD_QUERY_PARAMS(Int32, "maintenPriod", ZH_WORDS_GETTER("workfixture.type.fields.mpriod"), 0, false);
		//备注
		//API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("workfixture.type.fields.remark"), "", false);
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}
	// 3.2 定义Type查询接口处理
	ENDPOINT(API_M_GET, "/tm/query-type-list", queryWorkFixtureType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, WorkFixtureTypeListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execType(query));
	}
	
	// 3.1 定义TypeName查询接口描述
	ENDPOINT_INFO(queryWorkFixtureTypeName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workfixture.type.query.summaryTN"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}
	// 3.2 定义TypeName查询接口处理
	ENDPOINT(API_M_GET, "/tm/query-typename-list", queryWorkFixtureTypeName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, WorkFixtureTypeNameListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execTypeName(query));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(createWorkFixtureType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workfixture.type.query.create"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/tm/create-type", createWorkFixtureType, BODY_DTO(WorkFixtureTypeCreateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execCreateType(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("workfixture.type.query.update"), UpdateType, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/tm/update-type", UpdateType, BODY_DTO(WorkFixtureTypeUpdateDTO::Wrapper, dto), execUpdateType(dto));

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(deleteType) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("workfixture.type.query.delete"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("workfixture.type.fields.deleteid"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/tm/delete-type-setting/{id}", deleteType, PATH(UInt64, id), execDeleteType(id));

	// 3.1 定义导出下载接口描述
	ENDPOINT_INFO(exportFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("workfixture.type.query.export"), Void);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "public/excel/tooltype.xlsx", true);
	}
	//"public/excel/tooltype.xlsx"
	// 定义端点
	ENDPOINT(API_M_GET, "/tm/workfixture-export-excel", exportFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execExportType();
	}

private:
	// 3.3 演示Type分页查询数据
	WorkFixtureTypeListPageJsonVO::Wrapper execType(const WorkFixtureTypeListQuery::Wrapper& query);
	// 3.3 演示TypeName分页查询数据
	WorkFixtureTypeNameListJsonVO::Wrapper execTypeName(const WorkFixtureTypeNameListQuery::Wrapper& query);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execCreateType(const WorkFixtureTypeCreateDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execUpdateType(const WorkFixtureTypeUpdateDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execDeleteType(const UInt64& id);
	// 3.3 导出
	std::shared_ptr<OutgoingResponse> execExportType();
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WORKFIXTURETYPESETTINGCONTROLLER_H_