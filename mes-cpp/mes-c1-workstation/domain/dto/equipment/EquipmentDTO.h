#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _EQUIPMENT_DTO_
#define _EQUIPMENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �豸�������
 */
class EquipmentDTO : public oatpp::DTO
{
	DTO_INIT(EquipmentDTO, DTO);
	// �豸id
	DTO_FIELD(UInt64, equipmentId);
	DTO_FIELD_INFO(equipmentId) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.equipmentId");
	}
	// �豸���
	DTO_FIELD(String, equipmentCode);
	DTO_FIELD_INFO(equipmentCode) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.equipmentCode");
	}
	// �豸����
	DTO_FIELD(String, equipmentName);
	DTO_FIELD_INFO(equipmentName) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.equipmentName");
	}
	// Ʒ��
	DTO_FIELD(String, brand);
	DTO_FIELD_INFO(brand) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.brand");
	}
	//����ͺ�
	DTO_FIELD(String, specificationsAndModels);
	DTO_FIELD_INFO(specificationsAndModels) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.specificationsAndModels");
	}
	//������������
	DTO_FIELD(String, workshopName);
	DTO_FIELD_INFO(workshopName) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.workshopName");
	}
	//�豸״̬
	DTO_FIELD(String, equipmentStatus);
	DTO_FIELD_INFO(equipmentStatus) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.equipmentStatus");
	}
	//����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("equipment.equipmentDto.createTime");
	}
};

/**
 * �豸��ҳ�������
 */
class EquipmentPageDTO : public PageDTO<EquipmentDTO::Wrapper>
{
	DTO_INIT(EquipmentPageDTO, PageDTO<EquipmentDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_