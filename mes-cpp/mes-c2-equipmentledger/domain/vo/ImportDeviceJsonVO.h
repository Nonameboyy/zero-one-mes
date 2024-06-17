/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/19 14:15:47

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
#ifndef _IMPORTDEVICEJSONVO_H_
#define _IMPORTDEVICEJSONVO_H_

#include "../GlobalInclude.h"
#include "ApiHelper.h"
#include "domain/dto/ImportDeviceDTo.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导入设备JsonVo
 * 负责人：。好
 */
class ImportDeviceJsonVO : public JsonVO<ImportDeviceDTO::Wrapper>
{
	DTO_INIT(ImportDeviceJsonVO, JsonVO<ImportDeviceDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTDEVICEJSONVO_H_