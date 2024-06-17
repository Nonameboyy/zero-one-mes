#pragma once
#ifndef _rejectionQuery_DAO_
#define _rejectionQuery_DAO_
#include "BaseDAO.h"
#include "../../domain/do/rejection/rejectionQueryDO.h"
#include "../../domain/query/rejection/RejectQuery.h"

/**
 * 表数据库操作实现
 */
class RejectDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RejectQuery::Wrapper& query);
	// 分页查询数据
	list<RejectQueryDO> selectWithPage(const RejectQuery::Wrapper& query);
	// 通过退料单单号查询数据
	list<RejectQueryDO> selectByRt_code(const string& rt_code);
	// 通过生产工单查询数据
	list<RejectQueryDO> selectByWorkorder_code(const string& workorder_code);
	// 通过仓库名称查询数据
	list<RejectQueryDO> selectByWarehouse_name(const string& warehouse_name);
	//detailQuery
	list<RejectQueryDO> detailmes(const RejectDetailQuery::Wrapper& query);


	// 插入数据
	uint64_t insert(const RejectQueryDO& iObj);
	// 修改数据
	int update(const RejectQueryDO& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_rejectionQuery_DAO_