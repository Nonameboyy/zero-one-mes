#pragma once
#ifndef _Single_Defect_DAO
#define _Single_Defect_DAO
#include "BaseDAO.h"
#include "../../domain/do/Single_Defect/Single_Defect_DO.h"
#include "../../domain/query/Single_Defect/Single_Defect_Query.h"

/**
 * ���ϼ�����Ϣ��Ϣ�����ݿ����
 */
class Single_Defect_DAO : public BaseDAO
{
public:
	// ͳ����ؼ������������
	uint64_t count_Index(const SingleQuery::Wrapper& query);
	// ��ҳ��ѯ���������
	list<IndexDO> selectIndexPage(const SingleQuery::Wrapper& query);
	// ͳ�����ȱ����������
	uint64_t count_Defect(const DefectQuery::Wrapper& query);
	// ��ҳ��ѯȱ������
	list<DefectDO> selectDefectPage(const DefectQuery::Wrapper& query);
	// ����ȱ������
	uint64_t insert(const DefectDO& iObj);
	// �޸�ȱ������
	int update(const DefectDO& uObj);
	// ͨ��IDɾ��ȱ������
	int deleteById(uint64_t iqc_id);
};


#endif // !_Single_Defect_DAO
