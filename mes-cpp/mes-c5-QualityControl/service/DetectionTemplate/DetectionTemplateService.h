#pragma once
#ifndef _DETECTIONTEMPLATE_SERVICE_
#define _DETECTIONTEMPLATE_SERVICE_
#include <list>
#include "../../dao/DetectionTemplate/DetectionTemplateDAO.h"

class DetectionTemplateService
{
public:
	//ɾ�����ģ��
	bool RemoveDetectionTemplateData(uint64_t id);
	// ��ȡ���ģ���б���, ��ҳ��ѯ��������
	DetectionTemplatePageDTO::Wrapper listAllTemplateList(const DetectionTemplateQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const DetectionTemplateDTO::Wrapper& dto);

	bool update(const DetectionTemplateDTO::Wrapper& dto);
	// ��ȡ����ģ������
	DetectionTemplatePageDTO::Wrapper queryDetecTempDetails(const string & template_code);
};

#endif // !_TEST_SERVICE_#pragma once
