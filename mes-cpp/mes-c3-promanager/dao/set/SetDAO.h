#pragma once

#ifndef _SET_DAO_
#define _SET_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProProcessDO.h"
#include "../../domain/do/pro/ProProcessContentDO.h"
#include "../../domain/query/set/SetProListQuery.h"
#include "../../domain/query/set/ProDetailQuery.h"
#include "../../domain/query/set/ProListQuery.h"

/**
 * 示例表数据库操作实现
 */
class SetDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SetProListQuery::Wrapper& query);
	// 分页查询工序步骤
	list<ProProcessContentDO> selectWithPage(const SetProListQuery::Wrapper& query);
	// 通过id查询工序
	list<ProProcessContentDO> selectById(const uint64_t& id);
	// 添加工序
	uint64_t insertSet(const ProProcessDO& iObj, const string username);
	// 添加工序步骤数据
	uint64_t insertstepSet(const ProProcessContentDO& iObj, const string username);
	// 修改工序
	int updateSet(const ProProcessDO& uObj, const string username);
	// 统计数据条数
	uint64_t countForProcess(const ProListQuery::Wrapper& query);
	// 分页查询工序
	std::list<ProProcessDO> selectWithPageForProcess(const ProListQuery::Wrapper& query);
	// 查询工序名称列表
	std::list<ProProcessDO> selectProNameList();
	// 通过 工序id 查询 工序说明
	std::list<ProProcessDO> selectByid(const ProDetailQuery::Wrapper& query);
	// 导出工序步骤
	list<ProProcessContentDO> selectWithStepExport(const SetProListQuery::Wrapper& query);

};
#endif // !_SET_DAO_
