#pragma once
#ifndef _SET_EXPOET_DAO_
#define _SET_EXPOET_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProProcessDO.h"
#include "../../domain/query/set/ProcessExportQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SetExportDAO : public BaseDAO
{
public:
	// �������� ��ѯ��������
	list<ProProcessDO> selectWithProcessExport(const ProcessExportQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_