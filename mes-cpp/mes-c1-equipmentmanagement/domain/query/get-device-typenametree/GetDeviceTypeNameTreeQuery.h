#pragma once

#ifndef _GETDEVICETYPETREEQUERY_H_
#define _GETDEVICETYPETREEQUERY_H

#include"domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 设备类型名称树查询条件对象
*/
class GetDeviceTypeNameTreeQuery :public oatpp::DTO
{
	DTO_INIT(GetDeviceTypeNameTreeQuery, DTO);
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
	//类型名称
	API_DTO_FIELD_DEFAULT(String, machineryTypeName, ZH_WORDS_GETTER("devicet.fields.tname "));
};

#endif // _GETDEVICETYPEQUERY_H_
