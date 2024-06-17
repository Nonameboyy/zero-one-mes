#include "stdafx.h"
#include "RController.h"
#include "../../service/material/MatService.h"
#include "../ApiDeclarativeServicesHelper.h"

GetReturnListPageJsonVO::Wrapper RController::execQueryList(const GetReturnListQuery::Wrapper& query)
{

	// ����һ��Service
	MatService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetReturnListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper RController::execAddReturnLine(const AddReturnDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->rtcode || !dto->rtname || !dto->vendorname || !dto->rtdate)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
		//jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		//return jvo;
	//}

	// ����һ��Service
	MatService service;
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

Uint64JsonVO::Wrapper RController::execModifyReturnline(const AddReturnDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->rtid || dto->rtid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MatService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->rtid);
	}
	else
	{
		jvo->fail(dto->rtid);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper RController::execRemoveReturnline(const UInt64& lineid)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!lineid || lineid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MatService service;
	// ִ������ɾ��
	if (service.removeData(lineid.getValue(0))) {
		jvo->success(lineid);
	}
	else
	{
		jvo->fail(lineid);
	}
	// ��Ӧ���
	return jvo;
}
