#pragma once

#ifndef _ProdWorkorder_DO_
#define _ProdWorkorder_DO_
#include "../DoInclude.h"

/**
 * �����������ݿ�ʵ����
 */
class ProdWorkorderDO
{	
	//����id
	CC_SYNTHESIZE(uint64_t, workorder_id, WorkOrderID);
	//��������
	CC_SYNTHESIZE(string, workorder_code, WorkOrderCode);
	//��������
	CC_SYNTHESIZE(string, workorder_name, WorkOrderName);
	//��������
	CC_SYNTHESIZE(string, workorder_type, WorkOrderType);
	//��Դ����
	CC_SYNTHESIZE(string, order_source, OrderSource);
	//��Դ����
	CC_SYNTHESIZE(string, source_code, SourceCode);
	//��Ʒid
	CC_SYNTHESIZE(uint64_t, product_id, ProductId);
	//��Ʒ���
	CC_SYNTHESIZE(string, product_code, ProductCode);
	//��Ʒ����
	CC_SYNTHESIZE(string, product_name, ProductName);
	//����ͺ�
	CC_SYNTHESIZE(string, product_spc, ProductSpc);
	//��λ
	CC_SYNTHESIZE(string, unit_of_measure, UnitOfMeasure);
	//���κ�
	CC_SYNTHESIZE(string, batch_code, BatchCode);
	//��������
	CC_SYNTHESIZE(double, quantity, Quantity);
	//����������
	CC_SYNTHESIZE(double, quantity_produced, QuantityProduced);
	//��������
	CC_SYNTHESIZE(double, quantity_changed, QuantityChanged);
	//���Ų�����
	CC_SYNTHESIZE(double, quantity_scheduled, QuantitySchedule);
	//�ͻ�ID
	CC_SYNTHESIZE(uint64_t, client_id, ClientId);
	//�ͻ�����
	CC_SYNTHESIZE(string, client_code, ClientCode);
	//�ͻ�����
	CC_SYNTHESIZE(string, client_name, ClientName);
	//��Ӧ��id
	CC_SYNTHESIZE(uint64_t, vendor_id, VendorId);
	//��Ӧ�̱���
	CC_SYNTHESIZE(string, vendor_code, VendorCode);
	//��Ӧ������
	CC_SYNTHESIZE(string, vendor_name, VendorName);
	//���ʱ��
	CC_SYNTHESIZE(string, finish_date, FinishDate);
	//��������
	CC_SYNTHESIZE(string, request_date, RequestDate);
	//����״̬
	CC_SYNTHESIZE(string, status, Status);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//������
	CC_SYNTHESIZE(string, create_by, CreateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
	//������
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	//����ʱ��
	CC_SYNTHESIZE(string, update_time, UpdateTime);
	//������ID
	CC_SYNTHESIZE(uint64_t, parent_id, ParentId);
	//���и��ڵ�ID
	CC_SYNTHESIZE(string, ancestors, Ancestors);
public:
	ProdWorkorderDO() {
		workorder_id = 0;
		workorder_code = "";
		workorder_name = "";
		workorder_type = "";
		order_source = "";
		source_code = "";
		product_id = 0;
		product_code = "";
		product_name = "";
		product_spc = "";
		unit_of_measure = "";
		batch_code = "";
		quantity = 0.0;
		quantity_produced = 0.0;
		quantity_changed = 0.0;
		quantity_scheduled = 0.0;
		client_id = 0;
		client_code = "";
		client_name = "";
		vendor_id = 0;
		vendor_code = "";
		vendor_name = "";
		finish_date = "";
		request_date = "";
		status = "";
		remark = "";
		create_by = "";
		update_by = "";
		update_time = "";
		parent_id = 0;
		ancestors = "";
	}
};

#endif // !_ProdWorkorder_DO_
