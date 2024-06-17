#pragma once

#ifndef _SET_DAO_
#define _SET_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProProcessDO.h"
#include "../../domain/do/pro/ProProcessContentDO.h"
#include "../../domain/query/set/SetProListQuery.h"
#include "../../domain/query/set/ProDetailQuery.h"
#include "../../domain/query/set/ProListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SetDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SetProListQuery::Wrapper& query);
	// ��ҳ��ѯ������
	list<ProProcessContentDO> selectWithPage(const SetProListQuery::Wrapper& query);
	// ͨ��id��ѯ����
	list<ProProcessContentDO> selectById(const uint64_t& id);
	// ��ӹ���
	uint64_t insertSet(const ProProcessDO& iObj, const string username);
	// ��ӹ���������
	uint64_t insertstepSet(const ProProcessContentDO& iObj, const string username);
	// �޸Ĺ���
	int updateSet(const ProProcessDO& uObj, const string username);
	// ͳ����������
	uint64_t countForProcess(const ProListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ProProcessDO> selectWithPageForProcess(const ProListQuery::Wrapper& query);
	// ��ѯ���������б�
	std::list<ProProcessDO> selectProNameList();
	// ͨ�� ����id ��ѯ ����˵��
	std::list<ProProcessDO> selectByid(const ProDetailQuery::Wrapper& query);
	// ����������
	list<ProProcessContentDO> selectWithStepExport(const SetProListQuery::Wrapper& query);

};
#endif // !_SET_DAO_
