#pragma once
#ifndef _PROCESS_DAO_
#define _PROCESS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteDO.h"
#include "../../domain/query/process/ProcessListQuery.h"

/**
 * 工艺相关的数据库操作实现
 */
class ProcessDAO : public BaseDAO
{
public:
	// 统计工艺列表数据条数
	uint64_t count(const ProcessListQuery::Wrapper& query);
	// 分页查询工艺列表
	list<ProRouteDO> selectWithPage(const ProcessListQuery::Wrapper& query);
	// 通过id查询工艺详情
	list<ProRouteDO> selectById(const ProcessDetailQuery::Wrapper& query);
	// 添加工艺
	uint64_t insert(const ProRouteDO& iObj, const string username);
	// 修改工艺
	int update(const ProRouteDO& uObj, const string updatename);
	// 通过ID删除组成工序
	int deleteById(list<uint64_t> id);
	// 导出工艺
	list<ProRouteDO> selectWithProcessExport(const ProcessListQuery::Wrapper& query);
	// 删除工艺
	int deleteById(uint64_t id);
	
};
#endif // !_SAMPLE_DAO_
