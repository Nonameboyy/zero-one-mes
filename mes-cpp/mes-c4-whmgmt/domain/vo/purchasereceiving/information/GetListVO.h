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
#ifndef _GETLIST_VO_
#define _GETLIST_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/purchasereceiving/information/GetListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetListJsonVo : public JsonVO<GetListDTO::Wrapper> {
	DTO_INIT(GetListJsonVo, JsonVO<GetListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class GetListPageJsonVO : public JsonVO<GetListPageDTO::Wrapper> {
	DTO_INIT(GetListPageJsonVO, JsonVO<GetListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_

