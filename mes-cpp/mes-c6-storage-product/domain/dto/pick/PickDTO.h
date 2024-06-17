#pragma once

#ifndef _PICK_DTO_
#define _PICK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PickDTO : public oatpp::DTO
{
	DTO_INIT(PickDTO, DTO);
	
	//领料单id
	API_DTO_FIELD_DEFAULT(Int64, issueId, ZH_WORDS_GETTER("pick.field.id"));
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
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("pick.field.remark"));
};

/**
 * 示例分页传输对象
 */
class PickPageDTO : public PageDTO<PickDTO::Wrapper>
{
	DTO_INIT(PickPageDTO, PageDTO<PickDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PICK_DTO_