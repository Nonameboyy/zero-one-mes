#pragma once

#ifndef _DELETEWORKREPORT_SERVICE_H
#define _DELETEWORKREPORT_SERVICE_H
#include <list>
#include <cstdint> 
/**
 * 删除报工 服务实现
 */
class DeleteWorkReportService
{
public:
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_DELETEWORKREPORT_SERVICE_H

