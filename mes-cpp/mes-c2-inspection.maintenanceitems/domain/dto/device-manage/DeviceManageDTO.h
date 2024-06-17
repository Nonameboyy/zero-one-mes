#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _DEVICEMANAGE_DTO_
#define _DEVICEMANAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeviceManageIdDTO : public oatpp::DTO
{
	DTO_INIT(DeviceManageIdDTO, DTO);

	//��ĿID
	API_DTO_FIELD_DEFAULT(String, subjectId, ZH_WORDS_GETTER("device-manage.field.subjectOprId"));

};


class DeviceManageAddDTO : public oatpp::DTO
{
	DTO_INIT(DeviceManageAddDTO, DTO);

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectCode, ZH_WORDS_GETTER("device-manage.field.subjectCode"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectName, ZH_WORDS_GETTER("device-manage.field.subjectName"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectType, ZH_WORDS_GETTER("device-manage.field.subjectType"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectContent, ZH_WORDS_GETTER("device-manage.field.subjectContent"));

	//��׼
	API_DTO_FIELD_DEFAULT(String, subjectStandard, ZH_WORDS_GETTER("device-manage.field.subjectStandard"));

	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, enableFlag, ZH_WORDS_GETTER("device-manage.field.enableFlag"));
};

class DeviceManageDTO : public oatpp::DTO
{
	DTO_INIT(DeviceManageDTO, DTO);

	//��ĿID
	API_DTO_FIELD_DEFAULT(String, subjectId, ZH_WORDS_GETTER("device-manage.field.subjectId"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectCode, ZH_WORDS_GETTER("device-manage.field.subjectCode"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectName, ZH_WORDS_GETTER("device-manage.field.subjectName"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectType, ZH_WORDS_GETTER("device-manage.field.subjectType"));

	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectContent, ZH_WORDS_GETTER("device-manage.field.subjectContent"));

	//��׼
	API_DTO_FIELD_DEFAULT(String, subjectStandard, ZH_WORDS_GETTER("device-manage.field.subjectStandard"));

	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, enableFlag, ZH_WORDS_GETTER("device-manage.field.enableFlag"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_DEVICEMANAGE_DTO_