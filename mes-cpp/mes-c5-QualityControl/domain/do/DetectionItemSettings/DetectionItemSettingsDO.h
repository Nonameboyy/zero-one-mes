#pragma once
#ifndef _DETECTIONITEMSETTINGS_DO_
#define	_DETECTIONITEMSETTINGS_DO_
#include "../DoInclude.h"

class DetectionItemSettingsDO
{
	CC_SYNTHESIZE(uint64_t, id, Id);
	CC_SYNTHESIZE(string, code, Code);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, type, Type);
	CC_SYNTHESIZE(string, tool, Tool);
	CC_SYNTHESIZE(string, remark, Remark);
public:
	DetectionItemSettingsDO() {
		id = 0;
		code = "";
		name = "";
		type = "";
		tool = "";
		remark = "";
	}
};
#endif // !_DETECTIONITEMSETTINGS_DO_
