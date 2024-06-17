/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 9:25:43

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
#include "RemoveDeviceService.h"
#include "dao/RemoveDevice/RemoveDeviceDAO.h"

bool RemoveDeviceService::removeDevice(const RemoveDeviceListDTO::Wrapper& listDto)
{
	RemoveDeviceDAO dao;
	// ����һ���Ự
	auto sqlSession = dao.getSqlSession();
	// ��������
	sqlSession->beginTransaction();
	bool flag = true;
	for (auto code : *(listDto->item)) {
		std::uint64_t device_id(code->device_id);
		std::cout << device_id << std::endl;
		if (!dao.removeDeviceOne(device_id)) {
			// ɾ��ʧ�ܣ��ع�
			sqlSession->rollbackTransaction();
			flag = false;
			break;
		}
	}
	// �ύ����
	sqlSession->commitTransaction();
	return flag;
}