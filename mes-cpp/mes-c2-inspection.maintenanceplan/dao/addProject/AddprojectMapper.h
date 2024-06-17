#pragma once
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
#ifndef _ADDPROJECTMAPPER_H_
#define _ADDPROJECTMAPPER_H_

#include "Mapper.h"
#include"../../../mes-c2-equipmentledger/domain/do/dv_subject/dvSubjectDO.h"
/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AddprojectMapper : public Mapper<dvSubjectDO>
{
public:
	dvSubjectDO mapper(ResultSet* resultSet) const override
	{

		//subject_code, subject_name, subject_type, subject_content, subject_standard
		dvSubjectDO data;
		data.setSubjectCode(resultSet->getString(1));
		data.setSubjectName(resultSet->getString(2));
		data.setSubjectType(resultSet->getString(3));
		data.setSubjectContent(resultSet->getString(4));
		data.setSubjectStandard(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_