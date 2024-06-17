#pragma once

#ifndef __RECEIPT_SERVICE_
#define __RECEIPT_SERVICE_
#include <list>
#include "../../domain/dto/Receipt/ReceiptDTO.h"
#include "../../domain/query/Receipt/ReceiptQuery.h"
#include "../../domain/do/Receipt/ReceiptDO.h"

/**
 * ��ȡ�����б� 
 */
class ReceiptService
{
public:
	// ��ҳ��ѯ�б�����
	ReceiptPageTableDTO::Wrapper listAll(const ReceiptTableQuery::Wrapper& query);

	// ��ѯ��ϸ����
	ReceiptDetailDTO::Wrapper getDetail(const ReceiptDetailQuery::Wrapper& query);
};

#endif // !__RECEIPT_SERVICE_

