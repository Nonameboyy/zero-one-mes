#include "stdafx.h"
#include "DeviceResourceController.h"
#include "domain/do/deviceresource/DeviceResourceDO.h"
#include "service/deviceresource/DeviceResourceService.h"



DeviceResourcePageVO::Wrapper DeviceResourceController::execGetDeviceResourceList(const DeviceResourceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	DeviceResourceService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DeviceResourcePageVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper DeviceResourceController::execAddDeviceResource(const DeviceResourceDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->equipmentCode || !dto->equipmentName || !dto->quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->quantity < 0 || dto->equipmentName->empty() || dto->equipmentCode->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	DeviceResourceService service;
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

Uint64JsonVO::Wrapper DeviceResourceController::execModifyDeviceResource(const DeviceResourceDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->machineryId || dto->machineryId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DeviceResourceService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->machineryId);
	}
	else
	{
		jvo->fail(dto->machineryId);
	}
	// ��Ӧ���
	return jvo;
}
Uint64JsonVO::Wrapper DeviceResourceController::execDeleteDeviceResource(const UInt64& deviceResourceId)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!deviceResourceId || deviceResourceId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DeviceResourceService service;
	// ִ������ɾ��
	if (service.deleteData(deviceResourceId.getValue(0))) {
		jvo->success(deviceResourceId);
	}
	else
	{
		jvo->fail(deviceResourceId);
	}
	// ��Ӧ���
	return jvo;
}


