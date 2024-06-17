#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49

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
#ifndef _PROINSPECT_DAO_
#define _PROINSPECT_DAO_
#include "BaseDAO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/ProinSpect/ProinSpectDO.h"
#include "../../domain/dto/ProcessInspection/ProinSpect/ProinSpectDTO.h"
#include "domain/vo/ProcessInspection/ProinSpect/ProinSpectVO.h"
#include "domain/query/ProcessInspection/ProinSpect/ProinSpectQuery.h"

/**
 * 示例表数据库操作实现
 */
class  ProinspectDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count1(const ProinspectQuery::Wrapper & query);
	uint64_t count2(const ProinspectQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const ProinspectDO& iObj);
	// 修改数据
	int update(const ProinspectDO& uObj);
	// 通过ID删除数据
	int deleteById(const ProinspectDO& dObj);
	int update_qc(const ProinspectDO& uObj, string mem1);//用来修改qc_ipqc_
	list<ProinspectDO> selectByIpqc_id(const ProinspectQuery::Wrapper& query);
	list<ProinspectDO> selectByLine_id(const ProinspectQuery::Wrapper& query);
};
#endif // !_PROINSPECT_DAO_
