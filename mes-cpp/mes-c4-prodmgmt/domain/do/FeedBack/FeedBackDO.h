#pragma once

#include "../DoInclude.h"
/*
* 报工实体类
*/
class FeedBackDO
{
	//报工类型 , feedback_type ,FeedBack_type
	CC_SYNTHESIZE(string, feedback_type, Feedback_type);
	//工作站名称 workstation_name Workstation_name
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	//生产工单编号 workorder_code, Workorder_code
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//产品物料编码 item_code, Item_code
	CC_SYNTHESIZE(string, item_code, Item_code);
	//产品物料名 item_name, Item_name
	CC_SYNTHESIZE(string, item_name, Item_name);
	//规格型号 specification, Specification
	CC_SYNTHESIZE(string, specification, Specification);
	//报工数量 quantity_feedback, Quantity_feedback
	CC_SYNTHESIZE(uint64_t, quantity_feedback, Quantity_feedback);
	//报工人 user_name, User_name
	CC_SYNTHESIZE(string, user_name, User_name);
	//报工时间 
	CC_SYNTHESIZE(string, feedback_time, Feedback_time);
	//审核人 record_user, Record_user
	CC_SYNTHESIZE(string, record_user, Record_user);
	//状态
	CC_SYNTHESIZE(string, _status, _Status);
	FeedBackDO() { 
		this->feedback_type = "";
		this->workorder_code = "";
		this->workstation_name = "";
		this->item_code = "";
		this->item_name = "";
		this->specification = "";
		this->quantity_feedback = 0;
		this->user_name = "";
		this->feedback_time = "";
		this->record_user = "";
		this->_status = "";
	};

};