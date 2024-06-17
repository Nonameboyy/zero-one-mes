#include "stdafx.h"
#include "../../service/purchasereceiving/ModifyListService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "ModifyListController.h"

Uint64JsonVO::Wrapper ModifyListController::execModifyList(const ModifyListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	//!dto->recptcode || !dto->recptname || 
	//!dto->recptdate || !dto->pocode || !dto->status || !dto->vendorid ||
		//!dto->warehousename || !dto->remark
	if (!dto->recptid || dto->recptid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ModifyListService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->recptid);
	}
	else
	{
		jvo->fail(dto->recptid);
	}
	// ��Ӧ���
	return jvo;
}
