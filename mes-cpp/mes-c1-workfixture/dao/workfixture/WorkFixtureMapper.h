#pragma once

#include "Mapper.h"
#include "domain/do/workfixture/WorkFixtureDO.h"

/* *
* 工装夹具表字段匹配映射
*/
class WorkFixtureMapper : public Mapper<WorkFixtureDO> 
{
public:
	WorkFixtureDO mapper(ResultSet *rset) const override
	{
		WorkFixtureDO data;
		data.setToolId(rset->getUInt64(1));
		data.setToolCode(rset->getString(2));
		data.setToolName(rset->getString(3));
		data.setBrand(rset->getString(4));
		data.setSpec(rset->getString(5));
		data.setToolTypeId(rset->getUInt64(6));
		data.setToolTypeCode(rset->getString(7));
		data.setToolTypeName(rset->getString(8));
		data.setQuantity(rset->getInt(9));
		data.setQuantityAvail(rset->getInt(10));
		data.setMaintenType(rset->getString(11));
		data.setNextMaintenDate(rset->getString(12));
		data.setStatus(rset->getString(13));
		data.setRemark(rset->getString(14));
		return data;
	}
};