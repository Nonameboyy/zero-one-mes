/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "DeviceMangeDAO.h"
#include "DeviceManageMapper.h"
#include <sstream>

uint64_t DeviceManageDAO::update(const DeviceManageDO& uObj)
{
	string sql = "UPDATE `dv_subject` SET `subject_code`=?, `subject_name`=?, `subject_type`=?, `subject_content`=?, `subject_standard`=?, `enable_flag`=?, `update_time`=NOW() WHERE `subject_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", uObj.getSubjectCode(), uObj.getSubjectName(), uObj.getSubjectType(), uObj.getSubjectContent(), uObj.getSubjectStandard(), 
		uObj.getEnableFlag(), uObj.getSubjectId());

}

list<DeviceManageDO> DeviceManageDAO::queryById(const DeviceManageIdDO& uObj)
{
	string sql = "SELECT subject_id,subject_code,subject_name,subject_type,subject_content,subject_standard,enable_flag FROM dv_subject WHERE subject_id in(" + uObj.getSubjectId() + ")";
	DeviceManageMapper mapper;
	return sqlSession->executeQuery<DeviceManageDO, DeviceManageMapper>(sql, mapper);

}

uint64_t DeviceManageIdDAO::deleteById(const DeviceManageIdDO& uObj)
{
	string sql = "DELETE from `dv_subject` WHERE `subject_id` in(" + uObj.getSubjectId() + ")";

	 
	return sqlSession->executeUpdate(sql);

}

uint64_t DeviceManageDAO::insert(const DeviceManageAddDO& iObj)
{
	string sql = "INSERT INTO `dv_subject` (`subject_code`, `subject_name`, `subject_type`, `subject_content`, `subject_standard`, `enable_flag`, `create_time`) VALUES (?, ?, ?, ?, ?, ?, NOW())";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s", iObj.getSubjectCode(), iObj.getSubjectName(), iObj.getSubjectType(), iObj.getSubjectContent(), iObj.getSubjectStandard(), iObj.getEnableFlag());
}


