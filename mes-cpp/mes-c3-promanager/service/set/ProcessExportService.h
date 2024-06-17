#pragma once
#ifndef _PROCESSEXPORT_SERVICE_
#define _PROCESSEXPORT_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/set/ProcessExportQuery.h"
#include "domain/dto/set/SetProAddDTO.h"
/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ProcessExportService
{
public:
	// �������� ��ѯ����
	list<SetProAddTableDTO::Wrapper> listAll(const ProcessExportQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_