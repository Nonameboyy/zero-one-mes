#include "stdafx.h"
#include "HumanResourceListController.h"
#include "../../service/humanresource/HumanResourceListService.h"
#include "../ApiDeclarativeServicesHelper.h"

HumanResourceListPageVO::Wrapper HumanResourceListController::execQueryHumanResourceList(const HumanResourceListQuery::Wrapper& query)
{
	// ����һ��Service
	HumanResourceListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = HumanResourceListPageVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper HumanResourceListController::execAddHumanResourceList(const HumanResourceListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->postName || !dto->quantity || !dto->workstationId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->postName->empty() || dto->quantity < 0 || dto->workstationId < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	HumanResourceListService service;
	// ִ����������
	uint64_t recordId = service.saveData(dto);
	if (recordId > 0) {
		jvo->success(UInt64(recordId));
	}
	else
	{
		jvo->fail(UInt64(recordId));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper HumanResourceListController::execModifyHumanResource(const HumanResourceListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->recordId || dto->recordId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	HumanResourceListService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->recordId);
	}
	else
	{
		jvo->fail(dto->recordId);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper HumanResourceListController::execRemoveHumanResource(const UInt64& recordId)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!recordId || recordId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	HumanResourceListService service;
	// ִ������ɾ��
	if (service.removeData(recordId.getValue(0))) {
		jvo->success(recordId);
	}
	else
	{
		jvo->fail(recordId);
	}
	// ��Ӧ���
	return jvo;
}
