#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/18 20:34:02

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
#ifndef _REMOVEDEVICEDTO_H_
#define _REMOVEDEVICEDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �б�DTO�����Խ�DTO��װ��List
 * �����ˣ�����
 */

// �����б�DTO����֧������ɾ�������������Ҳ��Ҫ�Ļ������԰������ųɹ�����
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, oatpp::DTO)
	// �����б�
	API_DTO_FIELD(List<T>, item, ZH_WORDS_GETTER("list_dto"), false, {});
public:
	// ���һ������
	void addItem(const T& item) {
		this->item->push_back(item);
	}
};

/**
 * ɾ���豸DTO
 * �����ˣ�����
 */
class RemoveDeviceDTO : public oatpp::DTO
{
	DTO_INIT(RemoveDeviceDTO, DTO)
	API_DTO_FIELD_DEFAULT(UInt64, device_id, 
		ZH_WORDS_GETTER("equipmentledger.remove-device.device-id"))
};

/**
 * ɾ���豸ListDTO
 * �����ˣ�����
 */

// �̳���ListDTO
class RemoveDeviceListDTO : public ListDTO<RemoveDeviceDTO::Wrapper>
{
	DTO_INIT(RemoveDeviceListDTO, ListDTO<RemoveDeviceDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REMOVEDEVICEDTO_H_