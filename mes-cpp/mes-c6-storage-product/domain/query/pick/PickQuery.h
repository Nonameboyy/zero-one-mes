#pragma once

#ifndef _PICK_QUERY_
#define _PICK_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class PickQuery : public PageQuery
{
	DTO_INIT(PickQuery, PageQuery);
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
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PICK_QUERY_