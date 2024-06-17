#pragma once
#ifndef _INSPECT_QUERY_
#define _INSPECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询来料检验表信息的数据传输模型
 */
class InspectQuery : public PageQuery
{
	DTO_INIT(InspectQuery, PageQuery);
	
	// 来料检验单编号
	API_DTO_FIELD_DEFAULT(String, iqc_code, ZH_WORDS_GETTER("inspect.iqc_code"));
	// 供应商编码
	API_DTO_FIELD_DEFAULT(String, vendor_code, ZH_WORDS_GETTER("inspect.vendor_code"));
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, vendor_name, ZH_WORDS_GETTER("inspect.vendor_name"));
	//供应商批次号
	API_DTO_FIELD_DEFAULT(String, vendor_batch, ZH_WORDS_GETTER("inspect.vendor_batch"));
	//产品物料编码
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("inspect.item_code"));
	//产品物料名称
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("inspect.item_name"));
	//检测结果
	API_DTO_FIELD_DEFAULT(String, check_result, ZH_WORDS_GETTER("inspect.check_result"));
	//来料日期
	API_DTO_FIELD_DEFAULT(String, recive_date, ZH_WORDS_GETTER("inspect.recive_date"));
	//检测日期
	API_DTO_FIELD_DEFAULT(String, inspect_date, ZH_WORDS_GETTER("inspect.inspect_date"));
	//检测人员
	API_DTO_FIELD_DEFAULT(String, inspector, ZH_WORDS_GETTER("inspect.inspector"));

};

//查看报表
class Inspect_tableQuery :public oatpp::DTO
{
	DTO_INIT(Inspect_tableQuery, DTO);
	// 来料检验表主键id
	API_DTO_FIELD_DEFAULT(Int64, iqc_id, ZH_WORDS_GETTER("inspect.iqc_id"));
};

//
#include OATPP_CODEGEN_END(DTO)
#endif // !_INSPECT_QUERY_
