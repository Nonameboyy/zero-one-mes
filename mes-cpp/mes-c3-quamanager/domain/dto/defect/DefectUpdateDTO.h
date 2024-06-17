#pragma once

#ifndef _DEFECTUPDATE_DTO_
#define _DEFECTUPDATE_DTO_
#include "../../GlobalInclude.h"
/**
 * 常规缺陷修改DTO
 */
#include OATPP_CODEGEN_BEGIN(DTO)
class DefectUpdateDTO : public oatpp::DTO
{
    DTO_INIT(DefectUpdateDTO, DTO);
    // 唯一标识
    API_DTO_FIELD_DEFAULT(String, defectId,
                          ZH_WORDS_GETTER("defect.field.defectId"));
    // 缺陷描述
    API_DTO_FIELD_DEFAULT(String, defectName,
                          ZH_WORDS_GETTER("defect.field.defectName"));
    // 检测箱类型
    API_DTO_FIELD_DEFAULT(String, indexType,
                          ZH_WORDS_GETTER("defect.field.indexType"));
    // 缺陷等级
    API_DTO_FIELD_DEFAULT(String, defectLevel,
                          ZH_WORDS_GETTER("defect.field.defectLevel"));
};

#include OATPP_CODEGEN_END(DTO)
#endif