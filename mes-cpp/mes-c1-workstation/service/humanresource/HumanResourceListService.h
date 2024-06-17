#pragma once
#ifndef _HUMANRESOURCELIST_SERVICE_
#define _HUMANRESOURCELIST_SERVICE_
#include <list>
#include "domain/vo/humanresource/HumanResourceListVO.h"
#include "domain/query/humanresource/HumanResourceListQuery.h"
#include "domain/dto/humanresource/HumanResourceListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class HumanResourceListService
{
public:
	// ��ҳ��ѯ��������
	HumanResourcePageDTO::Wrapper listAll(const HumanResourceListQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const HumanResourceListDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const HumanResourceListDTO::Wrapper& dto);
	// ͨ����¼IDɾ������
	bool removeData(uint64_t recordId);
};

#endif 

