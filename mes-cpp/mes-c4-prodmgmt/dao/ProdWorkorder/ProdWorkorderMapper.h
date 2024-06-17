#pragma once
#ifndef _PRODWORKORDER_MAPPER_
#define _PRODWORKORDER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../../domain/do/ProdWorkorder/GetProdWorkorderListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderBomListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderInfoDO.h"

/**
 * ��ȡ������������
 */
class ProdWorkorderInfoMapper : public Mapper<ProdWorkorderInfoDO>
{
public:
	ProdWorkorderInfoDO mapper(ResultSet* resultSet) const override
	{
		ProdWorkorderInfoDO data;
		//��������;workorder_code;varchar
		data.setWorkorder_code(resultSet->getString(1));
		//��������;workorder_name;varchar
		data.setWorkorder_name(resultSet->getString(2));
		//��Դ����;order_source;varchar
		data.setOrder_source(resultSet->getString(3));
		//�������;source_code;varchar
		data.setSource_code(resultSet->getString(4));
		//����״̬;status;varchar
		data.setStatus(resultSet->getString(5));
		//��������;workorder_type;varchar
		data.setWorkorder_type(resultSet->getString(6));
		//��Ʒ���;product_code;varchar
		data.setProduct_code(resultSet->getString(7));
		//��Ʒ����;product_name;varchar
		data.setProduct_name(resultSet->getString(8));
		//����ͺ�;product_spc;varchar
		data.setProduct_spc(resultSet->getString(9));
		//��λ;unit_of_measure;varchar
		data.setUnit_of_measure(resultSet->getString(10));
		//��������������������;quantity;double
		data.setQuantity(resultSet->getDouble(11));
		//��������;request_date;datetime
		data.setRequest_date(resultSet->getString(12));
		//���κ�;batch_code;varchar
		data.setBatch_code(resultSet->getString(13));
		//�ͻ�����;client_code;varchar
		data.setClient_code(resultSet->getString(14));
		//�ͻ�����;client_name;varchar
		data.setClient_name(resultSet->getString(15));
		//��Ӧ�̱���;vendor_code;varchar
		data.setVendor_code(resultSet->getString(16));
		//��Ӧ������;vendor_name;varchar
		data.setVendor_name(resultSet->getString(17));
		//��ע;remark;varchar
		data.setRemark(resultSet->getString(18));
		return data;
	}
};

/**
 * ��ȡ��������BOM�б�
 */
class ProdWorkorderBomListMapper : public Mapper<ProdWorkorderBomListDO>
{
public:
	ProdWorkorderBomListDO mapper(ResultSet* resultSet) const override
	{
		ProdWorkorderBomListDO data;
		//BOM��ID;line_id;bigint
		data.setLine_id(resultSet->getUInt64(1));
		
		return data;
	}
};

/**
 * ��ȡ���������б�
 */
class GetProdWorkorderListMapper : public Mapper<GetProdWorkorderListDO>
{
public:
	GetProdWorkorderListDO mapper(ResultSet* resultSet) const override
	{
		GetProdWorkorderListDO data;
		//��������;workorder_code;varchar
		data.setWorkorder_code(resultSet->getString(1));
		//��������;workorder_name;varchar
		data.setWorkorder_name(resultSet->getString(2));
		//��������;workorder_type;varchar
		data.setWorkorder_type(resultSet->getString(3));
		//�������;source_code;varchar
		data.setSource_code(resultSet->getString(4));
		//��Ʒ���;product_code;varchar
		data.setProduct_code(resultSet->getString(5));
		//��Ʒ����;product_name;varchar
		data.setProduct_name(resultSet->getString(6));
		//�ͻ�����;client_code;varchar
		data.setClient_code(resultSet->getString(7));
		//�ͻ�����;client_name;varchar
		data.setClient_name(resultSet->getString(8));
		//��������;request_date;datetime
		data.setRequest_date(resultSet->getString(9));

		return data;
	}
};
#endif // !_PRODWORKORDER_MAPPER_