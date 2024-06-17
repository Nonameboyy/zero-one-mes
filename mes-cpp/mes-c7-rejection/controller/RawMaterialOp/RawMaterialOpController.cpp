#include "stdafx.h"
#include "RawMaterialOpController.h"
#include "../../service/RawMaterialOpService/RawMaterialOpService.h"
#include "../ApiDeclarativeServicesHelper.h"



Uint64JsonVO::Wrapper RawMaterialOpController::execRemoveRawMaterialOp(const UInt64& id)
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
	RawMaterialOpService service;
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

Uint64JsonVO::Wrapper RawMaterialOpController::execModifyRawMaterialOp(const RawMaterialOpDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->rt_id || dto->rt_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RawMaterialOpService service;
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


RawMaterialOpPageJsonVO::Wrapper RawMaterialOpController::execQueryRawMaterialOp(const RawMaterialOpQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	RawMaterialOpService service;
	// ��ѯ����
	auto result = service.listAll(query);
	
	//// ��Ӧ���
	auto jvo = RawMaterialOpPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
