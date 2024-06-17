#pragma once

#ifndef _MDPRODUCTBOM_DO_
#define _MDPRODUCTBOM_DO_
#include "../DoInclude.h"

/**
 * md_product_bom���ݿ�ʵ����
 */
class MdProductBomDO
{
	//���ϲ�ƷID
	CC_SYNTHESIZE(uint64_t, item_id, ItemId);
	//BOM����ID
	CC_SYNTHESIZE(uint64_t, bom_item_id, BomItemId);
	//BOM���ϱ��
	CC_SYNTHESIZE(string, bom_item_code, BomItemCode);
	//BOM��������
	CC_SYNTHESIZE(string, bom_item_name, BomItemName);
	//����ͺ�
	CC_SYNTHESIZE(string, bom_item_spec, BomItemSpc);
	//��λ
	CC_SYNTHESIZE(string, unit_of_measure, UnitOfMeasure);
	//���ϲ�Ʒ��ʶ
	CC_SYNTHESIZE(string, item_or_product, ItemOrProduct);
	//����ʹ�ñ���
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
