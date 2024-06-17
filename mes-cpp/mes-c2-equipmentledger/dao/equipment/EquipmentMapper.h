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
#ifndef _EQUIPMENT_MAPPER_
#define _EQUIPMENT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dv_machinery/dvMachineryDO.h"
#include"../../domain/do/dv_machinery_type/dvMachineryTypeDO.h"
#include"../../domain/do/md_workshop/md_workshopDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class EquipmentMapper : public Mapper<dvMachineryDO>
{
public:
	dvMachineryDO mapper(ResultSet* resultSet) const override
	{
		dvMachineryDO data;
		data.setMachineryId(resultSet->getUInt64(1));
		data.setMachineryCode(resultSet->getString(2));
		data.setMachineryName(resultSet->getString(3));
		data.setMachineryBrand(resultSet->getString(4));
		data.setMachinerySpec(resultSet->getString(5));
		data.setWorkshopId(resultSet->getUInt64(6));
		data.setWorkshopCode(resultSet->getString(7));
		data.setWorkshopName(resultSet->getString(8));
		data.setStatus(resultSet->getString(9));
		data.setCreateTime(resultSet->getString(10));

		
		return data;
	}
};

class EquipmentSampleMapper : public Mapper<dvMachineryDO>
{
public:
	dvMachineryDO mapper(ResultSet* resultSet) const override
	{
		dvMachineryDO data;
		data.setMachineryId(resultSet->getUInt64(1));
		data.setMachineryCode(resultSet->getString(2));
		data.setMachineryName(resultSet->getString(3));
		data.setMachineryBrand(resultSet->getString(4));
		data.setMachineryTypeId(resultSet->getUInt64(5));
		data.setMachineryTypeCode(resultSet->getString(6));
		data.setMachineryTypeName(resultSet->getString(7));
		data.setMachinerySpec(resultSet->getString(8));
		data.setWorkshopId(resultSet->getUInt64(9));
		data.setWorkshopCode(resultSet->getString(10));
		data.setWorkshopName(resultSet->getString(11));
		data.setRemark(resultSet->getString(12));


		return data;
	}
};

class EquipmentDetailMapper : public Mapper<dvMachineryDO>
{
public:
	dvMachineryDO mapper(ResultSet* resultSet) const override
	{

		//machinery_id, machinery_code, machinery_name, machinery_brand, machinery_type_id, machinery_type_code, machinery_type_name, 
		//machinery_spec, workshop_id, workshop_code, workshop_name, status FROM dv_machinery ";
			
		dvMachineryDO data;
		data.setMachineryId(resultSet->getUInt64(1));
		data.setMachineryCode(resultSet->getString(2));
		data.setMachineryName(resultSet->getString(3));
		data.setMachineryBrand(resultSet->getString(4));
		data.setMachineryTypeId(resultSet->getUInt64(5));
		data.setMachineryTypeCode(resultSet->getString(6));
		data.setMachineryTypeName(resultSet->getString(7));
		data.setMachinerySpec(resultSet->getString(8));
		data.setWorkshopId(resultSet->getUInt64(9));
		data.setWorkshopCode(resultSet->getString(10));
		data.setWorkshopName(resultSet->getString(11));
		data.setRemark(resultSet->getString(12));


		return data;
	}
};

class EquipmentTypeMapper : public Mapper<dvMachineryTypeDO>
{
public:
	dvMachineryTypeDO mapper(ResultSet* resultSet) const override
	{

		dvMachineryTypeDO data;
		data.setMachineryTypeId(resultSet->getUInt64(1));


		return data;
	}
};

class EquipmentTypeDetailMapper : public Mapper<dvMachineryTypeDO>
{
public:
	dvMachineryTypeDO mapper(ResultSet* resultSet) const override
	{

		dvMachineryTypeDO data;
		data.setMachineryTypeId(resultSet->getUInt64(1));
		data.setMachineryTypeCode(resultSet->getString(2));
		data.setMachineryTypeName(resultSet->getString(3));


		return data;
	}
};

class WorkshopMapper : public Mapper<MdWorkshopDO>
{
public:
	MdWorkshopDO mapper(ResultSet* resultSet) const override
	{

		MdWorkshopDO data;
		data.setWorkshopId(resultSet->getUInt64(1));

		return data;
	}
};

class WorkshopdetailMapper : public Mapper<MdWorkshopDO>
{
public:
	MdWorkshopDO mapper(ResultSet* resultSet) const override
	{

		MdWorkshopDO data;
		data.setWorkshopId(resultSet->getUInt64(1));
		data.setWorkshopCode(resultSet->getString(2));
		data.setWorkshopName(resultSet->getString(3));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_