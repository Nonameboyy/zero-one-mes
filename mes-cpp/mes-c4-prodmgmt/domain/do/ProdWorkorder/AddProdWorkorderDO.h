#pragma once
#ifndef _ADDPRODWORKORDER_DO_
#define _ADDPRODWORKORDER_DO_
#include "../DoInclude.h"

/**
 * �����������ݿ�ʵ����
 */
class AddProdWorkorderDO
{
	//����ID;workorder_id;bigint
	CC_SYNTHESIZE(int, workorder_id, Workorder_id);
	//�������;workorder_code;varchar
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//��������;workorder_name;varchar
	CC_SYNTHESIZE(string, workorder_name, Workorder_name);
	//��Դ����;order_source;varchar
	CC_SYNTHESIZE(string, order_source, Order_source);
	//����״̬;status;varchar
	CC_SYNTHESIZE(string, status, Status);
	//��������;workorder_type;varchar
	CC_SYNTHESIZE(string, workorder_type, Workorder_type);
	//��Ʒ���;product_code;varchar
	CC_SYNTHESIZE(string, product_code, Product_code);
	//��Ʒ����;product_name;varchar
	CC_SYNTHESIZE(string, product_name, Product_name);
	//����ͺ�;product_spc;varchar
	CC_SYNTHESIZE(string, product_spc, Product_spc);
	//��λ;unit_of_measure;varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//��������������������;quantity;double
	CC_SYNTHESIZE(double, quantity, Quantity);
	//��������;request_date;datetime
	CC_SYNTHESIZE(string, request_date, Request_date);
	//���κ�;batch_code;varchar
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	//��ע;remark;varchar
	CC_SYNTHESIZE(string, remark, Remark);
	//��ƷID;product_id;bigint
	CC_SYNTHESIZE(int, product_id, Product_id);
	//���и��ڵ�ID;ancestors;varchar
	CC_SYNTHESIZE(string, ancestors, Ancestors);
public:
	AddProdWorkorderDO() {
		workorder_id = 0;
		workorder_code = "";
		workorder_name = "";
		order_source = "";
		status = "";
		workorder_type = "";
		product_code = "";
		product_name = "";
		product_spc = "";
		unit_of_measure = "";
		quantity = 0.0;
		request_date = "";
		batch_code = "";
		remark = "";
		product_id = 0;
		ancestors = "";
	}
};

#endif // !_ADDPRODWORKORDER_DO_