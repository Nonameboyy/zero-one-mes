#include "stdafx.h"
#include "../../service/purchasereceiving/AddListService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "AddListController.h"

Uint64JsonVO::Wrapper AddListController::execAddList(const AddListDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->recptcode || !dto->recptname || !dto->recptdate || !dto->pocode || !dto->status || !dto-> vendorid || !dto->warehousename || !dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->recptcode->empty() || dto->recptname->empty() || dto->recptdate->empty() || dto->pocode->empty() || dto->status->empty() || dto->vendorid < 0 || dto->warehousename->empty() || dto->remark->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//service�� 
	//.......
	// ����һ��Service
	AddListService service;
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
