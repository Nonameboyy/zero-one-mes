#pragma once
#ifndef _TEMPLATEDETECTITEM_SERVICE_
#define _TEMPLATEDETECTITEM_SERVICE_

#include <list>
#include "Macros.h"
#include "../../../domain/dto/DetectionTemplate/TemplateDetectItemDTO.h"
#include "../../../domain/vo/DetectionTemplate/TemplateDetectItemJsonVO.h"
#include "../../../domain/do/DetectionTemplate/TemplateDetectItemDO.h"
#include "../../../domain/query/DetectionTemplate/TemplateDetectItemQuery.h"

class TemplateDetectItemService
{
public:
	// ��ҳ��ѯ��������
	TemplateDetectItemPageDTO::Wrapper listAllTemplateDetectItem(const TemplateDetectItemQuery::Wrapper& query);
	// �޸�����
	bool updateTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	// ��������
	uint64_t saveTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeTemplateDetectItem(uint64_t id);
	// ��ȡʱ�䣬��ʽ��Ϊ���ڸ�ʽ
	string getCurrentTime();
};

#endif // !_TEMPLATEDETECTITEM_SERVICE_
