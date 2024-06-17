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
#ifndef _ADDLIST_DTO_
#define _ADDLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class AddListDTO : public oatpp::DTO
{
	DTO_INIT(AddListDTO, DTO);

	
	//入库单编号
	DTO_FIELD(String, recptcode);
	DTO_FIELD_INFO(recptcode) {
		info->description = ZH_WORDS_GETTER("addlist.field.recptcode");
	}
	//入库单名称
	API_DTO_FIELD_DEFAULT(String, recptname, ZH_WORDS_GETTER("addlist.field.recptname"));

	//入库日期
	API_DTO_FIELD_DEFAULT(String, recptdate, ZH_WORDS_GETTER("addlist.field.recptdate"));

	//采购订单号
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("addlist.field.pocode"));

	//单据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("addlist.field.status"));
	
	//供应商id
	API_DTO_FIELD_DEFAULT(UInt64, vendorid, ZH_WORDS_GETTER("addlist.field.vendorid"));

	
	//入库仓库
	API_DTO_FIELD_DEFAULT(String, warehousename, ZH_WORDS_GETTER("addlist.field.warehousename"));
	
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("addlist.field.remark"));
};
class AddListPageDTO : public PageDTO<AddListDTO::Wrapper>
{
	DTO_INIT(AddListPageDTO, PageDTO<AddListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_