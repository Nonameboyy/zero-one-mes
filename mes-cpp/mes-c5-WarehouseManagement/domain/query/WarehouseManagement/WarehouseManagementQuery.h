#pragma once

#ifndef _WAREHOUSEMANAGEMENT_QUERY_
#define _WAREHOUSEMANAGEMENT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//��ҳ��ѯ����
class WarehouseManagementQuery : public PageQuery
{
	DTO_INIT(WarehouseManagementQuery, PageQuery);

	//��Ʒ����id
	DTO_FIELD(UInt64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_id");
	}

	//��Ʒ���ϱ���
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_code");
	}

	// ��Ʒ��������
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_name");
	}

	// ����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.specification");
	}

	// ��λ
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.unit_of_measure");
	}

	// ������κ�
	DTO_FIELD(String, batch_code);
	DTO_FIELD_INFO(batch_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.batch_code");
	}

	//�ֿ�����
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.warehouse_name");
	}

	// ��������
	DTO_FIELD(String, location_name);
	DTO_FIELD_INFO(location_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.location_name");
	}

	// ��λ����
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.area_name");
	}

	// ��Ӧ�̱��
	DTO_FIELD(String, vendor_code);
	DTO_FIELD_INFO(vendor_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.vendor_code");
	}

	// ��Ӧ������
	DTO_FIELD(String, vendor_name);
	DTO_FIELD_INFO(vendor_name) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.vendor_name");
	}

	// ��Ӧ�̼��
	DTO_FIELD(String, vendor_nick);
	DTO_FIELD_INFO(vendor_nick) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.vendor_nick");
	}

	// �����������
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.workorder_code");
	}

	// ��������
	DTO_FIELD(String, recpt_date);
	DTO_FIELD_INFO(recpt_date) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.recpt_date");
	}

	// �����Ч��
	DTO_FIELD(String, expire_date);
	DTO_FIELD_INFO(expire_date) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.expire_date");
	}



};

class WarehouseManagementIdQuery : public PageQuery
{
	DTO_INIT(WarehouseManagementIdQuery, PageQuery);
	//��Ʒ����id
	DTO_FIELD(UInt64, item_id);
	DTO_FIELD_INFO(item_id) {
		info->description = ZH_WORDS_GETTER("WarehouseManagement.field.item_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WAREHOUSEMANAGEMENT_QUERY_