#pragma once

#ifndef _DEFECT_UPDATE_DTO_
#define _DEFECT_UPDATE_DTO_
#include "domain/GlobalInclude.h"
/**
 * ����ȱ���޸�DTO
 */
#include OATPP_CODEGEN_BEGIN(DTO)
class DefectModifyDTO : public oatpp::DTO
{
    DTO_INIT(DefectModifyDTO, DTO);
    // Ψһ��ʶ
    API_DTO_FIELD_DEFAULT(UInt64, defect_id, ZH_WORDS_GETTER("defect.field.defect_id"));
    // ȱ������
    API_DTO_FIELD_DEFAULT(String, defect_name, ZH_WORDS_GETTER("defect.field.defect_name"));
    // ���������
    API_DTO_FIELD_DEFAULT(String, index_type, ZH_WORDS_GETTER("defect.field.index_type"));
    // ȱ�ݵȼ�
    API_DTO_FIELD_DEFAULT(String, defect_level, ZH_WORDS_GETTER("defect.field.defect_level"));
    // �޸�ʱ��
    API_DTO_FIELD_DEFAULT(String, update_time, ZH_WORDS_GETTER("defect.field.update_time"));
};

#include OATPP_CODEGEN_END(DTO)
#endif