#include "stdafx.h"

#include "DefectController.h"
#include "service/defect/QcDefectService.h"
#include <ExcelComponent.h>
#include <SimpleDateTimeFormat.h>
#include <ctime>
#include <iostream>
#include <regex>
#include <string>

// 1 获取缺陷列表（条件+分页）
DefectPageJsonVO::Wrapper DefectController::execQueryDefect(const QcDefectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	DefectService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = DefectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 2 添加缺陷
Uint64JsonVO::Wrapper DefectController::execAddDefect(const DefectDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->defect_code || !dto->defect_name || !dto->index_type || !dto->defect_level)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->defect_code->empty() || dto->defect_name->empty() || dto->index_type->empty() || dto->defect_level->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	DefectService service;
	// 执行数据新增
	uint64_t id = service.insert(dto, payload);
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
// 3 修改缺陷
Uint64JsonVO::Wrapper DefectController::execModifyDefect(const DefectModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
    auto jvo = Uint64JsonVO::createShared();
    // 参数校验
    if (!dto->defect_id)
    {
        jvo->init(UInt64(-1), ResultStatus("defect_id must exits"));
        return jvo;
    }
    if (!dto->defect_name)
    {
        jvo->init(UInt64(-1), ResultStatus("defect_name must exits"));
        return jvo;
    }
    if (!dto->index_type)
    {
        jvo->init(UInt64(-1), ResultStatus("index_type must exits"));
        return jvo;
    }
    if (!dto->defect_level)
    {
        jvo->init(UInt64(-1), ResultStatus("defect_level must exits"));
        return jvo;
    }
    if (dto->defect_id.getValue({}) <= 0)
    {
        jvo->init(UInt64(-1), ResultStatus("defect_id must greater than 0"));
        return jvo;
    }
    static const std::unordered_set<std::string> index_types{
        "SIZE",
            "APPEARANCE",
            "WEIGHT",
            "PERFORMANCE",
            "COMPONENT",
    };
    if (index_types.find(dto->index_type.getValue({})) == index_types.end())
    {
        jvo->init(UInt64(-1), ResultStatus("index_type must in SIZE, APPEARANCE, WEIGHT, PERFORMANCE, COMPONENT"));
        return jvo;
    }
    static const std::unordered_set<std::string> defect_levels{"CR", "MAJ", "MIN"};
    if (defect_levels.find(dto->defect_level.getValue({})) == defect_levels.end())
    {
        jvo->init(UInt64(-1), ResultStatus("defect_level must in CR, MAJ, MIN"));
        return jvo;
    }

    const string update_by = payload.getUsername();
    const string update_time = SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S");

    DefectService service;
    if (service.modify(dto, update_by, update_time))
    {
        jvo->success(UInt64(200));
    }
    else
    {
        jvo->fail(UInt64(500));
    }
    return jvo;
}
// 4 删除缺陷
Uint64JsonVO::Wrapper DefectController::execRemoveDefect(const String& ids)
{
    // 1%2C10%2C32%2C4 -> 1,10,32,4
    auto jvo = Uint64JsonVO::createShared();
    std::string s = std::regex_replace(ids.getValue("").c_str(), regex("%2C"), ",");
    // 方便触发判断
    s.push_back(',');
    int id = 0;
    for (int i = 0, n = s.size(); i < n; i++)
    {
        if (std::isdigit(s[i]))
        {
            id = id * 10 + s[i] - '0';
        }
        else if (s[i] == ',')
        {
            if (id <= 0)
            {
                jvo->init(UInt64(-1), RS_PARAMS_INVALID);
                return jvo;
            }
            id = 0;
        }
        // 非数字
        else
        {
            jvo->init(UInt64(-1), RS_PARAMS_INVALID);
            return jvo;
        }
    }
    s.pop_back();

    DefectService service;
    if (service.remove(s))
    {
        jvo->success(UInt64(200));
    }
    else
    {
        jvo->fail(UInt64(500));
    }
    return jvo;
}
// 5 导出缺陷
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
DefectController::execExportDefect(std::shared_ptr<oatpp::web::server::api::ApiController::IncomingRequest> request)
{
    // 解析请求
    API_MULTIPART_INIT(container, reader);
    API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
    request->transferBody(&reader);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "page_num", page_num);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "page_size", page_size);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "defect_name", defect_name);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "index_type", index_type);
    API_MULTIPART_PARSE_FORM_FIELD_STR(container, "defect_level", defect_level);
    if (!page_num)
    {
        return createResponse(Status::CODE_400, "page_num must be exist");
    }
    if (!page_size)
    {
        return createResponse(Status::CODE_400, "page_size must be exist");
    }

    auto query = QcDefectQuery::createShared();
    query->pageIndex = std::stoi(page_num);
    query->pageSize = std::stoi(page_size);
    if (defect_name)
    {
        query->defect_name = defect_name.getValue({});
    }
    if (index_type)
    {
        query->index_type = index_type.getValue({});
    }
    if (defect_level)
    {
        query->defect_level = defect_level.getValue({});
    }

    DefectService service;
    auto res = service.listAll(query);

    // 构造数据
    std::vector<std::vector<std::string>> data;
    data.push_back({ ZH_WORDS_GETTER("defect.field.defect_code"),
                    ZH_WORDS_GETTER("defect.field.defect_name"),
                    ZH_WORDS_GETTER("defect.field.index_type"),
                    ZH_WORDS_GETTER("defect.field.defect_level") });
    for (const auto& row : *res->rows)
    {
        data.push_back({
            row->defect_code.getValue("Null"), //
            row->defect_name.getValue("Null"), //
            row->index_type.getValue("Null"),  //
            row->defect_level.getValue("Null") //
            });
    }

    // 构造文件并返回
    const string timestamp{ std::to_string(time(NULL)) };
    const string filename{ "defect_" + timestamp + ".xlsx" };
    const string filepath{ "public/static/qc_defect.xlsx" };
    ExcelComponent excel;
    excel.writeVectorToFile(filepath, "Sheet1", data);
    const auto file_string = String::loadFromFile(filepath.c_str());
    auto response = createResponse(Status::CODE_200, file_string);
    response->putHeader(Header::CONTENT_TYPE, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    return response;
}