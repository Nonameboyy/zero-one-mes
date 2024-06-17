#pragma once
#ifndef _PROCESS_MAPPER_
#define _PROCESS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProRouteDO.h"

/**
 * 工艺列表数据映射
 */
class ProcessMapper : public Mapper<ProRouteDO>
{
public:
	ProRouteDO mapper(ResultSet* resultSet) const override
	{
		ProRouteDO data;
		data.setRouteId(resultSet->getUInt64(1));
		data.setRouteCode(resultSet->getString(2));
		data.setRouteName(resultSet->getString(3));
		data.setRouteDesc(resultSet->getString(4));
		data.setEnableFlag(resultSet->getString(5));
		data.setRemark(resultSet->getString(6));
		return data;
	}
};


#endif // !_SAMPLE_MAPPER_
