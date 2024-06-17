/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/18 19:50:23

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
#ifndef _REMOVEDEVICECONTROLLER_H_
#define _REMOVEDEVICECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/dto/RemoveDeviceDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

// ɾ�����ݲ���Ҫ�Զ���JsonVO��ֻҪ����true��false���ɣ�ֱ��ʹ��ѧ����BaseJsonVO.h�ж����BooleanJsonVO����
// ɾ�����ݲ���ҪQuery������û�з�ҳ��ѯ������������Ĳ���������ɾ����ͨ��ǰ�����û��ڻ������������й�ѡ�õ���

class RemoveDeviceController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(RemoveDeviceController)
public: // ����ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("equipmentledger.remove-device.summary"), removeDevice, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/equipment-ledger/equip/remove-device", removeDevice, BODY_DTO(RemoveDeviceListDTO::Wrapper, dto), execRemoveDevice(dto))
private: // ����ӿ�ִ�к���

	// ǰ�˷�������dto���������ִ��
	BooleanJsonVO::Wrapper execRemoveDevice(const RemoveDeviceListDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REMOVEDEVICECONTROLLER_H_