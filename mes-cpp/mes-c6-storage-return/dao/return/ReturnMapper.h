#pragma once

#ifndef _RETURN_MAPPER_
#define _RETURN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/return/ReturnDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class ReturnMapper : public Mapper<ReturnDO>
{
public:
	ReturnDO mapper(ResultSet* returnSet) const override
	{
		ReturnDO data;
		data.setreturncode(returnSet->getString(1));
		data.setreturnname(returnSet->getString(2));
		data.setpurchasecode(returnSet->getString(3));
		data.setvendorcode(returnSet->getString(4));
		data.setvendorname(returnSet->getString(5));
		data.setreturndate(returnSet->getString(6));
		data.setstatus(returnSet->getString(7));
		return data;
	}
};
class ReturnDetailMapper : public Mapper<ReturnDO>
{
public:
	ReturnDO mapper(ResultSet* returnSet) const override
	{
		ReturnDO data;
		data.setreturncode(returnSet->getString(1));
		data.setreturnname(returnSet->getString(2));
		data.setpurchasecode(returnSet->getString(3));
		data.setvendorcode(returnSet->getString(4));
		data.setvendorname(returnSet->getString(5));
		data.setreturndate(returnSet->getString(6));
		data.setstatus(returnSet->getString(7));
		data.setbatchcode(returnSet->getString(8));
		data.setremark(returnSet->getString(9));
		return data;
	}
};
#endif // !_RETURN_MAPPER_

