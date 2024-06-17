/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 9:39:36

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
#include "RemoveDeviceDAO.h"

bool RemoveDeviceDAO::removeDeviceOne(const std::uint64_t code)
{
	// ֻ�漰��һ�����ݿ�ʵ���ֶΣ����Բ���Ҫmapper
	std::string sql = "DELETE FROM `dv_machinery` WHERE `machinery_id`=?";
	return sqlSession->executeUpdate(sql, "%i", code);
}