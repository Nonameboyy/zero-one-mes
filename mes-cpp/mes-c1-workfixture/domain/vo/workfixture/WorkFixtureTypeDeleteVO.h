#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _DELETEVO_H_
#define _DELETEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workfixture/WorkFixtureTypeDeleteDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WorkFixtureTypeDeleteJsonVO : public JsonVO<WorkFixtureTypeDeleteDTO::Wrapper> {
	DTO_INIT(WorkFixtureTypeDeleteJsonVO, JsonVO<WorkFixtureTypeDeleteDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETEVO_H_