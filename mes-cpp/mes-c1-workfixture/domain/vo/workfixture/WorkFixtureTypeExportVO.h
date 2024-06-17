#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/18

*/
#ifndef _EXPORTVO_H_
#define _EXPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/workfixture/WorkFixtureTypeExportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WorkFixtureTypeExportJsonVO : public JsonVO<WorkFixtureTypeExportDTO::Wrapper> {
	DTO_INIT(WorkFixtureTypeExportJsonVO, JsonVO<WorkFixtureTypeExportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTVO_H_