#include "stdafx.h"
#include "DeleteWorkReportDAO.h"


int DeleteWorkReportDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `pro_feedback` WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
