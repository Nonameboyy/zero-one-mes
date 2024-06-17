#pragma once

#ifndef _DEFECTUPDATE_DTO_
#define _DEFECTUPDATE_DTO_
#include "../../GlobalInclude.h"
/**
 * ����ȱ���޸�DTO
 */
#include OATPP_CODEGEN_BEGIN(DTO)
class DefectUpdateDTO : public oatpp::DTO
{
    DTO_INIT(DefectUpdateDTO, DTO);
    // Ψһ��ʶ
    API_DTO_FIELD_DEFAULT(String, defectId,
                          ZH_WORDS_GETTER("defect.field.defectId"));
    // ȱ������
    API_DTO_FIELD_DEFAULT(String, defectName,
                          ZH_WORDS_GETTER("defect.field.defectName"));
    // ���������
    API_DTO_FIELD_DEFAULT(String, indexType,
                          ZH_WORDS_GETTER("defect.field.indexType"));
    // ȱ�ݵȼ�
    API_DTO_FIELD_DEFAULT(String, defectLevel,
                          ZH_WORDS_GETTER("defect.field.defectLevel"));
};

#include OATPP_CODEGEN_END(DTO)
#endif