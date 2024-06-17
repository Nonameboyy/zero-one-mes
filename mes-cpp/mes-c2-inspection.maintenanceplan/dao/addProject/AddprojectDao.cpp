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
#include "AddprojectDao.h"
#include"AddprojectMapper.h"

int AddprojectDao::savedate(const DvCheckSubjectDO& uObj)
{
	list<dvSubjectDO> s1 = getDvSubject(uObj.getSubject_id());
	dvSubjectDO sub;
	if (!s1.empty())
	{
		// 获取指向第一个元素的迭代器
		auto it = s1.begin();
		sub.setSubjectCode(it->getSubjectCode());
		sub.setSubjectName(it->getSubjectName());
		sub.setSubjectType(it->getSubjectType());
		sub.setSubjectContent(it->getSubjectContent());
		sub.setSubjectStandard(it->getSubjectStandard());
		
	}
	

	string sql = "INSERT INTO `dv_check_subject` (`plan_id`, `subject_id`, `subject_code`,`subject_name`,`subject_type`,`subject_content`,`subject_standard`,`create_by`,`create_time`) VALUES (?, ?, ?,?,?,?,?,?,?)";

	return sqlSession->executeInsert(sql, "%i%i%s%s%s%s%s%s%s",uObj.getPlan_id(),uObj.getSubject_id(), sub.getSubjectCode(), sub.getSubjectName(), sub.getSubjectType(), sub.getSubjectContent(), sub.getSubjectStandard(),uObj.getCreate_by(),uObj.getCreate_time());
}

list<dvSubjectDO> AddprojectDao::getDvSubject(uint64_t id)
{
	
		string sql = "SELECT subject_code,subject_name,subject_type,subject_content,subject_standard FROM dv_subject WHERE `subject_id`=?";
		AddprojectMapper mapper;
		return sqlSession->executeQuery<dvSubjectDO, AddprojectMapper>(sql, mapper, "%i", id);
	

}
