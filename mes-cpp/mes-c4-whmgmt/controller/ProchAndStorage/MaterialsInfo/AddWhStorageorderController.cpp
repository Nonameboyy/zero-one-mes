#include "stdafx.h"
#include "AddWhStorageorderController.h"
#include "../../../service/ProchAndStorage/MaterialsInfo/WhStorageorderService.h"
#include "../../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper AddWhStorageorderController::execAddWhStorageorder(const AddWhStorageorderDTO::Wrapper& dto)
{
	//���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��
	//�ǿ�У��(�����ݿ��зǿ�null����)
	if (!dto || !dto->item_id || !dto->quantity_recived) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//�ش���ֵ����Ϊnull
	if (!dto->iqc_check || !dto->warehouse_code || !dto->area_code || !dto->area_name || !dto->location_name
		|| !dto->item_code || !dto->item_name || !dto->warehouse_name || !dto->unit_of_measure || !dto->location_code) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//��ЧֵУ��
	if (dto->iqc_id < 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->area_id < 0 || dto->item_id < 0 || dto->location_id < 0 || dto->warehouse_id < 0 || dto->quantity_recived < 0.00) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//�ش���ֵ����Ϊ���ַ���
	if (dto->iqc_check->empty() || dto->warehouse_code->empty() || dto->area_code->empty() || dto->area_name->empty() || dto->location_name->empty()
		|| dto->item_code->empty() || dto->item_name->empty() || dto->warehouse_name->empty() || dto->unit_of_measure->empty() || dto->location_code->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//����һ��Service
	WhStorageorderService service;
	//ִ����������
	uint64_t id = service.addWhStorageorder(dto);
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