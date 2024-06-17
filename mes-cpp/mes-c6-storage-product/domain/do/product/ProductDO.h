#pragma once

#ifndef _PRODUCT_DO_
#define _PRODUCT_DO_
#include "../DoInclude.h"
/**
 * �����������ݿ�ʵ����
 */
class ProductTableDO {
	//���ϵ�id
	CC_SYNTHESIZE(uint64_t, issue_id, Issue_id);
	//���ϵ����
	CC_SYNTHESIZE(string, issue_code, Issue_code);
	//���ϵ�����
	CC_SYNTHESIZE(string, issue_name, Issue_name);
	//��������
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//�ͻ����
	CC_SYNTHESIZE(string, client_code, Client_code);
	//�ͻ�����
	CC_SYNTHESIZE(string, client_name, Client_name);
	//��������
	CC_SYNTHESIZE(string, issue_date, Issue_date);
	//����״̬
	CC_SYNTHESIZE(string, status, Status1);
	//����վid
	CC_SYNTHESIZE(uint64_t, workstation_id, Workstation_id);
	//����վ���
	CC_SYNTHESIZE(string, workstation_code, Workstation_code);
	//����վ����
	CC_SYNTHESIZE(string, workstation_name, Workstation_name);
	//��������id
	CC_SYNTHESIZE(uint64_t, workorder_id, Workorder_id);
	//��������id
	CC_SYNTHESIZE(uint64_t, task_id, Task_id);
	//�����������
	CC_SYNTHESIZE(string, task_code, Task_code);
	//�ͻ�id
	CC_SYNTHESIZE(uint64_t, client_id, Client_id);
	//�ͻ����
	CC_SYNTHESIZE(string, client_nick, Client_nick);
	//"�ֿ�id"
	CC_SYNTHESIZE(uint64_t, warehouse_id, Warehouse_id);
	//"�ֿ����"
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//"�ֿ�����"
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	//"����id"
	 CC_SYNTHESIZE(uint64_t, location_id, Location_id);
	//"��������"
	 CC_SYNTHESIZE(string, location_code, Location_code);
	//��������"
	 CC_SYNTHESIZE(string, location_name, Location_name);
	//"��λid"
	 CC_SYNTHESIZE(uint64_t, area_id, Area_id);
	//"��λ����"
	 CC_SYNTHESIZE(string, area_code, Area_code);
	//"��λ����"
	CC_SYNTHESIZE(string, area_name, Area_name);
	//"��ע"
	CC_SYNTHESIZE(string, remark, Remark);
//"Ԥ���ֶ�1"
	CC_SYNTHESIZE(string, attr1, Attr1);
//"Ԥ���ֶ�2"
CC_SYNTHESIZE(string, attr2, Attr2);
//"Ԥ���ֶ�3"
CC_SYNTHESIZE(int32_t, attr3, Attr3);
//"Ԥ���ֶ�4"
CC_SYNTHESIZE(int32_t, attr4, Attr4);
//"������"
CC_SYNTHESIZE(string, create_by, Create_by);
//"����ʱ��"
CC_SYNTHESIZE(string, create_time, Create_time);
//"������"
CC_SYNTHESIZE(string, update_by, Update_by);
//"����ʱ��"
CC_SYNTHESIZE(string, update_time, Update_time);
public:
	ProductTableDO() {
		issue_id = 0;
		issue_code = "";
		issue_name = "";
		workorder_code = "";
		client_code = "";
		client_name = "";
		issue_date = "";
		status = "";
		workstation_id = 0;
		workstation_code = "";
		workstation_name = "";
		workorder_id = 0;
		task_id = 0;
		task_code = "";
		client_id = 0;
		client_nick = "";
		warehouse_id = 0;
		warehouse_code = "";
		warehouse_name = "";
		location_id = 0;
		location_code = "";
		location_name = "";
		area_id = 0;
		area_code = "";
		area_name = "";
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
 * ���������������ݿ�ʵ����
 */
class ProductDetailDO :public ProductTableDO{

};
#endif 