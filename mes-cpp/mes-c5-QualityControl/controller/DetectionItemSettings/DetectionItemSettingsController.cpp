#include "stdafx.h"
#include "DetectionItemSettingsController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/DetectionItemSettings/DetectionItemSettingsService.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "gtest/gtest.h"
#include "FastDfsClient.h"
#include "../include/NacosClient.h"
DetectionItemSettingsPageJsonVO::Wrapper DetectionItemSettingsController::execQueryqc(const DetectionItemSettingsQuery::Wrapper& query) {
	DetectionItemSettingsService service;
	auto res = service.listAll(query);
	auto jvo = DetectionItemSettingsPageJsonVO::createShared();
	jvo->success(res);
	return jvo;
	return {};
}

Uint64JsonVO::Wrapper DetectionItemSettingsController::execAddqc(const DetectionItemSettingsDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->code || !dto->name || !dto->type || !dto->tool) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->code->empty() || dto->name->empty() || dto->type->empty() || dto->tool->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	DetectionItemSettingsService service;
	uint64_t id = service.saveData(dto);
	if (id >= 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	return jvo;
	return {};
}

Uint64JsonVO::Wrapper DetectionItemSettingsController::execModifyqc(const DetectionItemSettingsDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->code->empty() || dto->name->empty() || dto->type->empty() || dto->tool->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	DetectionItemSettingsService service;
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
	return{};
}

Uint64JsonVO::Wrapper DetectionItemSettingsController::execRemoveTheDetection(const oatpp::List<UInt64>& ids)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	for (list<UInt64>::iterator i = ids->begin(); i != ids->end(); i++)
	{
		UInt64 id = *i;
		// ����У��
		if (!id || id <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		DetectionItemSettingsService service;
		// ִ������ɾ��
		if (service.removeData(id.getValue(0))) {
			jvo->success(id);
		}
		else
		{
			jvo->fail(id);
		}

	}
	// ��Ӧ���
	return jvo;

}

StringJsonVO::Wrapper DetectionItemSettingsController::execExportDetectionItemSettings(const DetectionItemSettingsQuery::Wrapper& query, const PayloadDTO& payload)
{
	ExcelComponent excel;
	DetectionItemSettingsService service;
	//��ȡ����
	auto result = service.listAllExort(query);
	vector<vector<std::string>> data;
	stringstream ss;
	//��ȡ����
	for (auto i = result.begin(); i != result.end(); ++i) {
		auto x = *i;
		vector<std::string> row;
		ss.clear();
		ss << x.getId();
		row.push_back(ss.str());

		ss.str("");
		ss << x.getCode();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getName();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getType();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getTool();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getRemark();
		row.push_back(ss.str());
		ss.str("");


		data.push_back(row);
	}
	std::string fileName = ZH_WORDS_GETTER("excel.DetectionItemSettings.path");
	// ���Ĵʵ�
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.DetectionItemSettings.header.h1"),
		ZH_WORDS_GETTER("excel.DetectionItemSettings.header.h2"),
		ZH_WORDS_GETTER("excel.DetectionItemSettings.header.h3"),
		ZH_WORDS_GETTER("excel.DetectionItemSettings.header.h4"),
		ZH_WORDS_GETTER("excel.DetectionItemSettings.header.h5"),
		ZH_WORDS_GETTER("excel.DetectionItemSettings.header.h6")
		});
	//����excel
	excel.writeVectorToFile(fileName, sheetName, data);
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
	auto downloadUrl = dfs.uploadFile(fileName);
	downloadUrl = urlPrefix + downloadUrl;
	auto ans = StringJsonVO::createShared();
	//ֻ��ǰ׺,�ϴ�ʧ��
	if (downloadUrl == urlPrefix) {
		ans->init("error", RS_FAIL);
	}
	else {
		ans->init(downloadUrl, RS_SUCCESS);
	}
	//ɾ�������ļ�
	std::remove(fileName.c_str());
	return ans;
}