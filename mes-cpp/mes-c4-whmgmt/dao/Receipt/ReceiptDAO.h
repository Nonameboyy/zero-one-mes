#pragma once

#ifndef _RECEIPT_DAO_H
#define _RECEIPT_DAO_H

#include "BaseDAO.h"
#include "../../domain/do/Receipt/ReceiptDO.h"
#include "../../domain/query/Receipt/ReceiptQuery.h"

/**
* �����б� ����ģ��
*/
class ReceiptPageTableDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ReceiptTableQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ReceiptPageTableDO> selectWithPage(const ReceiptTableQuery::Wrapper& query);
};

/**
* �������� ����ģ��
*/
class ReceiptDetailDAO : public BaseDAO
{
public:
	// ��ѯ��������
	ReceiptDetailDO selectByRecptCode(const ReceiptDetailQuery::Wrapper& query);
};




#endif // _RECEIPT_DAO_H