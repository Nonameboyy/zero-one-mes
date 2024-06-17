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
#include "MaterialProductsController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/DetectionTemplate/MaterialProducts/MaterialProductsService.h"

MaterialProductsPageJsonVO::Wrapper MaterialProductsController::execMaterialProducts(const MaterialProductsQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	MaterialProductsService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MaterialProductsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}

Uint64JsonVO::Wrapper MaterialProductsController::execModifyMaterialProducts(const MaterialProductsDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MaterialProductsService service;
	// ִ�������޸�
	if (service.updateMaterialProducts(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper MaterialProductsController::execRemoveMaterialProduct(const oatpp::List<oatpp::UInt64>& record_ids)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ����У��
	if (record_ids->empty()) {
		jvo->init(oatpp::UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	MaterialProductsService service;

	// ִ������ɾ��
	if (service.deleteByRecordId(record_ids)) {
		
			jvo->init(oatpp::UInt64(1), RS_SUCCESS);  // ���� success �����ܹ������� id
			return jvo;
	}
	else {
		
			jvo->init(oatpp::UInt64(1), RS_FAIL);  // ���� fail �����ܹ������� id
		
	}

	// ��Ӧ���
	return jvo;
}
	



Uint64JsonVO::Wrapper MaterialProductsController::execAddMaterialProducts(const MaterialProductsDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->record_id || !dto->item_code || !dto->item_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->record_id < 0 || dto->item_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	MaterialProductsService service;
	// ִ����������
	uint64_t record_id = service.saveMaterialProducts(dto);
	if (record_id > 0) {
		jvo->success(UInt64(record_id));
	}
	else
	{
		jvo->fail(UInt64(record_id));
	}
	//��Ӧ���
	return jvo;
}