#pragma once
#ifndef _GETPRODWORKORDERLIST_DO_
#define _GETPRODWORKORDERLIST_DO_
#include "../DoInclude.h"

/**
 * 获取生产工单列表数据库实体类
 */
class GetProdWorkorderListDO
{
	//工单ID;workorder_id;bigint
	CC_SYNTHESIZE(int, workorder_id, Workorder_id);
	//工单编码;workorder_code;varchar
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//工单名称;workorder_name;varchar
	CC_SYNTHESIZE(string, workorder_name, Workorder_name);
	//工单类型;workorder_type;varchar
	CC_SYNTHESIZE(string, workorder_type, Workorder_type);
	//工单来源;order_source;varchar
	CC_SYNTHESIZE(string, order_source, Order_source);
	//订单编号;source_code;varchar
	CC_SYNTHESIZE(string, source_code, Source_code);
	//产品编号;product_code;varchar
	CC_SYNTHESIZE(string, product_code, Product_code);
	//产品名称;product_name;varchar
	CC_SYNTHESIZE(string, product_name, Product_name);
	//规格型号;product_spc;varchar
	CC_SYNTHESIZE(string, product_spc, Product_spc);
	//单位;unit_of_measure;varchar
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//工单数量（生产数量）;quantity;double
	CC_SYNTHESIZE(double, quantity, Quantity);
	//调整数量;quantity_changed;double
	CC_SYNTHESIZE(double, quantity_changed, Quantity_changed);
	//已生产数量;quantity_produced;double
	CC_SYNTHESIZE(double, quantity_produced, Quantity_produced);
	//批次号;batch_code;varchar
	CC_SYNTHESIZE(string, batch_code, Batch_code);
	//客户编码;client_code;varchar
	CC_SYNTHESIZE(string, client_code, Client_code);
	//客户名称;client_name;varchar
	CC_SYNTHESIZE(string, client_name, Client_name);
	//需求日期;request_date;datetime
	CC_SYNTHESIZE(string, request_date, Request_date);
	//单据状态;status;varchar
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