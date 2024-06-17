#pragma once
#ifndef _SINGLE_DEFECT_SERVICE_
#define _SINGLE_DEFECT_SERVICE_
#include <list>
#include "domain/vo/Single_Defect/Single_Defect_VO.h"
#include "domain/query/Single_Defect/Single_Defect_Query.h"
#include "domain/dto/Single_Defect/Single_Defect_DTO.h"

/**
 * ������Ϣ�ķ������
 */
class Single_Defect_Service
{
public:
	// ��ҳ��ѯ����������
	SinglePageDTO::Wrapper listAll_Index(const SingleQuery::Wrapper& query);
	// ��ҳ��ѯȱ������
	DefectPageDTO::Wrapper listAll_Defect(const DefectQuery::Wrapper& query);
	// ����ȱ������
	uint64_t saveData(const DefectDTO::Wrapper& dto);
	// �޸�ȱ������
	bool updateData(const DefectDTO::Wrapper& dto);
	// ͨ��ȱ��IDɾ��ȱ������
	bool removeData(uint64_t id);
};

#endif // !_SINGLE_DEFECT_SERVICE_
