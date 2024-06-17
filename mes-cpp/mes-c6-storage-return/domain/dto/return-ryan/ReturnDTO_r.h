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
#ifndef _RETURNDTO_R_H_
#define _RETURNDTO_R_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个修改供应商退货信息的数据传输模型
 */
class ReturnDTO_r : public oatpp::DTO
{
	DTO_INIT(ReturnDTO_r, DTO);
	//退货单ID
	DTO_FIELD(UInt64, rt_id);
	DTO_FIELD_INFO(rt_id) {
		info->description = ZH_WORDS_GETTER("return.fields.rt_id");
	}
	// 退货单编号
	API_DTO_FIELD(String, rt_code, ZH_WORDS_GETTER("return.fields.rt_code"), true, "111");
	// 退货单名称
	API_DTO_FIELD(String, rt_name, ZH_WORDS_GETTER("return.fields.rt_name"), true, "01star");
	// 采购单编号
	API_DTO_FIELD(String, po_code, ZH_WORDS_GETTER("return.fields.po_code"), true, "222");
	// 供应商编码
	API_DTO_FIELD(String, vendor_code, ZH_WORDS_GETTER("return.fields.vendor_code"), true, "333");
	// 供应商名称
	API_DTO_FIELD(String, vendor_name, ZH_WORDS_GETTER("return.fields.vendor_name"), true, "01star");
	// 退货日期
	API_DTO_FIELD(String, rt_date, ZH_WORDS_GETTER("return.fields.rt_date"), true, "2024-05-21 09:49:51");
	// 单据状态
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("return.fields.status"), true, "PREPARE");
	// 退货日期
	API_DTO_FIELD(String, batch_code, ZH_WORDS_GETTER("return.fields.batch_code"), true, "444");
	// 单据状态
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("return.fields.remark"), true, "remark");


};
/**
* 定义一个单据详情传输对象
*/
class ReturnDetailDTO_r : public ReturnDTO_r
{
	DTO_INIT(ReturnDetailDTO_r, ReturnDTO_r);
	//// 批次号
	//API_DTO_FIELD_DEFAULT(String, batch_code, ZH_WORDS_GETTER("return.fields.batch_code"));
	//// 备注
	//API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("return.fields.remark"));
};
/**
 * 定义一个单据信息分页传输对象
 */
class ReturnPageDTO_r : public PageDTO<ReturnDTO_r::Wrapper>
{
	DTO_INIT(ReturnPageDTO_r, PageDTO<ReturnDTO_r::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _RETURNDTO_H_