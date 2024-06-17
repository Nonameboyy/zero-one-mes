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
#ifndef _PURCHASERECEIVING_MAPPER_
#define _PURCHASERECEIVING_MAPPER_

#include "Mapper.h"
#include "../../domain/do/purchasereceiving/AddListDO.h"
#include "../../domain/do/purchasereceiving/ModifyListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AddListMapper : public Mapper<AddListDO>
{
public:
	AddListDO mapper(ResultSet* resultset) const override
	{
		AddListDO data;
		data.setRecptcode(resultset->getString(1));
		data.setRecptname(resultset->getString(2));
		data.setRecptdate(resultset->getString(3));
		data.setPocode(resultset->getString(4));
		data.setStatus(resultset->getString(5));
		data.setVendorid(resultset->getUInt64(6));
		data.setWarehousename(resultset->getString(7));
		data.setRemark(resultset->getString(8));
		return data;
	}
};
class ModifyListMapper : public Mapper<ModifyListDO>
{
public:
	ModifyListDO mapper(ResultSet* resultset) const override
	{
		ModifyListDO data;
		data.setRecptid(resultset->getUInt64(9));
		data.setRecptcode(resultset->getString(1));
		data.setRecptname(resultset->getString(2));
		data.setRecptdate(resultset->getString(3));
		data.setPocode(resultset->getString(4));
		data.setStatus(resultset->getString(5));
		data.setVendorid(resultset->getUInt64(6));
		data.setWarehousename(resultset->getString(7));
		data.setRemark(resultset->getString(8));
		return data;
	}
};
class GetListMapper : public Mapper<GetListDO>
{
public:
	GetListDO mapper(ResultSet* resultSet) const override
	{
		GetListDO data;
		data.setRecptcode(resultSet->getString(1));
		data.setRecptname(resultSet->getString(2));
		data.setVendorname(resultSet->getString(3));
		data.setRecptdate(resultSet->getString(4));
		data.setPocode(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_