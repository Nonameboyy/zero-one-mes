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
#ifndef _GETAREADETAILS_VO_
#define  _GETAREADETAILS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/storage_area/GetAreaDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class GetAreaDetailsJsonVO : public JsonVO<GetAreaDetailsDTO::Wrapper> 
{
	DTO_INIT(GetAreaDetailsJsonVO, JsonVO<GetAreaDetailsDTO::Wrapper>);
};
//����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
class GetAreaDetailsPageJsonVO : public JsonVO<GetAreaDetailsPageDTO::Wrapper>
{
	DTO_INIT(GetAreaDetailsPageJsonVO, JsonVO<GetAreaDetailsPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_