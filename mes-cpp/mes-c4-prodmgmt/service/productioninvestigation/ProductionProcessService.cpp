/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/25 11:13:11

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
#include "ProductionProcessService.h"
#include "../../dao/productioninvestigation/ProductionProcessDAO.h"
ProductionProcessPageDTO::Wrapper ProductionProcessService::listAll(const ProductionProcessQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ProductionProcessPageDTO::createShared();
	// 查询数据总条数
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	ProductionProcessDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProRouteProcessDO> result = dao.query_by_workordercode(query);
	// 将DO转换成DTO
	map<string,string> m;
	map<string, string>m1;
	bool flag = false;
	for (ProRouteProcessDO sub : result)
	{
		if (query->itemCode)
		{
			m[sub.getnextProcessName()] = sub.getprocessName();
			m1[sub.getprocessName()] = sub.getnextProcessName();
			flag = true;
		}
		else
		{
			auto dto = ProductionProcessDTO::createShared();
			dto->processName =sub.getprocessName();
			pages->addData(dto);
		}
	}
	if (flag)
	{
		string start;
		list<string>processList;
		for (auto it : m)
		{
			string s = it.second;
			if (m.find(s) == m.end())
			{
				start = s;
				break;
			}
		}
		string s = m1[start];
		processList.push_back(start);
		while (s != "")
		{
			processList.push_back(s);
			string t = s;
			s.clear();
			s = m1[t];
			t.clear();
		}
		processList.pop_back();
		for (auto it : processList)
		{
			auto dto = ProductionProcessDTO::createShared();
			dto->processName = it;
			pages->addData(dto);
		}
	}
	return pages;
}