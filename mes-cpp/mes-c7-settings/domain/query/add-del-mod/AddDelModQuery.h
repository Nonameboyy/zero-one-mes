#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _ADDDELMOD_QUERY_
#define _ADDDELMOD_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class AddDelModQuery : public PageQuery
{
	DTO_INIT(AddDelModQuery, PageQuery);
	// �ֿ����
	DTO_FIELD(String, warehouse_code);
	DTO_FIELD_INFO(warehouse_code) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.warehouse_code");
	}
	// �ֿ�����
	DTO_FIELD(String, warehouse_name);
	DTO_FIELD_INFO(warehouse_name) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.warehouse_name");
	}
	// λ��
	DTO_FIELD(String, location);
	DTO_FIELD_INFO(location) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.location");
	}
	// ���
	DTO_FIELD(Float64, area);
	DTO_FIELD_INFO(area) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.area");
	}
	// ������
	DTO_FIELD(String, charge);
	DTO_FIELD_INFO(charge) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.charge");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("add-del-mod.query-dto.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDDELMOD_QUERY_