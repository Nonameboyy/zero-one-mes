#pragma once
#ifndef _PROROUTE_DO_
#define _PROROUTE_DO_
#include "../DoInclude.h"

/**
 * ����·�߱�
 */
class ProRouteDO
{
	// ����·��ID
	CC_SYNTHESIZE(uint64_t, routeid, RouteId);
	// ����·�߱��
	CC_SYNTHESIZE(string, routecode, RouteCode);
	// ����·������
	CC_SYNTHESIZE(string, routename, RouteName);
	// ����·��˵��
	CC_SYNTHESIZE(string, routedesc, RouteDesc);
	// �Ƿ�����
	CC_SYNTHESIZE(string, enableflag, EnableFlag);
	// ��ע
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