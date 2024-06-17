#include "stdafx.h"
#include "WorkFixtureService.h"
#include "domain/do/workfixture/WorkFixtureDO.h"
#include "dao/workfixture/WorkFixtureDAO.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

// 检查所有DTO参数的传入情况组装成DO，包括所有可选和非必选参数
#define ASSEMBLE_DO(data, dto) \
ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ToolName, toolName, ToolTypeId, toolTypeId, ToolTypeCode, toolTypeCode, ToolTypeName, toolTypeName, Quantity, quantity); \
if (dto->toolId)  data.setToolId(dto->toolId.getValue({})); \
if (dto->toolCode)  data.setToolCode(dto->toolCode.getValue({})); \
if (dto->brand)  data.setBrand(dto->brand.getValue({})); \
if (dto->spec)  data.setSpec(dto->spec.getValue({})); \
if (dto->quantityAvail)  data.setQuantityAvail(dto->quantityAvail.getValue({})); \
if (dto->maintenType)  data.setMaintenType(dto->maintenType.getValue({})); \
if (dto->nextMaintenDate)  data.setNextMaintenDate(dto->nextMaintenDate.getValue({})); \
if (dto->status)  data.setStatus(dto->status.getValue({})); \
if (dto->remark)  data.setRemark(dto->remark.getValue({}));

WorkFixturePageDTO::Wrapper WorkFixtureService::queryList(const WorkFixtureQuery::Wrapper &query)
{
	// 构建返回对象
	auto pages = WorkFixturePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	WorkFixtureDAO dao;
	uint64_t cnt = dao.count(query);
	if (cnt <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = cnt;
	pages->calcPages();
	list<WorkFixtureDO> res = dao.selectWithPageCondition(query);
	for (WorkFixtureDO sub : res) {
		auto dto = WorkFixtureDTO::createShared();
		// 此处是列表查询，因此不包含备注remark
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, toolId, ToolId, toolCode, ToolCode, toolName, ToolName,
			brand, Brand, spec, Spec, toolTypeId, ToolTypeId, toolTypeCode, ToolTypeCode, toolTypeName,
			ToolTypeName, quantity, Quantity, quantityAvail, QuantityAvail, maintenType, MaintenType,
			nextMaintenDate, NextMaintenDate, status, Status);
		pages->addData(dto);
	}

	return pages;
}

WorkFixtureDTO::Wrapper WorkFixtureService::queryDetail(uint64_t id)
{
	// 构建返回对象
	auto dto = WorkFixtureDTO::createShared();
	// 通过id查询数据
	WorkFixtureDAO dao;
	auto res = dao.selectById(id);
	// do转换成dto（通过id的查询只会返回一条数据），此处查询的是单条数据的详细信息，因此包含remark
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, res.front(), toolId, ToolId, toolCode, ToolCode, toolName, ToolName,
		brand, Brand, spec, Spec, toolTypeId, ToolTypeId, toolTypeCode, ToolTypeCode, toolTypeName,
		ToolTypeName, quantity, Quantity, quantityAvail, QuantityAvail, maintenType, MaintenType,
		nextMaintenDate, NextMaintenDate, status, Status, remark, Remark);
	return dto;
}

uint64_t WorkFixtureService::addData(const WorkFixtureDTO::Wrapper &dto)
{
	// 组装DO数据
	WorkFixtureDO data;
	ASSEMBLE_DO(data, dto);
	// 执行数据添加
	WorkFixtureDAO dao;
	return dao.insert(data);
}

bool WorkFixtureService::updateData(const WorkFixtureDTO::Wrapper &dto)
{
	// 组装DO数据，注意修改操作是必须要传入夹具ID的
	WorkFixtureDO data;
	ASSEMBLE_DO(data, dto);
	// 执行数据修改
	WorkFixtureDAO dao;
	return dao.update(data) == 1;
}

bool WorkFixtureService::removeData(const list<uint64_t> &id)
{
	WorkFixtureDAO dao;
	return dao.deleteBatch(id);
}

string WorkFixtureService::exportData(const list<uint64_t>& id)
{
	//获取查询结果
	auto dto = WorkFixtureDTO::createShared();
	WorkFixtureDAO dao;
	auto res = dao.selectByIdList(id);

	//将list数据写入vector
	std::vector<std::vector<std::string>> data;
	for (auto l : res) {
		std::vector<std::string> row;
		row.push_back(to_string(l.getToolId()));
		row.push_back(l.getToolCode());
		row.push_back(l.getToolName());
		row.push_back(l.getBrand());
		row.push_back(l.getSpec());
		row.push_back(to_string(l.getToolTypeId()));
		row.push_back(l.getToolTypeCode());
		row.push_back(l.getToolTypeName());
		row.push_back(to_string(l.getQuantity()));
		row.push_back(to_string(l.getQuantityAvail()));
		row.push_back(l.getMaintenType());
		row.push_back(l.getNextMaintenDate());
		row.push_back(l.getStatus());
		row.push_back(l.getRemark());
		data.push_back(row);
	}
	
	
	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string filename = "./public/excel/1.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetname = "excel.sheet.s1";

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


