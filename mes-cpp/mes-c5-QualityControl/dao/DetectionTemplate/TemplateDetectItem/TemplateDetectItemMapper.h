#pragma once
#ifndef _TEMPLATEDETECTITEM_MAPPER_
#define _TEMPLATEDETECTITEM_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/DetectionTemplate/TemplateDetectItemDO.h"

class TemplateDetectItemMapper : public Mapper<TemplateDetectItemDO>
{
public:
	TemplateDetectItemDO mapper(ResultSet* resultSet) const override
	{
		TemplateDetectItemDO data;
		data.setRecord_id(resultSet->getUInt64(1));
		data.setTemplate_id(resultSet->getUInt64(2));
		data.setIndex_id(resultSet->getUInt64(3));
		data.setIndex_code(resultSet->getString(4));
		data.setIndex_name(resultSet->getString(5));
		data.setIndex_type(resultSet->getString(6));
		data.setQc_tool(resultSet->getString(7));
		data.setCheck_method(resultSet->getString(8));
		data.setStander_val(resultSet->getDouble(9));
		data.setUnit_of_measure(resultSet->getString(10));
		data.setThreshold_max(resultSet->getDouble(11));
		data.setThreshold_min(resultSet->getDouble(12));
		data.setDoc_url(resultSet->getString(13));
		data.setRemark(resultSet->getString(14));
		data.setAttr1(resultSet->getString(15));
		data.setAttr2(resultSet->getString(16));
		data.setAttr3(resultSet->getInt(17));
		data.setAttr4(resultSet->getInt(18));
		data.setCreate_by(resultSet->getString(19));
		data.setCreate_time(resultSet->getString(20));
		data.setUpdate_by(resultSet->getString(21));
		data.setUpdate_time(resultSet->getString(22));
		return data;
	}
};
#endif // !_TEMPLATEDETECTITEM_MAPPER_
