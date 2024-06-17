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
#ifndef _PRODUCT_RECPT_DTO_
#define _PRODUCT_RECPT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ʒ��⴫�����
 */
class ProductRecptDTO : public oatpp::DTO
{
	DTO_INIT(ProductRecptDTO, DTO);
	//��ⵥ���,����
	API_DTO_FIELD(String, recpt_code, ZH_WORDS_GETTER("product-recpt.field.recpt_code"), true, "recpt_code");
	// ��ⵥ����,Ĭ��:""
	API_DTO_FIELD_DEFAULT(String, recpt_name, ZH_WORDS_GETTER("product-recpt.field.recpt_name"));
	//������������,����
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("product-recpt.field.workorder_code"), true, "workorder_code");
	//������������
	API_DTO_FIELD_DEFAULT(String, workorder_name, ZH_WORDS_GETTER("product-recpt.field.workorder_name"));
	//�������,����
	API_DTO_FIELD(String, recpt_date, ZH_WORDS_GETTER("product-recpt.field.recpt_date"), true, "2024-06-01");
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("product-recpt.field.remark"));
	//��Ʒ����ID,����
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("product-recpt.field.item_id"), true, 1);

};

/**
 * ʾ����ҳ�������
 */
class ProductRecptPageDTO : public PageDTO<ProductRecptDTO::Wrapper>
{
	DTO_INIT(ProductRecptPageDTO, PageDTO<ProductRecptDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRODUCT_RECPT_DTO_