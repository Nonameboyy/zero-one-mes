#pragma once
#ifndef _SINGLE_DO_
#define _SINGLE_DO_
#include "../DoInclude.h"

class IndexDO
{
	//��¼ID
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	//���鵥ID
	CC_SYNTHESIZE(int64_t, iqc_id, Iqc_id);
	//�����ID
	CC_SYNTHESIZE(int64_t, index_id, Index_id);
	//��������
	CC_SYNTHESIZE(string, index_code, Index_code);
	//���������
	CC_SYNTHESIZE(string, index_name, Index_name);
	//���������
	CC_SYNTHESIZE(string, index_type, Index_type);
	//��⹤��
	CC_SYNTHESIZE(string, qc_tool, Qc_tool);
	//��ⷽ��
	CC_SYNTHESIZE(string, check_method, Check_method);
	//��׼ֵ
	CC_SYNTHESIZE(double, stander_val, Stander_val);
	//��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	//�������
	CC_SYNTHESIZE(double, threshold_max, Threshold_max);
	//�������
	CC_SYNTHESIZE(double, threshold_min, Threshold_min);
	//����ȱ������
	CC_SYNTHESIZE(int, cr_quantity, Cr_quantity);
	//����ȱ������
	CC_SYNTHESIZE(int, maj_quantity, Maj_quantity);
	//��΢ȱ������
	CC_SYNTHESIZE(int, min_quantity, Min_quantity);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	//Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	//������
	CC_SYNTHESIZE(string, create_by, Create_by);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//������
	CC_SYNTHESIZE(string, update_by, Update_by);
	//����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
public:
	IndexDO() {
		line_id = 0;
		iqc_id = 0;
		index_id = 0;
		index_code = "";
		index_name = "";
		index_type = "";
		qc_tool = "";
		check_method = "";
		stander_val=0;
		unit_of_measure = "";
		remark = "";
		stander_val = 0.0;
		threshold_max = 0.0;
		threshold_min = 0.0;
		cr_quantity = 0;
		maj_quantity = 0;
		min_quantity = 0;
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


class DefectDO
{
	//ȱ��ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	//���ϼ��鵥ID
	CC_SYNTHESIZE(uint64_t, iqc_id, Iqc_id);
	//���ϼ��鵥��ID
	CC_SYNTHESIZE(uint64_t, line_id, Line_id);
	//ȱ������
	CC_SYNTHESIZE(string, defect_name, Defect_name);
	//ȱ�ݵȼ�
	CC_SYNTHESIZE(string, defect_level, Defect_level);
	//ȱ������
	CC_SYNTHESIZE(int, defect_quantity, Defect_quantity);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	//Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	//������
	CC_SYNTHESIZE(string, create_by, Create_by);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	//������
	CC_SYNTHESIZE(string, update_by, Update_by);
	//����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
public:
	DefectDO() {
		record_id = 0;
		iqc_id = 0;
		line_id = 0;
		defect_name = "";
		defect_level = "";
		defect_quantity = 0;
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
#endif // !_SINGLE_DO_
