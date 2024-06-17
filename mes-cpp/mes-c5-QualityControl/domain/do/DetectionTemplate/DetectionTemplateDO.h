#pragma once
#ifndef _DETECTIONTEMPLATE_DO_
#define _DETECTIONTEMPLATE_DO_

#include "../DoInclude.h"
class DetectionTemplateDO
{
	// 检测模板ID(唯一值)
	CC_SYNTHESIZE(uint64_t, template_id, Template_Id);
	// 检测模板编号
	CC_SYNTHESIZE(string, template_code, Template_Code);
	// 检测模板名称
	CC_SYNTHESIZE(string, template_name, Template_Name);
	// 产品编码
	CC_SYNTHESIZE(string, item_code, Item_Code);
	// 产品名称
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// 检测种类
	CC_SYNTHESIZE(string, qc_types, Qc_Types);
	//  是否启用
	CC_SYNTHESIZE(string, enable_flag, Enable_Flag);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);

public:
	DetectionTemplateDO() {
		template_id = 0;
		template_code = "";
		template_name = "";
		item_code = "";
		item_name = "";
		qc_types = "";
		enable_flag = "";
		remark = "";
	}
};

#endif // !_DETECTIONTEMPLATE_DO_
