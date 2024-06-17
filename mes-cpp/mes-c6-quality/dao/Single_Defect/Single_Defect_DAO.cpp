#include "stdafx.h"
#include "Single_Defect_DAO.h"
#include "Single_Defect_Mapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE1(query, sql) \
SqlParams params1; \
sql<<" WHERE 1=1"; \
if (query->iqc_id) { \
	sql << " AND `iqc_id`=?"; \
	SQLPARAMS_PUSH(params1, "ull", std::uint64_t, query->iqc_id.getValue(0)); \
} 

#define SAMPLE_TERAM_PARSE2(query, sql) \
SqlParams params2; \
sql<<" WHERE 1=1"; \
if (query->line_id) { \
	sql << " AND `line_id`=?"; \
	SQLPARAMS_PUSH(params2, "ull", std::uint64_t, query->line_id.getValue(0)); \
} 

// 统计检测项表数据条数

uint64_t Single_Defect_DAO::count_Index(const SingleQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_iqc_line ";
	SAMPLE_TERAM_PARSE1(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params1);
}

// 统计对应的缺陷表数据条数
uint64_t Single_Defect_DAO::count_Defect(const DefectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM qc_iqc_defect ";
	SAMPLE_TERAM_PARSE2(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params2);
}

list<IndexDO> Single_Defect_DAO::selectIndexPage(const SingleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT index_name,index_type,qc_tool,check_method,stander_val,unit_of_measure,threshold_max,threshold_min,cr_quantity,maj_quantity,min_quantity, remark FROM  qc_iqc_line";
	SAMPLE_TERAM_PARSE1(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	IndexMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<IndexDO, IndexMapper>(sqlStr, mapper, params1);
}

list<DefectDO> Single_Defect_DAO::selectDefectPage(const DefectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT record_id,iqc_id,line_id,defect_name,defect_level,defect_quantity,remark FROM  qc_iqc_defect";
	SAMPLE_TERAM_PARSE2(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DefectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DefectDO, DefectMapper>(sqlStr, mapper, params2);
}

uint64_t Single_Defect_DAO::insert(const DefectDO& iObj)
{
	string sql = "INSERT INTO `qc_iqc_defect` ( `record_id`,`iqc_id`,`line_id`,`defect_name`,`defect_level`,`defect_quantity`,`remark`) VALUES (?, ?, ?, ?, ?, ?, ?)";//
	return sqlSession->executeInsert(sql, "%ull%ull%ull%s%s%i%s",  //
		iObj.getRecord_id(),
		iObj.getIqc_id(),
		iObj.getLine_id(),
		iObj.getDefect_name(),
		iObj.getDefect_level(),
		iObj.getDefect_quantity(),
		iObj.getRemark()
	);
}

int Single_Defect_DAO::update(const DefectDO& uObj)
{
	string sql = "UPDATE `qc_iqc_defect` SET `defect_name`= ?,  `defect_level`= ?, `defect_quantity`= ? WHERE `record_id` = ?;";
	return sqlSession->executeUpdate(sql, "%s%s%i%ull",
		uObj.getDefect_name(),
		uObj.getDefect_level(),
		uObj.getDefect_quantity(),
		uObj.getRecord_id()
	);
}

int Single_Defect_DAO::deleteById(uint64_t record_id)
{
	string sql = "DELETE FROM `qc_iqc_defect` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", record_id);
}
