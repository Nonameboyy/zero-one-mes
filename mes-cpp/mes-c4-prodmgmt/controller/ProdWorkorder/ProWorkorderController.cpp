#include "stdafx.h"
#include "ProWorkorderController.h"
#include "../mes-c4-prodmgmt/service/ProWorkorder/ProWorkorderService.h"


Uint64JsonVO::Wrapper ProWorkorderController::execModifyProWorkdorder(const ModifyProWorkorderDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->workorderId || dto->workorderId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProWorkorderService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->workorderId);
	}
	else
	{
		jvo->fail(dto->workorderId);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper ProWorkorderController::execRemoveProWorkorder(const UInt64& id)
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
	ProWorkorderService service;
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

Uint64JsonVO::Wrapper ProWorkorderController::execConfirmProWorkorder(const UInt64& workorderId)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!workorderId || workorderId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProWorkorderService service;

	if (service.confirmData(workorderId.getValue(0))) {
		jvo->success(workorderId);
	}
	else
	{
		jvo->fail(workorderId);
	}
	// ��Ӧ���
	return jvo;

}

Uint64JsonVO::Wrapper ProWorkorderController::execCompleteProWorkorder(const UInt64& workorderId)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!workorderId || workorderId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProWorkorderService service;
	// ִ������ɾ��
	if (service.completeData(workorderId.getValue(0))) {
		jvo->success(workorderId);
	}
	else
	{
		jvo->fail(workorderId);
	}
	// ��Ӧ���
	return jvo;
}

