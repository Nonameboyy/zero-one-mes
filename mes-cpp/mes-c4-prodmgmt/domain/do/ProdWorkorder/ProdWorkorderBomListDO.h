#pragma once
#ifndef _PRODWORKORDERBOMLIST_DO_
#define _PRODWORKORDERBOMLIST_DO_
#include "../DoInclude.h"

/**
 * ��������BOM���ݿ�ʵ����
 */
class ProdWorkorderBomListDO {
	//BOM��ID;line_id;bigint
	CC_SYNTHESIZE(int, line_id, Line_id);
	//BOM���ϱ��;item_code;varchar
	CC_SYNTHESIZE(string, item_code, Item_code);
	//BOM��������;item_name;varchar
	CC_SYNTHESIZE(string, item_name, Item_name);
	//����ͺ�;item_spc;varchar
	CC_SYNTHESIZE(string, item_spc, Item_spc);
	//��λ;unit_of_measure;varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//����/��Ʒ;item_or_product;varchar
	CC_SYNTHESIZE(string, item_or_product, Item_or_product);
	//Ԥ��ʹ����;quantity;double
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