#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _PRODUCT_RECPT_DAO_
#define _PRODUCT_RECPT_DAO_
#include "BaseDAO.h"
#include "domain/do/item-information/ProductRecptDO.h"
#include "domain/query/item-information/ProductRecptQuery.h"

/**
 * �Ա�wm_storage_location�����ݿ����ʵ��
 */
class ProductRecptDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProductRecptQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProductRecptDO> selectWithPage(const ProductRecptQuery::Wrapper& query);
	// ��������
	uint64_t insert(const ProductRecptDO& iObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);

	// �޸�����
	int update(const ProductRecptDO& uObj);
};
#endif // !_PRODUCT_RECPT_DAO_
