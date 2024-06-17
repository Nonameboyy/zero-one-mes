#pragma once
#ifndef _product_DO_
#define _product_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ProductDO
{
	// ��ⵥid��Ψһ��
	CC_SYNTHESIZE(uint64_t, recpt_id, Recpt_id);
	// ��ⵥ���
	CC_SYNTHESIZE(string, recpt_code, Recpt_code);
	// // ��ⵥ����
	CC_SYNTHESIZE(string, recpt_name, Recpt_name);
	// // ��������code
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//  �ֿ�����
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	//  ��Ʒ����
	CC_SYNTHESIZE(string, product_code, Product_code);
	//  ��Ʒ����
	CC_SYNTHESIZE(string, product_name, Product_name);
	
	//�������
	CC_SYNTHESIZE(string, recpt_date, Recpt_date);
	//����״̬
	CC_SYNTHESIZE(string, status, Status);

	

public:
	ProductDO() {
		recpt_id = 0;
		recpt_code = "0000";
		recpt_name = "Rtname";
		//workorder_id = "1";
		warehouse_name = "warehouse_name";
		product_name = "product_name";
		product_code= "product_code";
		recpt_date = "recpt_date";
		status = "status";
	}
};

#endif // !_rejectionQuery_DO_
