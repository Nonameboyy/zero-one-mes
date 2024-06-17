#pragma once
#ifndef _PROCESSLIST_SERVICE_
#define _PROCESSLIST_SERVICE_
#include <list>
#include "domain/vo/process/ProcessListVo.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ProcessListService
{
public:
	// ��ҳ��ѯ�����б�����
	ProcessListDTO::Wrapper listAll(const ProcessListQuery::Wrapper& query);
	// ͨ��id��ѯ��������
	ProcessDTO::Wrapper getById(const ProcessDetailQuery::Wrapper& query);
	// ��ӹ��� ��������
	uint64_t saveProcessAdd(const ProcessAddDTO::Wrapper& dto, const string username);
	// �޸Ĺ���
	bool updateData(const ProcessDTO::Wrapper& dto, const string updatename);
	// �������� ��ѯ����
	list<ProcessAddDTO::Wrapper> listAllForProcess(const ProcessListQuery::Wrapper& query);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
