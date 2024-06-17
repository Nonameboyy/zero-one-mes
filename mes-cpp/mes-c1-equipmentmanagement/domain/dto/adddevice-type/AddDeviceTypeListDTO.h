#pragma once

#ifndef _ADDDEVICETYPEDTO_H_
#define _ADDDEVICETYPEDTO_H

#include"domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 设备类型列表
*/
class AddDeviceTypeListDTO :public oatpp::DTO
{
	DTO_INIT(AddDeviceTypeListDTO, DTO);
	//类型名称（类型编码通过调用声明式服务接口获得）
	API_DTO_FIELD_DEFAULT(String, machineryTypeName, ZH_WORDS_GETTER("devicet.fields.tname "));
	//父类型id	
	API_DTO_FIELD_DEFAULT(UInt64, parentTypeId, ZH_WORDS_GETTER("devicet.fields.fname"));
	//是否启用	Y 启用,		描述要使用到中文词典
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("devicet.fields.status "));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("devicet.fields.remake "));
};

#endif // _ADDDEVICETTYPEDTO_H_
