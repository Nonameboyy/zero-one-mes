#pragma once
#ifndef _GETPRODWORKORDERLIST_DO_
#define _GETPRODWORKORDERLIST_DO_
#include "../DoInclude.h"

/**
 * ��ȡ���������б����ݿ�ʵ����
 */
class GetProdWorkorderListDO
{
	//����ID;workorder_id;bigint
	CC_SYNTHESIZE(int, workorder_id, Workorder_id);
	//��������;workorder_code;varchar
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//��������;workorder_name;varchar
	CC_SYNTHESIZE(string, workorder_name, Workorder_name);
	//��������;workorder_type;varchar
	CC_SYNTHESIZE(string, workorder_type, Workorder_type);
	//������Դ;order_source;varchar
	CC_SYNTHESIZE(string, order_source, Order_source);
	//�������;source_code;varchar
	CC_SYNTHESIZE(string, source_code, Source_code);
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
	//��������;quantity_changed;double
	CC_SYNTHESIZE(double, quantity_changed, Quantity_changed);
	//����������;quantity_produced;double
	CC_SYNTHESIZE(double, quantity_produced, Quantity_produced);
	//���κ�;batch_code;varchar
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	//�ͻ�����;client_code;varchar
	CC_SYNTHESIZE(string, client_code, Client_code);
	//�ͻ�����;client_name;varchar
	CC_SYNTHESIZE(string, client_name, Client_name);
	//��������;request_date;datetime
	CC_SYNTHESIZE(string, request_date, Request_date);
	//����״̬;status;varchar
	CC_SYNTHESIZE(string, status, Status);
public:
	GetProdWorkorderListDO() {
		workorder_id = 0;
		workorder_code = "";
		workorder_name = "";
		workorder_type = "";
		order_source = " ";
		source_code = "";
		product_code = "";
		product_name = "";
		product_spc = "";
		unit_of_measure = "";
		quantity = 0;
		quantity_changed = 0;
		quantity_produced = 0;
		batch_code = "";
		client_code = "";
		client_name = "";
		request_date = "";	
		status = "";
	}
};
 

#endif // !_GETPRODWORKORDERLIST_DO_