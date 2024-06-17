#pragma once
#ifndef _INSPECTDTO_H
#define _INSPECTDTO_H

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ϼ��鵥�б����ݴ������
 */
class InspectDTO:public oatpp::DTO
{
	DTO_INIT(InspectDTO, DTO);
	// ���ݿ����id
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("inspect.iqc_id"));
	// ���ϼ��鵥���
	API_DTO_FIELD_DEFAULT(String, iqc_code, ZH_WORDS_GETTER("inspect.iqc_code"));
	// ���ϼ��鵥����
	API_DTO_FIELD_DEFAULT(String, iqc_name, ZH_WORDS_GETTER("inspect.iqc_name"));
	//����ģ��ID
	API_DTO_FIELD_DEFAULT(UInt64, template_id, ZH_WORDS_GETTER("inspect.template_id"));
	//��Ӧ��ID
	API_DTO_FIELD_DEFAULT(UInt64, vendor_id, ZH_WORDS_GETTER("inspect.vendor_id"));
	// ��Ӧ�̱���
	API_DTO_FIELD_DEFAULT(String, vendor_code, ZH_WORDS_GETTER("inspect.vendor_code"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendor_name, ZH_WORDS_GETTER("inspect.vendor_name"));
	// ��Ӧ�̼��
	API_DTO_FIELD_DEFAULT(String, vendor_nick, ZH_WORDS_GETTER("inspect.vendor_nick"));
	//��Ӧ�����κ�
	API_DTO_FIELD_DEFAULT(String, vendor_batch, ZH_WORDS_GETTER("inspect.vendor_batch"));
	//��Ʒ����ID
	API_DTO_FIELD_DEFAULT(Int64, item_id, ZH_WORDS_GETTER("inspect.item_id"));
	//��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("inspect.item_code"));
	//��Ʒ��������
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("inspect.item_name"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, unit_of_measure, ZH_WORDS_GETTER("inspect.unit_of_measure"));
	//��������
	API_DTO_FIELD_DEFAULT(Float64, quantity_recived, ZH_WORDS_GETTER("inspect.quantity_recived"));
	//�������
	API_DTO_FIELD_DEFAULT(Int64, quantity_check, ZH_WORDS_GETTER("inspect.quantity_check"));
	//���ϸ���
	API_DTO_FIELD_DEFAULT(Int64, quantity_unqualified, ZH_WORDS_GETTER("inspect.quantity_unqualified"));
	//�����
	API_DTO_FIELD_DEFAULT(String, check_result, ZH_WORDS_GETTER("inspect.check_result"));
	//��������
	API_DTO_FIELD_DEFAULT(String, recive_date, ZH_WORDS_GETTER("inspect.recive_date"));
	//�������
	API_DTO_FIELD_DEFAULT(String, inspect_date, ZH_WORDS_GETTER("inspect.inspect_date"));
	//�����Ա
	API_DTO_FIELD_DEFAULT(String, inspector, ZH_WORDS_GETTER("inspect.inspector"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, list_status, ZH_WORDS_GETTER("inspect.list_status"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("inspect.remark"));
	
};

//���ϼ����б��ҳ�������
class InspectPageDTO : public PageDTO<InspectDTO::Wrapper>
{
	DTO_INIT(InspectPageDTO, PageDTO<InspectDTO::Wrapper>);
};

class Inspect_detailDTO :public InspectDTO
{
	DTO_INIT(Inspect_detailDTO, InspectDTO);

	
	//����ȱ����
	API_DTO_FIELD_DEFAULT(Float64, maj_rate, ZH_WORDS_GETTER("inspect.maj_rate"));
	//����ȱ����
	API_DTO_FIELD_DEFAULT(Float64, cr_rate, ZH_WORDS_GETTER("inspect.cr_rate")); 
	//��΢ȱ����
	API_DTO_FIELD_DEFAULT(Float64, min_rate, ZH_WORDS_GETTER("inspect.min_rate"));
	//����ȱ������
	API_DTO_FIELD_DEFAULT(Int64, cr_quantity, ZH_WORDS_GETTER("inspect.cr_quantity"));
	//����ȱ������
	API_DTO_FIELD_DEFAULT(Int64, maj_quantity, ZH_WORDS_GETTER("inspect.maj_quantity"));
	//��΢ȱ������
	API_DTO_FIELD_DEFAULT(Int64, min_quantity, ZH_WORDS_GETTER("inspect.min_quantity"));
	
};



class Inspect_tableDTO : public Inspect_detailDTO
{
	DTO_INIT(Inspect_tableDTO, Inspect_detailDTO);
};

class Item_idDTO :public oatpp::DTO
{
	DTO_INIT(Item_idDTO, DTO);
	// ���ݿ����id
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("inspect.iqc_id"));
	//�����
	API_DTO_FIELD_DEFAULT(String, check_result, ZH_WORDS_GETTER("inspect.check_result"));
	////״̬
	//API_DTO_FIELD_DEFAULT(String, list_status, ZH_WORDS_GETTER("inspect.list_status"));
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_INSPECTDTO_H_