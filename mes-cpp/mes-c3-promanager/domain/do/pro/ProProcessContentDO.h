#ifndef _PROPROCESSCONTENT_DO_
#define _PROPROCESSCONTENT_DO_
#include "../DoInclude.h"

/**
 * 生产工序内容表
 */
class ProProcessContentDO
{
	// 内容说明
	CC_SYNTHESIZE(string, contenttext, ContentText);
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//顺序编号
	CC_SYNTHESIZE(int, ordernum, OrderNum);
	//工序ID
	CC_SYNTHESIZE(uint64_t, processid, ProcessId);
	//内容ID
	CC_SYNTHESIZE(uint64_t, contentid, ContentId);
	//辅助设备
	CC_SYNTHESIZE(string, device, Device);
	//辅助材料
	CC_SYNTHESIZE(string, material, Material);
	//材料URL
	CC_SYNTHESIZE(string, docurl, DocUrl);
public:
	ProProcessContentDO() {
		contenttext = "";
		remark = "";
		docurl = "";
		material = "";
		device = "";
		contentid = 229;
		processid = 283;
		ordernum = 1;

	}
};

#endif // !_PROPROCESSCONTENT_DO_