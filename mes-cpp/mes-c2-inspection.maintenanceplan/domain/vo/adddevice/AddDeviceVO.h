#pragma once
#ifndef _DEVICELISTVO_H_
#define _DEVICELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/adddevice/AddDeviceDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个项目列表显示VO
 */
class AddDeviceJsonVO : public JsonVO<oatpp::List<AddDeviceDTO::Wrapper>>
{
	DTO_INIT(AddDeviceJsonVO, JsonVO<oatpp::List<AddDeviceDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_