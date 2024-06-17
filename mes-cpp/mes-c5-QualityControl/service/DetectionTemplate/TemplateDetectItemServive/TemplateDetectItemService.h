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
	// 分页查询所有数据
	TemplateDetectItemPageDTO::Wrapper listAllTemplateDetectItem(const TemplateDetectItemQuery::Wrapper& query);
	// 修改数据
	bool updateTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	// 保存数据
	uint64_t saveTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeTemplateDetectItem(uint64_t id);
	// 获取时间，格式化为日期格式
	string getCurrentTime();
};

#endif // !_TEMPLATEDETECTITEM_SERVICE_
