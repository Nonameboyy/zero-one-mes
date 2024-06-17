#include "stdafx.h"
#include "PickController.h"
#include "../../service/pick/PickService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper PickController::execAddPick(const PickDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->issueCode || !dto->issueName || !dto->clientName||!dto->createTime||!dto->workorderCode||
		!dto->warehouseName||!dto->status||!dto->clientCode||!dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->issueCode->empty() || dto->issueName->empty() || dto->workorderCode->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	PickService service;
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

Uint64JsonVO::Wrapper PickController::execModifyPick(const PickDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->issueCode || !dto->issueName || !dto->clientName || !dto->createTime || !dto->workorderCode ||
		!dto->warehouseName || !dto->status || !dto->clientCode || !dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->issueCode->empty() || dto->issueName->empty() || dto->workorderCode->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	PickService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(UInt64(dto->issueId));
	}
	else
	{
		jvo->fail(UInt64(dto->issueId));
	}
	// ��Ӧ���
	return jvo;
}

//ִ����������
Uint64JsonVO::Wrapper PickController::executeExecuteGet(const UInt64& id)
{
	return{};
}
//ɾ������
Uint64JsonVO::Wrapper PickController::executeRemoveReturn(const UInt64& id)
{
	return{};
}
// ��������
StringJsonVO::Wrapper PickController::executeDownloadFile(const oatpp::List<UInt64>& ids)
{
	return{};
}