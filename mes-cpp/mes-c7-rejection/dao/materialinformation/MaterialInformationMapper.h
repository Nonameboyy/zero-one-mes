#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _MATERIALINFORMATION_MAPPER_
#define _MATERIALINFORMATION_MAPPER_

#include "Mapper.h"
#include "../../domain/do/materialinformation/MaterialinformationDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class MaterianInformationMapper : public Mapper<MaterialInformationDO>
{
public:
	MaterialInformationDO mapper(ResultSet* resultSet) const override
	{
		MaterialInformationDO data;
		data.setRt_Id(resultSet->getUInt64(1));
		data.setRt_Code(resultSet->getString(2));
		data.setRt_Name(resultSet->getString(3));
		data.setWorkororder_Id(resultSet->getUInt64(4));
		data.setWorkororder_Code(resultSet->getString(5));
		data.setWarehouse_Id(resultSet->getUInt64(6));
		data.setWarehouse_Code(resultSet->getString(7));
		data.setWarehouse_Name(resultSet->getString(8));
		data.setLocation_Id(resultSet->getUInt64(9));
		data.setLocation_Code(resultSet->getString(10));
		data.setLocation_Name(resultSet->getString(11));
		data.setArea_Id(resultSet->getUInt64(12));
		data.setArea_Code(resultSet->getString(13));
		data.setArea_Name(resultSet->getString(14));
		data.setRt_Date(resultSet->getString(15));
		data.setRemark(resultSet->getString(16));

		return data;
	}
};

#endif // !_SAMPLE_MAPPER_