#pragma once

#ifndef _DELETEWORKREPORT_DAO_H
#define _DELETEWORKREPORT_DAO_H
#include "BaseDAO.h"
#include "../../domain/do/prodmgmt/DeleteWorkReportDO.h"

/**
 * ɾ������ ���ݿ����ʵ��
 */
class DeleteWorkReportDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_DELETEWORKREPORT_DAO_H
