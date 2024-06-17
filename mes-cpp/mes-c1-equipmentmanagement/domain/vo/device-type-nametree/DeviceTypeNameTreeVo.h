#pragma once

#ifndef _GETDEVICETYPEVO_H_
#define _GETDEVICETYPEVO_H


#include"../../../domain/GlobalInclude.h"
#include"../../../domain/dto/device-typenametree/DeviceTypeNameTreeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 定义一个设备类型显示列表
*/									//可能含有多个根结点，因此用List包裹数据
class DeviceTypeNameTreeJsonVo :public JsonVO<List<DeviceTypeNameTreeDTO::Wrapper>>
{
	DTO_INIT(DeviceTypeNameTreeJsonVo, JsonVO<List<DeviceTypeNameTreeDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	DeviceTypeNameTreeJsonVo() {
		this->data = {};
	}
};

#endif //_GETDEVICETYPEVO_H_