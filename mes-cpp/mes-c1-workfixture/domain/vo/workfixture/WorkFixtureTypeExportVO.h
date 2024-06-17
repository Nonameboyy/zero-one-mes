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
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class WorkFixtureTypeExportJsonVO : public JsonVO<WorkFixtureTypeExportDTO::Wrapper> {
	DTO_INIT(WorkFixtureTypeExportJsonVO, JsonVO<WorkFixtureTypeExportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTVO_H_