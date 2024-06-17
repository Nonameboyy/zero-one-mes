#pragma once
#ifndef _SETEXPORT_MAPPER_
#define _SETEXPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProProcessDO.h"

/**
 * µ¼³ö¹¤ÐòÓ³Éä
 */
class SetExportMapper : public Mapper<ProProcessDO>
{
public:
	ProProcessDO mapper(ResultSet* resultSet) const override
	{
		ProProcessDO data;
		data.setProcessCode(resultSet->getString(1));
		data.setProcessName(resultSet->getString(2));
		data.setAttention(resultSet->getString(3));
		data.setEnableFlag(resultSet->getString(4));
		return data;
	}
};


#endif // !_SAMPLE_MAPPER_
