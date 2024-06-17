#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/5/27 14:21:55

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
#ifndef _MATMAPPER_H_
#define _MATMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/material/MatDO.h"

/**
 * 供应商退货行数据库字段匹配映射
 */
class MatlistMapper : public Mapper<MatlistDO>
{
public:
	MatlistDO mapper(ResultSet* resultSet) const override
	{
		MatlistDO data;
		data.setRtid(resultSet->getUInt64(1));
		data.setRtcode(resultSet->getString(2));
		data.setRtname(resultSet->getString(3));
		data.setPocode(resultSet->getString(4));
		data.setVendorcode(resultSet->getString(5));
		data.setVendorname(resultSet->getString(6));
		data.setRtdate(resultSet->getString(7));
		data.setStatuss(resultSet->getString(8));
		return data;
	}
};

#endif // !_MATMAPPER_H_