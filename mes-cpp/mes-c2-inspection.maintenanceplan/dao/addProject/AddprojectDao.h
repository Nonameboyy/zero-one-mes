#pragma once
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
#ifndef _ADDPROJECTDAO_H_
#define _ADDPROJECTDAO_H_
#include "BaseDAO.h"
#include"../../../mes-c2-repairorder/domain/do/dv_check_subject/DvCheckSubjectDO.h"
#include"../../../mes-c2-equipmentledger/domain/do/dv_subject/dvSubjectDO.h"
/**
 * 示例表数据库操作实现
 */
class AddprojectDao : public BaseDAO
{
public:
	//插入
	int savedate(const DvCheckSubjectDO& uObj);
	//根据项目ID获取详情
	list< dvSubjectDO> getDvSubject(uint64_t id);

};
#endif 

