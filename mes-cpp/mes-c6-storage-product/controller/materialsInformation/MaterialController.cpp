#include "stdafx.h"
#include "MaterialController.h"
#include "../../service/materialsInformation/MaterialService.h"
#include "../ApiDeclarativeServicesHelper.h"

MaterialPageJsonVO::Wrapper MaterialController::execQueryMaterial(const MaterialQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	MaterialService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MaterialPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper MaterialController::execAddMaterial(const MaterialDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->issue_id || !dto->item_id || !dto->item_code || !dto->item_name || !dto->specification || !dto->unit_of_measure || !dto->quantity_issued || !dto->batch_code || !dto->warehouse_name || !dto->location_name || !dto->area_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->issue_id <= 0 || dto->item_id <= 0 || dto->item_code->empty() || dto->item_name->empty() || dto->specification->empty() || dto->unit_of_measure->empty() || dto->quantity_issued <= 0 || dto->batch_code->empty() || dto->warehouse_name->empty() || dto->location_name->empty() || dto->area_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	MaterialService service;
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

Uint64JsonVO::Wrapper MaterialController::execModifyMaterial(const MaterialDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->line_id || dto->line_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MaterialService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->line_id);
	}
	else
	{
		jvo->fail(dto->line_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper MaterialController::execRemoveMaterial(const UInt64& id)
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
	MaterialService service;
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
