#pragma once
#ifndef _DETECTIONTEMPLATE_SERVICE_
#define _DETECTIONTEMPLATE_SERVICE_
#include <list>
#include "../../dao/DetectionTemplate/DetectionTemplateDAO.h"

class DetectionTemplateService
{
public:
	//删除检测模板
	bool RemoveDetectionTemplateData(uint64_t id);
	// 获取检测模板列表函数, 分页查询所有数据
	DetectionTemplatePageDTO::Wrapper listAllTemplateList(const DetectionTemplateQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const DetectionTemplateDTO::Wrapper& dto);

	bool update(const DetectionTemplateDTO::Wrapper& dto);
	// 获取检验模板详情
	DetectionTemplatePageDTO::Wrapper queryDetecTempDetails(const string & template_code);
};

#endif // !_TEST_SERVICE_#pragma once
