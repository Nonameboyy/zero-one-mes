#include "stdafx.h"
#include "DetectionItemsController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/DetectionTemplate/TemplateDetectItemServive/TemplateDetectItemService.h"
TemplateDetectItemPageJsonVO::Wrapper DetectionItemsController::execQueryTemplateDetectItem(const TemplateDetectItemQuery::Wrapper& query)
{
	TemplateDetectItemService service;
	auto result = service.listAllTemplateDetectItem(query); // ��ҳ��ѯ���ģ����������
	auto jvo = TemplateDetectItemPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper DetectionItemsController::execModifyTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	TemplateDetectItemService service;
	// ִ�������޸�
	if (service.updateTemplateDetectItem(dto)) {
		jvo->success(dto->record_id);
	}
	else {
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper DetectionItemsController::execAddTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->template_id || !dto->index_id || !dto->index_code || !dto->index_name || !dto->index_type)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->template_id < 0 || dto->index_id < 0 || dto->index_code->empty() || dto->index_name->empty() || dto->index_type->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	TemplateDetectItemService service;
	// ִ����������
	uint64_t id = service.saveTemplateDetectItem(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper DetectionItemsController::execRemoveTemplateDetectItem(const oatpp::List<UInt64>& record_ids)
{
	// ����һ��Service
	TemplateDetectItemService service;
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	bool flag = false;
	for (auto it = record_ids->begin(); it != record_ids->end(); it++) {
		auto x = (*it).getValue(0);
		//����У��
		if (x < 0 || !x) {
			if (!flag)
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			flag = true;
		}
		else {
			// ִ������ɾ��
			if (!service.removeTemplateDetectItem(x)) {
				if (!flag)
					jvo->init(UInt64(-1), RS_FAIL);
				flag = true;
			}
		}
	}

	// ��Ӧ���
	if (!flag)
		jvo->init(UInt64(1), RS_SUCCESS);
	return jvo;
}
