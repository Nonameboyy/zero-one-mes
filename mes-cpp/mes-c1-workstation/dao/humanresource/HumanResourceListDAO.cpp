#include "stdafx.h"
#include "HumanResourceListDAO.h"
#include "HumanResourceListMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define HUMANRESOURCE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->workstationId) { \
	sql << " AND workstation_id=?"; \
	SQLPARAMS_PUSH(params, "i", uint64_t, query->workstationId.getValue(1)); \
}

//ͳ�ƹ���վ������Դ�����ж���������
uint64_t HumanResourceListDAO::count(const HumanResourceListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM md_workstation_worker";
	HUMANRESOURCE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// ��ҳ��ѯ����
std::list<HumanResourceListDO> HumanResourceListDAO::selectWithPage(const HumanResourceListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT record_id,post_name,quantity,workstation_id,post_id FROM md_workstation_worker";
	HUMANRESOURCE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	HumanResourceListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<HumanResourceListDO, HumanResourceListMapper>(sqlStr, mapper, params);
}

// ͨ������վID��ѯ����
std::list<HumanResourceListDO> HumanResourceListDAO::selectById(const string& workstationId)
{
	string sql = "SELECT record_id,post_name,quantity,workstation_id,post_id FROM md_workstation_worker WHERE workstation_id = ?";
	HumanResourceListMapper mapper;
	return sqlSession->executeQuery<HumanResourceListDO, HumanResourceListMapper>(sql, mapper, "%ull", workstationId);
}

//����µĹ���վ������Դ����
uint64_t HumanResourceListDAO::insert(const HumanResourceListDO& iObj)
{
	string sql = "INSERT INTO `md_workstation_worker` (`post_name`, `quantity` ,`workstation_id` , `post_id`) VALUES (?, ?, ? ,?)";
	return sqlSession->executeInsert(sql, "%s%i%ull%ull", iObj.getPostName(), iObj.getQuantity(), iObj.getWorkstationId(), iObj.getPostId());

}

//�޸Ĺ���վ������Դ����
int HumanResourceListDAO::update(const HumanResourceListDO& uObj)
{
	string sql = "UPDATE `md_workstation_worker` SET `post_name`=?, `quantity`=?, `workstation_id`=? WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%s%i%ull%ull", uObj.getPostName(), uObj.getQuantity(), uObj.getWorkstationId(), uObj.getRecordId());
}

//ɾ������վ������Դ����
int HumanResourceListDAO::deleteById(uint64_t recordId)
{
	string sql = "DELETE FROM `md_workstation_worker` WHERE record_id = ?";
	return sqlSession->executeUpdate(sql, "%ull", recordId);
}