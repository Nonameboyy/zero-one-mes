#pragma once
#ifndef _SET_CONTROLLER_
#define _SET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/set/ProcessExportQuery.h"
#include "domain/query/set/SetProListQuery.h"

#include "domain/dto/set/SetProAddDTO.h"
#include "domain/dto/set/SetProListDTO.h"
#include "domain/vo/set/SetProListVO.h"

#include "domain/query/set/ProListQuery.h"
#include "domain/dto/set/ProListDTO.h"
#include "domain/vo/set/ProListVO.h"

#include "domain/dto/set/ProNameListDTO.h"
#include "domain/vo/set/ProNameListVO.h"

#include "domain/query/set/ProDetailQuery.h"
#include "domain/vo/set/ProDetailVO.h"

#include "domain/query/set/SetStepExportQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 工艺流程控制器
 */
class SetController : public oatpp::web::server::api::ApiController 
{

	API_ACCESS_DECLARE(SetController);

public:

	// 1 导出工序
	ENDPOINT_INFO(queryProcessExport) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.export.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "processCode", ZH_WORDS_GETTER("set.field.code"), "R1126", false);
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("set.field.name"), "111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("set.field.flag"), "Y", false);
	}
	ENDPOINT(API_M_POST, "/pro/export-procedure", queryProcessExport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(Query, ProcessExportQuery, queryParams);
		API_HANDLER_RESP_VO(execProcessExport(Query));
	}

	// 2 添加工序接口描述
	ENDPOINT_INFO(addSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-set", addSet, BODY_DTO(SetProAddTableDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddSet(dto, authObject->getPayload()));
	}

	// 3 修改工序接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("set.modify.summary"), modifySet, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-set", modifySet, BODY_DTO(SetProAddTableDTO::Wrapper, dto), execModifySet(dto, authObject->getPayload()));

	// 4 获取工序步骤列表接口
	ENDPOINT_INFO(querySet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(SetProListPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("set.fields.processid"), 1, false);
	}
	ENDPOINT(API_M_GET, "/pro/query-list-set", querySet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, SetProListQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySet(query, authObject->getPayload()));
	}

	// 5 添加工序步骤接口描述
	ENDPOINT_INFO(addstepSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.addstep.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/addstep-set", addstepSet, BODY_DTO(SetProListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddStepSet(dto, authObject->getPayload()));
	}

	// 6 获取工序名称列表
	ENDPOINT_INFO(queryProNameList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary2"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProNameListJsonVO);
	}
	ENDPOINT(API_M_GET, "/pro/query-process-name-list", queryProNameList,  API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProNameList());
	}

	// 7 获取工序列表（条件+分页）
	ENDPOINT_INFO(queryProList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "processCode", ZH_WORDS_GETTER("process.fields.processCode"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("process.fields.processName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("process.fields.enableFlag"), "Y", false);
	}
	ENDPOINT(API_M_GET, "/pro/query-process-list", queryProList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ProListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProList(query));
	}

	// 8 获取工序详情
	ENDPOINT_INFO(queryProcessDetail) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary3"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProDetailJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("process.fields.processId"), 265, true);
	}
	ENDPOINT(API_M_GET, "/pro/query-process-detail", queryProcessDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, ProDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryProDetail(query));
	}

	// 9 修改工序步骤
	ENDPOINT_INFO(modifystepSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.modify.summary1"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/pro/modifystep-set", modifystepSet, BODY_DTO(SetProListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyStepSet(dto, authObject->getPayload()));
	}
	// 10 删除工序步骤
	ENDPOINT_INFO(deletestepSet) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("set.modify.summary2"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("set.fields.processid"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete-process-step/{id}", deletestepSet, PATH(UInt64, id), execDeleteStepSet(id));

	// 11 导出工序步骤
	ENDPOINT_INFO(SetStepExport) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.export.summary1"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("set.fields.processid"), 1, true);
	}
	ENDPOINT(API_M_POST, "/pro/export-process-step", SetStepExport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(setstepQuery, SetProListQuery, queryParams);
		API_HANDLER_RESP_VO(execExportStepSet(setstepQuery));
	}
	// 12 删除工序
	ENDPOINT_INFO(DeleteSet) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("set.modify.summary3"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("set.fields.processid"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete-set/{id}", DeleteSet, PATH(UInt64, id), execDeleteSet(id));

private:
	// 1 导出文件
	StringJsonVO::Wrapper execProcessExport(const ProcessExportQuery::Wrapper& query);
	// 2 添加工序
	Uint64JsonVO::Wrapper execAddSet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3 修改工序
	Uint64JsonVO::Wrapper execModifySet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload);
	// 4 获取工序步骤列表
	SetProListPageJsonVO::Wrapper execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload);
	// 5 添加工序步骤
	Uint64JsonVO::Wrapper execAddStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload);
	// 6 获取工序列表
	ProListPageJsonVO::Wrapper execQueryProList(const ProListQuery::Wrapper& query);
	// 7 获取工序名称列表
	ProNameListJsonVO::Wrapper execQueryProNameList();
	// 8 获取工序详情
	ProDetailJsonVO::Wrapper execQueryProDetail(const ProDetailQuery::Wrapper& query);
	// 9 修改工序步骤
	Uint64JsonVO::Wrapper execModifyStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload);
	//10 删除工序步骤
	Uint64JsonVO::Wrapper execDeleteStepSet(const UInt64& id);
	//11 导出工序步骤
	StringJsonVO::Wrapper execExportStepSet(const SetProListQuery::Wrapper& query);
	//12 删除工序
	Uint64JsonVO::Wrapper execDeleteSet(const UInt64& id);
};


#include OATPP_CODEGEN_END(ApiController) 
#endif 