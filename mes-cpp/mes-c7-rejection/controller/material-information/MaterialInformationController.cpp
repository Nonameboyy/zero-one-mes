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
#include "MaterialInformationController.h"
#include "../../service/materialinformation/MaterialInformationService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper MaterialInformationController::execAddMaterialInformation(const MaterialInformationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->rt_id || !dto->rt_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	std::istringstream iss(dto->rt_date);
	std::tm tm = {};
	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (dto->rt_code->empty() || iss.fail())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	MaterialInformationService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id >= 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper MaterialInformationController::execModifyMaterialInformation(const MaterialInformationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->rt_id || !dto->rt_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	std::istringstream iss(dto->rt_date);
	std::tm tm = {};
	iss >> std::get_time(&tm, "%Y-%m-%d");
	if (dto->rt_code->empty() || iss.fail())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MaterialInformationService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->rt_id);
	}
	else
	{
		jvo->fail(dto->rt_id);
	}
	// ��Ӧ���
	return jvo;
}

MaterialInformationPageJsonVO::Wrapper MaterialInformationController::execQuerySample(const MaterialInformationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	MaterialInformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MaterialInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MaterialInformationController::execRemoveMaterialInformation(const UInt64& id)
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
	MaterialInformationService service;
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
