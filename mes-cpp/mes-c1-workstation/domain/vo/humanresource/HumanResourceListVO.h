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
#ifndef _HUMANRESOURCELISTVO_H_
#define _HUMANRESOURCELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/humanresource/HumanResourceListDTO.h"
//#include<List>
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��������Դ�б� ��ʾJsonVO����������Ӧ���ͻ���,Ҳ����Ҫ�����ֻ��Ҫ�����ҳ��
 */
class HumanResourceListVO : public JsonVO<HumanResourceListDTO::Wrapper>
{
	DTO_INIT(HumanResourceListVO, JsonVO<HumanResourceListDTO::Wrapper>);
};

/**
 * ����һ��������Դ��Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class HumanResourceListPageVO : public JsonVO<HumanResourcePageDTO::Wrapper>
{
	DTO_INIT(HumanResourceListPageVO, JsonVO<HumanResourcePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _HUMANRESOURCELISTVO_H_