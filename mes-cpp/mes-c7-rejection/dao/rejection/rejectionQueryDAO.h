#pragma once
#ifndef _rejectionQuery_DAO_
#define _rejectionQuery_DAO_
#include "BaseDAO.h"
#include "../../domain/do/rejection/rejectionQueryDO.h"
#include "../../domain/query/rejection/RejectQuery.h"

/**
 * �����ݿ����ʵ��
 */
class RejectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RejectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<RejectQueryDO> selectWithPage(const RejectQuery::Wrapper& query);
	// ͨ�����ϵ����Ų�ѯ����
	list<RejectQueryDO> selectByRt_code(const string& rt_code);
	// ͨ������������ѯ����
	list<RejectQueryDO> selectByWorkorder_code(const string& workorder_code);
	// ͨ���ֿ����Ʋ�ѯ����
	list<RejectQueryDO> selectByWarehouse_name(const string& warehouse_name);
	//detailQuery
	list<RejectQueryDO> detailmes(const RejectDetailQuery::Wrapper& query);


	// ��������
	uint64_t insert(const RejectQueryDO& iObj);
	// �޸�����
	int update(const RejectQueryDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_rejectionQuery_DAO_