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
#include "ReturnService.h"
#include "../../domain/do/return/ReturnDO.h"
#include "../../dao/return/ReturnDAO.h"

ReturnPageDTO::Wrapper ReturnService::listAll(const ReturnQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReturnPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ReturnDAO dao;	
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ReturnDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ReturnDO sub : result)
	{
		auto dto = ReturnDTO::createShared();
		dto->returnCode = sub.getreturncode();
		dto->returnName = sub.getreturnname();
		dto->purchaseCode = sub.getpurchasecode();
		dto->vendorCode = sub.getvendorcode();
		dto->vendorName = sub.getvendorname();
		dto->returnDate = sub.getreturndate();
		dto->status = sub.getstatus();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, returnCode, returnName, purchaseCode, vendorCode, vendorName, returnDate, status)
		pages->addData(dto);
	}
	return pages;
}
ReturnDetailDTO::Wrapper ReturnService::getDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
{
	auto dto = ReturnDetailDTO::createShared();
	ReturnDAO dao;
	list<ReturnDO> result = dao.selectByRtCode(returnDetailQuery->returnCode);
	if (result.size() == 0)
	{

		return dto;
	}
	dto->returnCode = result.front().getreturncode();
	dto->returnName = result.front().getreturnname();
	dto->purchaseCode = result.front().getpurchasecode();
	dto->vendorCode = result.front().getvendorcode();
	dto->vendorName = result.front().getvendorname();
	dto->returnDate = result.front().getreturndate();
	dto->status = result.front().getstatus();
	dto->batchCode = result.front().getbatchcode();
	dto->remark = result.front().getremark();
	return dto;
}

uint64_t ReturnService::saveData(const ReturnAdd::Wrapper& dto)
{
	// 组装DO数据
	ReturnDO data;
	data.setreturncode(dto->returnCode.getValue(""));
	data.setreturnname(dto->returnName.getValue(""));
	data.setpurchasecode(dto->purchaseCode.getValue(""));
	data.setvendorname(dto->vendorName.getValue(""));
	data.setbatchcode(dto->batchCode.getValue(""));
	data.setreturndate(dto->returndate.getValue(""));
	data.setstatus(dto->status.getValue(""));
	data.setremark(dto->remark.getValue(""));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// 执行数据添加
	ReturnDAO dao;
	return dao.insert(data);
}
