#pragma once
#ifndef _REJECT_DTO_
#define _REJECT_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * �����б�����ģ��
 */
class RejectTableDTO : public oatpp::DTO
{
	DTO_INIT(RejectTableDTO, DTO);
	// ���ϵ�id��Ψһ��
	API_DTO_FIELD(UInt64, rt_id, ZH_WORDS_GETTER("reject.fields.id"), true,1);
	// ���ϵ����
	API_DTO_FIELD(String, rt_code, ZH_WORDS_GETTER("reject.fields.rt_code"), true, "rt_code");
	// ���ϵ�����
	API_DTO_FIELD(String,rt_name, ZH_WORDS_GETTER("reject.fields.rt_name"), true, "rt_name");
	// ��������id
	API_DTO_FIELD(String, workorder_id, ZH_WORDS_GETTER("reject.fields.workorder_id"), true, "workorder_id");
	// �ֿ�����
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("reject.fields. warehouse_name"), true, " warehouse_name");
	//��������
	API_DTO_FIELD(String, location_name, ZH_WORDS_GETTER("reject.fields.location_name"), true, "01star");
	//��λ����
	API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("reject.fields.area_name"), true, "01star");
	//��������
	API_DTO_FIELD(String, rt_date, ZH_WORDS_GETTER("reject.fields.rt_date"), true, "2024-05-17 00:29:30");
	//����״̬
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("reject.fields.status"), true, "default");
};

/**
 * ������������ģ��
 */
class RejectDetailDTO : public RejectTableDTO
{
	DTO_INIT(RejectDetailDTO, RejectTableDTO);
	// .......
	// ������������
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("reject.fields.workorder_code"), true, "workorder_code");
	//�ֿ�id
	API_DTO_FIELD(String, warehouse_id, ZH_WORDS_GETTER("reject.fields.warehouse_idbh"), true, "warehouse_id");
	//�ֿ����
	API_DTO_FIELD(String,warehouse_code , ZH_WORDS_GETTER("reject.fields.warehouse_code"), true, "warehouse_code");
	//����id
	 API_DTO_FIELD(String, location_id, ZH_WORDS_GETTER("reject.fields.location_id"), true, "location_id");
	//��������
	 API_DTO_FIELD(String, location_code, ZH_WORDS_GETTER("reject.fields.location_code"), true, "location_code");
	//��λid
	 API_DTO_FIELD(String, area_id, ZH_WORDS_GETTER("reject.fieldsarea_id"), true, "area_id");
	//��λ����
	 API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("reject.fields.area_code"), true, "area_code");
	 //...

	//���ղֿ�
	API_DTO_FIELD(String, rsname, ZH_WORDS_GETTER("reject.fields.receivedstorage"), true, "receivedstorage");

	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("reject.fields.remark"), true, "remark");
};

/**
 * �����б��ҳ�������
 */
class RejectPageDTO : public PageDTO<RejectTableDTO::Wrapper>
{
	DTO_INIT(RejectPageDTO, PageDTO<RejectTableDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_#pragma once
