#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/17 16:29:07

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _TREEEQUIPMENTMAPPER_H_
#define _TREEEQUIPMENTMAPPER_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/equipment/EquipmentTypeDO.h"
#include "domain/dto/equipment/EquipmentTypeDTO.h"

/**
 * 演示菜单数据字段匹配实现
 */
class TreeEquipmentMapper : public TreeNodeMapper<EquipmentTypeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(EquipmentTypeDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<EquipmentTypeDTO>();
		// 计算层级结构属性映射
		res->_id(source->getMachineryTypeId());
		res->_pid(source->getParentTypeId());
		// 扩展属性映射
		res->machineryTypeId = source->getMachineryTypeId();
		res->parentTypeId = source->getParentTypeId();
		res->machineryTypeCode = source->getMachineryTypeCode();
		res->machineryTypeName = source->getMachineryTypeName();
		res->enableFlag = source->getEnableFlag();
		res->remark = source->getRemark();
		return res;
	}
};

#endif // !_TREEMENUMAPPER_H_