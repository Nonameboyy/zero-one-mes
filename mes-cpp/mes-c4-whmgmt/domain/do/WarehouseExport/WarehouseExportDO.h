#pragma once
#ifndef _WAREHOUSING_EXPORT_DO_
#define _WAREHOUSING_EXPORT_DO_
#include "../DoInclude.h"

/**
 * 物料入库单传输对象
 */
class WarehouseExportDO
{
    CC_SYNTHESIZE(string, recpt_code, c_recpt_code);
    CC_SYNTHESIZE(string, recpt_name, c_recpt_name);
    CC_SYNTHESIZE(int, iqc_id, c_iqc_id);
    CC_SYNTHESIZE(string, iqc_code, c_iqc_code);
    CC_SYNTHESIZE(string, po_code, c_po_code);
    CC_SYNTHESIZE(int, vendor_id, c_vendor_id);
    CC_SYNTHESIZE(string, vendor_code, c_vendor_code);
    CC_SYNTHESIZE(string, vendor_name, c_vendor_name);
    CC_SYNTHESIZE(string, vendor_nick, c_vendor_nick);
    CC_SYNTHESIZE(int, warehouse_id, c_warehouse_id);
    CC_SYNTHESIZE(string, warehouse_code, c_warehouse_code);
    CC_SYNTHESIZE(string, warehouse_name, c_warehouse_name);
    CC_SYNTHESIZE(int, location_id, c_location_id);
    CC_SYNTHESIZE(string, location_code, c_location_code);
    CC_SYNTHESIZE(string, location_name, c_location_name);
    CC_SYNTHESIZE(int, area_id, c_area_id);
    CC_SYNTHESIZE(string, area_code, c_area_code);
    CC_SYNTHESIZE(string, area_name, c_area_name);
    CC_SYNTHESIZE(string, recpt_date, c_recpt_date);
    CC_SYNTHESIZE(string, status, c_status);
public:
    WarehouseExportDO() {
        recpt_code = "";
        recpt_name = "";
        iqc_id = 0;
        iqc_code = "";
        po_code = "";
        vendor_id = 0;
        vendor_code = "";
        vendor_name = "";
        vendor_nick = "";
        warehouse_id = 0;
        warehouse_code = "";
        warehouse_name = "";
        location_id = 0;
        location_code = "";
        location_name = "";
        area_id = 0;
        area_code = "";
        area_name = "";
        recpt_date = "";
        status = "";
    }
};
#endif // !_WAREHOUSING_EXPORT_DO_