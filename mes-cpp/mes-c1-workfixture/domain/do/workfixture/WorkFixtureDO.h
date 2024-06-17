#pragma once
#include "../DoInclude.h"

/**
 * 工装夹具数据库实体类
 */
class WorkFixtureDO
{
	// 工装夹具ID
	CC_SYNTHESIZE(uint64_t, toolId, ToolId);
	// 工装夹具编码
	CC_SYNTHESIZE(string, toolCode, ToolCode);
	// 工装夹具名称
	CC_SYNTHESIZE(string, toolName, ToolName);
	// 品牌
	CC_SYNTHESIZE(string, brand, Brand);
	// 型号
	CC_SYNTHESIZE(string, spec, Spec);
	// 工装夹具类型ID
	CC_SYNTHESIZE(uint64_t, toolTypeId, ToolTypeId);
	// 工装夹具类型编码
	CC_SYNTHESIZE(string, toolTypeCode, ToolTypeCode);
	// 工装夹具类型名称
	CC_SYNTHESIZE(string, toolTypeName, ToolTypeName);
	// 数量（库存）
	CC_SYNTHESIZE(int32_t, quantity, Quantity);
	// 可用数量
	CC_SYNTHESIZE(int32_t, quantityAvail, QuantityAvail);
	// 保养维护类型
	CC_SYNTHESIZE(string, maintenType, MaintenType);
	// 下次保养周期
	// CC_SYNTHESIZE(int32_t, nextMaintenPeriod, NextMaintenPeriod);
	// 下次保养日期
	CC_SYNTHESIZE(string, nextMaintenDate, NextMaintenDate);
	// 状态
	CC_SYNTHESIZE(string, status, Status);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 是否单独编码管理
	CC_SYNTHESIZE(string, codeFlag, CodeFlag);
public:
	WorkFixtureDO() {  // 初始化所有字段的的默认值
		toolId = 0;
		toolCode = "";
		toolName = "";
		brand = "";
		spec = "";
		toolTypeId = 0;
		toolTypeCode = "";
		toolTypeName = "";
		quantity = 0;
		quantityAvail = 0;
		maintenType = "";
		// nextMaintenPeriod = 0;
		nextMaintenDate = "";
		status = "";
		remark = "";
	}
};