#include "stdafx.h"
#include "storageController.h"
#include "../../service/storage/storageService.h"
#include "../ApiDeclarativeServicesHelper.h"



Uint64JsonVO::Wrapper storageController::execRemovestorage(const UInt64& id)
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
	storageService service;
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

Uint64JsonVO::Wrapper storageController::execModifystorage(const storageDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->re_id || dto->re_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	storageService service;
	// ִ�������޸�
	if (service.update(dto)) {
		jvo->success(dto->re_id);
	}
	else
	{
		jvo->fail(dto->re_id);
	}
	// ��Ӧ���
	return jvo;
}


storagePageJsonVO::Wrapper storageController::execQuerystorage(const storageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	storageService service;
	// ��ѯ����
	auto result = service.listAll(query);
	
	//// ��Ӧ���
	auto jvo = storagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
