#pragma once

#ifndef _PICK_SERVICE_
#define _PICK_SERVICE_
#include <list>
#include "../../domain/vo/pick/PickVO.h"
#include "../../domain/query/pick/PickQuery.h"
#include "../../domain/dto/pick/PickDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PickService
{
public:
	// ��ҳ��ѯ��������
	//PickPageDTO::Wrapper listAll(const PickQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const PickDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const PickDTO::Wrapper& dto);
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_PICK_SERVICE_

