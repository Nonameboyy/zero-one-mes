#include "ProdTaskController.h"
#include "stdafx.h"
#include "../../service/ProdTask/ProdTaskService.h"
#include "../ApiDeclarativeServicesHelper.h"
Uint64JsonVO::Wrapper ProdTaskController::execModifyProdTask(const ProdTaskModifyDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->task_id || dto->task_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProdTaskService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(UInt64(dto->task_id));
	}
	else
	{
		jvo->fail(UInt64(dto->task_id));
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper ProdTaskController::execRemoveProdTask(const UInt64& id)
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
	ProdTaskService service;
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