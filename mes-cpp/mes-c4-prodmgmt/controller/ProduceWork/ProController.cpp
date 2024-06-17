/*
 Copyright Zero One Star. All rights reserved.

 @Author: ������
 @Date: 2024/5/28 10:58:42

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
#include "ProController.h"
#include "../../service/ProduceWork/ProduceWorkService.h"


/*
������Ա��������
//��ȡ��������
*/
ProduceWorkJsonVO::Wrapper ProController::execProduceWorkDetail(const UInt64& record_id)
{
	ProduceWorkService service;
	auto result = service.execeQueryDetail(record_id);

	auto jvo = ProduceWorkJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


Uint64JsonVO::Wrapper ProController::execAddProduceWork(const ProduceWorkDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	//�ǿռ���
	if (!dto->feedback_type || !dto->workorder_code || !dto->task_code || !dto->nick_name || !dto->feedback_time)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->quantity_feedback<0||dto->quantity_uncheck<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	ProduceWorkService service;
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

Uint64JsonVO::Wrapper ProController::execModifyProduceWork(const ProduceWorkDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	ProduceWorkService service;
	if (service.updateData(dto))
	{
		jvo->success(UInt64(dto->record_id));
	}
	else
	{
		jvo->fail(UInt64(dto->record_id));
	}

	return jvo;
}