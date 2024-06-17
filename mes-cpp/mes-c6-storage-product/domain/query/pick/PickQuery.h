#pragma once

#ifndef _PICK_QUERY_
#define _PICK_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class PickQuery : public PageQuery
{
	DTO_INIT(PickQuery, PageQuery);
	//领料单编号
	API_DTO_FIELD_DEFAULT(String, issueCode, ZH_WORDS_GETTER("pick.field.icode"));
	//领料单名称
	API_DTO_FIELD_DEFAULT(String, issueName, ZH_WORDS_GETTER("pick.field.iname"));
	//领料日期
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("pick.field.ctime"));
	//领料仓库
	API_DTO_FIELD_DEFAULT(String, warehouseName, ZH_WORDS_GETTER("pick.field.whname"));
	//单据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("pick.field.status"));
	//生产工单
	API_DTO_FIELD_DEFAULT(String, workorderCode, ZH_WORDS_GETTER("pick.field.wocode"));
	//客户编号
	API_DTO_FIELD_DEFAULT(String, clientCode, ZH_WORDS_GETTER("pick.field.cltcode"));
	//客户名称
	API_DTO_FIELD_DEFAULT(String, clientName, ZH_WORDS_GETTER("pick.field.cltname"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PICK_QUERY_