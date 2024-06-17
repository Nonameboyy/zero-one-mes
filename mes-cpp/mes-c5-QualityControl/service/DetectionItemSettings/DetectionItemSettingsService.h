#pragma once
#ifndef _DETECTIONITEMSETTINGS_SERVICE_
#define _DETECTIONITEMSETTINGS_SERVICE_

#include <list>
#include "domain/query/DetectionItemSettings/DetectionItemSettingsQuery.h"
#include "domain/dto/DetectionItemSettings/DetectionItemSettingsDTO.h"
#include "domain/vo/DetectionItemSettings/DetectionItemSettingsJsonVO.h"
#include "domain/do/DetectionItemSettings/DetectionItemSettingsDO.h"
class DetectionItemSettingsService
{
public:
	DetectionItemSettingsPageDTO::Wrapper listAll(const DetectionItemSettingsQuery::Wrapper& query);
	uint64_t saveData(const DetectionItemSettingsDTO::Wrapper& dto);
	bool updateData(const DetectionItemSettingsDTO::Wrapper& dto);
	bool removeData(uint64_t id);
	//µ¼³ö
	list<DetectionItemSettingsDO> listAllExort(const DetectionItemSettingsQuery::Wrapper& query);
};

#endif // !_DETECTIONITEMSETTINGS_SERVICE_
