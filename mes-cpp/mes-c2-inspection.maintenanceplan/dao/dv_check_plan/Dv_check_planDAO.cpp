/*
* 
*/
#include "stdafx.h"
#include "Dv_check_planDAO.h"
#include "dv_check_planMapper.h"
#include <sstream>
#include"./dao/dv_check_plan/Dv_check_planDAO.h"

//�������������꣬�����ظ�����
//abf�����Ӧ���������sql���ĺ꣬���ڲ�ѯ������������ͷ�ANDһ��ȥ��ѯ
/*
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_code) { \
	sql << " AND `plan_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->plan_code.getValue("")); \
} \
if (query->plan_name) { \
	sql << " AND plan_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->plan_name.getValue("")); \
} \
if (query->plan_type) { \
	sql << " AND plan_type=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->plan_type.getValue("")); \
} \
if (query->status) { \
	sql << " AND status=?"; \
	SQLPARAMS_PUSH(params, "i", std::string, query->status.getValue("")); \
}

uint64_t Dv_check_planDAO::count(const MachineryPlanQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_check_plan";


	//SAMPLE_TERAM_PARSE(query, sql);
	SqlParams params; sql << " WHERE 1=1"; if (query->plan_code) {
		sql << " AND `plan_code`=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->plan_code.getValue(""))));
	} if (query->plan_name) {
		sql << " AND plan_name=?"; params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->plan_name.getValue(""))));
	} if (query->plan_type) {
		sql << " AND plan_type=?"; params.emplace_back(SqlParam("i", std::make_shared<std::string>(query->plan_type.getValue(""))));
	} if (query->status) {
		sql << " AND status=?"; params.emplace_back(SqlParam("i", std::make_shared<std::string>(query->status.getValue(""))));
	};


	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<Dv_check_planDO> Dv_check_planDAO::selectWithPage(const MachineryPlanQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT plan_id,plan_code,plan_name,plan_type,status FROM dv_check_plan";
	sql << "SELECT * FROM dv_check_plan";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	Dv_check_planMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_planDO, Dv_check_planMapper>(sqlStr, mapper, params);
}

*/

//----������Ҫһ��ֻ����id�Ĳ�ѯ�����ڽ���ɾ������ǰ�ĸ�����ѯ
/*
#define SAMPLE_TERAM_PARSE_ID_DELETE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_id) { \
	sql << " AND `plan_id`=?"; \
	SQLPARAMS_PUSH(params, "ll", uint64_t, query->plan_id.getValue(0)); \
} 

uint64_t Dv_check_planDAO::count(const MachineryPlanDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_check_plan";

	SAMPLE_TERAM_PARSE_ID_DELETE(query, sql);
	//SqlParams params;
	//sql << " WHERE 1=1"; if (query->plan_id) 
	//{
	//	sql << " AND `plan_id`=?";
	//	params.emplace_back(SqlParam("s", std::make_shared<long long>(query->plan_id.getValue(0))));
	//};


	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
*/

//��һ�ε�detail����
/*
std::list<Dv_check_planDO> Dv_check_planDAO::selectWithPage(const MachineryPlanDetailsQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT plan_id,plan_code,plan_name,plan_type,status FROM dv_check_plan";
	sql << "SELECT * FROM dv_check_plan";
	SAMPLE_TERAM_PARSE_ID_DELETE(query, sql);

	//����Ǽ̳е�DTO����û�ж�ҳ�����ԣ��������������
	//1������ҳ��  2��������ҳ����ע��  ����ʱע�����ԣ�
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	Dv_check_planMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_planDO, Dv_check_planMapper>(sqlStr, mapper, params);
}
*/
//---��ʽ��ʼ

//�ȶ���һ���򻯵ĺ�
#define SAMPLE_TERAM_PARSE_ID_DELETE_PLAN(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->plan_id) { \
	sql << " AND `plan_id`=?"; \
	SQLPARAMS_PUSH(params, "ll", int64_t, query->plan_id.getValue(0)); \
} 


std::list<Dv_check_planDO> Dv_check_planDAO::selectWithPage(const DeletePlanQuery::Wrapper& query)
{
	stringstream sql;
	//sql << "SELECT plan_id,plan_code,plan_name,plan_type,status FROM dv_check_plan";
	//sql << "SELECT * FROM dv_check_plan";
	sql << "SELECT * FROM dv_check_plan";
	SAMPLE_TERAM_PARSE_ID_DELETE_PLAN(query, sql);

	//����Ǽ̳е�DTO����û�ж�ҳ�����ԣ��������������
	//1������ҳ��  2��������ҳ����ע��  ����ʱע�����ԣ�
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	Dv_check_planMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Dv_check_planDO, Dv_check_planMapper>(sqlStr, mapper, params);
}


/*
std::list<SampleDO> Dv_check_planDO::selectByName(const string& name)
{
	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	SampleMapper mapper;
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sql, mapper, "%s", name);
}
*/

//��ʱ��ע�Ͳ��������룬�޸ģ�ɾ����
/*
uint64_t Dv_check_planDAO::insert(const Dv_check_planDO& iObj)
{
	string sql = "INSERT INTO `sample` (`name`, `sex`, `age`) VALUES (?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getName(), iObj.getSex(), iObj.getAge());
}

int Dv_check_planDAO::update(const Dv_check_planDO& uObj)
{
	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}
*/



int Dv_check_planDAO::dv_check_planDeleteById(int64_t id)
{
	string sql = "DELETE FROM `dv_check_plan` WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%ll", id);
}

int Dv_check_planDAO::dv_check_machineryDeleteByIdPlan(int64_t idp)
{
	string sql = "DELETE FROM `dv_check_machinery` WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%ll", idp);
}

int Dv_check_planDAO::dv_check_subjectDeleteByIdPlan(int64_t idp)
{
	string sql = "DELETE FROM `dv_check_subject` WHERE `plan_id`=?";
	return sqlSession->executeUpdate(sql, "%ll", idp);
}