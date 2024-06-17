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
#ifndef _QC_DEFECT_DAO_
#define _QC_DEFECT_DAO_
#include "BaseDAO.h"
#include "domain/do/qc/QcDefectDO.h"
#include "domain/dto/defect/DefectModifyDTO.h"
#include "domain/query/defect/QcDefectExportQuery.h"
#include "domain/query/defect/QcDefectQuery.h"
/**
 * 示例表数据库操作实现
 */
class QcDefectDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const QcDefectQuery::Wrapper& query);
	// 分页查询数据
	list<QcDefectDO> selectWithPage(const QcDefectQuery::Wrapper& query);
	// 通过缺陷描述查询数据
	list<QcDefectDO> selectByName(const string& name);
	// 通过检测项类型查询数据
	list<QcDefectDO> selectByType(const string& Type);
	// 通过缺陷等级查询数据
	list<QcDefectDO> selectByLevel(const string& Level);
	// 插入数据
	uint64_t insert(const QcDefectDO& iObj);
	// 删除数据
	uint64_t remove(const string& ids);
	// 更新数据
	uint64_t modify(const DefectModifyDTO::Wrapper& dto, const string& update_by, const string& update_time);
};
#endif // !_QC_DEFECT_DAO_
