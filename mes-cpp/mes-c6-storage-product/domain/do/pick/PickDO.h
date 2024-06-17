#pragma once

#ifndef _PICK_DO_
#define _PICK_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PickDO
{
	// ���ϵ�ID
	CC_SYNTHESIZE(int64_t, issueId, Id);
	// ���ϵ����
	CC_SYNTHESIZE(string, issueCode, Icode);
	// ���ϵ�����
	CC_SYNTHESIZE(string, issueName, Iname);
	// ��������
	CC_SYNTHESIZE(string, workorderCode, Wcode);
public:
	PickDO() {
		issueId = 0;
		issueCode = "input issueCode";
		issueName = "input issueName";
		workorderCode = "input workorderCode";
	}
};

#endif // !_PICK_DO_
