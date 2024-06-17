#pragma once

#ifndef _WORKSTATION_CONTROLLER_H_
#define _WORKSTATION_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/workstation/WorkStationDTO.h"
#include "domain/query/workstation/WorkStationQuery.h"
#include "domain/vo/workstation/GetWorkStationListVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class WorkStationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 工作站
	API_ACCESS_DECLARE(WorkStationController);
public:
	// 1.定义修改工作站接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("workstation.modify.summary"), modifyWorkStation, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ws/modify-ws", modifyWorkStation, BODY_DTO(ModifyWorkStationDTO::Wrapper, dto), execModifyWorkStation(dto));

	// 2.定义新增工作站接口描述
	ENDPOINT_INFO(addWorkStation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workstation.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/ws/add-ws", addWorkStation, BODY_DTO(AddWorkStationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddWorkStation(dto));
	}

	// 3.定义导出工作站接口描述
	//ENDPOINT_INFO(exportWorkStation) {
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workstation.export.summary"));
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//	//定义分页查询参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// 定义其他查询参数描述
	//	//工作站编码
	//	API_DEF_ADD_QUERY_PARAMS(String, "workstationCode", ZH_WORDS_GETTER("workstation.fields.workstationCode"), "WS0124", false);
	//	//工作站名称
	//	API_DEF_ADD_QUERY_PARAMS(String, "workstationName", ZH_WORDS_GETTER("workstation.fields.workstationName"), "zhusu", false);
	//	//所在车间名称
	//	API_DEF_ADD_QUERY_PARAMS(String, "workshopName", ZH_WORDS_GETTER("workstation.fields.workshopName"), "car", false);
	//	//所属工序(工序名称)
	//	API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("workstation.fields.processName"), "QCC", false);
	//}

	// 定义导出工作站接口处理
	//ENDPOINT(API_M_GET, "/ws/export-ws", exportWorkStation, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//	// 解析查询参数为Query领域模型
	//	API_HANDLER_QUERY_PARAM(query, ExportWorkStationQuery, queryParams);
	//	// 呼叫执行函数响应结果
	//	API_HANDLER_RESP_VO(execWorkStation(query));
	//}


	ENDPOINT_INFO(exportWorkStation) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workstation.export.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式（返回的字符串可以是文件下载地址，具体取决于实现）
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/ws/workstation/export", exportWorkStation, BODY_DTO(List<UInt64>, id), execExportWorkStation(id));



	// 4.定义分页获取工作站列表查询接口描述
	ENDPOINT_INFO(queryWorkStationList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workstation.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetWorkStationListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//工作站编码
		API_DEF_ADD_QUERY_PARAMS(String, "workstationCode", ZH_WORDS_GETTER("workstation.fields.workstationCode"), "WS0124", false);
		//工作站名称
		API_DEF_ADD_QUERY_PARAMS(String, "workstationName", ZH_WORDS_GETTER("workstation.fields.workstationName"), "zhusu", false);
		//所在车间名称
		API_DEF_ADD_QUERY_PARAMS(String, "workshopName", ZH_WORDS_GETTER("workstation.fields.workshopName"), "car", false);
		//所属工序(工序名称)
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("workstation.fields.processName"), "QCC", false);
	}
	// 定义获取工作站列表查询接口处理
	ENDPOINT(API_M_GET, "/ws/query-ws-list", queryWorkStationList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, GetWorkStationListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execWorkStationList(query));
	}

	// 5.定义删除工作站接口描述
	ENDPOINT_INFO(removeWorkStation) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("workstation.remove.summary"), Uint64JsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/workstation/remove", removeWorkStation, BODY_DTO(List<UInt64>, id), execRemoveWorkStation(id));

	//ENDPOINT_INFO(removeWorkStation) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("workstation.delete.summary"), oatpp::List<UInt64>);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(List<UInt64>, "workstationId", ZH_WORDS_GETTER("workstation.fields.workstationId"), { 1 }, true);
	//}
	//// 定义删除工作站接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/remove-ws", removeWorkStation, BODY_DTO(List<UInt64>, workstationId), execRemoveWorkStation(workstationId));

private:
	// 1.修改工作站
	Uint64JsonVO::Wrapper execModifyWorkStation(const ModifyWorkStationDTO::Wrapper& dto);
	// 2.新增工作站
	Uint64JsonVO::Wrapper execAddWorkStation(const AddWorkStationDTO::Wrapper& dto);
	// 3.导出工作站
	StringJsonVO::Wrapper execExportWorkStation(const List<UInt64>& id);
	// 4.分页获取工作站列表数据
	GetWorkStationListPageJsonVO::Wrapper execWorkStationList(const GetWorkStationListQuery::Wrapper& query);
	// 5.批量删除工作站数据
	Uint64JsonVO::Wrapper execRemoveWorkStation(const List<UInt64>& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_