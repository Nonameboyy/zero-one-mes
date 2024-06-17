/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "WorkStationService.h"
#include "../../dao/workstation/WorkStationDAO.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
// 获取工作站列表
GetWorkStationListPageDTO::Wrapper WorkStationService::listAll(const GetWorkStationListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetWorkStationListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	WorkStationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<WorkStationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (WorkStationDO sub : result)
	{
		auto dto = GetWorkStationListDTO::createShared();
		//用阿伟的宏简化步骤
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, workstationId, WorkstationId,workstationCode, WorkstationCode, workstationName, WorkstationName, workstationAddress, WorkstationAddress, workshopName, WorkshopName, processName, ProcessName, enableFlag, EnableFlag, remark, Remark)
			pages->addData(dto);
	}
	return pages;
}

// 新增工作站并保存数据
uint64_t WorkStationService::saveData(const AddWorkStationDTO::Wrapper& dto)
{
	// 组装DO数据
	WorkStationDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, WorkstationCode, workstationCode, WorkstationName, workstationName, WorkshopName, workshopName, ProcessName, processName, EnableFlag, enableFlag, WorkstationAddress, workstationAddress, Remark, remark, WarehouseId, warehouseId, LocationId, locationId, AreaId, areaId)
		// 执行数据添加
		WorkStationDAO dao;
	return dao.insert(data);
}

// 修改工作站
bool WorkStationService::updateData(const ModifyWorkStationDTO::Wrapper& dto)
{
	// 组装DO数据
	WorkStationDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, WorkstationId, workstationId, WorkstationCode, workstationCode, WorkstationName, workstationName, WorkshopName, workshopName, ProcessName, processName, EnableFlag, enableFlag, WorkstationAddress, workstationAddress, Remark, remark)
		// 执行数据修改
		WorkStationDAO dao;
	return dao.update(data) == 1;
}

//删除工作站
bool WorkStationService::removeData(uint64_t id)
{
	WorkStationDAO dao;
	return dao.deleteById(id) == 1;
}

bool WorkStationService::removeDatas(list<uint64_t> id)
{
	WorkStationDAO dao;
	return dao.deleteByIdList(id);
}

string WorkStationService::exportData(const list<uint64_t>& id)
{
	//获取查询结果
	WorkStationDAO dao;
	auto res = dao.selectByIdList(id);

	//将list数据写入vector
	std::vector<std::vector<std::string>> data;
	for (auto l : res) {
		std::vector<std::string> row;
		row.push_back(to_string(l.getWorkstationId()));
		row.push_back(l.getWorkstationCode());
		row.push_back(l.getWorkstationName());
		row.push_back(l.getWorkstationAddress());
		row.push_back(l.getWorkshopName());
		row.push_back(l.getProcessName());
		row.push_back(l.getRemark());
		row.push_back(l.getEnableFlag());
		row.push_back(to_string(l.getWarehouseId()));
		row.push_back(to_string(l.getLocationId()));
		row.push_back(to_string(l.getAreaId()));
		data.push_back(row);
	}




	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string filename = "./public/excel/1.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetname = "excel.sheet.s1";

	//插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("workstation_id") ,
		ZH_WORDS_GETTER("workstation_code") ,
		ZH_WORDS_GETTER("workstation_name") ,
		ZH_WORDS_GETTER("workstation_address") ,
		ZH_WORDS_GETTER("workshop_name") ,
		ZH_WORDS_GETTER("process_name") ,
		ZH_WORDS_GETTER("remark") ,
		ZH_WORDS_GETTER("enable_flag") ,
		ZH_WORDS_GETTER("warehouse_id") ,
		ZH_WORDS_GETTER("location_id") ,
		ZH_WORDS_GETTER("area_id") ,
		});

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(filename, sheetname, data);

	// DFS客户端连接对象
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);

	std::string tmpField = client.uploadFile(filename);
	std::string downloadUrl = urlPrefix + tmpField;
	//返回下载地址
	return downloadUrl;
}
