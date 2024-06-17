#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _EQUIPMENT_TYPE_DO_H_
#define _EQUIPMENT_TYPE_DO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class EquipmentTypeDO
{
	// 设备类型ID						uint64
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 设备类型编码						string
	CC_SYNTHESIZE(string, code, Code);
	// 设备类型名称						string
	CC_SYNTHESIZE(string, name, Name);
	// 父类型ID             默认0		uint64
	CC_SYNTHESIZE(uint64_t, parentId, ParentId);
	// 所有父节点ID						string
	CC_SYNTHESIZE(string, ancestorId, AncestorId);
	// 是否启用							string      Y/N
	CC_SYNTHESIZE(string, enable, Enable);
	// 备注                 默认""		string
	CC_SYNTHESIZE(string, remark, Remark);
	// 下面的部分是数据库内部内容，非业务部分，无须动
	// 创建者				默认""		string
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// 创建时间				默认NULL	string
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 更新者				默认""		string
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// 更新时间				默认NULL	string
	CC_SYNTHESIZE(string, updateTime, UpdateTime);

public:
	EquipmentTypeDO() {
		id = 0;    // id自增
		code = "";
		name = "";
		parentId = 0;
		ancestorId = "";
		enable = "";
		remark = "";
		createBy = "";
		createTime = "";   // 可为NULL
		updateBy = "";
		updateTime = "";   // 可为NULL
	}
};

#endif 
