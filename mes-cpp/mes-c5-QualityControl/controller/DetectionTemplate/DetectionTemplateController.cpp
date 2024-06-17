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
	//是否启用只能有一个字符,不是就是参数错了
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
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!template_id || template_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DetectionTemplateService service;
	// 执行数据删除
	if (service.RemoveDetectionTemplateData(template_id.getValue(0))) {
		jvo->success(template_id);
	}
	else
	{
		jvo->fail(template_id);
	}
	// 响应结果
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
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->template_code || !dto->template_name || !dto->qc_types)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// 定义一个Service
	DetectionTemplateService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
	return {};
}

DetectionTemplatePageJsonVO::Wrapper DetectionTemplateController::execQueryDetecTempDetails(const String& template_code, const PayloadDTO& payload)
{
	// 定义一个Service
	DetectionTemplateService service;
	// 查询数据
	auto result = service.queryDetecTempDetails(template_code);
	// 响应结果
	auto jvo = DetectionTemplatePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


