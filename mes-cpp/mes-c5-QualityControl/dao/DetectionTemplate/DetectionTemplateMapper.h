#pragma once
#ifndef _DETECTIONTEMPLATE_MAPPER_
#define _DETECTIONTEMPLATE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/DetectionTemplate/DetectionTemplateDO.h"

// 获取检测模板列表
class DetectionTemplateMapper : public Mapper<DetectionTemplateDO> {
public:
	DetectionTemplateDO mapper(ResultSet* resultSet) const override {
		DetectionTemplateDO data;
		int i = 1;
		data.setTemplate_Id(resultSet->getUInt64(i++));
		data.setTemplate_Code(resultSet->getString(i++));
		data.setTemplate_Name(resultSet->getString(i++));
		data.setQc_Types(resultSet->getString(i++));
		data.setEnable_Flag(resultSet->getString(i++));
		return data;
	}
};

class DetectionTemplateDetilesMapper : public Mapper<DetectionTemplateDO>
{
public:
	DetectionTemplateDO mapper(ResultSet* resultSet) const override
	{
		DetectionTemplateDO data;
		data.setTemplate_Code(resultSet->getString(1));
		data.setTemplate_Name(resultSet->getString(2));
		data.setQc_Types(resultSet->getString(3));
		data.setEnable_Flag(resultSet->getString(4));
		data.setRemark(resultSet->getString(5));
		return data;
	}
};

#endif // !_DETECTIONTEMPLATE_MAPPER_
