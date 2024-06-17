#pragma once

#ifndef _PICK_DTO_
#define _PICK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PickDTO : public oatpp::DTO
{
	DTO_INIT(PickDTO, DTO);
	
	//���ϵ�id
	API_DTO_FIELD_DEFAULT(Int64, issueId, ZH_WORDS_GETTER("pick.field.id"));
	//���ϵ����
	API_DTO_FIELD_DEFAULT(String, issueCode, ZH_WORDS_GETTER("pick.field.icode"));
	//���ϵ�����
	API_DTO_FIELD_DEFAULT(String, issueName, ZH_WORDS_GETTER("pick.field.iname"));
	//��������
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("pick.field.ctime"));
	//���ϲֿ�
	API_DTO_FIELD_DEFAULT(String, warehouseName, ZH_WORDS_GETTER("pick.field.whname"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("pick.field.status"));
	//��������
	API_DTO_FIELD_DEFAULT(String, workorderCode, ZH_WORDS_GETTER("pick.field.wocode"));
	//�ͻ����
	API_DTO_FIELD_DEFAULT(String, clientCode, ZH_WORDS_GETTER("pick.field.cltcode"));
	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, clientName, ZH_WORDS_GETTER("pick.field.cltname"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("pick.field.remark"));
};

/**
 * ʾ����ҳ�������
 */
class PickPageDTO : public PageDTO<PickDTO::Wrapper>
{
	DTO_INIT(PickPageDTO, PageDTO<PickDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PICK_DTO_