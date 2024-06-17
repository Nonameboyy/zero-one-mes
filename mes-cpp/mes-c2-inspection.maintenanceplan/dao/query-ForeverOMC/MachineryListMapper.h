#ifndef _MACHINERY_LIST_MAPPER_
#define _MACHINERY_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"

/**
* Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
*/
class MachineryListMapper : public Mapper<Dv_check_machineryDO>
{
public:
	Dv_check_machineryDO mapper(ResultSet* resultSet) const override
	{
		Dv_check_machineryDO data;
		data.setRecord_id(resultSet->getUInt64(1));
		data.setMachinery_code(resultSet->getString(2));
		data.setMachinery_name(resultSet->getString(3));
		data.setMachinery_brand(resultSet->getString(4));
		data.setMachinery_spec(resultSet->getString(5));
		data.setRemark(resultSet->getString(6));
		return data;
	}
};

#endif // !_MACHINERY_LIST_MAPPER_