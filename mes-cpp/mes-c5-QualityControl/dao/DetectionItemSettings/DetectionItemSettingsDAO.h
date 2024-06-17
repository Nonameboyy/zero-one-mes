#pragma once
#ifndef _DETECTIONITEMSETTINGS_DAO_
#define	_DETECTIONITEMSETTINGS_DAO_

#include "BaseDAO.h"
#include "../../domain/do/DetectionItemSettings/DetectionItemSettingsDO.h"
#include "../../domain/query/DetectionItemSettings/DetectionItemSettingsQuery.h"

class DetectionItemSettingsDAO : public BaseDAO
{
public:
	uint64_t count(const DetectionItemSettingsQuery::Wrapper& query);
	//flag传0是查询,传1是导出
	list<DetectionItemSettingsDO> selectWithPage(const DetectionItemSettingsQuery::Wrapper& query,int flag);
	uint64_t insert(const DetectionItemSettingsDO& iobj);
	int update(const DetectionItemSettingsDO& uobj);
	int remove(uint64_t id);
};

#endif // !_DETECTIONITEMSETTINGS_DAO_
