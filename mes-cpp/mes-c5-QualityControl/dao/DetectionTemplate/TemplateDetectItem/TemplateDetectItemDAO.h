#pragma once
#ifndef _TEMPLATEDETECTITEM_DAO_
#define _TEMPLATEDETECTITEM_DAO_

#include "BaseDAO.h"
#include "../../../domain/do/DetectionTemplate/TemplateDetectItemDO.h"
#include "../../../domain/query/DetectionTemplate/TemplateDetectItemQuery.h"

class TemplateDetectItemDAO :public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const TemplateDetectItemQuery::Wrapper& query);
	// 分页查询数据
	list<TemplateDetectItemDO> selectTemplateDetectItemWithPage(const TemplateDetectItemQuery::Wrapper& query);
	// 修改数据
	int updateTemplateDetectItem(const TemplateDetectItemDO& uObj);
	// 插入数据
	uint64_t insertTemplateDetectItem(const TemplateDetectItemDO& iObj);
	// 通过ID删除数据
	int deleteByRecordId(uint64_t record_id);
};

#endif // !_TEMPLATEDETECTITEM_DAO_
