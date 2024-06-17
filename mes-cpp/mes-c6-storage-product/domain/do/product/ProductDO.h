#pragma once

#ifndef _PRODUCT_DO_
#define _PRODUCT_DO_
#include "../DoInclude.h"
/**
 * 生产领料数据库实体类
 */
class ProductTableDO {
	//领料单id
	CC_SYNTHESIZE(uint64_t, issue_id, Issue_id);
	//领料单编号
	CC_SYNTHESIZE(string, issue_code, Issue_code);
	//领料单名称
	CC_SYNTHESIZE(string, issue_name, Issue_name);
	//生产工单
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//客户编号
	CC_SYNTHESIZE(string, client_code, Client_code);
	//客户名称
	CC_SYNTHESIZE(string, client_name, Client_name);
	//领料日期
	CC_SYNTHESIZE(string, issue_date, Issue_date);
	//单据状态
	CC_SYNTHESIZE(string, status, Status1);
	//工作站id
	CC_SYNTHESIZE(uint64_t, workstation_id, Workstation_id);
	//工作站编号
	CC_SYNTHESIZE(string, workstation_code, Workstation_code);
	//工作站名称
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	//生产工单id
	CC_SYNTHESIZE(uint64_t, workorder_id, Workorder_id);
	//生产任务id
	CC_SYNTHESIZE(uint64_t, task_id, Task_id);
	//生产任务编码
	CC_SYNTHESIZE(string, task_code, Task_code);
	//客户id
	CC_SYNTHESIZE(uint64_t, client_id, Client_id);
	//客户简称
	CC_SYNTHESIZE(string, client_nick, Client_nick);
	//"仓库id"
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_id);
	//"仓库编码"
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//"仓库名称"
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	//"库区id"
	 CC_SYNTHESIZE(uint64_t, location_id, Location_id);
	//"库区编码"
	 CC_SYNTHESIZE(string, location_code, Location_code);
	//库区名称"
	 CC_SYNTHESIZE(string, location_name, Location_name);
	//"库位id"
	 CC_SYNTHESIZE(uint64_t, area_id, Area_id);
	//"库位编码"
	 CC_SYNTHESIZE(string, area_code, Area_code);
	//"库位名称"
	CC_SYNTHESIZE(string, area_name, Area_name);
	//"备注"
	CC_SYNTHESIZE(string, remark, Remark);
//"预留字段1"
	CC_SYNTHESIZE(string, attr1, Attr1);
//"预留字段2"
CC_SYNTHESIZE(string, attr2, Attr2);
//"预留字段3"
CC_SYNTHESIZE(int32_t, attr3, Attr3);
//"预留字段4"
CC_SYNTHESIZE(int32_t, attr4, Attr4);
//"创建者"
CC_SYNTHESIZE(string, create_by, Create_by);
//"创建时间"
CC_SYNTHESIZE(string, create_time, Create_time);
//"更新者"
CC_SYNTHESIZE(string, update_by, Update_by);
//"更新时间"
CC_SYNTHESIZE(string, update_time, Update_time);
public:
	ProductTableDO() {
		issue_id = 0;
		issue_code = "";
		issue_name = "";
		workorder_code = "";
		client_code = "";
		client_name = "";
		issue_date = "";
		status = "";
		workstation_id = 0;
		workstation_code = "";
		workstation_name = "";
		workorder_id = 0;
		task_id = 0;
		task_code = "";
		client_id = 0;
		client_nick = "";
		warehouse_id = 0;
		warehouse_code = "";
		warehouse_name = "";
		location_id = 0;
		location_code = "";
		location_name = "";
		area_id = 0;
		area_code = "";
		area_name = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";

	}
};
/**
 * 生产领料详情数据库实体类
 */
class ProductDetailDO :public ProductTableDO{

};
#endif 