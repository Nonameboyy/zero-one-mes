/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "stdafx.h"
#include "ProductRecptController.h"
#include "service/item-information/ProductRecptService.h"

//controller����service�����ҳ��ѯ����
ProductRecptPageJsonVO::Wrapper ProductRecptController::execQueryProductRecpt(const ProductRecptQuery::Wrapper& query)
{//query����(recpt_code,recpt_name,workorder_code,warehouse_name)
	//����service
	ProductRecptService service;
	//��ѯ����
	auto result = service.listAll(query);//����PageDTO
	//��Ӧ���
	auto jvo = ProductRecptPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ProductRecptController::execAddProductRecpt(const ProductRecptDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��:recpt_code workorder_code recpt_date item_id
	if (!dto->recpt_code || !dto->workorder_code || !dto->recpt_date || !dto->item_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->recpt_code->empty() || dto->workorder_code->empty() || dto->recpt_date->empty() || dto->item_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProductRecptService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper ProductRecptController::execRemoveProductRecpt(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProductRecptService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper ProductRecptController::execModifyProductRecpt(const ProductRecptDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��:recpt_code workorder_code recpt_date item_id
	if (!dto->recpt_code || !dto->workorder_code || !dto->recpt_date || !dto->item_id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProductRecptService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->item_id);
	}
	else
	{
		jvo->fail(dto->item_id);
	}
	// ��Ӧ���
	return jvo;
}
