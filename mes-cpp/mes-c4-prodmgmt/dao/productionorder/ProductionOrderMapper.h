#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/25 14:21:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ORDER_MAPPER_
#define _ORDER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro_workorder/ProWorkOrderDO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"
/**
 * 示例表字段匹配映射
 */
class ProWorkOrderMapper : public Mapper<ProWorkOrderDO>
{
public:
	ProWorkOrderDO mapper(ResultSet* resultSet) const override
	{
		ProWorkOrderDO data;
		data.setworkOrderCode(resultSet->getString(1));
		data.setworkOrderName(resultSet->getString(2));
		data.setworkOrderType(resultSet->getString(3));
		data.setorderSource(resultSet->getString(4));
		data.setsourceCode(resultSet->getString(5));
		data.setproductId(resultSet->getInt(6));
		data.setproductCode(resultSet->getString(7));
		data.setproductName(resultSet->getString(8));
		data.setproductSpc(resultSet->getString(9));
		data.setunitOfMeasure(resultSet->getString(10));
		data.setbatchCode(resultSet->getString(11));
		data.setpQuantity(resultSet->getDouble(12));
		data.setquantityProduced(resultSet->getDouble(13));
		data.setquantityChanged(resultSet->getDouble(14));
		data.setquantityScheduled(resultSet->getDouble(15));
		data.setclientId(resultSet->getInt(16));
		data.setclientCode(resultSet->getString(17));
		data.setclientName(resultSet->getString(18));
		data.setvendorId(resultSet->getInt(19));
		data.setvendorCode(resultSet->getString(20));
		data.setvendorName(resultSet->getString(21));
		data.setfinishDate(resultSet->getString(22));
		data.setrequestDate(resultSet->getString(23));
		data.setstatus(resultSet->getString(24));
		return data;
	}
};
class ProWorkOrderBomMapper :public Mapper<ProWorkOrderBomDO>
{
public:
	ProWorkOrderBomDO mapper(ResultSet* resultSet) const override
	{
		ProWorkOrderBomDO data;
		data.setitemCode(resultSet->getString(1));
		data.setitemName(resultSet->getString(2));
		data.setitemSpc(resultSet->getString(3));
		data.setunitOfMeasure(resultSet->getString(4));
		data.setitemOrProduct(resultSet->getString(5));
		data.setbQuantity(resultSet->getDouble(6));
		data.setitemId(resultSet->getInt(7));
		data.setworkOrderId(resultSet->getInt(8));
		return data;
	}
};
#endif // !_ORDER_MAPPER_