#include "stdafx.h"
#include "WarehouseManagementService.h"
#include "../../dao/WarehouseManagement/WarehouseManagementDAO.h"
#include "../lib-common/include/ExcelComponent.h"
#include "../lib-common/include/NacosClient.h"
#include "../lib-common/include/FastDfsClient.h"

//ֻд�˻�ȡ
WarehouseManagementPageDTO::Wrapper WarehouseManagementService::listAll(const WarehouseManagementQuery::Wrapper& query)
{
	// �������ض���
	auto pages = WarehouseManagementPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	WarehouseManagementDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<WarehouseManagementDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (WarehouseManagementDO sub : result)
	{
		auto dto = WarehouseManagementDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, item_code, Item_Code, item_name, Item_Name, batch_code, Batch_Code, warehouse_name, Warehouse_Name, vendor_code, Vendor_Code, vendor_name, Vendor_Name)
			pages->addData(dto);
	}
	return pages;
}

//����Excel
string WarehouseManagementService::creatExcel(const WarehouseManagementQuery::Wrapper& query)
{
	WarehouseManagementDAO dao;

	list<WarehouseManagementDO> result = dao.QueryByExport(query);

	std::vector<std::vector<std::string>> vvexcel;
	vvexcel.insert(vvexcel.begin(), {
		ZH_WORDS_GETTER("warehousemanagement.field.item_id"),
		ZH_WORDS_GETTER("warehousemanagement.field.item_code"),
		ZH_WORDS_GETTER("warehousemanagement.field.item_name"),
		ZH_WORDS_GETTER("warehousemanagement.field.specification"),
		ZH_WORDS_GETTER("warehousemanagement.field.unit_of_measure"),
		ZH_WORDS_GETTER("warehousemanagement.field.batch_code"),
		ZH_WORDS_GETTER("warehousemanagement.field.warehouse_name"),
		ZH_WORDS_GETTER("warehousemanagement.field.location_name"),
		ZH_WORDS_GETTER("warehousemanagement.field.area_name"),
		ZH_WORDS_GETTER("warehousemanagement.field.vendor_code"),
		ZH_WORDS_GETTER("warehousemanagement.field.vendor_name"),
		ZH_WORDS_GETTER("warehousemanagement.field.vendor_nick"),
		ZH_WORDS_GETTER("warehousemanagement.field.workorder_code"),
		ZH_WORDS_GETTER("warehousemanagement.field.recpt_date"),
		ZH_WORDS_GETTER("warehousemanagement.field.expire_date"),
		});
	for (WarehouseManagementDO sub : result)
	{
		std::vector<string> v;
		v.push_back(to_string(sub.getItem_Id()));
		v.push_back(sub.getItem_Code());
		v.push_back(sub.getItem_Name());
		v.push_back(sub.getSpecification());
		v.push_back(sub.getUnit_Of_Measure());
		v.push_back(sub.getBatch_Code());
		v.push_back(sub.getWarehouse_Name());
		v.push_back(sub.getLocation_Name());
		v.push_back(sub.getArea_Name());
		v.push_back(sub.getVendor_Code());
		v.push_back(sub.getVendor_Name());
		v.push_back(sub.getVendor_Nick());
		v.push_back(sub.getWorkorder_Code());
		v.push_back(sub.getRecpt_Date());
		v.push_back(sub.getExpire_Date());
		vvexcel.push_back(v);
	}
	const std::string tempfilePath = "./public/execl/wm-project.xlsx";
	const std::string tempsheetName = "WM";
	//����excel�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(tempfilePath, tempsheetName, vvexcel);
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// ��ȡ�ļ���׺��
	string suffix = "";
	size_t pos = tempfilePath.rfind(".");
	if (pos != string::npos)
	{
		suffix = tempfilePath.substr(pos + 1);
	}

	// �ϴ��ļ�
	string downloadUrl = dfs.uploadFile(tempfilePath);
	downloadUrl = urlPrefix + downloadUrl;

	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	//ɾ���������ɵ�excel�ļ�
	std::remove(tempfilePath.c_str());

	return downloadUrl;
}