#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ksw12355
 @Date: 2024/5/20

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
#ifndef _GETPROGECTVO_H_
#define _GETPROGECTVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/getprogect/GetProgectDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * ����һ���豸�б��ҳ��ʾJsonVO����
 */
class GetProgectPageJsonVO : public JsonVO<GetProgectPageDTO::Wrapper>
{
	DTO_INIT(GetProgectPageJsonVO, JsonVO<GetProgectPageDTO::Wrapper>);
};
/**
 * ����һ���豸������ʾJsonVO����
 */
class GetProgectDetailJsonVO : public JsonVO<GetProgectDetailDTO::Wrapper>
{
	DTO_INIT(GetProgectDetailJsonVO, JsonVO<GetProgectDetailDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif 


