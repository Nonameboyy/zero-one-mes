#pragma once
#ifndef _INSPECT_DO_
#define _INSPECT_DO_
#include "../DoInclude.h"



/**
 * ���ϼ����б����ݿ�ʵ����
 */
class InspectDO
{
	// ���ϼ��鵥id
	CC_SYNTHESIZE(int64_t, iqc_id, Iqc_id);
	// ���ϼ��鵥���
	CC_SYNTHESIZE(string, iqc_code, Iqc_code);
	// ���ϼ��鵥����
	CC_SYNTHESIZE(string, iqc_name, Iqc_name);
	//����ģ��ID
	CC_SYNTHESIZE(int64_t, template_id, Template_id);
	//��Դ����ID
	CC_SYNTHESIZE(int64_t, source_doc_id, Source_doc_id);
	// ��Դ�������� 
	CC_SYNTHESIZE(string, source_doc_type, Source_doc_type);
	// ��Դ���ݱ��
	CC_SYNTHESIZE(string, source_doc_code, Source_doc_code);
	// ��Դ������ID
	CC_SYNTHESIZE(int64_t, source_line_id, Source_line_id);
	//��Ӧ��ID
	CC_SYNTHESIZE(int64_t, vendor_id, Vendor_id);
	//��Ӧ�̱���
	CC_SYNTHESIZE(string, vendor_code, Vendor_code);
	//��Ӧ������
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vendor_nick, Vendor_nick);
	//��Ӧ�����κ�
	CC_SYNTHESIZE(string, vendor_batch, Vendor_batch);
	//��Ʒ����ID
	CC_SYNTHESIZE(int64_t, item_id, Item_id);
	//��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_code);
	//��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_name);
	//����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	//��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	// ��ͼ����
	CC_SYNTHESIZE(int, quantity_min_check, Quantity_min_check);
	// ��󲻺ϸ���
	CC_SYNTHESIZE(int, quantity_max_unqualified, Quantity_max_unqualified);
	//��������
	CC_SYNTHESIZE(double, quantity_recived, Quantity_recived);
	//�������
	CC_SYNTHESIZE(int, quantity_check, Quantity_check);
	//���ϸ���
	CC_SYNTHESIZE(int, quantity_unqualified, Quantity_unqualified);
	//����ȱ����
	CC_SYNTHESIZE(double, maj_rate, Maj_rate);
	//����ȱ����
	CC_SYNTHESIZE(double, cr_rate, Cr_rate);
	//��΢ȱ����
	CC_SYNTHESIZE(double, min_rate, Min_rate);
	//����ȱ������
	CC_SYNTHESIZE(int64_t, cr_quantity, Cr_quantity);
	//����ȱ������
	CC_SYNTHESIZE(int64_t, maj_quantity, Maj_quantity);
	//��΢ȱ������
	CC_SYNTHESIZE(int64_t, min_quantity, Min_quantity);
	//�����
	CC_SYNTHESIZE(string, check_result, Check_result);
	//��������
	CC_SYNTHESIZE(string, recive_date, Recive_date);
	//�������
	CC_SYNTHESIZE(string, inspect_date, Inspect_date);
	//�����Ա
	CC_SYNTHESIZE(string, inspector, Inspector);
	//����״̬
	CC_SYNTHESIZE(string, list_status, List_status);
	
//protected: string list_status; public: string getList_status(void) const {
//	return list_status;
//}public: void setList_status(string var) {
//	list_status = var;
//};
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
	InspectDO() {
		iqc_id = 0;
		iqc_code = "";
		iqc_name = "";
		template_id = 0;
		source_doc_id = 0;
		source_doc_type = "";
		source_doc_code = "";
		source_line_id = 0;
		vendor_id = 0;
		vendor_code = "";
		vendor_name = "";
		vendor_nick = "";
		vendor_batch = "";
		item_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		quantity_min_check = 0;
		quantity_max_unqualified = 0;
		quantity_recived = 0.0;
		quantity_check = 0;
		quantity_unqualified = 0;
		maj_rate = 0.0;
		cr_rate = 0.0;
		min_rate = 0.0;
		cr_quantity = 0;
		maj_quantity = 0;
		min_quantity = 0;
		check_result = "";
		recive_date = "";
		inspect_date = "";
		inspector = "";
		list_status = "";
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


/**
 * ���ϼ����������ݿ�ʵ����
 */
class Inspect_detailDO :public InspectDO
{

};

class Inspect_tableDO :public InspectDO
{

};

#endif // !_INSPECT_DO_
