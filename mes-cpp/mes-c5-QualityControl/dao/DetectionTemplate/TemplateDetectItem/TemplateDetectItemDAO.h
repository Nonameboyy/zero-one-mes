#pragma once
#ifndef _TEMPLATEDETECTITEM_DAO_
#define _TEMPLATEDETECTITEM_DAO_

#include "BaseDAO.h"
#include "../../../domain/do/DetectionTemplate/TemplateDetectItemDO.h"
#include "../../../domain/query/DetectionTemplate/TemplateDetectItemQuery.h"

class TemplateDetectItemDAO :public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TemplateDetectItemQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<TemplateDetectItemDO> selectTemplateDetectItemWithPage(const TemplateDetectItemQuery::Wrapper& query);
	// �޸�����
	int updateTemplateDetectItem(const TemplateDetectItemDO& uObj);
	// ��������
	uint64_t insertTemplateDetectItem(const TemplateDetectItemDO& iObj);
	// ͨ��IDɾ������
	int deleteByRecordId(uint64_t record_id);
};

#endif // !_TEMPLATEDETECTITEM_DAO_
