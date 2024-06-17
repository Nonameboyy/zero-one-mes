#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _HUMANRESOURCELISTDTO_H_
#define _HUMANRESOURCELISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ�б�����ģ��
 */
class HumanResourceListDTO : public oatpp::DTO
{
	DTO_INIT(HumanResourceListDTO, DTO);
	// ��λ����
	API_DTO_FIELD(String, postName, ZH_WORDS_GETTER("post.fields.pname"), true, "ceo");
	// ��λ����
	API_DTO_FIELD(Int32, quantity, ZH_WORDS_GETTER("post.fields.quantity"), true, 1);
	// ��¼ID
	API_DTO_FIELD(UInt64, recordId, ZH_WORDS_GETTER("post.fields.recordid"), true, 1);
	// ����վID
	API_DTO_FIELD(UInt64, workstationId, ZH_WORDS_GETTER("post.fields.workstationdid"), true, 1);
	// ��λID
	API_DTO_FIELD(UInt64, postId, ZH_WORDS_GETTER("post.fields.postid"), true, 1);

};

/**
 * ����һ����λ��Ϣ��ҳ�������
 */
class HumanResourcePageDTO : public PageDTO<HumanResourceListDTO::Wrapper>
{
	DTO_INIT(HumanResourcePageDTO, PageDTO<HumanResourceListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _RESOURCELISTDTO_H_