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
#ifndef _GETLIST_DTO_
#define _GETLIST_DTO_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class GetListDTO : public oatpp::DTO
{
	DTO_INIT(GetListDTO, DTO);


	//��ⵥ���
	DTO_FIELD(String, recptcode);
	DTO_FIELD_INFO(recptcode) {
		info->description = ZH_WORDS_GETTER("getlist.field.recptcode");
	}
	//��ⵥ����
	API_DTO_FIELD_DEFAULT(String, recptname, ZH_WORDS_GETTER("getlist.field.recptname"));

	//��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorname, ZH_WORDS_GETTER("getlist.field.vendorname"));

	//�������
	API_DTO_FIELD_DEFAULT(String, recptdate, ZH_WORDS_GETTER("getlist.field.recptdate"));

	//�������
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("getlist.field.pocode"));


};

/**
 * ʾ����ҳ�������
 */
class GetListPageDTO : public PageDTO<GetListDTO::Wrapper>
{
	DTO_INIT(GetListPageDTO, PageDTO<GetListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
