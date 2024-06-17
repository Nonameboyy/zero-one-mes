#include "stdafx.h"
#include "ProcessInspectionController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/ProcessInspection/ProcessInspectionService.h"
#include "../../dao/ProcessInspection/ProcessInspectionDAO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "gtest/gtest.h"
#include "FastDfsClient.h"
#include "../include/NacosClient.h"

ProcessInspectionQueryPageJsonVO::Wrapper ProcessInspectionController::execQueryProcessInspection(const ProcessInspectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ProcessInspectionService service;
	//ִ�в�ѯ
	auto result = service.listAll(query);
	auto vo = ProcessInspectionQueryPageJsonVO::createShared();
	//��QueryPageDTOװ��vo��
	vo->success(result);
	return vo;
}

Uint64JsonVO::Wrapper ProcessInspectionController::execRemoveProcessInspection(const List<UInt64>& ids)
{
	ProcessInspectionService service;
	//��ѯ�Ƿ�ÿһ��id������,���ϵĲ�ѯ,
	int flag = 0;
	auto result = Uint64JsonVO::createShared();
	for (auto i = ids->begin(); i != ids->end(); ++i) {
		auto x = (*i).getValue(0);
		//��������
		if (x < 0 || !x) {
			if(!flag)
				result->init(UInt64(-1), RS_PARAMS_INVALID);
			flag = 1;
		}
		else {
			//ɾ��ʧ��
			if (!service.remove(x)) {
				if (!flag)
					result->init(UInt64(-1), RS_FAIL);
				flag = 1;
			}
		}
	}
	if(!flag)
		result->init(UInt64(1), RS_SUCCESS);
	return result;
}

StringJsonVO::Wrapper ProcessInspectionController::execExportProcessInspection(const ProcessInspectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ExcelComponent excel;
	ProcessInspectionService service;
	//��ȡ����
	auto result = service.listAllExort(query);
	vector<vector<std::string>> data;
	stringstream ss;
	//��ȡ����
	for (auto i = result.begin(); i != result.end();++i) {
		auto x = *i;
		vector<std::string> row;
		ss.clear();
		ss << x.getId();
		row.push_back(ss.str());

		ss.str("");
		ss << x.getIpqc_Code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getIpqc_Type();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getWorkorder_Code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getItem_Code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getItem_Name();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getSpecification();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getUnit_Of_Measure();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getQuantity_Check();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getCheck_Result();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getInspect_Date();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getInspector();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getStatus_Order();
		row.push_back(ss.str());
		ss.str("");

		data.push_back(row);
	}
	std::string fileName = ZH_WORDS_GETTER("excel.ProcessInspection.path");
	// ���Ĵʵ� 
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h1"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h2"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h3") ,
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h4") ,
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h5") ,
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h6"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h7"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h8"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h9"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h10"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h11"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h12"),
		ZH_WORDS_GETTER("excel.ProcessInspection.header.h13")
		});
	//����excel
	excel.writeVectorToFile(fileName, sheetName,data);
	//�����ļ�����������,��ƴ��urlǰ׺
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	//��׺������
	auto pos = fileName.rfind(".");
	string suffix = "";
	//�к�׺��
	if (pos != string::npos) {
		suffix = fileName.substr(pos + 1);
	}
	//�ϴ��ļ�
	auto downloadUrl=dfs.uploadFile(fileName);
	downloadUrl = urlPrefix + downloadUrl;
	auto ans = StringJsonVO::createShared();
	//ֻ��ǰ׺,�ϴ�ʧ��
	if (downloadUrl== urlPrefix) {
		ans->init("error", RS_FAIL);
	}
	else {
		ans->init(downloadUrl, RS_SUCCESS);
	}
	//ɾ�������ļ�
	std::remove(fileName.c_str());
	return ans;
}

// ��ȡ���̼��鵥����
ProcessInspectionJsonVO::Wrapper ProcessInspectionController::execQueryInspectionDetails(const ProcessInspectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	ProcessInspectionService service;
	auto result = service.getInspectionDetails(query);
	auto jvo = ProcessInspectionJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ProcessInspectionController::execModifyTheProcessInspection(const ProcessInspectionDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProcessInspectionService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
	//return {};
}

Uint64JsonVO::Wrapper ProcessInspectionController::execAddProcessInspection(const ProcessInspectionDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->ipqc_code || !dto->ipqc_type || !dto->workorder_code
		|| !dto->workstation_code || !dto->quantity_check
		|| !dto->quantity_unqualified || !dto->quantity_qualified)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->ipqc_code->empty() || dto->ipqc_type->empty() || dto->workorder_code->empty()
		|| dto->workstation_code->empty() || dto->quantity_check < 0
		|| dto->quantity_unqualified < 0 || dto->quantity_qualified < 0
		)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	ProcessInspectionService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

// ȷ�ϼ��鵥
Uint64JsonVO::Wrapper ProcessInspectionController::execModifyConfirmOrders(const ProcessInspectionDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (dto->check_result != "ACCEPT" && dto->check_result != "REJECT") {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ProcessInspectionService service;
	// ִ�������޸�
	if (service.updateConfirmOrdersData(dto)) {
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
	//return Uint64JsonVO::Wrapper();
}
// ��ɼ��鵥
Uint64JsonVO::Wrapper ProcessInspectionController::execModifyFinishOrders(const ProcessInspectionDTO::Wrapper& dto) {
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (dto->workorder_code == "" || !dto->workorder_code) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ProcessInspectionService service;
	// ִ�������޸�
	if (service.updateFinishOrdersData(dto)) {
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
	//return Uint64JsonVO::Wrapper();
}