#pragma once
#ifndef _INSPECT_DAO
#define _INSPECT_DAO
#include "BaseDAO.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"
#include "../../domain/query/LaiLiaoInspect/InspectQuery.h"

/**
 * ���ϼ�����Ϣ��Ϣ�����ݿ����
 */
class InspectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const InspectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<InspectDO> selectWithPage(const InspectQuery::Wrapper& query);
	//��ѯ����
	Inspect_detailDO selectWithID(const int& iqc_id);
	// ��������
	uint64_t insert(const InspectDO& iObj);
	// �޸�����
	int update(const InspectDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t iqc_id);
	//ȷ�ϼ��鵥
	int Is_Ok( InspectDO& uObj);
	//��ɼ��鵥
	int Finished( InspectDO& uObj);
	//�������鵥
	list<InspectDO> selectAll(const Inspect_tableQuery::Wrapper& query);
};


#endif // !_INSPECT_DAO

