#include "stdafx.h"
#include "ProcessController.h"
#include "../../service/process/ProcessListService.h"
#include "../../service/process/ProcessProductsService.h"
#include "../../service/process/ComProService.h"
#include "../../service/process/RelateProService.h"
#include "../../service/process/ProMaterialService.h"
#include "../../service/process/ProcessBOMService.h"

//#include "declarative/ProMaterialApiClient.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "Macros.h"
#include "ExcelComponent.h"

// ע�⣺�õ�FastDfs�ĵط���Ҫ������ڵ���DFS��ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// 1 ��ѯ�����б�
ProcessListJsonVO::Wrapper ProcessController::execQueryProcessList(const ProcessListQuery::Wrapper& query)
{
	// ����һ��Service
	ProcessListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProcessListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 2 ��ѯ��������
ProcessDetailJsonVO::Wrapper ProcessController::execQueryProcessDetail(const ProcessDetailQuery::Wrapper& query)
{
	// ����һ��Service
	ProcessListService service;
	// ��ѯ����
	auto result = service.getById(query);
	// ��Ӧ���
	auto jvo = ProcessDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 3 ��ӹ���
Uint64JsonVO::Wrapper ProcessController::execAddProcess(const ProcessAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	//�ǿ�У��
	if (!dto->routeCode || !dto->routeName || !dto->enableFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->routeCode->empty() || dto->routeName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//����һ��Service
	ProcessListService service;
	//ִ����������
	uint64_t id = service.saveProcessAdd(dto, payload.getUsername());
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

// 4 �޸Ĺ���
Uint64JsonVO::Wrapper ProcessController::execModifyBasicProcess(const ProcessDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->routeId || dto->routeId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProcessListService service;
	// ִ�������޸�
	if (service.updateData(dto, payload.getUsername())) {
		jvo->success(dto->routeId);
	}
	else
	{
		jvo->fail(dto->routeId);
	}
	// ��Ӧ���
	return jvo;
}

// 5 ��ȡ���չ�����Ʒ�б�����+��ҳ��
ProductsPageJsonVO::Wrapper ProcessController::execQueryProducts(const ProcessProductsQuery::Wrapper& query)
{
	// ����һ��Service
	ProcessProductsService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProductsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 6 ɾ����ɹ���
Uint64JsonVO::Wrapper ProcessController::execRemoveProcess(const List<UInt64>& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	list<uint64_t> data;
	for (auto p = id->begin(); p != id->end(); ++p) {
		//����У��
		if (!*p || *p <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		data.emplace_back(*p);
	}
	// ����һ��Service
	ComProService service;
	// ִ������ɾ��
	int res = service.removeData(data);
	if (res) {
		jvo->success(res);
	}
	else
	{
		jvo->fail(res);
	}
	// ��Ӧ���
	return jvo;
}

//7 ���յ���
StringJsonVO::Wrapper ProcessController::execQueryProcess(const ProcessListQuery::Wrapper& query)
{
	// ����һ��Service
	ProcessListService service;
	// ��ѯ����
	list<ProcessAddDTO::Wrapper> result = service.listAllForProcess(query);
	std::vector<std::vector<std::string>> data;

	// DTO����ת��Ϊvector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(sub->routeCode);
		tmp.emplace_back(sub->routeName);
		tmp.emplace_back(sub->routeDesc);
		tmp.emplace_back(sub->enableFlag);
		data.emplace_back(tmp);
	}

	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h5"),
		ZH_WORDS_GETTER("excel.header.h6"),
		ZH_WORDS_GETTER("excel.header.h7"),
		ZH_WORDS_GETTER("excel.header.h8"),
		});

	// ���浽�ļ�
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s2");
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

//8 ��ȡ��ɹ����б�
ProJsonVO::Wrapper ProcessController::execProTable(const ProQuery::Wrapper& query)
{
	// ����һ��Service
	ComProService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//9 �����ɹ���
Uint64JsonVO::Wrapper ProcessController::execaddComProcess(const NewProcessDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->process_code || !dto->process_name || !dto->key_flag || !dto->is_check)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->process_code->empty() || dto->process_name->empty() || dto->key_flag->empty() || dto->is_check->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ComProService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
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

//10 �޸���ɹ���
Uint64JsonVO::Wrapper ProcessController::execModifyProcess(const ModifyProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ComProService service;
	// ִ�������޸�
	if (service.updateData(dto,payload)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}

// 11 ��ӹ��չ�����Ʒ
Uint64JsonVO::Wrapper ProcessController::execAddRelatePro(const AddRelateProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->item_code || !dto->item_name || !dto->unit_of_measure || !dto->specification)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->item_code->empty() || dto->item_name->empty() || dto->unit_of_measure->empty() || dto->specification->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RelateProService service;
	// ִ����������
	uint64_t id = service.saveData(dto, payload);
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

// 12 �޸Ĺ��չ�����Ʒ
Uint64JsonVO::Wrapper ProcessController::execModifyRelatePro(const ModRelateProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0 || !dto->item_code || !dto->item_name || !dto->unit_of_measure ||
		!dto->specification)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RelateProService service;
	// ִ�������޸�
	if (service.updateData(dto, payload)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}

// 13 ��ȡ��Ʒ�Ƴ�����BOM�б�
ProMaterialPageJsonVO::Wrapper ProcessController::execQueryProMaterial(const ProMaterialQuery::Wrapper& query)
{
	// ����һ��Service
	ProMaterialService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProMaterialPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 14 ɾ����������
List<Uint64JsonVO::Wrapper> ProcessController::execRemoveProRoute(const List<UInt64>&Lid)
{
	// ��Ӧ���
	List< Uint64JsonVO::Wrapper> temp;
	auto ans = temp.createShared();
	// ���巵�����ݶ���
	list<UInt64> id = *(Lid.get());
	for (auto iter : id)
	{
		UInt64 temp = *iter;
		//printf("-----------test-----------\n---------%d---------\n", iter.getValue(0));

		auto jvo = Uint64JsonVO::createShared();
		// ����У��
		if (!temp || *temp <= 0)
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		else
		{
			// ����һ��Service
			ProcessListService service;
			// ִ������ɾ��
			if (service.removeData(temp.getValue(0))) {
				jvo->success(temp);
			}
			else
			{
				jvo->fail(temp);
			}
		}
		ans.get()->emplace_back(jvo);
		//it.get()->emplace_back(jvo);
	}

	return ans;
}
// 15 ɾ�����չ�����Ʒ
List<Uint64JsonVO::Wrapper> ProcessController::execRemoveRouteProduct(const List<UInt64>& Lid)
{
	// ��Ӧ���
	List< Uint64JsonVO::Wrapper> temp;
	auto ans = temp.createShared();
	// ���巵�����ݶ���
	list<UInt64> id = *(Lid.get());
	for (auto iter : id)
	{
		UInt64 temp = *iter;
		auto jvo = Uint64JsonVO::createShared();
		// ����У��
		if (!temp || *temp <= 0)
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		else
		{
			// ����һ��Service
			RelateProService service;
			// ִ������ɾ��
			if (service.removeData(temp.getValue(0))) {
				jvo->success(temp);
			}
			else
			{
				jvo->fail(temp);
			}
		}
		ans.get()->emplace_back(jvo);
	}

	return ans;
}
// 16 �������չ�����Ʒ
StringJsonVO::Wrapper ProcessController::execExportRouteProduct(const List<UInt64>& Lid)
{
	// ����һ��Service
	RelateProService service;
	// ��ѯ����
	list<UInt64> id = *(Lid.get());
	std::vector<std::vector<std::string>> data;

	// DTO����ת��Ϊvector
	for (const auto& iter : id)
	{
		ExportRelateProDTO::Wrapper result = service.listAll(iter.getValue(0));
		std::vector<std::string> temp;

		//�е�����
		temp.emplace_back(to_string(result->record_id.getValue(0)));
		temp.emplace_back(to_string(result->route_id.getValue(0)));
		temp.emplace_back(to_string(result->item_id.getValue(0)));
		temp.emplace_back(result->item_code.getValue(""));
		temp.emplace_back(result->item_name.getValue(""));
		temp.emplace_back(result->unit_of_measure.getValue(""));
		temp.emplace_back(result->specification.getValue(""));
		temp.emplace_back(result->RPmodels.getValue(""));
		data.emplace_back(temp);
	}

	// �����ͷ
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1"),
		ZH_WORDS_GETTER("excel.header.h2"),
		ZH_WORDS_GETTER("excel.header.h3"),
		ZH_WORDS_GETTER("excel.header.h4"),
		ZH_WORDS_GETTER("excel.header.h5"),
		ZH_WORDS_GETTER("excel.header.h6"),
		ZH_WORDS_GETTER("excel.header.h7"),
		ZH_WORDS_GETTER("excel.header.h8"),
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
	//auto jvo = StringJsonVO::createShared();
	return jvo;

}
// 17 ɾ����Ʒ�Ƴ�����BOM
Uint64JsonVO::Wrapper ProcessController::execRemoveProcessBOM(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProcessBOMService service;
	// ִ������ɾ��
	if (service.removeBOM(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	return jvo;
}
// 18 ��Ӳ�Ʒ�Ƴ�����BOM
Uint64JsonVO::Wrapper ProcessController::execAddProductMaterial(const ProductMaterialDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->item_name || !dto->unit_of_measure || !dto->quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if ( dto->item_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ProcessBOMService service;
	// ִ����������
	uint64_t id = service.saveBOM(dto, payload);
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
// 19 �޸Ĳ�Ʒ�Ƴ�����BOM
Uint64JsonVO::Wrapper ProcessController::execModifyProductMaterial(const ProductModefyMaterialDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || !dto->item_name || !dto->unit_of_measure || !dto->quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProcessBOMService service;
	// ִ�������޸�
	if (service.updateBOM(dto, payload)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}
