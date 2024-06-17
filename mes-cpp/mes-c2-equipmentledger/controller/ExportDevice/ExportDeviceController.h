/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/19 13:41:55

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
#ifndef _EXPORTDEVICECONTROLLER_H_
#define _EXPORTDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/ExportDeviceQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ExportDeviceController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportDeviceController)
public: // ����ӿ�
	ENDPOINT_INFO(exportDevice) {
		// ����ӿ���������
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("equipmentledger.export-device.summary"));

		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		// ����������������
		API_DEF_ADD_QUERY_PARAMS(String, "device_code",
			ZH_WORDS_GETTER("equipmentledger.export-device.device-code"), {}, false);
		API_DEF_ADD_QUERY_PARAMS(String, "device_name",
			ZH_WORDS_GETTER("equipmentledger.export-device.device-name"), {}, false);

		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, "/equipment-ledger/equip/export-device", exportDevice,
		QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, ExportDeviceQuery, queryParams);
		// ����ִ�к���
		API_HANDLER_RESP_VO(execExportDevice(query));
	}

private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execExportDevice(const ExportDeviceQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTDEVICECONTROLLER_H_