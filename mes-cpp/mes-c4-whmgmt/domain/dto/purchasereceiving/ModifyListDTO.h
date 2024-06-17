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
 * 示例传输对象
 */
class ModifyListDTO : public oatpp::DTO
{
	DTO_INIT(ModifyListDTO, DTO);

	//入库单id
	API_DTO_FIELD_DEFAULT(UInt64, recptid, ZH_WORDS_GETTER("modifylist.field.recptid"));

	//入库单编号
	DTO_FIELD(String, recptcode);
	DTO_FIELD_INFO(recptcode) {
		info->description = ZH_WORDS_GETTER("modifylist.field.recptcode");
	}
	//入库单名称
	API_DTO_FIELD_DEFAULT(String, recptname, ZH_WORDS_GETTER("modifylist.field.recptname"));

	//入库日期
	API_DTO_FIELD_DEFAULT(String, recptdate, ZH_WORDS_GETTER("modifylist.field.recptdate"));

	//采购订单号
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("modifylist.field.pocode"));

	//单据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("modifylist.field.status"));

	//供应商id
	API_DTO_FIELD_DEFAULT(UInt64, vendorid, ZH_WORDS_GETTER("modifylist.field.vendorid"));


	//入库仓库
	API_DTO_FIELD_DEFAULT(String, warehousename, ZH_WORDS_GETTER("modifylist.field.warehousename"));

	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("modifylist.field.remark"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_