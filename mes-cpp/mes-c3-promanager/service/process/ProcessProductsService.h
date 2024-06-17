#pragma once
#ifndef _PROCESSPRODUCT_SERVICE_
#define _PROCESSPRODUCT_SERVICE_

#include <list>
#include "domain/vo/process/ProcessProductsVO.h"
#include "domain/query/process/ProcessProductsQuery.h"
#include "domain/dto/process/ProcessProductsDTO.h"

/**
 * ��ȡ���չ�����Ʒ�б��service
 */
class ProcessProductsService
{
public:
	// ��ҳ��ѯ��������
	ProductsPageDTO::Wrapper listAll(const ProcessProductsQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_