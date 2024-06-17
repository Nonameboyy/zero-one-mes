#pragma once
#ifndef _RERURN_MAPPER_H_
#define _RETURN_MAPPER_H_
#include "Mapper.h"
#include "../../domain/do/return-ryan/ReturnDO_r.h"
class ReturnMapper_r : public Mapper<ReturnDO_r>
{
public:
	ReturnDO_r mapper(ResultSet* res) const override
	{
		//rt_id,rt_code,rt_name,po_code, vendor_name, batch_code, rt_date, status, remark
		ReturnDO_r data;
		data.setRt_id(res->getUInt64(1));
		data.setRt_code(res->getString(2));
		data.setRt_name(res->getString(3));
		data.setPo_code(res->getString(4));
		data.setVendor_name(res->getString(5));
		data.setBatch_code(res->getString(6));
		data.setRt_date(res->getString(7));
		data.setStatus_(res->getString(8));
		data.setRemark(res->getString(9));
		return data;
	}
};

#endif // !_DETECTIONITEMSETTINGS_MAPPER_
#pragma once
