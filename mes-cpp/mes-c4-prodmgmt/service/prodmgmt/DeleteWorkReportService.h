#pragma once

#ifndef _DELETEWORKREPORT_SERVICE_H
#define _DELETEWORKREPORT_SERVICE_H
#include <list>
#include <cstdint> 
/**
 * ɾ������ ����ʵ��
 */
class DeleteWorkReportService
{
public:
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_DELETEWORKREPORT_SERVICE_H

