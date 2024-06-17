#pragma once
#ifndef _SINGLE_VO_
#define _SINGLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Single_Defect/Single_Defect_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾ�����JsonVO��������Ӧ���ͻ��˵�Json����
 */
class SingleJsonVO : public JsonVO<SingleDTO::Wrapper> {
	DTO_INIT(SingleJsonVO, JsonVO<SingleDTO::Wrapper>);
};

/**
 * ��ҳ�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SinglePageJsonVO : public JsonVO<SinglePageDTO::Wrapper> {
	DTO_INIT(SinglePageJsonVO, JsonVO<SinglePageDTO::Wrapper>);
};

/**
 * ��ʾȱ��JsonVO��������Ӧ���ͻ��˵�Json����
 */
class DefectJsonVO : public JsonVO<DefectDTO::Wrapper> {
	DTO_INIT(DefectJsonVO, JsonVO<DefectDTO::Wrapper>);
};

/**
 * ��ҳ��ʾȱ��JsonVO��������Ӧ���ͻ��˵�Json����
 */
class DefectPageJsonVO : public JsonVO<DefectPageDTO::Wrapper> {
	DTO_INIT(DefectPageJsonVO, JsonVO<DefectPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SINGLE_VO_
