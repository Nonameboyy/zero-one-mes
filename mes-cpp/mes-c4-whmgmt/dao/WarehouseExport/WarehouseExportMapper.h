#pragma once

#ifndef _WAREHOUSE_EXPORT_MAPPER_
#define _WAREHOUSE_EXPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/WarehouseExport/WarehouseExportDO.h"
/**
 * 示例表字段匹配映射
 */
class WarehouseExportMapper : public Mapper<WarehouseExportDO>
{
public:
    WarehouseExportDO mapper(ResultSet* resultSet) const override
    {
        WarehouseExportDO data;
        data.setc_recpt_code(resultSet->getString(1));
        data.setc_recpt_name(resultSet->getString(2));
        data.setc_iqc_id(resultSet->getInt(3));
        data.setc_iqc_code(resultSet->getString(4));
        data.setc_po_code(resultSet->getString(5));
        data.setc_vendor_id(resultSet->getInt(6));
        data.setc_vendor_code(resultSet->getString(7));
        data.setc_vendor_name(resultSet->getString(8));
        data.setc_vendor_nick(resultSet->getString(9));
        data.setc_warehouse_id(resultSet->getInt(10));
        data.setc_warehouse_code(resultSet->getString(11));
        data.setc_warehouse_name(resultSet->getString(12));
        data.setc_location_id(resultSet->getInt(13));
        data.setc_location_code(resultSet->getString(14));
        data.setc_location_name(resultSet->getString(15));
        data.setc_area_id(resultSet->getInt(16));
        data.setc_area_code(resultSet->getString(17));
        data.setc_area_name(resultSet->getString(18));
        data.setc_recpt_date(resultSet->getString(19));
        data.setc_status(resultSet->getString(20));
        return data;
    }

};
#endif // !_WAREHOUSE_EXPORT_MAPPER_