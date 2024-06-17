#include "stdafx.h"
#include "WorkFixtureTypeSettingController.h"
#include "../../service/workfixture/WorkFixtureTypeSettingService.h"
WorkFixtureTypeListPageJsonVO::Wrapper WorkFixtureTypeSettingController::execType(const WorkFixtureTypeListQuery::Wrapper& query)
{
	// 定义一个Service
	WorkFixtureTypeSettingService service;
	// 查询数据
	auto result = service.typeList(query);
	// 响应结果
	auto jvo = WorkFixtureTypeListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
WorkFixtureTypeNameListJsonVO::Wrapper WorkFixtureTypeSettingController::execTypeName(const WorkFixtureTypeNameListQuery::Wrapper& query)
{
	// 定义一个Service
	WorkFixtureTypeSettingService service;
	// 查询数据
	auto result = service.typeNameList(query);
	// 响应结果
	auto jvo = WorkFixtureTypeNameListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper WorkFixtureTypeSettingController::execCreateType(const WorkFixtureTypeCreateDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
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
	
	if (!dto->typeCode || !dto->typeName || !dto->codeFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->typeCode->empty() || dto->typeName->empty() || dto->codeFlag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	WorkFixtureTypeSettingService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
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
Uint64JsonVO::Wrapper WorkFixtureTypeSettingController::execDeleteType(const UInt64& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WorkFixtureTypeSettingService service;
	// 执行数据删除
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> WorkFixtureTypeSettingController::execExportType()
{
	// 定义一个Service
	WorkFixtureTypeSettingService service;
	// 生成文件
	service.makeFile();
	// 构建文件全路径
	std::string fullPath = "public/excel/"+URIUtil::urlDecode("tooltype.xlsx");
	cout << fullPath << endl;
	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=tooltype.xlsx");

	// 影响成功结果
	return response;
}
Uint64JsonVO::Wrapper WorkFixtureTypeSettingController::execUpdateType(const WorkFixtureTypeUpdateDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	/*
	//类型编码
	API_DTO_FIELD_DEFAULT(String, typeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, typeName, ZH_WORDS_GETTER("workfixture.type.fields.name"));
	//是否编码管理N/Y 
	API_DTO_FIELD_DEFAULT(String, codeFlag, ZH_WORDS_GETTER("workfixture.type.fields.codeflag"));
	*/
	if (!dto->toolTypeID || dto->toolTypeID<0 ||
		!dto->typeCode || dto->typeCode->empty() ||
		!dto->typeName || dto->typeName->empty() ||
		!dto->codeFlag || dto->codeFlag->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	WorkFixtureTypeSettingService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->toolTypeID);
	}
	else
	{
		jvo->fail(dto->toolTypeID);
	}
	// 响应结果
	return jvo;
}
