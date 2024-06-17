#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_MAPPER_
#define _PLANSUBJECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/planSubject/PlanSubjectDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class PlanSubjectMapper : public Mapper<PlanSubjectTableDO>
{
public:
	// ��Ŀ����
	CC_SYNTHESIZE(string, code, Code);
	// ��Ŀ����
	CC_SYNTHESIZE(string, name, Name);
	// ��Ŀ����
	CC_SYNTHESIZE(string, type, Type);
	// ��Ŀ����
	CC_SYNTHESIZE(string, content, Content);
	// ��Ŀ��׼
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
