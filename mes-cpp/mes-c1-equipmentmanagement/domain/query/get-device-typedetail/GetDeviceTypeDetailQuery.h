#pragma once

#ifndef _GETDEVICETYPEQUERY_H_
#define _GETDEVICETYPEQUERY_H

#include"domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 设备类型列表查询条件对象
*/
class GetDeviceTypeDetailQuery :public oatpp::DTO
{
	DTO_INIT(GetDeviceTypeDetailQuery, DTO);
	/**
 * DTO字段定义宏，大部分属性保持系统默认
 * @param _TYPE_: 字段类型。如：String、Int32、List<Int32>、List<SampleQuery::Wrapper>
 * @param _NAME_: 字段名称。如：name、sex
 * @param _DESCRIPTION_: 字段描述
 */
	/*#define API_DTO_FIELD_DEFAULT(_TYPE_, _NAME_, _DESCRIPTION_) \
	DTO_FIELD(_TYPE_, _NAME_); \
	DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \*/
	
	//类型名称				描述要使用到中文词典
	API_DTO_FIELD_DEFAULT(String, machineryTypeName, ZH_WORDS_GETTER("devicet.fields.tname "));

	//是否启用	Y 启用,		描述要使用到中文词典
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("devicet.fields.status "));
};

#endif // _GETDEVICETYPEQUERY_H_
