#pragma once
#ifndef _rejectionQuery_SERVICE_
#define _rejectionQuery_SERVICE_
#include <list>
#include "domain/vo/rejection/RejectVo.h"
#include "domain/dto/rejection/RejectDTO.h"
#include "domain/query/rejection/RejectQuery.h"
/**
 * �����б��ҳ��ѯ����
 */
class RejectTableQueryService
{
public:
	// ��ҳ��ѯ��������
	RejectPageDTO::Wrapper listAll(const RejectQuery::Wrapper& query);
	//��ѯ��ϸ����
	RejectDetailDTO::Wrapper queryDetail(const RejectDetailQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const RejectTableDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const RejectTableDTO::Wrapper& dto);
	//// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};


#endif 