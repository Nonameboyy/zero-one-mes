#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_DO_
#define _DV__CHECK__MACHINERY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Dv_check_machineryDO
{
	//流水号
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// 计划ID，
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	//设备id
	CC_SYNTHESIZE(uint64_t, machinery_id, Machinery_id);
	//设备编码
	CC_SYNTHESIZE(string, machinery_code, Machinery_code);
	//设备名称
	CC_SYNTHESIZE(string, machinery_name, Machinery_name);
	//品牌
	CC_SYNTHESIZE(string, machinery_brand, Machinery_brand);
	//规格型号
	CC_SYNTHESIZE(string, machinery_spec, Machinery_spec);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//预留字段3
	CC_SYNTHESIZE(uint32_t, attr3, Attr3);
	//预留字段4
	CC_SYNTHESIZE(uint32_t, attr4, Attr4);
	//创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	//更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);

public:
	//默认构造
	Dv_check_machineryDO() {
		record_id = 0;
		plan_id = 0;
		machinery_id = 0;
		machinery_code = "";
		machinery_name = "";
		machinery_brand = "";
		machinery_spec = "";
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

#endif // !_DV__CHECK__Machinery_DO_
