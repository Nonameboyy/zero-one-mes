#pragma once
#ifndef _MATERIAL_SERVICE_
#define _MATERIAL_SERVICE_
#include <list>
#include "domain/vo/materialsInformation/MaterialVO.h"
#include "domain/query/materialsInformation/MaterialQuery.h"
#include "domain/dto/materialsInformation/MaterialDTO.h"

/**
 * ������Ϣ�ķ������
 */
class MaterialService
{
public:
	// ��ҳ��ѯ��������
	MaterialPageDTO::Wrapper listAll(const MaterialQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const MaterialDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const MaterialDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_MATERIAL_SERVICE_
