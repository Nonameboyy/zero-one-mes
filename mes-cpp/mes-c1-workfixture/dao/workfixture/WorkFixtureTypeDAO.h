#pragma once
/*
 @Author: Croissant
*/
#ifndef _WORKFIXTURETYPEDAO_H_
#define _WORKFIXTURETYPEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/workfixture/WorkFixtureTypeSettingDO.h"
#include "../../domain/query/workfixture/WorkFixtureTypeCreateQuery.h"
#include "../../domain/query/workfixture/WorkFixtureTypeDeleteQuery.h"
#include "../../domain/query/workfixture/WorkFixtureTypeExportQuery.h"
#include "../../domain/query/workfixture/WorkFixtureTypeListQuery.h"
#include "../../domain/query/workfixture/WorkFixtureTypeNameListQuery.h"
#include "../../domain/query/workfixture/WorkFixtureTypeUpdateQuery.h"

/**
 * 数据库操作实现
 */
class WorkFixtureTypeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const WorkFixtureTypeListQuery::Wrapper& query);
	// 查询所有数据
	list<WorkFixtureTypeSettingDO> selectAll();
	// 分页查询数据
	list<WorkFixtureTypeSettingDO> selectWithPage(const WorkFixtureTypeListQuery::Wrapper& query);
	// 通过Code编码查数据
	list<WorkFixtureTypeSettingDO> selectByCode(string code);
	// 通过Name查数据
	list<WorkFixtureTypeSettingDO> selectByName(string name);
	// 插入数据
	uint64_t insert(const WorkFixtureTypeSettingDO& iObj);
	// 修改数据
	int update(const WorkFixtureTypeSettingDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
	//导出
	void makeFile();
};
#endif // !_WORKFIXTURETYPEDAO_H_
