#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/05/19 17:00:00

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
#ifndef _GETRETURNLISTQUERY_H_
#define _GETRETURNLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class GetReturnListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(GetReturnListQuery, PageQuery);
	// �˻������
	API_DTO_FIELD_DEFAULT(String, rtcode, ZH_WORDS_GETTER("material.rtcode"));
	// �˻�������
	API_DTO_FIELD_DEFAULT(String, rtname, ZH_WORDS_GETTER("material.rtname"));
	// �ɹ��������
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("material.pocode"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorname, ZH_WORDS_GETTER("material.vendorname"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETRETURNLISTQUERY_H_