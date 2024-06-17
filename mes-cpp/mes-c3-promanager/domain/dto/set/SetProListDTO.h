#pragma once

#ifndef _SETPROLIST_DTO_
#define _SETPROLIST_DTO_
#include "../../GlobalInclude.h"
/**
* ��ȡ�������б�����+��ҳ������ӹ�����
*/
#include OATPP_CODEGEN_BEGIN(DTO)
class SetProListDTO : public oatpp::DTO
{
	DTO_INIT(SetProListDTO, DTO);
	//����ID
	API_DTO_FIELD(UInt64, contentId, ZH_WORDS_GETTER("set.fields.contentid"), true, 229);
	//����ID,��ʶ
	API_DTO_FIELD(UInt64, processId, ZH_WORDS_GETTER("set.fields.processid"), true, 283);
	//˳�����
	API_DTO_FIELD(Int32, orderNum, ZH_WORDS_GETTER("set.fields.ordernum"), true, 1);
	//�����豸
	API_DTO_FIELD(String, device, ZH_WORDS_GETTER("set.fields.device"), true, "");
	//��������
	API_DTO_FIELD(String, material, ZH_WORDS_GETTER("set.fields.material"), true, "");
	////����URL
	API_DTO_FIELD(String, docUrl, ZH_WORDS_GETTER("set.fields.docurl"), true, "");
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("set.fields.remark"), true, "");
	//����˵��
	API_DTO_FIELD(String, contentText, ZH_WORDS_GETTER("set.fields.contenttext"), true, "");

};
class SetProListPageDTO : public PageDTO<SetProListDTO::Wrapper>
{
	DTO_INIT(SetProListPageDTO, PageDTO<SetProListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_