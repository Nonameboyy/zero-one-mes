#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTQUERY_H_
#define _PLANSUBJECTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �豸���/�������� ��ѯ��������
 */
class PlanSubjectQuery : public PageQuery
{
	DTO_INIT(PlanSubjectQuery, DTO);

	//��Ŀ��ţ���ϸչ��
	API_DTO_FIELD_DEFAULT(String, subCode, ZH_WORDS_GETTER("planSubject.fields.subCode"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subName, ZH_WORDS_GETTER("planSubject.fields.subName"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subType, ZH_WORDS_GETTER("planSubject.fields.subType"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // 
