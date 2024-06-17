#pragma once

#include "../DoInclude.h"
/*
* ����ʵ����
*/
class FeedBackDO
{
	//�������� , feedback_type ,FeedBack_type
	CC_SYNTHESIZE(string, feedback_type, Feedback_type);
	//����վ���� workstation_name Workstation_name
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	//����������� workorder_code, Workorder_code
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//��Ʒ���ϱ��� item_code, Item_code
	CC_SYNTHESIZE(string, item_code, Item_code);
	//��Ʒ������ item_name, Item_name
	CC_SYNTHESIZE(string, item_name, Item_name);
	//����ͺ� specification, Specification
	CC_SYNTHESIZE(string, specification, Specification);
	//�������� quantity_feedback, Quantity_feedback
	CC_SYNTHESIZE(uint64_t, quantity_feedback, Quantity_feedback);
	//������ user_name, User_name
	CC_SYNTHESIZE(string, user_name, User_name);
	//����ʱ�� 
	CC_SYNTHESIZE(string, feedback_time, Feedback_time);
	//����� record_user, Record_user
	CC_SYNTHESIZE(string, record_user, Record_user);
	//״̬
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