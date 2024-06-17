#include "stdafx.h"
#include "ReturnController_r.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "tree/TreeUtil.h"
#include "service/return-ryan/ReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "ExcelComponent.h"

//ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query, const PayloadDTO& payload)
//{
//	return {};
//}
//
//ReturnDetailJsonVO::Wrapper ReturnController::executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
//{
//	return {};
//}
//
//Uint64JsonVO::Wrapper ReturnController::execAddDetail(const ReturnAdd::Wrapper& dto)
//{
//	return {};
//}




// �޸ĵ���
Uint64JsonVO::Wrapper ReturnController_r::execModifyReturn(const ReturnDTO_r::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->rt_id || dto->rt_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ReturnService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->rt_id);
	}
	else
	{
		jvo->fail(dto->rt_id);
	}
	// ��Ӧ���
	return jvo;
}

// ִ�е���
Uint64JsonVO::Wrapper ReturnController_r::execExecuteReturn(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ReturnService service;
	// ִ�������޸�
	if (service.excuteData(id)){
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}
// ɾ������
Uint64JsonVO::Wrapper ReturnController_r::execRemoveReturn(const oatpp::List<UInt64>& ids)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	
	// ����У��
	for (list<UInt64>::iterator i = ids->begin();i != ids->end();i++)
	{
		UInt64 id = *i;
		if (!id || id <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		ReturnService service;
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
// ��������
StringJsonVO::Wrapper ReturnController_r::execDownloadFile(const ReturnQuery_r::Wrapper& query, const PayloadDTO& payload)
{
	ExcelComponent excel;
	ReturnService service;
	//��ȡ����
	auto result = service.listAllExort(query);
	vector<vector<std::string>> data;
	stringstream ss;
	//��ȡ����
	for (auto i = result.begin(); i != result.end(); ++i) {
		auto x = *i;
		//rt_id,rt_code,rt_name,po_code, vendor_name, batch_code, rt_date, status, remark
		vector<std::string> row;
		ss.clear();
		ss << x.getRt_code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getRt_name();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getPo_code();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getVendor_name();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getRt_date();
		row.push_back(ss.str());
		ss.str("");

		ss.str("");
		ss << x.getStatus_();
		row.push_back(ss.str());
		ss.str("");

		data.push_back(row);
	}
	std::string fileName = ZH_WORDS_GETTER("excel.Return.path");
	// ���Ĵʵ�
	//std::string sheetName = ZH_WORDS_GETTER("excel.Return.sheet.s1");
	std::string sheetName = "title";
	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.Return.header.h1"),
		ZH_WORDS_GETTER("excel.Return.header.h2"),
		ZH_WORDS_GETTER("excel.Return.header.h3"),
		ZH_WORDS_GETTER("excel.Return.header.h4"),
		ZH_WORDS_GETTER("excel.Return.header.h5"),
		ZH_WORDS_GETTER("excel.Return.header.h6")
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

StringJsonVO::Wrapper ReturnController_r::execDownloadFile_q(const ReturnQuery_r::Wrapper& query)
{
	auto res = StringJsonVO::createShared();

	ReturnService service;
	auto url = service.exportTable(query);

	if (url != "")
		res->success(url);
	else
		res->fail("");
	return res;
	return StringJsonVO::Wrapper();
}
