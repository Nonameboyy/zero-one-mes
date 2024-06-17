#include "stdafx.h"
#include "SetExportDAO.h"
#include "SetExportMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->processCode) { \
	sql << " AND `process_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->processCode.getValue("")); \
} \
if (query->processName) { \
	sql << " AND process_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->processName.getValue("")); \
} \
if (query->enableFlag) { \
	sql << " AND enable_flag=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->enableFlag.getValue("")); \
}
// �������� ��ѯ��������
list<ProProcessDO> SetExportDAO::selectWithProcessExport(const ProcessExportQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT process_code,process_name,attention,enable_flag FROM pro_process";
	SAMPLE_TERAM_PARSE(query, sql);
	SetExportMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProProcessDO, SetExportMapper>(sqlStr, mapper, params);
}
