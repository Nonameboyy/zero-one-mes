#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:08:56

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
#ifndef _PROINSPECT_SERVICE_
#define _PROINSPECT_SERVICE_
#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/ProinSpect/ProinSpectDO.h"
#include "domain/dto/ProcessInspection/ProinSpect/ProinSpectDTO.h"
#include "domain/vo/ProcessInspection/ProinSpect/ProinSpectVO.h"
#include "domain/query/ProcessInspection/ProinSpect/ProinSpectQuery.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class  ProinspectService
{
public:
	// 保存数据
	uint64_t saveData(const ProinspectDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ProinspectDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const ProinspectDTO::Wrapper& dto);
	// 获取过程检验单行列表（条件+分页）
	ProinspectPageDTO::Wrapper queryProcessInspectionList(const ProinspectQuery::Wrapper& query);
	// 获取过程检验单行缺陷列表（条件+分页）
	ProinspectPageDTO::Wrapper queryProcessInspectionDefectList(const ProinspectQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

