#pragma once

#ifndef _GETDEVICETYPEDTO_H_
#define _GETDEVICETYPEDTO_H

#include"domain/GlobalInclude.h"
#include"tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 设备类型完整数据
*/
class DeviceTypeDetailDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(DeviceTypeDetailDTO, DTO);
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, machineryTypeId, ZH_WORDS_GETTER("devicet.fields.id "));
	//类型编码
	API_DTO_FIELD_DEFAULT(String, machineryTypCode, ZH_WORDS_GETTER("devicet.fields.encoding "));
	//类型名称
	API_DTO_FIELD_DEFAULT(String, machineryTypeName, ZH_WORDS_GETTER("devicet.fields.tname "));
	//是否启用	Y 启用
	API_DTO_FIELD_DEFAULT(String, enableFlag, ZH_WORDS_GETTER("devicet.fields.status "));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("devicet.fields.remake "));
	// 子设备类型
	API_DTO_FIELD(List<DeviceTypeDetailDTO::Wrapper>, children, ZH_WORDS_GETTER("devicet.fields.subdevtype"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<DeviceTypeDetailDTO>(child), Wrapper::Class::getType()));
	}
};
#endif // _GETDEVICETTYPEDTO_H_
