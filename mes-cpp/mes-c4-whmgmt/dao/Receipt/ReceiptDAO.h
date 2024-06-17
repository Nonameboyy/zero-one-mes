#pragma once

#ifndef _RECEIPT_DAO_H
#define _RECEIPT_DAO_H

#include "BaseDAO.h"
#include "../../domain/do/Receipt/ReceiptDO.h"
#include "../../domain/query/Receipt/ReceiptQuery.h"

/**
* 单据列表 数据模型
*/
class ReceiptPageTableDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReceiptTableQuery::Wrapper& query);
	// 分页查询数据
	std::list<ReceiptPageTableDO> selectWithPage(const ReceiptTableQuery::Wrapper& query);
};

/**
* 单据详情 数据模型
*/
class ReceiptDetailDAO : public BaseDAO
{
public:
	// 查询数据详情
	ReceiptDetailDO selectByRecptCode(const ReceiptDetailQuery::Wrapper& query);
};




#endif // _RECEIPT_DAO_H