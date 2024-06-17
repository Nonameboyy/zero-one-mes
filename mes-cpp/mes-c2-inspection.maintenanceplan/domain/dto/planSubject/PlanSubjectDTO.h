#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTDTO_H_
#define _PLANSUBJECTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *    ���/�����ƻ����б�����ģ��
 */
class PlanSubjectTableDTO : public oatpp::DTO
{
	DTO_INIT(PlanSubjectTableDTO, DTO);
	//�����ⲿ��ʾ�ģ�������id
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("planSubject.fields.subId"));
	//��Ŀ��ţ���ϸ����չ��
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("planSubject.fields.subCode"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("planSubject.fields.subName"));
	//��Ŀ���� ��ֻ�����֣�
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("planSubject.fields.subType"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("planSubject.fields.subContent"));
	//��׼
	API_DTO_FIELD_DEFAULT(String, standard, ZH_WORDS_GETTER("planSubject.fields.subStandard"));

};

/*
*    ���/�����ƻ����б���ϸ������ģ��
*/
class PlanSubjectDetailDTO : public PlanSubjectTableDTO
{
	DTO_INIT(PlanSubjectDetailDTO, PlanSubjectTableDTO);
	//����չ��
	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, enable, ZH_WORDS_GETTER("planSubject.fields.enable"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("planSubject.fields.remark"));
};

/**
 *    ���/�����ƻ����б����ݣ���ҳ�������
 */
 class PlanSubjectTablePageDTO : public PageDTO<PlanSubjectTableDTO::Wrapper>
 {
 	DTO_INIT(PlanSubjectTablePageDTO, PageDTO<PlanSubjectTableDTO::Wrapper>);
 };

 /**
 *    ���/�����ƻ����б���ϸ�����ݣ���ҳ�������
 */
 class PlanSubjectDetailPageDTO : public PageDTO<PlanSubjectDetailDTO::Wrapper>
 {
	 DTO_INIT(PlanSubjectDetailPageDTO, PageDTO<PlanSubjectDetailDTO::Wrapper>);
 };
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
