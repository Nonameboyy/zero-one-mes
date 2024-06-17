#pragma once

#ifndef _GETDEVICETYPEVO_H_
#define _GETDEVICETYPEVO_H

#include"domain/GlobalInclude.h"
#include"domain/dto/device-typedetail/DeviceTypeDetailDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 定义一个设备类型显示列表
*/									//需要用List包裹数据 因为有多个数据
class DeviceTypeDetailJsonVo :public JsonVO<List<DeviceTypeDetailDTO::Wrapper>>
{
	DTO_INIT(DeviceTypeDetailJsonVo, JsonVO<List<DeviceTypeDetailDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	DeviceTypeDetailJsonVo() {
		this->data = {};
	}
};

#endif //_GETDEVICETYPEVO_H_