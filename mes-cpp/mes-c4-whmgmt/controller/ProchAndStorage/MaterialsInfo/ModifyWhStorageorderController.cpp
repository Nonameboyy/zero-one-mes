#include "stdafx.h"
#include "ModifyWhStorageorderController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/ProchAndStorage/MaterialsInfo/WhStorageorderService.h"

Uint64JsonVO::Wrapper ModifyWhStorageorderController::execModifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto)
{
	//���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��
//�ǿ�У��(�����ݿ��зǿ�null����)
	if (!dto || !dto->item_id || !dto->quantity_recived || !dto->line_id) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//�ش���ֵ����Ϊnull
	if (!dto->iqc_check || !dto->warehouse_code || !dto->area_code || !dto->area_name || !dto->location_name
		|| !dto->item_code || !dto->item_name || !dto->warehouse_name || !dto->unit_of_measure || !dto->location_code) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//����һ��service
	WhStorageorderService service;

	//ִ�������޸�
	if (service.modifyWhStorageorder(dto)) {
		jvo->success(dto->line_id);
	}
	else
	{
		jvo->fail(dto->line_id);
	}
	//��Ӧ�����ǰ��
	return jvo;
}