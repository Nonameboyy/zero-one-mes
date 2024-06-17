/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/19 14:12:58

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
#ifndef _IMPORTDEVICEDTO_H_
#define _IMPORTDEVICEDTO_H_

#include "../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导入设备DTO
 * 负责人：。好
 */
class ImportDeviceDTO : public oatpp::DTO
{
	DTO_INIT(ImportDeviceDTO, DTO)

	// 该DTO不需要定义各种字段，只需告诉前端成功和失败的条数，
	// 具体的数据是由公共接口中的获取数据项再次从数据库中获得的

	API_DTO_FIELD_DEFAULT(Int32, success_count, 
		ZH_WORDS_GETTER("equipmentledger.import-device.success-count"))

	API_DTO_FIELD_DEFAULT(Int32, fail_count,
		ZH_WORDS_GETTER("equipmentledger.import-device.fail-count"))
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTDEVICEDTO_H_