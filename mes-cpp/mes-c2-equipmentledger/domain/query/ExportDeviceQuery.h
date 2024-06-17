/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/05/19 13:38:09

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
#ifndef _EXPORTDEVICEQUERY_H_
#define _EXPORTDEVICEQUERY_H_

#include "../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportDeviceQuery : public oatpp::DTO
{
	DTO_INIT(ExportDeviceQuery, DTO)

	API_DTO_FIELD_DEFAULT(String, device_code,
		ZH_WORDS_GETTER("equipmentledger.export-device.device-code"))

	API_DTO_FIELD_DEFAULT(String, device_name,
		ZH_WORDS_GETTER("equipmentledger.export-device.device-name"))
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTDEVICEQUERY_H_