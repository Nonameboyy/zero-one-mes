#include "stdafx.h"
#include "ProdWorkorderController.h"
#include "../mes-c4-prodmgmt/service/ProdWorkorder/ProdWorkorderService.h"



Uint64JsonVO::Wrapper ProdWorkorderController::execAddProdWorkorder(const AddProdWorkorderDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	ProdWorkorderService service;
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

GetProdWorkorderListPageJsonVO::Wrapper ProdWorkorderController::execQueryGetProdWorkorderList(const GetProdWorkorderListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProdWorkorderService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetProdWorkorderListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}

ProdWorkorderInfoJsonVO::Wrapper ProdWorkorderController::execGetProdWorkorderInfo(const UInt64& workorder_id)
{
	// ����һ��Service
	ProdWorkorderService service;
	// ��ѯ����
	auto result = service.listDetail(workorder_id);
	// ��Ӧ���
	auto jvo = ProdWorkorderInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProdWorkorderBomListPageJsonVO::Wrapper ProdWorkorderController::execGetProdWorkorderBomList(const ProdWorkorderBomListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProdWorkorderService service;
	// ��ѯ����
	auto result = service.listBom(query);
	// ��Ӧ���
	auto jvo = ProdWorkorderBomListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}