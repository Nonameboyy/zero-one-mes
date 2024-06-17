#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 9:27:42

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
#ifndef _REMOVEDEVICEDAO_H_
#define _REMOVEDEVICEDAO_H_

#include "BaseDAO.h"

/**
 * ɾ���豸DAO��
 * �����ˣ�����
 */
class RemoveDeviceDAO : public BaseDAO
{
public:
	/**
	 * ɾ�������豸
	 */
	bool removeDeviceOne(const std::uint64_t code);
};

#endif // !_REMOVEDEVICEDAO_H_