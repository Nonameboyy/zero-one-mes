#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _DEVICERESOURCE_CONTROLLER_
#define _DEVICERESOURCE_CONTROLLER_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "../mes-c1-workstation/domain/query/deviceresource/DeviceResourceQuery.h"
#include "../mes-c1-workstation/domain/vo/deviceresource/DeviceResourceVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �豸��Դ����������ʾ�����ӿڵ�ʹ��
 */
class DeviceResourceController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeviceResourceController);
	// 3 ����ӿ�
public:
	//��ȡ�豸�б�(���� + ��ҳ)
		// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(getDeviceResourcetList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deviceResource.getDeviceResourcetList.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DeviceResourcePageVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/ws/deviceResource/getDeviceResourcetList", getDeviceResourcetList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(deviceResourceQuery, DeviceResourceQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execGetDeviceResourceList(deviceResourceQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addDeviceResource) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deviceResource.addDeviceResource.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ws/deviceResource/addDeviceResource", addDeviceResource, BODY_DTO(DeviceResourceDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddDeviceResource(dto));
	}
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("deviceResource.modifyDeviceResource.summary"), modifyDeviceResource, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ws/deviceResource/modifyDeviceResource", modifyDeviceResource, BODY_DTO(DeviceResourceDTO::Wrapper, dto), execModifyDeviceResource(dto));
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(deleteDeviceResource) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("deviceResource.deleteDeviceResource.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "deviceResourceId", ZH_WORDS_GETTER("deviceResource.deviceResourceDTO.deviceResourceId"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ws/deviceResource/removeDeviceResource/{deviceResourceId}", deleteDeviceResource, PATH(UInt64, deviceResourceId), execDeleteDeviceResource(deviceResourceId));

private:
	// 3.3 �豸��Դ��ҳ��ѯ����
	DeviceResourcePageVO::Wrapper execGetDeviceResourceList(const DeviceResourceQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 �豸��Դ��������
	Uint64JsonVO::Wrapper execAddDeviceResource(const DeviceResourceDTO::Wrapper& dto);
	// 3.3 �豸��Դ�޸�����
	Uint64JsonVO::Wrapper execModifyDeviceResource(const DeviceResourceDTO::Wrapper& dto);
	// 3.3 �豸��Դɾ������
	Uint64JsonVO::Wrapper execDeleteDeviceResource(const UInt64& deviceResourceId);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEVICERESOURCE_CONTROLLER_