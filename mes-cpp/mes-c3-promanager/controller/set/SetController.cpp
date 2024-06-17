#include "stdafx.h"
#include "SetController.h"
#include "../../service/set/ProcessExportService.h"
#include "../../service/set/ContentService.h"
#include "../../service/set/SetService.h"
#include "Macros.h"
#include "ExcelComponent.h"

// ע�⣺�õ�FastDfs�ĵط���Ҫ������ڵ���DFS��ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// 1 ��������
StringJsonVO::Wrapper SetController::execProcessExport(const ProcessExportQuery::Wrapper& query)
{
	// ����һ��Service
	ProcessExportService service;
	// ��ѯ����
	list<SetProAddTableDTO::Wrapper> result = service.listAll(query);
	std::vector<std::vector<std::string>> data;

	// DTO����ת��Ϊvector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(sub->processCode);
		tmp.emplace_back(sub->processName);
		tmp.emplace_back(sub->attention);
		tmp.emplace_back(sub->enableFlag);
		data.emplace_back(tmp);
	}

	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1"),
		ZH_WORDS_GETTER("excel.header.h2"),
		ZH_WORDS_GETTER("excel.header.h3"),
		ZH_WORDS_GETTER("excel.header.h4"),
		});

	// ���浽�ļ�
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// ����һ��fastdfs����ǰ׺
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// ��ȡ�ļ���׺��
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// �ϴ��ļ�
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	if (downloadUrl != "") {
		jvo->success(downloadUrl);
	}
	else {
		jvo->fail(downloadUrl);
	}

	return jvo;
}
// 2 ��ӹ���
Uint64JsonVO::Wrapper SetController::execAddSet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->processCode || !dto->processName || !dto->enableFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->processCode->empty() || dto->processName->empty() || dto->enableFlag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SetService service;
	// ִ����������
	uint64_t id = service.saveData(dto,payload.getUsername());
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
// 3 �޸Ĺ���
Uint64JsonVO::Wrapper SetController::execModifySet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->processId || dto->processId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SetService service;
	// ִ�������޸�
	if (service.updateData(dto,payload.getUsername())) {
		jvo->success(dto->processId);
	}
	else
	{
		jvo->fail(dto->processId);
	}
	// ��Ӧ���
	return jvo;
}
// 4 ��ȡ�������б�
SetProListPageJsonVO::Wrapper SetController::execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload) {
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = SetProListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 5 ��ӹ�����
Uint64JsonVO::Wrapper SetController::execAddStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->contentId || !dto->processId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->contentId < 0 || dto->processId < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SetService service;
	// ִ����������
	uint64_t id = service.saveStepData(dto, payload.getUsername());
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
// 6 ��ȡ�����б�
ProListPageJsonVO::Wrapper SetController::execQueryProList(const ProListQuery::Wrapper& query)
{
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.listAllForProcess(query);
	// ��Ӧ���
	auto jvo = ProListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ProListPageJsonVO::Wrapper();
}
// 7 ��ȡ���������б�
ProNameListJsonVO::Wrapper SetController::execQueryProNameList()
{
	auto jvo = ProNameListJsonVO::createShared();
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.getProcessNameList();
	// ��Ӧ���
	jvo->success(result);
	return jvo;
}
// 8 ��ȡ��������
ProDetailJsonVO::Wrapper SetController::execQueryProDetail(const ProDetailQuery::Wrapper& query)
{
	// ����һ��Service
	SetService service;
	// ��ѯ����
	auto result = service.getProcessDetail(query);
	// ��Ӧ���
	auto jvo = ProDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return ProDetailJsonVO::Wrapper();
}
//9 �޸Ĺ�����
Uint64JsonVO::Wrapper SetController::execModifyStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->contentId || dto->contentId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ContentService service;
	if (service.updateData(dto)) {
		jvo->success(dto->contentId);
	}
	else
	{
		jvo->fail(dto->contentId);
	}
	return jvo;
}
//10 ɾ��������
Uint64JsonVO::Wrapper SetController::execDeleteStepSet(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ContentService service;
	// ִ������ɾ��
	if (service.removeStep(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}
// 11 ����������
StringJsonVO::Wrapper SetController::execExportStepSet(const SetProListQuery::Wrapper& query)
{
	// ����һ��Service
	SetService service;
	// ��ѯ����
	list<SetProListDTO::Wrapper> result = service.listAllForExport(query);
	std::vector<std::vector<std::string>> data;

	// DTO����ת��Ϊvector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(to_string(sub->processId));
		tmp.emplace_back(to_string(sub->orderNum));
		tmp.emplace_back(sub->contentText);
		tmp.emplace_back(sub->device);
		tmp.emplace_back(sub->material);
		tmp.emplace_back(sub->docUrl);
		data.emplace_back(tmp);
	}

	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h9"),
		ZH_WORDS_GETTER("excel.header.h10"),
		ZH_WORDS_GETTER("excel.header.h11"),
		ZH_WORDS_GETTER("excel.header.h12"),
		ZH_WORDS_GETTER("excel.header.h13"),
		ZH_WORDS_GETTER("excel.header.h14"),
		});

	// ���浽�ļ�
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s3");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// ����һ��fastdfs����ǰ׺
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// ��ȡ�ļ���׺��
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// �ϴ��ļ�
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();
	if (downloadUrl != "") {
		jvo->success(downloadUrl);
	}
	else {
		jvo->fail(downloadUrl);
	}

	return jvo;
}

// 12 ɾ������
Uint64JsonVO::Wrapper SetController::execDeleteSet(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ContentService service;
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}