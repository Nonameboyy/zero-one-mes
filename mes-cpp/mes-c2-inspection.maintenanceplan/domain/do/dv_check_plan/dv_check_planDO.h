#pragma once
/*
*
*/
#ifndef _DV__CHECK__PLAN_DO_
#define _DV__CHECK__PLAN_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Dv_check_planDO
{
	// �ƻ�ID��
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	//����չ������ʽ������������ʵ�Ƕ�����һ��������get/set������get��ȡ�з��أ�set�����޷��أ�
//protected: uint64_t plan_id; 
//public: uint64_t getPlan_id(void) const {return plan_id;}
//public: void setPlan_id(uint64_t var) {plan_id = var;};
	// �ƻ�����
	CC_SYNTHESIZE(string, plan_code, Plan_code);
	// �ƻ�����
	CC_SYNTHESIZE(string, plan_name, Plan_name);
	// �ƻ�����
	CC_SYNTHESIZE(string, plan_type, Plan_type);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_date, Start_date);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_date, End_date);
	// Ƶ��
	CC_SYNTHESIZE(string, cycle_type, Cycle_type);
	// ����
	//CC_SYNTHESIZE(uint32_t, cycle_count, Cycle_count);
protected: uint32_t cycle_count; public: uint32_t getCycle_count(void) const {
	return cycle_count;
}public: void setCycle_count(uint32_t var) {
	cycle_count = var;
};
	// ״̬
	CC_SYNTHESIZE(string, status, Status);
	// ��ע 
	CC_SYNTHESIZE(string, remark, Remark);
	// Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// Ԥ���ֶ�3
	CC_SYNTHESIZE(uint32_t, attr3, Attr3);
	// Ԥ���ֶ�4
	CC_SYNTHESIZE(uint32_t, attr4, Attr4);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);

public:
	//Ĭ�Ϲ���
	Dv_check_planDO() {
		plan_id = 0;
		plan_code = "";
		plan_name = "";
		plan_type = "";
		start_date = "";
		end_date = "";
		cycle_type = "";
		cycle_count = 0;
		status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}
};

#endif // !_DV__CHECK__PLAN_DO_
