#pragma once

#ifndef _ProdWorkorder_DO_
#define _ProdWorkorder_DO_
#include "../DoInclude.h"

/**
 * 生产工单数据库实体类
 */
class ProdWorkorderDO
{	
	//工单id
	CC_SYNTHESIZE(uint64_t, workorder_id, WorkOrderID);
	//工单编码
	CC_SYNTHESIZE(string, workorder_code, WorkOrderCode);
	//工单名称
	CC_SYNTHESIZE(string, workorder_name, WorkOrderName);
	//工单类型
	CC_SYNTHESIZE(string, workorder_type, WorkOrderType);
	//来源类型
	CC_SYNTHESIZE(string, order_source, OrderSource);
	//来源单据
	CC_SYNTHESIZE(string, source_code, SourceCode);
	//产品id
	CC_SYNTHESIZE(uint64_t, product_id, ProductId);
	//产品编号
	CC_SYNTHESIZE(string, product_code, ProductCode);
	//产品名称
	CC_SYNTHESIZE(string, product_name, ProductName);
	//规格型号
	CC_SYNTHESIZE(string, product_spc, ProductSpc);
	//单位
	CC_SYNTHESIZE(string, unit_of_measure, UnitOfMeasure);
	//批次号
	CC_SYNTHESIZE(string, batch_code, BatchCode);
	//生产数量
	CC_SYNTHESIZE(double, quantity, Quantity);
	//已生产数量
	CC_SYNTHESIZE(double, quantity_produced, QuantityProduced);
	//调整数量
	CC_SYNTHESIZE(double, quantity_changed, QuantityChanged);
	//已排产数量
	CC_SYNTHESIZE(double, quantity_scheduled, QuantitySchedule);
	//客户ID
	CC_SYNTHESIZE(uint64_t, client_id, ClientId);
	//客户编码
	CC_SYNTHESIZE(string, client_code, ClientCode);
	//客户名称
	CC_SYNTHESIZE(string, client_name, ClientName);
	//供应商id
	CC_SYNTHESIZE(uint64_t, vendor_id, VendorId);
	//供应商编码
	CC_SYNTHESIZE(string, vendor_code, VendorCode);
	//供应商名称
	CC_SYNTHESIZE(string, vendor_name, VendorName);
	//完成时间
	CC_SYNTHESIZE(string, finish_date, FinishDate);
	//需求日期
	CC_SYNTHESIZE(string, request_date, RequestDate);
	//订单状态
	CC_SYNTHESIZE(string, status, Status);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//创建者
	CC_SYNTHESIZE(string, create_by, CreateBy);
	//创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//更新者
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	//更新时间
	CC_SYNTHESIZE(string, update_time, UpdateTime);
	//父工单ID
	CC_SYNTHESIZE(uint64_t, parent_id, ParentId);
	//所有父节点ID
	CC_SYNTHESIZE(string, ancestors, Ancestors);
public:
	ProdWorkorderDO() {
		workorder_id = 0;
		workorder_code = "";
		workorder_name = "";
		workorder_type = "";
		order_source = "";
		source_code = "";
		product_id = 0;
		product_code = "";
		product_name = "";
		product_spc = "";
		unit_of_measure = "";
		batch_code = "";
		quantity = 0.0;
		quantity_produced = 0.0;
		quantity_changed = 0.0;
		quantity_scheduled = 0.0;
		client_id = 0;
		client_code = "";
		client_name = "";
		vendor_id = 0;
		vendor_code = "";
		vendor_name = "";
		finish_date = "";
		request_date = "";
		status = "";
		remark = "";
		create_by = "";
		update_by = "";
		update_time = "";
		parent_id = 0;
		ancestors = "";
	}
};

#endif // !_ProdWorkorder_DO_
