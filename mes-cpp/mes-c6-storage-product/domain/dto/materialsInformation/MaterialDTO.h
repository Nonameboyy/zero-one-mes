#pragma once
#ifndef _MATERIAL_DTO_
#define _MATERIAL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ�Ĵ������
 */
class MaterialDTO : public oatpp::DTO
{
	DTO_INIT(MaterialDTO, DTO);
	// ���
	DTO_FIELD(UInt64, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("Material.field.id");
	}
	// ���ϵ�ID
	DTO_FIELD(UInt64, issue_id);
	DTO_FIELD_INFO(issue_id) {
		info->description = ZH_WORDS_GETTER("Material.field.issue_id");
	}
	// ��Ʒ����ID
	DTO_FIELD(UInt64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("Material.field.item_id");
	}
	// ��Ʒ���ϱ���
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("Material.field.item_code");
	}
	// ��Ʒ��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("Material.field.item_name");
	}
	// ����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("Material.field.specification");
	}

	// ��λ
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("Material.field.unit_of_measure");
	}

	// ��������
	DTO_FIELD(Float64, quantity_issued);
	DTO_FIELD_INFO(quantity_issued) {
		info->description = ZH_WORDS_GETTER("Material.field.quantity_issued");
	}
	// ���κ�
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("Material.field.batch_code");
	}
	// �ֿ�����
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("Material.field.warehouse_name");
	}
	// ��������
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("Material.field.location_name");
	}
	// ��λ����
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("Material.field.area_name");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("Material.field.remark");
	}
};

/**
 * ʾ����ҳ�������
 */
class MaterialPageDTO : public PageDTO<MaterialDTO::Wrapper>
{
	DTO_INIT(MaterialPageDTO, PageDTO<MaterialDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MATERIAL_DTO_