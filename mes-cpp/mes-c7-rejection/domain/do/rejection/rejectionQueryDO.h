#pragma once
#ifndef _rejectionQuery_DO_
#define _rejectionQuery_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class RejectQueryDO
{
	// ���ϵ�id��Ψһ��
	CC_SYNTHESIZE(uint64_t, rt_id, Rt_id);
	// ���ϵ����
	CC_SYNTHESIZE(string, rt_code, Rt_code);
	// // ���ϵ�����
	CC_SYNTHESIZE(string, rt_name, Rt_name);
	// // ��������id
	CC_SYNTHESIZE(string, workorder_id, Workorder_id);
	//  �ֿ�����
	CC_SYNTHESIZE(string, warehouse_name, Warehouse_name);
	// ��������
	CC_SYNTHESIZE(string, location_name, Location_name);
	// ��λ����
	CC_SYNTHESIZE(string, area_name, Area_name);
	//��������
	CC_SYNTHESIZE(string, rt_date, Rt_date);
	//����״̬
	CC_SYNTHESIZE(string, status, Status);
	
	//detail data
	//������������
	CC_SYNTHESIZE(string, workorder_code, Workorder_code);
	//�ֿ�id
	CC_SYNTHESIZE(string, warehouse_id, Warehouse_id);
	//�ֿ����
	CC_SYNTHESIZE(string, warehouse_code, Warehouse_code);
	//����id
	CC_SYNTHESIZE(string, location_id, Location_id);
	//��������
	CC_SYNTHESIZE(string, location_code, Location_code);
	//��λid
	CC_SYNTHESIZE(string, area_id, Area_id);
	//��λ����
	CC_SYNTHESIZE(string, area_code, Area_code);

	//.......................................................
	//���ղֿ�
	CC_SYNTHESIZE(string, rsname, Rsname);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);

public:
	RejectQueryDO() {
		rt_id = 0;
		rt_code = "0000";
		rt_name = "Rtname";
		workorder_id = "1";
		warehouse_name = "warehouse_name";
		location_name = "location_name";
		area_name = "area_name";
		rt_date = "rt_date";
		status = "status";
	}
};

#endif // !_rejectionQuery_DO_
