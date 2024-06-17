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
#ifndef _RETURNVO_R_H_
#define _RETURNVO_R_H_

#include "../../GlobalInclude.h"
#include "../../dto/return-ryan/ReturnDTO_r.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�����ݼ�Ҫ��Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class ReturnJsonVO_r : public JsonVO<ReturnDTO_r::Wrapper>
{
	DTO_INIT(ReturnJsonVO_r, JsonVO<ReturnDTO_r::Wrapper>);
};
/**
* ����һ��������ϸ��Ϣ��ʾJsonVO����
*/
class ReturnDetailJsonVO_r : public JsonVO<ReturnDetailDTO_r::Wrapper>
{
	DTO_INIT(ReturnDetailJsonVO_r, JsonVO<ReturnDetailDTO_r::Wrapper>);
};
/**
 * ����һ��������Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class ReturnPageJsonVO_r : public JsonVO<ReturnPageDTO_r::Wrapper>
{
	DTO_INIT(ReturnPageJsonVO_r, JsonVO<ReturnPageDTO_r::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 