#pragma once
#ifndef _APPROVALSTAGEDTO_DO_
#define _APPROVALSTAGEDTO_DO_
#include "../DoInclude.h"

/**
 * ��ȡ���������б����ݿ�ʵ����
 */
class ApprovalStageDO
{
public:
	//��¼id/�����������;record_id;bigint
	CC_SYNTHESIZE(uint64_t, record_id, c_record_id);
	//����״̬;status;varchar
	CC_SYNTHESIZE(string, status, c_status);
public:
	ApprovalStageDO() {
		record_id = 0;
		status = "";
	}
};


#endif // !_GETPRODUCTIONREPORTLIST_DO_