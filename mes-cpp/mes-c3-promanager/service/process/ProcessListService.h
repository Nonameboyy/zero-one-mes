#pragma once
#ifndef _PROCESSLIST_SERVICE_
#define _PROCESSLIST_SERVICE_
#include <list>
#include "domain/vo/process/ProcessListVo.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ProcessListService
{
public:
	// 分页查询工艺列表数据
	ProcessListDTO::Wrapper listAll(const ProcessListQuery::Wrapper& query);
	// 通过id查询工艺详情
	ProcessDTO::Wrapper getById(const ProcessDetailQuery::Wrapper& query);
	// 添加工艺 保存数据
	uint64_t saveProcessAdd(const ProcessAddDTO::Wrapper& dto, const string username);
	// 修改工艺
	bool updateData(const ProcessDTO::Wrapper& dto, const string updatename);
	// 导出工艺 查询数据
	list<ProcessAddDTO::Wrapper> listAllForProcess(const ProcessListQuery::Wrapper& query);
	// 通过ID删除工艺
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
