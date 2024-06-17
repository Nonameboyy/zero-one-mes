/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/20 16:29:31

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
#include "stdafx.h"
#include "UserController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "domain/do/user/MenuDO.h"
#include "service/user/TreeMenuMapper.h"
#include "tree/TreeUtil.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

/**
 * 注意：这里的部分代码本应该放到service层中，为了方便演示就写在一起了
 */

UserPageJsonVO::Wrapper UserController::executeQueryAll(const UserQuery::Wrapper& query)
{
	// 定义一个JsonVO对象
	auto vo = UserPageJsonVO::createShared();
	// 定义一个分页对象
	auto page = UserPageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	page->total = 20;
	page->calcPages();

	// 模拟计算分页数据
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// 边界值值处理
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// 循环生成测试数据
	for (int64_t i = start; i < end; i++)
	{
		auto user = UserDTO::createShared();
		user->nickname = query->nickname;
		user->age = (uint32_t)(i + 1) * 10;
		user->idCard = "12345678901234567" + oatpp::utils::conversion::uint64ToStdStr(i);
		page->addData(user);
	}
	vo->success(page);
	return vo;
}

StringJsonVO::Wrapper UserController::executeModifyUser(const String& fileBody, const UserDTO::Wrapper& dto)
{
	// 将头像上传到FastDFS文件服务器
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	std::string fieldName = dfs.uploadFile(fileBody->data(), fileBody->size(), "png");
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	// 拼接文件下载路径
	std::stringstream ss;
	ss << urlPrefix << fieldName;

	// TODO:保存用户数据到数据库过程略过

	// 创建响应数据
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}

MenuJsonVO::Wrapper UserController::executeQueryMenu(const PayloadDTO& payload)
{
	// 定义一个JsonVO对象
	auto vo = MenuJsonVO::createShared();
	// 创建模拟菜单数据（此数据应来源于数据库）
	list<MenuDO> listData;
	listData.push_back(MenuDO("1", u8"系统管理", "sm", "/sm", ""));
	listData.push_back(MenuDO("2", u8"用户管理", "sm", "/sm/um", "1"));
	listData.push_back(MenuDO("3", u8"角色管理", "sm", "/sm/rm", "1"));
	listData.push_back(MenuDO("4", u8"菜单管理", "sm", "/sm/mm", "1"));
	listData.push_back(MenuDO("5", u8"订单管理", "om", "/om", ""));
	listData.push_back(MenuDO("6", u8"入库订单", "om", "/om/em", "5"));
	listData.push_back(MenuDO("7", u8"出库订单", "om", "/om/om", "5"));
	listData.push_back(MenuDO("8", u8"销售订单", "om", "/om/sm", "5"));
	listData.push_back(MenuDO("9", u8"订单统计", "om", "/om/sm/t1", "8"));
	listData.push_back(MenuDO("10",u8"订单报表", "om", "/om/sm/t2", "8"));
	// 转换为树形结构
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<MenuDO>(listData, TreeMenuMapper());
	// 将根节点存储到列表中
	for (auto one : res)
	{
		vo->data->push_back(MenuDTO::Wrapper(dynamic_pointer_cast<MenuDTO>(one), MenuDTO::Wrapper::Class::getType()));
	}
	return vo;
}
