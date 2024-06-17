#pragma once
#ifndef _PROCESSLIST_VO_
#define _PROCESSLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/process/ProcessListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//�޸�
/**
 * ������ϸ��ϢVO
 */
class ProcessDetailJsonVO : public JsonVO<ProcessDTO::Wrapper> {
	DTO_INIT(ProcessDetailJsonVO, JsonVO<ProcessDTO::Wrapper>);
};

/**
 * �����б�VO
 */
class ProcessListJsonVO : public JsonVO<ProcessListDTO::Wrapper> {
	DTO_INIT(ProcessListJsonVO, JsonVO<ProcessListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_