#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_MAPPER_
#define _PLANSUBJECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/planSubject/PlanSubjectDO.h"

/**
 * 示例表字段匹配映射
 */
class PlanSubjectMapper : public Mapper<PlanSubjectTableDO>
{
public:
	// 项目编码
	CC_SYNTHESIZE(string, code, Code);
	// 项目名称
	CC_SYNTHESIZE(string, name, Name);
	// 项目类型
	CC_SYNTHESIZE(string, type, Type);
	// 项目内容
	CC_SYNTHESIZE(string, content, Content);
	// 项目标准
	CC_SYNTHESIZE(string, standard, Standard);

	PlanSubjectTableDO mapper(ResultSet* resultSet) const override
	{
		PlanSubjectTableDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setType(resultSet->getString(3));
		data.setContent(resultSet->getString(4));
		data.setStandard(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
