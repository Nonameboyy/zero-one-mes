#pragma once
#ifndef _PRODWORKORDERBOMLIST_DO_
#define _PRODWORKORDERBOMLIST_DO_
#include "../DoInclude.h"

/**
 * 生产工单BOM数据库实体类
 */
class ProdWorkorderBomListDO {
	//BOM行ID;line_id;bigint
	CC_SYNTHESIZE(int, line_id, Line_id);
	//BOM物料编号;item_code;varchar
	CC_SYNTHESIZE(string, item_code, Item_code);
	//BOM物料名称;item_name;varchar
	CC_SYNTHESIZE(string, item_name, Item_name);
	//规格型号;item_spc;varchar
	CC_SYNTHESIZE(string, item_spc, Item_spc);
	//单位;unit_of_measure;varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//物料/产品;item_or_product;varchar
	CC_SYNTHESIZE(string, item_or_product, Item_or_product);
	//预计使用量;quantity;double
	CC_SYNTHESIZE(double, quantity, Quantity);
public:
	ProdWorkorderBomListDO() {
		line_id = 0;
		item_code = "";
		item_name = "";
		item_spc = "";
		unit_of_measure = "";
		item_or_product = "";
		quantity = 0;
		
	}
};

#endif // !_PRODWORKORDERBOMLIST_DO_