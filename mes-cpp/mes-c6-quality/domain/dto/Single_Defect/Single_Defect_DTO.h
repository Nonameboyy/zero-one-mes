#pragma once
#ifndef Single_Defect_DTO_H
#define Single_Defect_DTO_H

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class SingleDTO :public oatpp::DTO
{
	DTO_INIT(SingleDTO, DTO);
	//��¼ID
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("inspect.single.line_id"));
	//���鵥ID
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("inspect.single.iqc_id"));
	// �����ID
	API_DTO_FIELD_DEFAULT(UInt64, index_id, ZH_WORDS_GETTER("inspect.single.index_id"));
	//��������                  
	API_DTO_FIELD_DEFAULT(String, index_code, ZH_WORDS_GETTER("inspect.single.index_code"));
	//���������
	API_DTO_FIELD_DEFAULT(String, index_name, ZH_WORDS_GETTER("inspect.single.index_name"));
	//���������
	API_DTO_FIELD_DEFAULT(String, index_type, ZH_WORDS_GETTER("inspect.single.index_type"));
	//��⹤��
	API_DTO_FIELD_DEFAULT(String, qc_tool, ZH_WORDS_GETTER("inspect.single.qc_tool"));
	//���Ҫ��
	API_DTO_FIELD_DEFAULT(String, check_method, ZH_WORDS_GETTER("inspect.single.check_method"));
	//��׼ֵ
	API_DTO_FIELD_DEFAULT(Float64, stander_val, ZH_WORDS_GETTER("inspect.single.stander_val"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, unit_of_measure, ZH_WORDS_GETTER("inspect.single.unit_of_measure"));
	//�������
	API_DTO_FIELD_DEFAULT(Float64, threshold_max, ZH_WORDS_GETTER("inspect.single.threshold_max"));
	//�������
	API_DTO_FIELD_DEFAULT(Float64, threshold_min, ZH_WORDS_GETTER("inspect.single.threshold_min"));
	//����ȱ������
	API_DTO_FIELD_DEFAULT(Int64, cr_quantity, ZH_WORDS_GETTER("inspect.cr_quantity"));
	//����ȱ������
	API_DTO_FIELD_DEFAULT(Int64, maj_quantity, ZH_WORDS_GETTER("inspect.maj_quantity"));
	//��΢ȱ������
	API_DTO_FIELD_DEFAULT(Int64, min_quantity, ZH_WORDS_GETTER("inspect.min_quantity"));
	//����ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("inspect.single.index_remark"));
};

class SinglePageDTO : public PageDTO<SingleDTO::Wrapper>
{
	DTO_INIT(SinglePageDTO, PageDTO<SingleDTO::Wrapper>);
};

//ȱ����Ϣ
class DefectDTO : public oatpp::DTO
{
	DTO_INIT(DefectDTO, DTO);
	//ȱ��ID(Ψһ��ʶ)
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("single.record_id"));
	//���ϼ��鵥ID
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("single.iqc_id"));
	////���鵥����
	//API_DTO_FIELD_DEFAULT(String, qc_type, ZH_WORDS_GETTER("single.qc_type"));
	////���鵥ID
	//API_DTO_FIELD_DEFAULT(UInt64, qc_id, ZH_WORDS_GETTER("single.qc_id"));
	//���ϼ��鵥��ID
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("single.line"));
	//ȱ������
	API_DTO_FIELD_DEFAULT(String, defect_name, ZH_WORDS_GETTER("single.defect_name"));
	//ȱ�ݵȼ�
	API_DTO_FIELD_DEFAULT(String, defect_level, ZH_WORDS_GETTER("single.defect_level"));
	//ȱ������
	API_DTO_FIELD_DEFAULT(Int64, defect_quantity, ZH_WORDS_GETTER("single.defect_quantity"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("single.remark"));
	
};

//ȱ�ݷ�ҳ
class DefectPageDTO : public PageDTO<DefectDTO::Wrapper>
{
	DTO_INIT(DefectPageDTO, PageDTO<DefectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Single_Defect_DTO_H
