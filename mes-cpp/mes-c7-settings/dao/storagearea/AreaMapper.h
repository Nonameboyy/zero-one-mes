#pragma once
#ifndef __AREAMAPPER_H__
#define __AREAMAPPER_H__

#include "Mapper.h"
#include "domain/do/storagearea/AreaDO.h"

class AreaMapper : public Mapper<AreaDO>
{
public:

	AreaDO mapper(ResultSet* resultSet) const override
	{
		//	sql << "SELECT remark, \
			attr1,attr2,attr3,attr4,create_by,create_time,update_by,update_time FROM zero_mes";
		AreaDO data;
		data.setLid(resultSet->getUInt64(1));
		data.setId(resultSet->getUInt64(2));
		data.setAreaCode(resultSet->getString(3));
		data.setAreaName(resultSet->getString(4));
		data.setAreaSize(resultSet->getDouble(5));
		data.setMaxLoa(resultSet->getDouble(6));
		data.setX(resultSet->getInt(7));
		data.setY(resultSet->getInt(8));
		data.setZ(resultSet->getInt(9));
		data.setIson(resultSet->getString(10));
		data.setRemark(resultSet->getString(11));
		data.setText1(resultSet->getString(12));
		data.setText2(resultSet->getString(13));
		data.setText3(resultSet->getInt(14));
		data.setText4(resultSet->getInt(15));
		data.setCreateBy(resultSet->getString(16));
		data.setCreateTime(resultSet->getString(17));
		data.setUpdateBy(resultSet->getString(18));
		data.setUpdateTime(resultSet->getString(19));
		return data;
	}

};

#endif //__AREAMAPPER_H__