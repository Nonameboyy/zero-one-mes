#include "stdafx.h"
#include "AddPlanController.h"
#include "../../service/addplan/AddPlanService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper AddPlanController::execAddplan(const AddPlanDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->planCode || !dto->planType || !dto->cycleCount||!dto->planName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->cycleCount < 0 || dto->planCode->empty() || dto->planType->empty() || dto->planName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// �ǿ�У��
	// ����һ��Service
	AddPlanService service;
	// ִ����������
	uint64_t id = service.saveData(dto,payload);
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