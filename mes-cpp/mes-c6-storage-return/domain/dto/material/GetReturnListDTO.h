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
 * 定义一个查询信息的数据传输DTO
 */
class GetReturnListDTO : public oatpp::DTO
{
	DTO_INIT(GetReturnListDTO, DTO);
	// 退货单编号
	API_DTO_FIELD_DEFAULT(String, rtcode, ZH_WORDS_GETTER("material.rtcode"));
	// 退货单名称
	API_DTO_FIELD_DEFAULT(String, rtname, ZH_WORDS_GETTER("material.rtname"));
	// 采购订单编号
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("material.pocode"));
	// 供应商编码
	API_DTO_FIELD_DEFAULT(String, vendorcode, ZH_WORDS_GETTER("material.vendorcode"));
	// 供应商名称
	API_DTO_FIELD_DEFAULT(String, vendorname, ZH_WORDS_GETTER("material.vendorname"));
	// 退货日期
	API_DTO_FIELD_DEFAULT(String, rtdate, ZH_WORDS_GETTER("material.rtdate"));
	// 单据状态
	API_DTO_FIELD_DEFAULT(String, statuss, ZH_WORDS_GETTER("material.status"));

};

/**
 * 定义一个用户信息分页传输对象
 */
class GetReturnListPageDTO : public PageDTO<GetReturnListDTO::Wrapper>
{
	DTO_INIT(GetReturnListPageDTO, PageDTO<GetReturnListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _GETRETURNLISTDTO_H_