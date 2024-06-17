#pragma once
#ifndef _PROCESSEXPORT_SERVICE_
#define _PROCESSEXPORT_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/set/ProcessExportQuery.h"
#include "domain/dto/set/SetProAddDTO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ProcessExportService
{
public:
	// 导出工序 查询数据
	list<SetProAddTableDTO::Wrapper> listAll(const ProcessExportQuery::Wrapper& query);

};

#endif // !_SAMPLE_SERVICE_