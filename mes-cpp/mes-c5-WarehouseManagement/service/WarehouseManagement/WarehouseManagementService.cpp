#include "stdafx.h"
#include "WarehouseManagementService.h"
#include "../../dao/WarehouseManagement/WarehouseManagementDAO.h"
#include "../lib-common/include/ExcelComponent.h"
#include "../lib-common/include/NacosClient.h"
#include "../lib-common/include/FastDfsClient.h"

//只写了获取
WarehouseManagementPageDTO::Wrapper WarehouseManagementService::listAll(const WarehouseManagementQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = WarehouseManagementPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	WarehouseManagementDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<WarehouseManagementDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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

//导出Excel
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
	//生成excel文件
	ExcelComponent excel;
	excel.writeVectorToFile(tempfilePath, tempsheetName, vvexcel);
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = tempfilePath.rfind(".");
	if (pos != string::npos)
	{
		suffix = tempfilePath.substr(pos + 1);
	}

	// 上传文件
	string downloadUrl = dfs.uploadFile(tempfilePath);
	downloadUrl = urlPrefix + downloadUrl;

	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	//删除本地生成的excel文件
	std::remove(tempfilePath.c_str());

	return downloadUrl;
}