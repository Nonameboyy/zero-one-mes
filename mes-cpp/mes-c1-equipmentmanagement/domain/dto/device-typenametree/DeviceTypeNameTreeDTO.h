#pragma once

#ifndef _GETDEVICETYPETREEDTO_H_
#define _GETDEVICETYPETREEDTO_H

#include"domain/GlobalInclude.h"
#include"tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 设备名称树结点
*/
class DeviceTypeNameTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(DeviceTypeNameTreeDTO, DTO);
	// 唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, machineryTypeId, ZH_WORDS_GETTER("devicet.fields.unique "));
	// 类型编码
	API_DTO_FIELD_DEFAULT(String, machineryTypCode, ZH_WORDS_GETTER("devicet.fields.encoding "));
	// 类型名称
	API_DTO_FIELD_DEFAULT(String, machineryTypeName, ZH_WORDS_GETTER("devicet.fields.tname "));
	// 子设备类型
	API_DTO_FIELD(List<DeviceTypeNameTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("devicet.fields.subdevtype"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<DeviceTypeNameTreeDTO>(child), Wrapper::Class::getType()));
	}
};

#endif // _GETDEVICETTYPETREEDTO_H_
