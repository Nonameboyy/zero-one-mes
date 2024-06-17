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
#include "AddDelModController.h"
#include "../../service/add-del-mod/AddDelModService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper AddDelModController::execAddWarehouse(const AddDelModDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->warehouse_code || !dto->warehouse_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->warehouse_code->empty() || dto->warehouse_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	AddDelModService service;
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

Uint64JsonVO::Wrapper AddDelModController::execModifyWarehouse(const AddDelModDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->warehouse_id || dto->warehouse_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	AddDelModService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->warehouse_id);
	}
	else
	{
		jvo->fail(dto->warehouse_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper AddDelModController::execRemoveWarehouse(const UInt64& warehouse_id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!warehouse_id || warehouse_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	AddDelModService service;
	// ִ������ɾ��
	if (service.removeData(warehouse_id.getValue(0))) {
		jvo->success(warehouse_id);
	}
	else
	{
		jvo->fail(warehouse_id);
	}
	// ��Ӧ���
	return jvo;
}
