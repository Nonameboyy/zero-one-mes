
#include "stdafx.h"
#include "AreaController.h"
#include "../../service/storagearea/AreaService.h"

AreaPageJsonVO::Wrapper AreaController::execQueryArea(const AreaQuery::Wrapper& query, const PayloadDTO& payload)
{
	AreaService service;
	auto result = service.listAllAreabyPage(query);
	
	auto apj = AreaPageJsonVO::createShared();
	apj->success(result);
	return apj;
}
//���ص������ӵ���һ��

Uint64JsonVO::Wrapper AreaController::execAddArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto apj = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id ||!dto->location_id || !dto->area_code || !dto->area_name) {
		apj->init(UInt64(-1), RS_PARAMS_INVALID);
		return apj;
	}
	//// ��ЧֵУ��
	//if (dto->areasize <= 0 || dto->max_loa <= 0 || dto->create_by->empty() || dto->create_time->empty() || dto->update_by->empty() || dto->update_time->empty()) {
	//	apj->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return apj;
	//}
	//�Ƿ�Ҫ�ж� ȥ��
	AreaService service;
	uint64_t row =   service.insertArea(dto,payload);
	if (row > 0) {
		apj->success(UInt64(row));
	}
	else {
		apj->fail(UInt64(row));
	}
	return apj;
}
//���ص����޸ĵ���һ��
Uint64JsonVO::Wrapper AreaController::execModifyArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto apj = Uint64JsonVO::createShared();
	//�޸Ĵ������AreaDTO���� û�й��˵�id �� location_id
	if (!dto->id || !dto->location_id || !dto->area_code || !dto->area_name) {
		apj->init(UInt64(-1), RS_PARAMS_INVALID);
		return apj;
	}
	
	if (dto->areasize <= 0 || dto->max_loa <= 0 ) {
		apj->init(UInt64(-1), RS_PARAMS_INVALID);
		return apj;
	}
	AreaService service;
	// ִ�������޸�
	if (service.updateArea(dto,payload)) {
		apj->success(dto->id);
	}
	else
	{
		apj->fail(dto->id);
	}
	return apj;
}
//���ص���ɾ������һ��
Uint64JsonVO::Wrapper AreaController::execRemoveArea(const oatpp::List<Int32>& idsdto)
{
	auto apj = Uint64JsonVO::createShared();
	std::list<int64_t> list;
	auto p = idsdto->begin();
	for ( ;p!=idsdto->end(); p++)
	{
		list.push_back((*p).getValue(0));
		if (!(*p) || (*p) <= 0) {
			apj->init(UInt64(-1), RS_PARAMS_INVALID);
			return apj;
		}
	}
	// ����һ��Service
	AreaService service;
	// ִ������ɾ��
	
	if (service.removeArea(list)) {
		apj->success(list.size());
	}
	else
	{
		apj->fail(list.size());
	}
	// ��Ӧ���
	return apj;
}





