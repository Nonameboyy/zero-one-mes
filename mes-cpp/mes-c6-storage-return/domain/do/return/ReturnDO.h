#pragma once

#ifndef _RETURN_DO_
#define _RETURN_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ReturnDO
{
	// �˻���ID
	CC_SYNTHESIZE(uint64_t, returnID, returnid);
	// �˻������
	CC_SYNTHESIZE(string, returnCode, returncode);
	// �˻�������
	CC_SYNTHESIZE(string, returnName, returnname);
	// �ɹ������
	CC_SYNTHESIZE(string, purchaseCode, purchasecode);
	// ��Ӧ�̱���
	CC_SYNTHESIZE(string, vendorCode, vendorcode);
	// ��Ӧ������
	CC_SYNTHESIZE(string, vendorName, vendorname);
	// �˻�����
	CC_SYNTHESIZE(string, returnDate, returndate);
	// ����״̬
	CC_SYNTHESIZE(string, status, status);
	// ���κ�
	CC_SYNTHESIZE(string, batchCode, batchcode);
	// ��ע
	CC_SYNTHESIZE(string, remark, remark);
	// ������
	CC_SYNTHESIZE(string, updateBy, updateby);
	// ����ʱ��
	CC_SYNTHESIZE(string, updateTime, updatetime);
	// ������
	CC_SYNTHESIZE(string, createBy, createby);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, createtime);
	// ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, vendorID, vendorid);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vendorNick, vendornick);
	
public:
	ReturnDO() {

		returnID = 0;
		returnCode = "0";
		returnName = "returnName";
		purchaseCode = "1";
		vendorCode = "2";
		vendorName = "vendorName";
		returnDate = "1234-12-31";
		status = "PREPARE";
		batchCode = "1234";
		remark = "null";
		updateBy = "updateBy";
		updateTime = "updateTime";
		createBy = "createBy";
		createTime = "createTime";
		vendorID = 0;
		vendorNick = "vendorNick";
	}
};

#endif // !_RETURN_DO_
