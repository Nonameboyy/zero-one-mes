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

// 注意：用到FastDfs的地方都要在最后在导入DFS的头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// 1 查询工艺列表
ProcessListJsonVO::Wrapper ProcessController::execQueryProcessList(const ProcessListQuery::Wrapper& query)
{
	// 定义一个Service
	ProcessListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProcessListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 2 查询工艺详情
ProcessDetailJsonVO::Wrapper ProcessController::execQueryProcessDetail(const ProcessDetailQuery::Wrapper& query)
{
	// 定义一个Service
	ProcessListService service;
	// 查询数据
	auto result = service.getById(query);
	// 响应结果
	auto jvo = ProcessDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 3 添加工艺
Uint64JsonVO::Wrapper ProcessController::execAddProcess(const ProcessAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	//非空校验
	if (!dto->routeCode || !dto->routeName || !dto->enableFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->routeCode->empty() || dto->routeName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//定义一个Service
	ProcessListService service;
	//执行数据新增
	uint64_t id = service.saveProcessAdd(dto, payload.getUsername());
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

// 4 修改工艺
Uint64JsonVO::Wrapper ProcessController::execModifyBasicProcess(const ProcessDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->routeId || dto->routeId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProcessListService service;
	// 执行数据修改
	if (service.updateData(dto, payload.getUsername())) {
		jvo->success(dto->routeId);
	}
	else
	{
		jvo->fail(dto->routeId);
	}
	// 响应结果
	return jvo;
}

// 5 获取工艺关联产品列表（条件+分页）
ProductsPageJsonVO::Wrapper ProcessController::execQueryProducts(const ProcessProductsQuery::Wrapper& query)
{
	// 定义一个Service
	ProcessProductsService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProductsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 6 删除组成工序
Uint64JsonVO::Wrapper ProcessController::execRemoveProcess(const List<UInt64>& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	list<uint64_t> data;
	for (auto p = id->begin(); p != id->end(); ++p) {
		//数据校验
		if (!*p || *p <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
		data.emplace_back(*p);
	}
	// 定义一个Service
	ComProService service;
	// 执行数据删除
	int res = service.removeData(data);
	if (res) {
		jvo->success(res);
	}
	else
	{
		jvo->fail(res);
	}
	// 响应结果
	return jvo;
}

//7 工艺导出
StringJsonVO::Wrapper ProcessController::execQueryProcess(const ProcessListQuery::Wrapper& query)
{
	// 定义一个Service
	ProcessListService service;
	// 查询数据
	list<ProcessAddDTO::Wrapper> result = service.listAllForProcess(query);
	std::vector<std::vector<std::string>> data;

	// DTO数据转换为vector
	for (auto sub : result) {
		std::vector<std::string> tmp;
		tmp.emplace_back(sub->routeCode);
		tmp.emplace_back(sub->routeName);
		tmp.emplace_back(sub->routeDesc);
		tmp.emplace_back(sub->enableFlag);
		data.emplace_back(tmp);
	}

	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h5"),
		ZH_WORDS_GETTER("excel.header.h6"),
		ZH_WORDS_GETTER("excel.header.h7"),
		ZH_WORDS_GETTER("excel.header.h8"),
		});

	// 保存到文件
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s2");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// 创建一个fastdfs对象及前缀
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// 上传文件
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// 响应结果
	auto jvo = StringJsonVO::createShared();
	if (downloadUrl != "") {
		jvo->success(downloadUrl);
	}
	else {
		jvo->fail(downloadUrl);
	}

	return jvo;
}

//8 获取组成工序列表
ProJsonVO::Wrapper ProcessController::execProTable(const ProQuery::Wrapper& query)
{
	// 定义一个Service
	ComProService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//9 添加组成工序
Uint64JsonVO::Wrapper ProcessController::execaddComProcess(const NewProcessDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->process_code || !dto->process_name || !dto->key_flag || !dto->is_check)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->process_code->empty() || dto->process_name->empty() || dto->key_flag->empty() || dto->is_check->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ComProService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

//10 修改组成工序
Uint64JsonVO::Wrapper ProcessController::execModifyProcess(const ModifyProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ComProService service;
	// 执行数据修改
	if (service.updateData(dto,payload)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}

// 11 添加工艺关联产品
Uint64JsonVO::Wrapper ProcessController::execAddRelatePro(const AddRelateProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->item_code || !dto->item_name || !dto->unit_of_measure || !dto->specification)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->item_code->empty() || dto->item_name->empty() || dto->unit_of_measure->empty() || dto->specification->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	RelateProService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

// 12 修改工艺关联产品
Uint64JsonVO::Wrapper ProcessController::execModifyRelatePro(const ModRelateProDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || dto->record_id <= 0 || !dto->item_code || !dto->item_name || !dto->unit_of_measure ||
		!dto->specification)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RelateProService service;
	// 执行数据修改
	if (service.updateData(dto, payload)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}

// 13 获取产品制程物料BOM列表
ProMaterialPageJsonVO::Wrapper ProcessController::execQueryProMaterial(const ProMaterialQuery::Wrapper& query)
{
	// 定义一个Service
	ProMaterialService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProMaterialPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 14 删除工艺流程
List<Uint64JsonVO::Wrapper> ProcessController::execRemoveProRoute(const List<UInt64>&Lid)
{
	// 响应结果
	List< Uint64JsonVO::Wrapper> temp;
	auto ans = temp.createShared();
	// 定义返回数据对象
	list<UInt64> id = *(Lid.get());
	for (auto iter : id)
	{
		UInt64 temp = *iter;
		//printf("-----------test-----------\n---------%d---------\n", iter.getValue(0));

		auto jvo = Uint64JsonVO::createShared();
		// 参数校验
		if (!temp || *temp <= 0)
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		else
		{
			// 定义一个Service
			ProcessListService service;
			// 执行数据删除
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
// 15 删除工艺关联产品
List<Uint64JsonVO::Wrapper> ProcessController::execRemoveRouteProduct(const List<UInt64>& Lid)
{
	// 响应结果
	List< Uint64JsonVO::Wrapper> temp;
	auto ans = temp.createShared();
	// 定义返回数据对象
	list<UInt64> id = *(Lid.get());
	for (auto iter : id)
	{
		UInt64 temp = *iter;
		auto jvo = Uint64JsonVO::createShared();
		// 参数校验
		if (!temp || *temp <= 0)
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		else
		{
			// 定义一个Service
			RelateProService service;
			// 执行数据删除
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
// 16 导出工艺关联产品
StringJsonVO::Wrapper ProcessController::execExportRouteProduct(const List<UInt64>& Lid)
{
	// 定义一个Service
	RelateProService service;
	// 查询数据
	list<UInt64> id = *(Lid.get());
	std::vector<std::vector<std::string>> data;

	// DTO数据转换为vector
	for (const auto& iter : id)
	{
		ExportRelateProDTO::Wrapper result = service.listAll(iter.getValue(0));
		std::vector<std::string> temp;

		//有点问题
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

	// 插入表头
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

	// 保存到文件
	std::string fileName = "./public/excel/process.xlsx";
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	std::string filename = "";
	filename = "./public/excel/process.xlsx";
	// 创建一个fastdfs对象及前缀
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != string::npos)
	{
		suffix = filename.substr(pos + 1);
	}
	// 上传文件
	string downloadUrl = dfs.uploadFile(filename);
	downloadUrl = urlPrefix + downloadUrl;
	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

	// 响应结果
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
// 17 删除产品制程物料BOM
Uint64JsonVO::Wrapper ProcessController::execRemoveProcessBOM(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProcessBOMService service;
	// 执行数据删除
	if (service.removeBOM(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	return jvo;
}
// 18 添加产品制程物料BOM
Uint64JsonVO::Wrapper ProcessController::execAddProductMaterial(const ProductMaterialDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->item_name || !dto->unit_of_measure || !dto->quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if ( dto->item_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	ProcessBOMService service;
	// 执行数据新增
	uint64_t id = service.saveBOM(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
// 19 修改产品制程物料BOM
Uint64JsonVO::Wrapper ProcessController::execModifyProductMaterial(const ProductModefyMaterialDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->record_id || !dto->item_name || !dto->unit_of_measure || !dto->quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ProcessBOMService service;
	// 执行数据修改
	if (service.updateBOM(dto, payload)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// 响应结果
	return jvo;
}
