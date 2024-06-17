#include "stdafx.h"
#include "DetectionTemplateController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/DetectionTemplate/DetectionTemplateService.h"

Uint64JsonVO::Wrapper DetectionTemplateController::execModifyDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto) {
	auto result = Uint64JsonVO::createShared();
	if (dto->template_id < 0 || !dto->template_id) {
		result->init(UInt64(-1), RS_PARAMS_INVALID);
		return result;
	}
	DetectionTemplateService service;
	//�Ƿ�����ֻ����һ���ַ�,���Ǿ��ǲ�������
	if (dto->enable_flag->size() != 1) {
		result->init(UInt64(-1), RS_PARAMS_INVALID);
		return result;
	}
	if (!service.update(dto)) {
		result->init(UInt64(-1), RS_FAIL);
	}
	else {
		result->init(UInt64(1), RS_SUCCESS);
	}
	return result;
}

Uint64JsonVO::Wrapper DetectionTemplateController::execRemoveDetectionTemplate(const UInt64& template_id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!template_id || template_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DetectionTemplateService service;
	// ִ������ɾ��
	if (service.RemoveDetectionTemplateData(template_id.getValue(0))) {
		jvo->success(template_id);
	}
	else
	{
		jvo->fail(template_id);
	}
	// ��Ӧ���
	return jvo;
}

DetectionTemplatePageJsonVO::Wrapper DetectionTemplateController::execQueryDetectionTemplateList(const DetectionTemplateQuery::Wrapper& query, const PayloadDTO& payload)
{
	DetectionTemplateService service;
	auto result = service.listAllTemplateList(query);
	auto jvo = DetectionTemplatePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper DetectionTemplateController::execAddDetectionTemplate(const DetectionTemplateDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->template_code || !dto->template_name || !dto->qc_types)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// ����һ��Service
	DetectionTemplateService service;
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
	return {};
}

DetectionTemplatePageJsonVO::Wrapper DetectionTemplateController::execQueryDetecTempDetails(const String& template_code, const PayloadDTO& payload)
{
	// ����һ��Service
	DetectionTemplateService service;
	// ��ѯ����
	auto result = service.queryDetecTempDetails(template_code);
	// ��Ӧ���
	auto jvo = DetectionTemplatePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


