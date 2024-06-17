#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:34:14

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
#ifndef _ADDDELMOD_VO_ 
#define _ADDDELMOD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/add-del-mod/AddDelModDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddDelModJsonVO : public JsonVO<AddDelModDTO::Wrapper> {
	DTO_INIT(AddDelModJsonVO, JsonVO<AddDelModDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddDelModJsonPageJsonVO : public JsonVO<AddDelModPageDTO::Wrapper> {
	DTO_INIT(AddDelModJsonPageJsonVO, JsonVO<AddDelModPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDDELMOD_VO_