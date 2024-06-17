#pragma once
#ifndef _WORKFIXTUREFORWORKSTATION_DTO_H_
#define _WORKFIXTUREFORWORKSTATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工作站内工装夹具数据模型
 */
class AddWorkFixtureForWorkStationDTO : public oatpp::DTO 
{
	DTO_INIT(AddWorkFixtureForWorkStationDTO, DTO); //初始化
	API_DTO_FIELD(String, WFForWSTypeName, ZH_WORDS_GETTER("wf_for_ws.fields.workstationId"), true, "");
	//类型名称，必传参数，默认值为""
	API_DTO_FIELD(UInt64, WFForWSAccount, ZH_WORDS_GETTER("wf_for_ws.fields.workstationId"), true, 1);
	//数量，必传参数，默认值为1
};


#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_