#pragma once
//ProdWorkorderInfo
#ifndef _PRODWORKORDERINFO_DO_
#define _PRODWORKORDERINFO_DO_
#include "../DoInclude.h"

class ProdWorkorderInfoDO {
	//����ID;workorder_id;bigint
	CC_SYNTHESIZE(int, workorder_id, Workorder_id);
	//��������;workorder_code;varchar
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//��������;workorder_name;varchar
	CC_SYNTHESIZE(string, workorder_name, Workorder_name);
	//��Դ����;order_source;varchar
	CC_SYNTHESIZE(string, order_source, Order_source);
	//�������;source_code;varchar
	CC_SYNTHESIZE(string, source_code, Source_code);
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
	//�ͻ�����;client_code;varchar
	CC_SYNTHESIZE(string, client_code, Client_code);
	//�ͻ�����;client_name;varchar
	CC_SYNTHESIZE(string, client_name, Client_name);
	//��Ӧ�̱���;vendor_code;varchar
	CC_SYNTHESIZE(string, vendor_code, Vendor_code);
	//��Ӧ������;vendor_name;varchar
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	//��ע;remark;varchar
	CC_SYNTHESIZE(string, remark, Remark);
public:
	ProdWorkorderInfoDO() {
		workorder_id = 0;
		workorder_code = "";
		workorder_name = "";
		order_source = " ";
		source_code = "";
		status = "";
		workorder_type = "";
		product_code = "";
		product_name = "";
		product_spc = "";
		unit_of_measure = "";
		quantity = 0;
		request_date = "";
		batch_code = "";
		client_code = "";
		client_name = "";
		vendor_code = "";
		vendor_name = "";
		remark = "";

	}
};


#endif // !_PRODWORKORDERINFO_DO_