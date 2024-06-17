#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _EQUIPMENTQUERY_H_
#define _EQUIPMENTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�豸�б�����+��ҳ��
 */
class EquipmentQuery : public  PageQuery
{
	DTO_INIT(EquipmentQuery, PageQuery);
	//�豸����
	API_DTO_FIELD_DEFAULT(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"));
	//�豸����
	API_DTO_FIELD_DEFAULT(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"));

};

/**
 * ��ȡ�豸����
 */
class EquipmentDetailQuery : public  oatpp::DTO
{
	DTO_INIT(EquipmentDetailQuery, DTO);
	//����
	API_DTO_FIELD_DEFAULT(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"));
	
};


#include OATPP_CODEGEN_END(DTO)
#endif 

