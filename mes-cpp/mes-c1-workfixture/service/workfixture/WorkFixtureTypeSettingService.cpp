#include "stdafx.h"
#include "WorkFixtureTypeSettingService.h"
#include "../../dao/workfixture/WorkFixtureTypeDAO.h"
//excel�ļ�ʹ����������
#include "Macros.h"
#include "ExcelComponent.h"
WorkFixtureTypeListPageDTO::Wrapper WorkFixtureTypeSettingService::typeList(const WorkFixtureTypeListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = WorkFixtureTypeListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������
	WorkFixtureTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<WorkFixtureTypeSettingDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// �������ض���
	auto list = oatpp::List<WorkFixtureTypeNameListDTO::Wrapper>::createShared();
	// ͨ��id��ѯ����
	WorkFixtureTypeDAO dao;
	auto res = dao.selectAll();
	// doת����dto
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
	// ��װDO����
	WorkFixtureTypeSettingDO data;
	/*
	//���ͱ���
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//��������
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//�Ƿ�������N/Y 
	API_DTO_FIELD_DEFAULT(String, codeFlag, ZH_WORDS_GETTER("workfixture.type.fields.codeflag"));
	//����ά������ REGULAR����ά�� USAGE��ʹ�ô���ά��
	API_DTO_FIELD(String, maintenType, ZH_WORDS_GETTER("workfixture.type.fields.mtype"), true, "NULL");
	//��������
	API_DTO_FIELD(Int32, maintenPriod, ZH_WORDS_GETTER("workfixture.type.fields.mpriod"), true, 0);
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workfixture.type.fields.remark"), true, "");
	*/
	
	 	data.setCode(dto->typeCode.getValue(""));
	 	data.setName(dto->typeName.getValue(""));
		data.setFlag(dto->codeFlag.getValue("Y"));
		data.setMaintenType(dto->maintenType.getValue(""));
		data.setPeriod(dto->maintenPeriod.getValue(1));
		//�ظ�����
		WorkFixtureTypeDAO dao;
		size_t findSize = 0;
		findSize+=dao.selectByCode(data.getCode()).size();
		findSize += dao.selectByName(data.getName()).size();
		if (findSize > 0) {
			return 0;
		}
		// ִ���������
	return dao.insert(data);
}

bool WorkFixtureTypeSettingService::updateData(const WorkFixtureTypeUpdateDTO::Wrapper& dto)
{
	// ��װDO����
	WorkFixtureTypeSettingDO data;
	/*
	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(UInt64, toolTypeID, ZH_WORDS_GETTER("workfixture.fields.tooltypeid"));
	//���ͱ���
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//��������
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//�Ƿ�������N/Y 
	API_DTO_FIELD_DEFAULT(String, codeFlag, ZH_WORDS_GETTER("workfixture.type.fields.codeflag"));
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workfixture.type.fields.remark"), true, "");
	*/
	 	data.setId(dto->toolTypeID.getValue(0));
	 	data.setCode(dto->typeCode.getValue(""));
	 	data.setName(dto->typeName.getValue(""));
	 	data.setFlag(dto->codeFlag.getValue("Y"));
		data.setRemark(dto->remark.getValue(""));
		// ִ�������޸�
		WorkFixtureTypeDAO dao;
		//�ظ�����
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
	//��"public/static/exportFile"����excel�ļ�  
	string fileName = "./public/excel/tooltype.xlsx";
	string sheetName = "workfixturetypedata";

	//��dao��ȡ����
	WorkFixtureTypeDAO dao;
	auto listData = dao.selectAll();

	//��excel�����������data
	vector<vector<string>> data;
	//������ͷhead ������data
	vector<string> head;
	head.push_back("TypeCode");
	head.push_back("TypeName");
	head.push_back("Enable");
	head.push_back("MaintenType");
	head.push_back("MaintenPeriod");
	data.push_back(head);

	//��listDataת����ʽ ����data
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
