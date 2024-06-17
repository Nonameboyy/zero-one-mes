#pragma once

#ifndef _PROROUTEPROCESS_DO_
#define _PROROUTEPROCESS_DO_
#include "../DoInclude.h"

/**
 * 工艺组成表
 */

class ProRouteProcessDO
{
	// 记录ID
	CC_SYNTHESIZE(uint64_t, recordid, RecordId);
	// 工艺路线ID
	CC_SYNTHESIZE(uint64_t, routeid, RouteId);
	//工序ID
	CC_SYNTHESIZE(uint64_t, processid, ProcessId);
	//工序编码
	CC_SYNTHESIZE(string, processcode, ProcessCode);
	//工序名称
	CC_SYNTHESIZE(string, processname, ProcessName);
	//序号
	CC_SYNTHESIZE(int, ordernum, OrderNum);
	//工序ID
	CC_SYNTHESIZE(uint64_t, nextprocessid, NextProcessId);
	//工序编码
	CC_SYNTHESIZE(string, nextprocesscode, NextProcessCode);
	//工序名称
	CC_SYNTHESIZE(string, nextprocessname, NextProcessName);
	//与下一道工序关系
	CC_SYNTHESIZE(string, linktype, LinkType);
	//准备时间
	CC_SYNTHESIZE(int32_t, defaultpretime, DefaultPreTime);
	//等待时间
	CC_SYNTHESIZE(int32_t, defaultsuftime, DefaultSufTime);
	//甘特图显示颜色
	CC_SYNTHESIZE(string, colorcode, ColorCode);
	//关键工序
	CC_SYNTHESIZE(string, keyflag, KeyFlag);
	//是否检验
	CC_SYNTHESIZE(string, ischeck, IsCheck);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
public:
	ProRouteProcessDO() {
		recordid = 0;
		routeid = 0;
		processid = 0;
		processcode = "";
		processname = "";
		ordernum = 1;
		nextprocessid = 1;
		nextprocesscode = "";
		nextprocessname = "";
		linktype = "SS";
		defaultpretime = 0;
		defaultsuftime = 0;
		colorcode = "#00AEF3";
		keyflag = "N";
		ischeck = "N";
		remark = "";
	}
};

#endif // !_SAMPLE_DO_
