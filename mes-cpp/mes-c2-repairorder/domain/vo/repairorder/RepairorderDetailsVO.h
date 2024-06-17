#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 17:35:43

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
#ifndef _REPAIROR_DERDETAILS_VO_
#define _REPAIROR_DERDETAILS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/repairorder/RepairorderDetailsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ά�޵�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RepairorderDetailsJsonVO : public JsonVO<RepairorderDetailsDTO::Wrapper> {
    DTO_INIT(RepairorderDetailsJsonVO, JsonVO<RepairorderDetailsDTO::Wrapper>);
};

/**
 * ���ά�޵����ݴ���JsonVO�����ڴ��������˵�Json����
 */
class RepairorderDetailsByAddJsonVO : public JsonVO<RepairorderDetailsByAddDTO::Wrapper> {
    DTO_INIT(RepairorderDetailsByAddJsonVO, JsonVO<RepairorderDetailsByAddDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REPAIROR_DERDETAILS_VO_