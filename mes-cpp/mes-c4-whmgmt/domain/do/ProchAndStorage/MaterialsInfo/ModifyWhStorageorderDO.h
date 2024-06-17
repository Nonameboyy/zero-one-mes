#pragma once
#ifndef _MODIFYWHSTORAGEORDER_DO_
#define _MODIFYWHSTORAGEORDER_DO_
/*
修改入库单行的数据库实体类
*/
#include "../../DoInclude.h"
class ModifyWhStorageorderDO
{
	//行ID line_id bigint
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	//产品物料ID item_id bigint
	CC_SYNTHESIZE(uint64_t, item_id, Item_id);
	//物料编码 item_code varchar
	CC_SYNTHESIZE(string, item_code, Item_code);
	//物料名称 item_name varchar
	CC_SYNTHESIZE(string, item_name, Item_name);

	//单位 unit_of_measure varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//入库数量 quantity_recived double
	CC_SYNTHESIZE(double, quantity_recived, Quantity_recived);
	//入库批次号 batch_code varchar
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	//有效期 expire_date String
	CC_SYNTHESIZE(string, expire_date, Expire_date);

	//仓库ID warehouse_id bigint
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_id);
	//仓库编码 warehouse_code varchar
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//仓库名称 warehouse_name varchar
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);

	//库区ID location_id bigint
	CC_SYNTHESIZE(uint64_t, location_id, Location_id);
	//库区编码 location_code varchar
	CC_SYNTHESIZE(string, location_code, Location_code);
	//库区名称 location_name varchar
	CC_SYNTHESIZE(string, location_name, Location_name);

	//库位ID area_id bigint
	CC_SYNTHESIZE(uint64_t, area_id, Area_id);
	//库位编码 area_code varchar
	CC_SYNTHESIZE(string, area_code, Area_code);
	//库位名称 area_name varchar
	CC_SYNTHESIZE(string, area_name, Area_name);

	//是否检验 iqc_check char
	CC_SYNTHESIZE(string, iqc_check, Iqc_check);
	//来料检验单编码 iqc_code varchar
	CC_SYNTHESIZE(string, iqc_code, Iqc_code);
	//来料检验单ID iqc_id bigint
	CC_SYNTHESIZE(uint64_t, iqc_id, Iqc_id);
	//备注 remark varchar
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ModifyWhStorageorderDO() {
		line_id = 0;
		item_id = 1;
		item_code = "";
		item_name = "";

		unit_of_measure = "";
		quantity_recived = 0.00;
		batch_code = "";
		expire_date = "";

		warehouse_id = 0;
		warehouse_code = "";
		warehouse_name = "";

		location_id = 0;
		location_code = "";
		location_name = "";

		area_id = 0;
		area_code = "";
		area_name = "";

		iqc_check = "";
		iqc_code = "";
		iqc_id = 0;
		remark = "";
	}
};
#endif // !_MODIFYWHSTORAGEORDER_DO_
