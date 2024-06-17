#include "stdafx.h"
#include "WorkFixtureTypeSettingService.h"
#include "../../dao/workfixture/WorkFixtureTypeDAO.h"
//excel文件使用下面两个
#include "Macros.h"
#include "ExcelComponent.h"
WorkFixtureTypeListPageDTO::Wrapper WorkFixtureTypeSettingService::typeList(const WorkFixtureTypeListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = WorkFixtureTypeListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	WorkFixtureTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<WorkFixtureTypeSettingDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (WorkFixtureTypeSettingDO sub : result)
	{
		auto dto = WorkFixtureTypeListDTO::createShared();
		dto->toolTypeID = sub.getId();
		dto->typeCode = sub.getCode();
		dto->typeName = sub.getName();
		dto->maintenType = sub.getMaintenType();
		dto->codeFlag = sub.getFlag();
		dto->maintenPeriod = sub.getPeriod();
		dto->remark = sub.getRemark();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
			pages->addData(dto);

	}
	return pages;
}

oatpp::List<WorkFixtureTypeNameListDTO::Wrapper> WorkFixtureTypeSettingService::typeNameList(const WorkFixtureTypeNameListQuery::Wrapper& query)
{
	// 构建返回对象
	auto list = oatpp::List<WorkFixtureTypeNameListDTO::Wrapper>::createShared();
	// 通过id查询数据
	WorkFixtureTypeDAO dao;
	auto res = dao.selectAll();
	// do转换成dto
	for (WorkFixtureTypeSettingDO sub : res)
	{
		auto dto = WorkFixtureTypeNameListDTO::createShared();
		dto->toolTypeID = sub.getId();
		dto->typeName = sub.getName();
		dto->typeCode = sub.getCode();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
		list->push_back(dto);
	}
	return list;
}

uint64_t WorkFixtureTypeSettingService::saveData(const WorkFixtureTypeCreateDTO::Wrapper& dto)
{
	// 组装DO数据
	WorkFixtureTypeSettingDO data;
	/*
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//是否编码管理N/Y 
	API_DTO_FIELD_DEFAULT(String, codeFlag, ZH_WORDS_GETTER("workfixture.type.fields.codeflag"));
	//保养维护类型 REGULAR定期维护 USAGE按使用次数维护
	API_DTO_FIELD(String, maintenType, ZH_WORDS_GETTER("workfixture.type.fields.mtype"), true, "NULL");
	//保养周期
	API_DTO_FIELD(Int32, maintenPriod, ZH_WORDS_GETTER("workfixture.type.fields.mpriod"), true, 0);
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workfixture.type.fields.remark"), true, "");
	*/
	
	 	data.setCode(dto->typeCode.getValue(""));
	 	data.setName(dto->typeName.getValue(""));
		data.setFlag(dto->codeFlag.getValue("Y"));
		data.setMaintenType(dto->maintenType.getValue(""));
		data.setPeriod(dto->maintenPeriod.getValue(1));
		//重复检验
		WorkFixtureTypeDAO dao;
		size_t findSize = 0;
		findSize+=dao.selectByCode(data.getCode()).size();
		findSize += dao.selectByName(data.getName()).size();
		if (findSize > 0) {
			return 0;
		}
		// 执行数据添加
	return dao.insert(data);
}

bool WorkFixtureTypeSettingService::updateData(const WorkFixtureTypeUpdateDTO::Wrapper& dto)
{
	// 组装DO数据
	WorkFixtureTypeSettingDO data;
	/*
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, toolTypeID, ZH_WORDS_GETTER("workfixture.fields.tooltypeid"));
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//是否编码管理N/Y 
	API_DTO_FIELD_DEFAULT(String, codeFlag, ZH_WORDS_GETTER("workfixture.type.fields.codeflag"));
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workfixture.type.fields.remark"), true, "");
	*/
	 	data.setId(dto->toolTypeID.getValue(0));
	 	data.setCode(dto->typeCode.getValue(""));
	 	data.setName(dto->typeName.getValue(""));
	 	data.setFlag(dto->codeFlag.getValue("Y"));
		data.setRemark(dto->remark.getValue(""));
		// 执行数据修改
		WorkFixtureTypeDAO dao;
		//重复检验
		size_t findSize = 0;
		findSize += dao.selectByCode(data.getCode()).size();
		findSize += dao.selectByName(data.getName()).size();
		if (findSize > 0) {
			return 0;
		}

	return dao.update(data) == 1;
}

bool WorkFixtureTypeSettingService::removeData(uint64_t id)
{
	WorkFixtureTypeDAO dao;
	return dao.deleteById(id) == 1;
}

void WorkFixtureTypeSettingService::makeFile()
{
	//在"public/static/exportFile"生成excel文件  
	string fileName = "./public/excel/tooltype.xlsx";
	string sheetName = "workfixturetypedata";

	//从dao获取数据
	WorkFixtureTypeDAO dao;
	auto listData = dao.selectAll();

	//向excel中填入的数据data
	vector<vector<string>> data;
	//构建表头head 并加入data
	vector<string> head;
	head.push_back("TypeCode");
	head.push_back("TypeName");
	head.push_back("Enable");
	head.push_back("MaintenType");
	head.push_back("MaintenPeriod");
	data.push_back(head);

	//将listData转换格式 放入data
	for (auto a : listData) {
		vector<string> tem;
		tem.push_back(a.getCode());
		tem.push_back(a.getName());
		tem.push_back(a.getFlag());
		tem.push_back(a.getMaintenType());
		tem.push_back(to_string(a.getPeriod()));
		data.push_back(tem);
	}

	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
}
