#pragma once

#ifndef _RECEIPT_DO_H
#define _RECEIPT_DO_H
#include "../DoInclude.h"

/**
 * ��ȡ�����б� ���ݿ�ʵ����
 */
class ReceiptPageTableDO
{
	// ���ݿ�ı� wm_item_recpt
	// 
	// ��ⵥID
	CC_SYNTHESIZE(int32_t, recptId, RecptId);

	// ��ⵥ���
	CC_SYNTHESIZE(string, recptCode, RecptCode);

	// ��ⵥ����
	CC_SYNTHESIZE(string, recptName, RecptName);

	// ��Ӧ������
	CC_SYNTHESIZE(string, vendorName, VendorName);

	// �������
	CC_SYNTHESIZE(string, poCode, PoCode);

	// ������� 
	CC_SYNTHESIZE(string, recptDate, RecptDate);

	// ����״̬
	CC_SYNTHESIZE(string, status, Status);

public:
	ReceiptPageTableDO() {
		recptId = 0;
		recptCode = "";
		recptName = "";
		vendorName = "";
		poCode = "";
		recptDate = "";
		status = "";
	}
};

/**
* ��ȡ�������� ���ݿ�ʵ����
*/
class ReceiptDetailDO : public ReceiptPageTableDO
{
	// ���ֿ�
	CC_SYNTHESIZE(string, warehouseName, WarehouseName);

	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	ReceiptDetailDO() {
		warehouseName = "";
		remark = "";
	}
};
#endif // !_RECEIPT_DO_H
