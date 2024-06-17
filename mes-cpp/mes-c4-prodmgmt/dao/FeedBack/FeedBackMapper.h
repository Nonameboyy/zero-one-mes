#pragma once

#ifndef _FEEDBACK_MAPPER_
#define _FEEDBACK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/FeedBack/FeedBackDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class FeedBackMapper : public Mapper<FeedBackDO>
{
public:
	FeedBackDO mapper(ResultSet* resultSet) const override
	{
		FeedBackDO data;
		data.setFeedback_type(resultSet->getString(1));
		data.setFeedback_time(resultSet->getString(2));
		data.setItem_code(resultSet->getString(3));
		data.setItem_name(resultSet->getString(4));
		data.setQuantity_feedback(resultSet->getUInt64(5));
		data.setRecord_user(resultSet->getString(6));
		data.setSpecification(resultSet->getString(7));
		data.set_Status(resultSet->getString(8));
		data.setUser_name(resultSet->getString(9));
		data.setWorkorder_code(resultSet->getString(10));
		data.setWorkstation_name(resultSet->getString(11));
		return data;
	}
};

#endif // !_FEEDBACK_MAPPER_