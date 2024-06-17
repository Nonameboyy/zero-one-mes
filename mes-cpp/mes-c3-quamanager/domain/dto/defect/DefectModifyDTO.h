#pragma once

#ifndef _DEFECT_UPDATE_DTO_
#define _DEFECT_UPDATE_DTO_
#include "domain/GlobalInclude.h"
/**
 * 常规缺陷修改DTO
 */
#include OATPP_CODEGEN_BEGIN(DTO)
class DefectModifyDTO : public oatpp::DTO
{
    DTO_INIT(DefectModifyDTO, DTO);
    // 唯一标识
    API_DTO_FIELD_DEFAULT(UInt64, defect_id, ZH_WORDS_GETTER("defect.field.defect_id"));
    // 缺陷描述
    API_DTO_FIELD_DEFAULT(String, defect_name, ZH_WORDS_GETTER("defect.field.defect_name"));
    // 检测箱类型
    API_DTO_FIELD_DEFAULT(String, index_type, ZH_WORDS_GETTER("defect.field.index_type"));
    // 缺陷等级
    API_DTO_FIELD_DEFAULT(String, defect_level, ZH_WORDS_GETTER("defect.field.defect_level"));
    // 修改时间
    API_DTO_FIELD_DEFAULT(String, update_time, ZH_WORDS_GETTER("defect.field.update_time"));
};

#include OATPP_CODEGEN_END(DTO)
#endif