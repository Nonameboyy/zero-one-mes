#pragma once
#ifndef _MATERIALPRODUCTS_DO_
#define _MATERIALPRODUCTS_DO_

#include "../DoInclude.h"


class MaterialProductsDO
{

	CC_SYNTHESIZE(uint64_t, record_id, record_id);
	CC_SYNTHESIZE(int64_t, template_id, template_id);
	CC_SYNTHESIZE(int64_t, item_id, item_id);

	CC_SYNTHESIZE(string, item_code, item_code);


	CC_SYNTHESIZE(string, item_name, item_name);


	CC_SYNTHESIZE(string, specification, specification);


	CC_SYNTHESIZE(string, unit_of_measure, unit_of_measure);


	CC_SYNTHESIZE(int, quantity_check, quantity_check);

	CC_SYNTHESIZE(int, quantity_unqualified, quantity_unqualified);

	CC_SYNTHESIZE(double, cr_rate, cr_rate);


	CC_SYNTHESIZE(double, maj_rate, maj_rate);

	CC_SYNTHESIZE(double, min_rate, min_rate);


	CC_SYNTHESIZE(string, remark, remark);


	CC_SYNTHESIZE(string, attr1, Attr1);


	CC_SYNTHESIZE(string, attr2, Attr2);


	CC_SYNTHESIZE(int, attr3, Attr3);


	CC_SYNTHESIZE(int, attr4, Attr4);



public:
	MaterialProductsDO()
	{
		record_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		quantity_check = 0;
		quantity_unqualified = 0;
		cr_rate = 0.0;
		maj_rate = 0.0;
		min_rate = 0.0;
		remark = "";
		attr1 = "";
		attr2 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
	}
};
#endif // !_MATERIALPRODUCTS_DO_