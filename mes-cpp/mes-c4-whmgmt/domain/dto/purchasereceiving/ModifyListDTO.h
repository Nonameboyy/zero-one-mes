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
#ifndef _MODIFYLIST_DTO_
#define _MODIFYLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class ModifyListDTO : public oatpp::DTO
{
	DTO_INIT(ModifyListDTO, DTO);

	//��ⵥid
	API_DTO_FIELD_DEFAULT(UInt64, recptid, ZH_WORDS_GETTER("modifylist.field.recptid"));

	//��ⵥ���
	DTO_FIELD(String, recptcode);
	DTO_FIELD_INFO(recptcode) {
		info->description = ZH_WORDS_GETTER("modifylist.field.recptcode");
	}
	//��ⵥ����
	API_DTO_FIELD_DEFAULT(String, recptname, ZH_WORDS_GETTER("modifylist.field.recptname"));

	//�������
	API_DTO_FIELD_DEFAULT(String, recptdate, ZH_WORDS_GETTER("modifylist.field.recptdate"));

	//�ɹ�������
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("modifylist.field.pocode"));

	//����״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("modifylist.field.status"));

	//��Ӧ��id
	API_DTO_FIELD_DEFAULT(UInt64, vendorid, ZH_WORDS_GETTER("modifylist.field.vendorid"));


	//���ֿ�
	API_DTO_FIELD_DEFAULT(String, warehousename, ZH_WORDS_GETTER("modifylist.field.warehousename"));

	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("modifylist.field.remark"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_