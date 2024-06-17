#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PRODUCT_RECPT_SERVICE_
#define _PRODUCT_RECPT_SERVICE_
#include <list>
#include "domain/vo/item-information/ProductRecptVO.h"
#include "domain/query/item-information/ProductRecptQuery.h"
#include "domain/dto/item-information/ProductRecptDTO.h"

/**
 * ��Ʒ������ʵ��
 */
class ProductRecptService
{
public:
	// ��ҳ��ѯ��������
	ProductRecptPageDTO::Wrapper listAll(const ProductRecptQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ProductRecptDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	// �޸�����
	bool updateData(const ProductRecptDTO::Wrapper& dto);
};

#endif // !_PRODUCT_RECPT_SERVICE_