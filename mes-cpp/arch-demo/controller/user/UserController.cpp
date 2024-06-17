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

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

/**
 * ע�⣺����Ĳ��ִ��뱾Ӧ�÷ŵ�service���У�Ϊ�˷�����ʾ��д��һ����
 */

UserPageJsonVO::Wrapper UserController::executeQueryAll(const UserQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = UserPageJsonVO::createShared();
	// ����һ����ҳ����
	auto page = UserPageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	page->total = 20;
	page->calcPages();

	// ģ������ҳ����
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// �߽�ֵֵ����
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// ѭ�����ɲ�������
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
	// ��ͷ���ϴ���FastDFS�ļ�������
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	std::string fieldName = dfs.uploadFile(fileBody->data(), fileBody->size(), "png");
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	// ƴ���ļ�����·��
	std::stringstream ss;
	ss << urlPrefix << fieldName;

	// TODO:�����û����ݵ����ݿ�����Թ�

	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}

MenuJsonVO::Wrapper UserController::executeQueryMenu(const PayloadDTO& payload)
{
	// ����һ��JsonVO����
	auto vo = MenuJsonVO::createShared();
	// ����ģ��˵����ݣ�������Ӧ��Դ�����ݿ⣩
	list<MenuDO> listData;
	listData.push_back(MenuDO("1", u8"ϵͳ����", "sm", "/sm", ""));
	listData.push_back(MenuDO("2", u8"�û�����", "sm", "/sm/um", "1"));
	listData.push_back(MenuDO("3", u8"��ɫ����", "sm", "/sm/rm", "1"));
	listData.push_back(MenuDO("4", u8"�˵�����", "sm", "/sm/mm", "1"));
	listData.push_back(MenuDO("5", u8"��������", "om", "/om", ""));
	listData.push_back(MenuDO("6", u8"��ⶩ��", "om", "/om/em", "5"));
	listData.push_back(MenuDO("7", u8"���ⶩ��", "om", "/om/om", "5"));
	listData.push_back(MenuDO("8", u8"���۶���", "om", "/om/sm", "5"));
	listData.push_back(MenuDO("9", u8"����ͳ��", "om", "/om/sm/t1", "8"));
	listData.push_back(MenuDO("10",u8"��������", "om", "/om/sm/t2", "8"));
	// ת��Ϊ���νṹ
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<MenuDO>(listData, TreeMenuMapper());
	// �����ڵ�洢���б���
	for (auto one : res)
	{
		vo->data->push_back(MenuDTO::Wrapper(dynamic_pointer_cast<MenuDTO>(one), MenuDTO::Wrapper::Class::getType()));
	}
	return vo;
}
