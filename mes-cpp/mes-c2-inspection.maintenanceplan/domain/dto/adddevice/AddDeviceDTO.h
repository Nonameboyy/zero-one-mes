#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _ADDDEVICE_DTO_
#define _ADDDEVICE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddDeviceDTO : public oatpp::DTO
{
	DTO_INIT(AddDeviceDTO, DTO);

	//????id
	API_DTO_FIELD(UInt64, planId, ZH_WORDS_GETTER("device-list.field.planId"),true,210);

	//?¨²?¡Âid
	API_DTO_FIELD(String, machineryId, ZH_WORDS_GETTER("device-list.field.machineryId"),true,"machineryid");

};




#include OATPP_CODEGEN_END(DTO)
#endif // !_DEVICELIST_DTO_