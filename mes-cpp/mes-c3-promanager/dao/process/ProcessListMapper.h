#pragma once
#ifndef _PROCESS_LIST_MAPPER_
#define _PROCESS_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProRouteDO.h"

/**
 * 工艺路线表字段匹配映射
 */
class ProcessListMapper : public Mapper<ProRouteDO>
{
public:
	ProRouteDO mapper(ResultSet* resultSet) const override
	{
		ProRouteDO data;
		data.setRouteCode(resultSet->getString(1));
		data.setRouteName(resultSet->getString(2));
		data.setRouteDesc(resultSet->getString(3));
		data.setEnableFlag(resultSet->getString(4));
		return data;
	}
};

#endif // !_PROCESS_LIST_MAPPER_