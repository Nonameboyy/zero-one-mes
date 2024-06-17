#pragma once
#ifndef _DETECTIONITEMSETTINGS_MAPPER_
#define _DETECTIONITEMSETTINGS_MAPPER_
#include "Mapper.h"
#include "../../domain/do/DetectionItemSettings/DetectionItemSettingsDO.h"
class DetectionItemSettingsMapper : public Mapper<DetectionItemSettingsDO>
{
public:
	DetectionItemSettingsDO mapper(ResultSet* res) const override
	{
		DetectionItemSettingsDO data;
		data.setId(res->getUInt64(1));
		data.setCode(res->getString(2));
		data.setName(res->getString(3));
		data.setType(res->getString(4));
		data.setTool(res->getString(5));
		data.setRemark(res->getString(6));
		return data;
	}
};

#endif // !_DETECTIONITEMSETTINGS_MAPPER_
