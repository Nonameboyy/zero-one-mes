#pragma once

#ifndef _MDPRODUCTBOM_DO_
#define _MDPRODUCTBOM_DO_
#include "../DoInclude.h"

/**
 * md_product_bom数据库实体类
 */
class MdProductBomDO
{
	//物料产品ID
	CC_SYNTHESIZE(uint64_t, item_id, ItemId);
	//BOM物料ID
	CC_SYNTHESIZE(uint64_t, bom_item_id, BomItemId);
	//BOM物料编号
	CC_SYNTHESIZE(string, bom_item_code, BomItemCode);
	//BOM物料名称
	CC_SYNTHESIZE(string, bom_item_name, BomItemName);
	//规格型号
	CC_SYNTHESIZE(string, bom_item_spec, BomItemSpc);
	//单位
	CC_SYNTHESIZE(string, unit_of_measure, UnitOfMeasure);
	//物料产品标识
	CC_SYNTHESIZE(string, item_or_product, ItemOrProduct);
	//物料使用比例
	CC_SYNTHESIZE(double, quantity, Quantity);
	
public:
	MdProductBomDO() {
		bom_item_id = 0;
		bom_item_code = "";
		bom_item_name = "";
		bom_item_spec = "";
		unit_of_measure = "";
		item_or_product = "";
		quantity = 0.0;
		item_id = 0;
	}
};

#endif // !_MDPRODUCTBOM_DO_
