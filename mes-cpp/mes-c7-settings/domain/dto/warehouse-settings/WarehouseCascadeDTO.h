#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _WAREHOUSECASCADEDTO_
#define _WAREHOUSECASCADEDTO_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 仓库选择级联节点
 */
class WarehouseCascadeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(WarehouseCascadeDTO, DTO);
	//唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("alm.menu.id"));
	// 编码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("alm.menu.code"));
	// 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("alm.menu.name"));
	API_DTO_FIELD(List<WarehouseCascadeDTO::Wrapper>, children, ZH_WORDS_GETTER("alm.menu.sub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<WarehouseCascadeDTO>(child), Wrapper::Class::getType()));
	}
};

#include OATPP_CODEGEN_END(DTO) 
#endif // !_WAREHOUSECASCADEDTO_