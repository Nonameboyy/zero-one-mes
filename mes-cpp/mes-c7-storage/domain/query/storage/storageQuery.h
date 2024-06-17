#pragma once
#ifndef _storage_QUERY_
#define _storage_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class storageQuery : public PageQuery
{
	DTO_INIT(storageQuery, PageQuery);
	// ��Ʒ��ⵥID
	DTO_FIELD(UInt64, re_id);
	DTO_FIELD_INFO(re_id) {
		info->description = ZH_WORDS_GETTER("storage.field.re_id");
	}

	//��Ʒ��ⵥ���
	DTO_FIELD(String, re_code);
	DTO_FIELD_INFO(re_code) {
		info->description = ZH_WORDS_GETTER("storage.field.re_code");
	}

	// ��Ʒ��ⵥ����
	DTO_FIELD(String, re_name);
	DTO_FIELD_INFO(re_name) {
		info->description = ZH_WORDS_GETTER("storage.field.re_name");
	}

	//��������ID
	DTO_FIELD(UInt64, workorder_id);
	DTO_FIELD_INFO(workorder_id) {
		info->description = ZH_WORDS_GETTER("storage.field.workororder_id");
	}

	// �����������
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("storage.field.workororder_code");
	}


	// ���ղֿ�ID
	DTO_FIELD(UInt64, warehouse_id);
	DTO_FIELD_INFO(warehouse_id) {
		info->description = ZH_WORDS_GETTER("storage.field.warehouse_id");
	}
	// ���ղֿ����
	DTO_FIELD(String, warehouse_code);
	DTO_FIELD_INFO(warehouse_code) {
		info->description = ZH_WORDS_GETTER("storage.field.warehouse_code");
	}
	// ���ղֿ�����
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("storage.field.warehouse_name");
	}

	// ����ID
	DTO_FIELD(UInt64, location_id);
	DTO_FIELD_INFO(location_id) {
		info->description = ZH_WORDS_GETTER("storage.field.location_id");
	}
	// ��������
	DTO_FIELD(String, location_code);
	DTO_FIELD_INFO(location_code) {
		info->description = ZH_WORDS_GETTER("storage.field.location_code");
	}
	// ��������
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("storage.field.location_name");
	}

	// ��λID
	DTO_FIELD(UInt64, area_id);
	DTO_FIELD_INFO(area_id) {
		info->description = ZH_WORDS_GETTER("storage.field.area_id");
	}
	// ��λ����
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("storage.field.area_code");
	}
	// ��λ����
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("storage.field.area_name");
	}

	//��Ʒ��������
	DTO_FIELD(String, re_date);
	DTO_FIELD_INFO(re_date) {
		info->description = ZH_WORDS_GETTER("storage.field.re_date");
	}
	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("storage.field.remark");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 