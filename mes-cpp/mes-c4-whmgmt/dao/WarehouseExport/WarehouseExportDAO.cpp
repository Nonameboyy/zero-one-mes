#include "stdafx.h"
#include "WarehouseExportDAO.h"
#include "WarehouseExportMapper.h"
#include <sstream> 

uint64_t WarehouseExportDAO::count()
{
	string sql = "SELECT COUNT(*) FROM pro_workorder";
	return sqlSession->executeQueryNumerical(sql);
}

std::list<WarehouseExportDO> WarehouseExportDAO::WarehouseExport()
{
	string sql="SELECT recpt_code,recpt_name,iqc_id,iqc_code,po_code,vendor_id,vendor_code,vendor_name,vendor_nick,warehouse_id,warehouse_code,warehouse_name,location_id,location_code,location_name,area_id,area_code,area_name,DATE_FORMAT(recpt_date, '%Y-%m-%d'),status FROM wm_item_recpt";
	WarehouseExportMapper mapper;
	return sqlSession->executeQuery<WarehouseExportDO, WarehouseExportMapper>(sql, mapper);
}