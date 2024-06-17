#include "stdafx.h"
#include "WhStorageorderService.h"
#include "dao/ProchAndStorage/MaterialsInfo/WhStorageorderDAO.h"

uint64_t WhStorageorderService::addWhStorageorder(const AddWhStorageorderDTO::Wrapper& dto)
{
	//组装DO数据(将DTO转换为DO)
	AddWhStorageorderDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item_id, item_id, Item_code, item_code, Item_name, item_name,Unit_of_measure, unit_of_measure);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Quantity_recived, quantity_recived, Batch_code, batch_code, Expire_date, expire_date, Warehouse_id, warehouse_id, Warehouse_code, warehouse_code);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Location_id, location_id, Location_code, location_code, Location_name, location_name, Area_id, area_id, Area_code, area_code, Area_name, area_name)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Warehouse_name, warehouse_name, Iqc_check, iqc_check, Iqc_code, iqc_code, Iqc_id, iqc_id, Remark, remark);
	//执行数据添加
	WhStorageorderDAO dao;
	return dao.insert(data); //返回主键ID
}

bool WhStorageorderService::modifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto)
{
	//组装DO数据(将DTO转换为DO)
	ModifyWhStorageorderDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item_id, item_id, Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure, Line_id, line_id);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Quantity_recived, quantity_recived, Batch_code, batch_code, Expire_date, expire_date, Warehouse_id, warehouse_id, Warehouse_code, warehouse_code);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Location_id, location_id, Location_code, location_code, Location_name, location_name, Area_id, area_id, Area_code, area_code, Area_name, area_name)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Warehouse_name, warehouse_name, Iqc_check, iqc_check, Iqc_code, iqc_code, Iqc_id, iqc_id, Remark, remark);

	//执行数据修改
	WhStorageorderDAO dao;
	return dao.update(data) == 1; //返回是否修改正确（若修改影响了一行数据，则修改成功）
}
bool WhStorageorderService::deleteWhStorageorder(const oatpp::List<UInt64>& ids)
{
	//如果列表为空，则认为删除成功
	if (ids->empty()) {
		return true;
	}
	//执行数据删除
	WhStorageorderDAO dao;
	return dao.deleteById(ids) == ids->size(); //返回是否删除正确（若受影响行数等于ids列表大小，则删除成功）
}