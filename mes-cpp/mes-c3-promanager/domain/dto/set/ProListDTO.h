#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xingshoulang
 @Date: 2024/5/20  17:24

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
#ifndef _PROLISTDTO_H_
#define _PROLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 工序列表传输对象
 */
class ProListDTO : public oatpp::DTO
{
	DTO_INIT(ProListDTO, DTO);

	// 唯一标识
	API_DTO_FIELD(UInt64, processId, ZH_WORDS_GETTER("process.fields.processId"), true, 1);
	// 工序编码
	API_DTO_FIELD(String, processCode, ZH_WORDS_GETTER("process.fields.processCode"), true, "01star");
	// 工序名称
	API_DTO_FIELD(String, processName, ZH_WORDS_GETTER("process.fields.processName"), true, "01star");
	// 备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("process.fields.remark"), true, "01star");
	// 是否启用
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("process.fields.enableFlag"), true, "01star");
};
/**
 * 分页 工序列表传输对象
 */
class ProListPageDTO : public PageDTO<ProListDTO::Wrapper>
{
	DTO_INIT(ProListPageDTO, PageDTO<ProListDTO::Wrapper>);
};


/**
 * 工序详情传输对象
 */
class ProDetailDTO : public ProListDTO
{
	DTO_INIT(ProDetailDTO, ProListDTO);
	// 工序说明
	API_DTO_FIELD(String, attention, ZH_WORDS_GETTER("process.fields.attention"), true, "01star");
};

#include OATPP_CODEGEN_END(DTO)
#endif // _PROLISTDTO_H_