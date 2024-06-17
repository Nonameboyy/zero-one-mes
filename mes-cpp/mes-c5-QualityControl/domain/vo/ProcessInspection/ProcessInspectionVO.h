#pragma once
#ifndef _PROCESSINSPECTION_VO_
#define _PROCESSINSPECTION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ProcessInspection/ProcessInspectionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessInspectionJsonVO : public JsonVO<ProcessInspectionDTO::Wrapper> {
	DTO_INIT(ProcessInspectionJsonVO, JsonVO<ProcessInspectionDTO::Wrapper>);
};

class ProcessInspectionQueryJsonVO : public JsonVO<ProcessInspectionQueryDTO::Wrapper> {
	DTO_INIT(ProcessInspectionQueryJsonVO, JsonVO<ProcessInspectionQueryDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProcessInspectionPageJsonVO : public JsonVO<ProcessInspectionPageDTO::Wrapper> {
	DTO_INIT(ProcessInspectionPageJsonVO, JsonVO<ProcessInspectionPageDTO::Wrapper>);
};

class ProcessInspectionQueryPageJsonVO : public JsonVO<ProcessInspectionQueryPageDTO::Wrapper> {
	DTO_INIT(ProcessInspectionQueryPageJsonVO, JsonVO<ProcessInspectionQueryPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINSPECTION_VO_