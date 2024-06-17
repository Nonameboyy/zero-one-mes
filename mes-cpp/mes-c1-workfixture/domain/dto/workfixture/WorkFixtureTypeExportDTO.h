#pragma once
/*

 @Author: Croissant
 @Date: 2024/5/17

*/
#ifndef _EXPORTDTO_H_
#define _EXPORTDTO_H_
#include "../../GlobalInclude.h"
#include "ExcelComponent.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具/类型设置 导出
 */
class WorkFixtureTypeExportDTO : public oatpp::DTO
{
	DTO_INIT(WorkFixtureTypeExportDTO, DTO);
	// 文件src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("WorkFixture.type.fields.url"), true, {});
	// 文件文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("WorkFixture.type.fields.alt"));
	// 文件链接地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("WorkFixture.type.fields.href"));
public:
	WorkFixtureTypeExportDTO() {}
	WorkFixtureTypeExportDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTDTO_H_