#ifndef _MACHINERY_SUBJECT_MAPPER_
#define _MACHINERY_SUBJECT_MAPPER_

#include "Mapper.h"
#include "../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"

/**
* 点检保养项目表字段匹配映射
*/
class MachinerySubjectMapper : public Mapper<DvCheckSubjectDO>
{
public:
	DvCheckSubjectDO mapper(ResultSet* resultSet) const override
	{
		DvCheckSubjectDO data;
		data.setRecord_id(resultSet->getUInt64(1));
		data.setSubject_code(resultSet->getString(2));
		data.setSubject_name(resultSet->getString(3));
		data.setSubject_type(resultSet->getString(4));
		data.setSubject_content(resultSet->getString(5));
		data.setSubject_standard(resultSet->getString(6));
		return data;
	}
};

#endif // !_MACHINERY_SUBJECT_MAPPER_