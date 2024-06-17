#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTDTO_H_
#define _PLANSUBJECTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *    点检/保养计划，列表数据模型
 */
class PlanSubjectTableDTO : public oatpp::DTO
{
	DTO_INIT(PlanSubjectTableDTO, DTO);
	//不在外部显示的，主键，id
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("planSubject.fields.subId"));
	//项目编号，详细内联展开
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("planSubject.fields.subCode"));
	//项目名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("planSubject.fields.subName"));
	//项目类型 （只有两种）
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("planSubject.fields.subType"));
	//项目内容
	API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("planSubject.fields.subContent"));
	//标准
	API_DTO_FIELD_DEFAULT(String, standard, ZH_WORDS_GETTER("planSubject.fields.subStandard"));

};

/*
*    点检/保养计划，列表（详细）数据模型
*/
class PlanSubjectDetailDTO : public PlanSubjectTableDTO
{
	DTO_INIT(PlanSubjectDetailDTO, PlanSubjectTableDTO);
	//【扩展】
	//是否启用
	API_DTO_FIELD_DEFAULT(String, enable, ZH_WORDS_GETTER("planSubject.fields.enable"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("planSubject.fields.remark"));
};

/**
 *    点检/保养计划，列表数据，分页传输对象
 */
 class PlanSubjectTablePageDTO : public PageDTO<PlanSubjectTableDTO::Wrapper>
 {
 	DTO_INIT(PlanSubjectTablePageDTO, PageDTO<PlanSubjectTableDTO::Wrapper>);
 };

 /**
 *    点检/保养计划，列表（详细）数据，分页传输对象
 */
 class PlanSubjectDetailPageDTO : public PageDTO<PlanSubjectDetailDTO::Wrapper>
 {
	 DTO_INIT(PlanSubjectDetailPageDTO, PageDTO<PlanSubjectDetailDTO::Wrapper>);
 };
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
