#pragma once

#ifndef _DELETEWORKREPORT_DO_H
#define _DELETEWORKREPORT_DO_H
#include "../DoInclude.h"

/**
 * ɾ������ ���ݿ�ʵ����
 */
class DeleteWorkReportDO
{
	// ���ݿ�ı� pro_feedback
	// 
	// ��¼ID
	CC_SYNTHESIZE(uint64_t, recordId, RecordId);

public:
	DeleteWorkReportDO() {
		recordId = 0;
	}
};

#endif // !_DELETEWORKREPORT_DO_H
