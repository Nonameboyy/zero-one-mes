#pragma once
#ifndef _PRODWORKORDER_MAPPER_
#define _PRODWORKORDER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../../domain/do/ProdWorkorder/GetProdWorkorderListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderBomListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderInfoDO.h"

/**
 * 获取生产工单详情
 */
class ProdWorkorderInfoMapper : public Mapper<ProdWorkorderInfoDO>
{
public:
	ProdWorkorderInfoDO mapper(ResultSet* resultSet) const override
	{
		ProdWorkorderInfoDO data;
		//工单编码;workorder_code;varchar
		data.setWorkorder_code(resultSet->getString(1));
		//工单名称;workorder_name;varchar
		data.setWorkorder_name(resultSet->getString(2));
		//来源类型;order_source;varchar
		data.setOrder_source(resultSet->getString(3));
		//订单编号;source_code;varchar
		data.setSource_code(resultSet->getString(4));
		//单据状态;status;varchar
		data.setStatus(resultSet->getString(5));
		//工单类型;workorder_type;varchar
		data.setWorkorder_type(resultSet->getString(6));
		//产品编号;product_code;varchar
		data.setProduct_code(resultSet->getString(7));
		//产品名称;product_name;varchar
		data.setProduct_name(resultSet->getString(8));
		//规格型号;product_spc;varchar
		data.setProduct_spc(resultSet->getString(9));
		//单位;unit_of_measure;varchar
		data.setUnit_of_measure(resultSet->getString(10));
		//工单数量（生产数量）;quantity;double
		data.setQuantity(resultSet->getDouble(11));
		//需求日期;request_date;datetime
		data.setRequest_date(resultSet->getString(12));
		//批次号;batch_code;varchar
		data.setBatch_code(resultSet->getString(13));
		//客户编码;client_code;varchar
		data.setClient_code(resultSet->getString(14));
		//客户名称;client_name;varchar
		data.setClient_name(resultSet->getString(15));
		//供应商编码;vendor_code;varchar
		data.setVendor_code(resultSet->getString(16));
		//供应商名称;vendor_name;varchar
		data.setVendor_name(resultSet->getString(17));
		//备注;remark;varchar
		data.setRemark(resultSet->getString(18));
		return data;
	}
};

/**
 * 获取生产工单BOM列表
 */
class ProdWorkorderBomListMapper : public Mapper<ProdWorkorderBomListDO>
{
public:
	ProdWorkorderBomListDO mapper(ResultSet* resultSet) const override
	{
		ProdWorkorderBomListDO data;
		//BOM行ID;line_id;bigint
		data.setLine_id(resultSet->getUInt64(1));
		
		return data;
	}
};

/**
 * 获取生产工单列表
 */
class GetProdWorkorderListMapper : public Mapper<GetProdWorkorderListDO>
{
public:
	GetProdWorkorderListDO mapper(ResultSet* resultSet) const override
	{
		GetProdWorkorderListDO data;
		//工单编码;workorder_code;varchar
		data.setWorkorder_code(resultSet->getString(1));
		//工单名称;workorder_name;varchar
		data.setWorkorder_name(resultSet->getString(2));
		//工单类型;workorder_type;varchar
		data.setWorkorder_type(resultSet->getString(3));
		//订单编号;source_code;varchar
		data.setSource_code(resultSet->getString(4));
		//产品编号;product_code;varchar
		data.setProduct_code(resultSet->getString(5));
		//产品名称;product_name;varchar
		data.setProduct_name(resultSet->getString(6));
		//客户编码;client_code;varchar
		data.setClient_code(resultSet->getString(7));
		//客户名称;client_name;varchar
		data.setClient_name(resultSet->getString(8));
		//需求日期;request_date;datetime
		data.setRequest_date(resultSet->getString(9));

		return data;
	}
};
#endif // !_PRODWORKORDER_MAPPER_