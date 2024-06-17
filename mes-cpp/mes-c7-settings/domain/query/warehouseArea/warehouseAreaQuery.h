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
#ifndef _WAREHOUSE_AREA_QUERY_
#define _WAREHOUSE_AREA_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ҳ��ѯ����:��������˵Ĳ�ѯ��װ�ɲ�ѯ��,�������ԣ���������
 */
class WarehouseAreaQuery : public PageQuery
{
	DTO_INIT(WarehouseAreaQuery, PageQuery);
	//�����������,����Ĭ��ֵ
	API_DTO_FIELD_DEFAULT(String, warehouseAreaName, ZH_WORDS_GETTER("warehouse-area.field.name"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif 