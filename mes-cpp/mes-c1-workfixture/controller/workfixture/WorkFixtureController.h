#pragma once
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/workfixture/WorkFixtureQuery.h"
#include "domain/dto/workfixture/WorkFixtureDTO.h"
#include "domain/vo/workfixture/WorkFixtureVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 工装夹具列表管理控制器
*/
class WorkFixtureController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(WorkFixtureController);
public:
	// 1. 定义列表查询接口描述
	ENDPOINT_INFO(queryWorkFixtureTable) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workfixture.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkFixtureJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "toolCode", ZH_WORDS_GETTER("workfixture.fields.code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "toolName", ZH_WORDS_GETTER("workfixture.fields.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(Int64, "toolTypeId", ZH_WORDS_GETTER("workfixture.type.fields.id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "toolTypeCode", ZH_WORDS_GETTER("workfixture.type.fields.code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "toolTypeName", ZH_WORDS_GETTER("workfixture.type.fields.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "brand", ZH_WORDS_GETTER("workfixture.fields.brand"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "spec", ZH_WORDS_GETTER("workfixture.fields.spec"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("workfixture.fields.status"), "", false);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/tm/workfixture/query", queryWorkFixtureTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, WorkFixtureQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryWorkFixtureTable(query));
	}
	// 1.1 定义工装夹具详情获取接口描述和接口处理
	ENDPOINT_INFO(queryWorkFixtureDetail) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("workfixture.query.detail"), WorkFixtureDetailJsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/tm/workfixture/query/detail", queryWorkFixtureDetail, QUERY(UInt64, id), execQueryWorkFixtureDetail(id));

	// 2. 定义新增接口描述
	ENDPOINT_INFO(addWorkFixture) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workfixture.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 注：POST和PUT方法都是通过请求体而不是url传入参数，因此只有GET方法需要定义查询/路径参数（只有GET是通过url传入参数）
	}
	// 定义新增接口处理
	ENDPOINT(API_M_POST, "/tm/workfixture/add", addWorkFixture, BODY_DTO(WorkFixtureDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddWorkFixture(dto));
	}

	// 3. 定义修改接口描述和处理
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("workfixture.modify.summary"), modifyWorkFixture, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/tm/workfixture/modify", modifyWorkFixture, BODY_DTO(WorkFixtureDTO::Wrapper, dto), execModifyWorkFixture(dto));

	// 4. 定义删除接口描述和处理
	ENDPOINT_INFO(removeWorkFixture) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("workfixture.remove.summary"), Uint64JsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/tm/workfixture/remove", removeWorkFixture, BODY_DTO(List<UInt64>, id), execRemoveWorkFixture(id));

	// 5. 定义工装夹具导出接口描述和处理
	ENDPOINT_INFO(exportWorkFixture) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workfixture.export.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式（返回的字符串可以是文件下载地址，具体取决于实现）
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/tm/workfixture/export", exportWorkFixture, BODY_DTO(List<UInt64>, id), execExportWorkFixture(id));

private:
	// 查询工装夹具列表功能实现
	WorkFixtureJsonVO::Wrapper execQueryWorkFixtureTable(const WorkFixtureQuery::Wrapper &query);
	// 查询单个工装夹具详细信息
	WorkFixtureDetailJsonVO::Wrapper execQueryWorkFixtureDetail(const UInt64 id);
	// 添加工装夹具功能实现
	Uint64JsonVO::Wrapper execAddWorkFixture(const WorkFixtureDTO::Wrapper &dto);
	// 修改工装夹具信息功能实现
	Uint64JsonVO::Wrapper execModifyWorkFixture(const WorkFixtureDTO::Wrapper &dto);
	// 删除工装夹具功能实现
	Uint64JsonVO::Wrapper execRemoveWorkFixture(const List<UInt64> &id);
	// 导出工装夹具功能实现（说明：由于支持批量导出，因此要通过传入的id列表到数据库查找到相应数据集并导出为Excel文件）
	StringJsonVO::Wrapper execExportWorkFixture(const List<UInt64> &id);
};

#include OATPP_CODEGEN_END(ApiController)