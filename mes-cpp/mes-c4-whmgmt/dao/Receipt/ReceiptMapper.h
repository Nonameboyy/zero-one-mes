#pragma once
#ifndef _RECEIPT_MAPPER_
#define _RECEIPT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Receipt/ReceiptDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ReceiptMapper : public Mapper<ReceiptPageTableDO>
{
public:
	ReceiptPageTableDO mapper(ResultSet* resultSet) const override
	{
		ReceiptPageTableDO data;
		data.setRecptId(resultSet->getUInt(1));
		data.setRecptCode(resultSet->getString(2));
		data.setRecptName(resultSet->getString(3));
		data.setVendorName(resultSet->getString(4));
		data.setPoCode(resultSet->getString(5));
		data.setRecptDate(resultSet->getString(6));
		data.setStatus(resultSet->getString(7));
		return data;
	}
};

class ReceiptDetailMapper : public Mapper<ReceiptDetailDO>
{
public:
	ReceiptDetailDO mapper(ResultSet* resultSet) const override
	{
		ReceiptDetailDO data;
		data.setRecptId(resultSet->getUInt(1));
		data.setRecptCode(resultSet->getString(2));
		data.setRecptName(resultSet->getString(3));
		data.setVendorName(resultSet->getString(4));
		data.setPoCode(resultSet->getString(5));
		data.setRecptDate(resultSet->getString(6));
		data.setStatus(resultSet->getString(7));
		data.setWarehouseName(resultSet->getString(8));
		data.setRemark(resultSet->getString(9));
		return data;
	}
};

#endif // !_RECEIPT_MAPPER_