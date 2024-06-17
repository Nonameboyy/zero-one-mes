
#include "stdafx.h"
#include "ProWorkorderService.h"
#include "../../dao/ProWorkorder/ProWorkorderDAO.h"
#include "../../dao/MdProductBom/MdProductBomDAO.h"
#include "../../dao/ProWorkorderBom/ProWorkorderBomDAO.h"
#include "../lib-common/include/SimpleDateTimeFormat.h"


bool ProWorkorderService::updateData(const ModifyProWorkorderDTO::Wrapper& dto)
{
	ProWorkorderDAO d1;
	MdProductBomDAO d2;
	ProdWorkorderBomDAO d3;

	TransactionManager tm(&d1, &d2, &d3);

	//删除
	uint64_t oldProductId = d1.selectByID(dto->workorderId.getValue(0));
	if (d2.countById(oldProductId) > 0) {
		int row = d3.deleteByItemId(dto->workorderId.getValue(0));
		if (row <= 0) {
			tm.rollback();
			return false;
		}
	}

	//添加新BOM
	uint64_t productId = dto->productId.getValue(0);
	if(d2.countById(productId) > 0) {
		list<MdProductBomDO> mdBom = d2.selectByItemId(dto->productId.getValue(0));
		for (auto i : mdBom) {
			ProWorkOrderBomDO data;
			data.setworkOrderId(dto->workorderId.getValue(0));
			data.setitemId(i.getBomItemId());
			data.setitemCode(i.getBomItemCode());
			data.setitemName(i.getBomItemName());
			data.setitemSpc(i.getBomItemSpc());
			data.setunitOfMeasure(i.getUnitOfMeasure());
			data.setbQuantity(i.getQuantity() * dto->quantity.getValue(0));
			data.setitemOrProduct(i.getItemOrProduct());
			//创建时间
			data.setcreateTime(SimpleDateTimeFormat::format());
			int row = d3.insert(data);
			if (row <= 0) {
				tm.rollback();
				return false;
			}
		}
	}
	//修改
	ProdWorkorderDO dataDO;
	dataDO.setWorkOrderID(dto->workorderId.getValue(0));
	dataDO.setWorkOrderCode(dto->workorderCode.getValue(""));
	dataDO.setWorkOrderName(dto->workorderName.getValue(""));
	dataDO.setOrderSource(dto->orderSource.getValue(""));
	dataDO.setSourceCode(dto->sourceCode.getValue(""));
	dataDO.setWorkOrderType(dto->workorderType.getValue(""));
	dataDO.setQuantity(dto->quantity.getValue(0));
	dataDO.setRequestDate(dto->requestDate.getValue(""));
	dataDO.setBatchCode(dto->batchCode.getValue(""));
	dataDO.setClientId(dto->clientId.getValue(0));
	dataDO.setClientCode(dto->clientCode.getValue(""));
	dataDO.setProductId(dto->productId.getValue(0));
	dataDO.setProductName(dto->productName.getValue(""));
	dataDO.setProductCode(dto->productCode.getValue(""));
	dataDO.setProductSpc(dto->productSpc.getValue(""));
	dataDO.setUnitOfMeasure(dto->unitOfMeasure.getValue(""));
	dataDO.setClientName(dto->clientName.getValue(""));
	dataDO.setRemark(dto->remark.getValue(""));
	dataDO.setUpdateTime(SimpleDateTimeFormat::format());
	int row = d1.update(dataDO);
	if (row <= 0) {
		tm.rollback();
		return false;
	}
	tm.commit();
	return true;
}

bool ProWorkorderService::completeData(uint64_t id)
{
	ProdWorkorderDO childData;
	childData.setParentId(id);
	childData.setStatus("FINISHED");

	ProdWorkorderDO data;
	data.setWorkOrderID(id);
	data.setStatus("CONFIRMED");
	ProWorkorderDAO dao;
	if (dao.countById(childData) > 0 || dao.countById(data) <= 0) {
		return false;
	}
	return dao.completeById(id) == 1;
}

bool ProWorkorderService::removeData(uint64_t id)
{
	ProdWorkorderDO data;
	data.setWorkOrderID(id);
	data.setStatus("PREPARE");
	ProWorkorderDAO dao;
	if (dao.countById(data) <= 0) {
		return false;
	}
	return dao.deleteById(id)==1;
}

bool ProWorkorderService::confirmData(uint64_t id)
{
	
	ProWorkorderDAO dao;
	return dao.comfirmById(id)==1;
}
