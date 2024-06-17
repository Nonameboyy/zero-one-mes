#pragma once
#ifndef _PROROUTE_DO_
#define _PROROUTE_DO_
#include "../DoInclude.h"

/**
 * 工艺路线表
 */
class ProRouteDO
{
	// 工艺路线ID
	CC_SYNTHESIZE(uint64_t, routeid, RouteId);
	// 工艺路线编号
	CC_SYNTHESIZE(string, routecode, RouteCode);
	// 工艺路线名称
	CC_SYNTHESIZE(string, routename, RouteName);
	// 工艺路线说明
	CC_SYNTHESIZE(string, routedesc, RouteDesc);
	// 是否启用
	CC_SYNTHESIZE(string, enableflag, EnableFlag);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	ProRouteDO() {
		routeid = 0;
		routecode = "";
		routename = "";
		routedesc = "";
		enableflag = "";
		remark = "";
	}
};

#endif // !_SAMPLE_DO_