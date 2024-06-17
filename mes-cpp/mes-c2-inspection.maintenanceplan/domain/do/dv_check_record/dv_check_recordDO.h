#ifndef _DV_CHECK_RECORD_DO_
#define _DV_CHECK_RECORD_DO_
#include "../DoInclude.h"

/**
* dv_check_record数据表实体类
*/
class DvCheckRecordDO
{
	// 计划ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// 计划ID
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// 计划编码
	CC_SYNTHESIZE(string, plan_code, Plan_code);
	// 计划名称
	CC_SYNTHESIZE(string, plan_name, Plan_name);
	// 计划类型
	CC_SYNTHESIZE(string, plan_type, Plan_type);
	// 设备ID
	CC_SYNTHESIZE(uint64_t, machinery_id, machinery_id);
	// 设备编码
	CC_SYNTHESIZE(string, machinery_code, Machinery_code);
	// 设备名称
	CC_SYNTHESIZE(string, machinery_name, Machinery_name);
	// 品牌
	CC_SYNTHESIZE(string, machinery_brand, Machinery_brand);
	// 规格型号
	CC_SYNTHESIZE(string, machinery_spec, Machinery_spec);
	// 点检时间
	CC_SYNTHESIZE(string, check_time, check_time);
	// 状态
	CC_SYNTHESIZE(string, status, Status);
	// 备注	
	CC_SYNTHESIZE(string, remark, Remark);
	// 预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// 预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// 预留字段3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// 预留字段4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// 创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	// 更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新时间
	CC_SYNTHESIZE(string, datetime, Datetime);
public:
	SampleDO() {
		record_id = 0;
		plan_id = 0;
		plan_code = "";
		plan_name = "";
		plan_type = "";
		machinery_id = 0;
		machinery_code = "";
		machinery_name = "";
		machinery_brand = "";
		machinery_spec = "";
		check_time = "";
		status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		datetime = "";
	}
};

#endif // !_DV_CHECK_RECORD_DO_