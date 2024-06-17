#pragma once
#ifndef _DETECTIONTEMPLATE_DO_
#define _DETECTIONTEMPLATE_DO_

#include "../DoInclude.h"
class DetectionTemplateDO
{
	// ���ģ��ID(Ψһֵ)
	CC_SYNTHESIZE(uint64_t, template_id, Template_Id);
	// ���ģ����
	CC_SYNTHESIZE(string, template_code, Template_Code);
	// ���ģ������
	CC_SYNTHESIZE(string, template_name, Template_Name);
	// ��Ʒ����
	CC_SYNTHESIZE(string, item_code, Item_Code);
	// ��Ʒ����
	CC_SYNTHESIZE(string, item_name, Item_Name);
	// �������
	CC_SYNTHESIZE(string, qc_types, Qc_Types);
	//  �Ƿ�����
	CC_SYNTHESIZE(string, enable_flag, Enable_Flag);
	// ��ע
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
