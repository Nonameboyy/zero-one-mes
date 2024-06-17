#pragma once
#ifndef _WORKFIXTUREFORWORKSTATION_DTO_H_
#define _WORKFIXTUREFORWORKSTATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����վ�ڹ�װ�о�����ģ��
 */
class AddWorkFixtureForWorkStationDTO : public oatpp::DTO 
{
	DTO_INIT(AddWorkFixtureForWorkStationDTO, DTO); //��ʼ��
	API_DTO_FIELD(String, WFForWSTypeName, ZH_WORDS_GETTER("wf_for_ws.fields.workstationId"), true, "");
	//�������ƣ��ش�������Ĭ��ֵΪ""
	API_DTO_FIELD(UInt64, WFForWSAccount, ZH_WORDS_GETTER("wf_for_ws.fields.workstationId"), true, 1);
	//�������ش�������Ĭ��ֵΪ1
};


#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_