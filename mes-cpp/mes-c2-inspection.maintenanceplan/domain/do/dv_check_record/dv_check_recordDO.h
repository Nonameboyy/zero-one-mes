#ifndef _DV_CHECK_RECORD_DO_
#define _DV_CHECK_RECORD_DO_
#include "../DoInclude.h"

/**
* dv_check_record���ݱ�ʵ����
*/
class DvCheckRecordDO
{
	// �ƻ�ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// �ƻ�ID
	CC_SYNTHESIZE(uint64_t, plan_id, Plan_id);
	// �ƻ�����
	CC_SYNTHESIZE(string, plan_code, Plan_code);
	// �ƻ�����
	CC_SYNTHESIZE(string, plan_name, Plan_name);
	// �ƻ�����
	CC_SYNTHESIZE(string, plan_type, Plan_type);
	// �豸ID
	CC_SYNTHESIZE(uint64_t, machinery_id, machinery_id);
	// �豸����
	CC_SYNTHESIZE(string, machinery_code, Machinery_code);
	// �豸����
	CC_SYNTHESIZE(string, machinery_name, Machinery_name);
	// Ʒ��
	CC_SYNTHESIZE(string, machinery_brand, Machinery_brand);
	// ����ͺ�
	CC_SYNTHESIZE(string, machinery_spec, Machinery_spec);
	// ���ʱ��
	CC_SYNTHESIZE(string, check_time, check_time);
	// ״̬
	CC_SYNTHESIZE(string, status, Status);
	// ��ע	
	CC_SYNTHESIZE(string, remark, Remark);
	// Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, datetime, Datetime);
public:
	SampleDO() {
		record_id = 0;
		plan_id = 0;
		plan_code = "";
		plan_name = "";
		plan_type = "";
		machinery_id = 0;
		machinery_code = "";
		machinery_name = "";
		machinery_brand = "";
		machinery_spec = "";
		check_time = "";
		status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		datetime = "";
	}
};

#endif // !_DV_CHECK_RECORD_DO_