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
#ifndef _GETPROGECT_MAPPER_
#define _GETPROGECT_MAPPER_

#include "Mapper.h"
#include "../../../mes-c2-equipmentledger/domain/do/dv_subject/dvSubjectDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */

class GetProgectListAllMapper : public Mapper<dvSubjectDO>
{
public:
	dvSubjectDO mapper(ResultSet* resultSet) const override
	{
		//subject_id,subject_code,subject_type,subject_content,subject_standard,enable_flag,remark
		dvSubjectDO data;
		data.setSubjectId(resultSet->getUInt64(1));
		data.setSubjectCode(resultSet->getString(2));
		data.setSubjectType(resultSet->getString(3));
		data.setSubjectContent(resultSet->getString(4));
		data.setSubjectStandard(resultSet->getString(5));
		data.setEnableFlag(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};

class GetProgectIdMapper : public Mapper<dvSubjectDO>
{
public:
	dvSubjectDO mapper(ResultSet* resultSet) const override
	{
		dvSubjectDO data;
		data.setSubjectId(resultSet->getUInt64(1));
		data.setSubjectCode(resultSet->getString(2));
		data.setSubjectName(resultSet->getString(3));
		data.setSubjectType(resultSet->getString(4));
		data.setSubjectContent(resultSet->getString(5));
		data.setSubjectStandard(resultSet->getString(6));
		data.setEnableFlag(resultSet->getString(7));
		return data;
	}
};//pId, SubjectId,pCode, SubjectCode, pName, SubjectName, pType, SubjectType, pContent, SubjectContent, standard, SubjectStandard, enable, EnableFlag)

#endif // !_GETPROGECT_MAPPER_