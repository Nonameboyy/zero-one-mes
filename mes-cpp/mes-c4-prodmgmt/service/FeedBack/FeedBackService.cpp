/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#include "FeedBackService.h"
#include "../../dao/FeedBack/FeedBackDAO.h"

FeedBackPageDTO::Wrapper FeedBackService::listAll(const FeedBackQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = FeedBackPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	FeedBackDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FeedBackDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (FeedBackDO sub : result)
	{
		auto dto = FeedBackDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, feedback_type, Feedback_type, workstation_name, Workstation_name, workorder_code, Workorder_code, item_code, Item_code, item_name, Item_name, specification, Specification, quantity_feedback, Quantity_feedback, user_name, User_name, feedback_time, Feedback_time, record_user, Record_user, _status, _Status);
			pages->addData(dto);
	}
	return pages;
}


