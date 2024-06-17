#pragma once
/*
*
*/
#ifndef _DV__CHECK__MACHINERY_DO_
#define _DV__CHECK__MACHINERY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class Dv_check_machineryDO
{
	//��ˮ��
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// �ƻ�ID��
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	//�豸id
	CC_SYNTHESIZE(uint64_t, machinery_id, Machinery_id);
	//�豸����
	CC_SYNTHESIZE(string, machinery_code, Machinery_code);
	//�豸����
	CC_SYNTHESIZE(string, machinery_name, Machinery_name);
	//Ʒ��
	CC_SYNTHESIZE(string, machinery_brand, Machinery_brand);
	//����ͺ�
	CC_SYNTHESIZE(string, machinery_spec, Machinery_spec);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//Ԥ���ֶ�3
	CC_SYNTHESIZE(uint32_t, attr3, Attr3);
	//Ԥ���ֶ�4
	CC_SYNTHESIZE(uint32_t, attr4, Attr4);
	//������
	CC_SYNTHESIZE(string, create_by, Create_by);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//������
	CC_SYNTHESIZE(string, update_by, Update_by);
	//����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);

public:
	//Ĭ�Ϲ���
	Dv_check_machineryDO() {
		record_id = 0;
		plan_id = 0;
		machinery_id = 0;
		machinery_code = "";
		machinery_name = "";
		machinery_brand = "";
		machinery_spec = "";
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

#endif // !_DV__CHECK__Machinery_DO_
