#pragma once
/*
*
*/
#ifndef _DV__CHECK__SUBJECT_MAPPER_
#define _DV__CHECK__SUBJECT_MAPPER_

#include "Mapper.h"
#include "../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"

/**
 * dv_check_plan±Ì£¨◊÷∂Œ∆•≈‰”≥…‰
 */
class Dv_check_subjectDeleteMapper : public Mapper<DvCheckSubjectDO>
{
public:
	DvCheckSubjectDO mapper(ResultSet* resultSet) const override
	{
		DvCheckSubjectDO data;

		data.setRecord_id(resultSet->getInt64(1));
		data.setPlan_id(resultSet->getInt64(2));
		data.setSubject_id(resultSet->getInt64(3));
		data.setSubject_code(resultSet->getString(4));
		data.setSubject_name(resultSet->getString(5));
		return data;
	}
};

#endif // !_DV__CHECK__SUBJECT_MAPPER_
