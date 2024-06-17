#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/05/19 20:37

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
#ifndef _GETRETURNLISTDTO_H_
#define _GETRETURNLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ѯ��Ϣ�����ݴ���DTO
 */
class GetReturnListDTO : public oatpp::DTO
{
	DTO_INIT(GetReturnListDTO, DTO);
	// �˻������
	API_DTO_FIELD_DEFAULT(String, rtcode, ZH_WORDS_GETTER("material.rtcode"));
	// �˻�������
	API_DTO_FIELD_DEFAULT(String, rtname, ZH_WORDS_GETTER("material.rtname"));
	// �ɹ��������
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("material.pocode"));
	// ��Ӧ�̱���
	API_DTO_FIELD_DEFAULT(String, vendorcode, ZH_WORDS_GETTER("material.vendorcode"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorname, ZH_WORDS_GETTER("material.vendorname"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, rtdate, ZH_WORDS_GETTER("material.rtdate"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, statuss, ZH_WORDS_GETTER("material.status"));

};

/**
 * ����һ���û���Ϣ��ҳ�������
 */
class GetReturnListPageDTO : public PageDTO<GetReturnListDTO::Wrapper>
{
	DTO_INIT(GetReturnListPageDTO, PageDTO<GetReturnListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _GETRETURNLISTDTO_H_