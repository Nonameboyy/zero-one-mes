#pragma once
#ifndef _AWAITINSPECTION_DO_
#define _AWAITINSPECTION_DO_

#include "../DoInclude.h"

class AwaitinSpectionDO
{
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	CC_SYNTHESIZE(string, feedback_code, Feedback_code);
	CC_SYNTHESIZE(string, feedback_type, Feedback_type);
	CC_SYNTHESIZE(string, item_code, Item_code);
	CC_SYNTHESIZE(string, item_name, Item_name);
	CC_SYNTHESIZE(double, quantity_uncheck, Quantity_uncheck);
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);

public:
	AwaitinSpectionDO()
	{
		record_id = 0;
		feedback_code = "";
		feedback_type = "";
		item_code = "";
		item_name = "";
		quantity_uncheck = 0.0;
		workstation_name = "";
	}

};

#endif // !_AWAITINSPECTION_DO_