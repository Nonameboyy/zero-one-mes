#pragma once
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductDO.h"
#include "../../domain/query/process/ProcessProductsQuery.h"

/**
 * ��ȡ���չ�����Ʒ�б�����+��ҳ��
 */

class ProcessProductsDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProcessProductsQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProRouteProductDO> selectWithPage(const ProcessProductsQuery::Wrapper& query);
};