#include "stdafx.h"
#include "WarehouseExportService.h"
#include "../../dao/WarehouseExport/WarehouseExportDAO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("wm_item_recpt.export.sheet")
#include "FastDfsClient.h"

string WarehouseExportService::WarehouseExport()
{
	std::vector<std::vector<std::string>> data;
	std::string fileName = "./public/excel/warehouse.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("wm_item_recpt.export.sheet");
	stringstream ss;
	ExcelComponent excel;
	// 构建返回对象
	WarehouseExportDAO dao;
	// 查询数据总条数
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return "";
	}
	list<WarehouseExportDO> result = dao.WarehouseExport();
	// 将DO转换成DTO
	for (WarehouseExportDO sub : result)
	{
		auto dto = WarehouseExportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, recpt_code, c_recpt_code, recpt_name, c_recpt_name, iqc_id, c_iqc_id, iqc_code, c_iqc_code, po_code, c_po_code, vendor_id, c_vendor_id, vendor_code, c_vendor_code, vendor_name, c_vendor_name, vendor_nick, c_vendor_nick);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, warehouse_id, c_warehouse_id, warehouse_code, c_warehouse_code, warehouse_name, c_warehouse_name, location_id, c_location_id, location_code, c_location_code, location_name, c_location_name, area_id, c_area_id, area_code, c_area_code, area_name, c_area_name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, recpt_date, c_recpt_date, status, c_status);

		std::vector<std::string> row;
		row.push_back(sub.getc_recpt_code());
		row.push_back(sub.getc_recpt_name());
		ss.clear();
		ss << std::to_string(sub.getc_iqc_id());
		row.push_back(ss.str());
		ss.str("");
		row.push_back(sub.getc_iqc_code());
		row.push_back(sub.getc_po_code());
		ss.clear();
		ss << std::to_string(sub.getc_vendor_id());
		row.push_back(ss.str());
		ss.str("");
		row.push_back(sub.getc_vendor_code());
		row.push_back(sub.getc_vendor_name());
		row.push_back(sub.getc_vendor_nick());
		ss.clear();
		ss << std::to_string(sub.getc_warehouse_id());
		row.push_back(ss.str());
		ss.str("");
		row.push_back(sub.getc_warehouse_code());
		row.push_back(sub.getc_warehouse_name());
		ss.clear();
		ss << std::to_string(sub.getc_location_id());
		row.push_back(ss.str());
		ss.str("");
		row.push_back(sub.getc_location_code());
		row.push_back(sub.getc_location_name());
		ss.clear();
		ss << std::to_string(sub.getc_area_id());
		row.push_back(ss.str());
		ss.str("");
		row.push_back(sub.getc_area_code());
		row.push_back(sub.getc_area_name());
		row.push_back(sub.getc_recpt_date());
		row.push_back(sub.getc_status());
		data.push_back(row);

	}
	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("wm_item_recpt.field.recpt_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.recpt_name") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.iqc_id") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.iqc_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.po_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.vendor_id") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.vendor_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.vendor_name") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.vendor_nick") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_id") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_name") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.location_id") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.location_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.location_name") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.area_id") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.area_code") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.area_name") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.recpt_date") ,
		ZH_WORDS_GETTER("wm_item_recpt.field.status") ,
		});
	excel.writeVectorToFile(fileName, sheetName, data);
	FastDfsClient f("192.168.183.128", 22122);
	//string t = f.uploadFile("./public/excel/warehouse.xlsx");
	return f.uploadFile("./public/excel/warehouse.xlsx");
}
