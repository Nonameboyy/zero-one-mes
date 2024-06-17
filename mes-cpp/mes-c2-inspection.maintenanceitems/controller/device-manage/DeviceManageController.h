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
#ifndef _DEVICEMANAGE_CONTROLLER_
#define _DEVICEMANAGE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/device-manage/DeviceManageDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class DeviceManageController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeviceManageController);
	// 3 ����ӿ�
public:


	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("device-manage.summary.modify-proj"), modifyProj, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/equipment-ledger/device-manage/modify-proj", modifyProj, BODY_DTO(DeviceManageDTO::Wrapper, dto), execModifyProj(dto));

	//ɾ���ӿ������ʹ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("device-manage.summary.remove-proj"), removeProj, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/equipment-ledger/device-manage/remove-proj", removeProj, BODY_DTO(DeviceManageIdDTO::Wrapper, dto), execRemoveProj(dto));

	//�����ӿ������ʹ���
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("device-manage.summary.export-proj"), exportProj, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "/equipment-ledger/device-manage/export-proj", exportProj, BODY_DTO(DeviceManageIdDTO::Wrapper, dto), execExportProj(dto));

	//�����ӿ������ʹ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("device-manage.summary.add-proj"), addProj, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/equipment-ledger/device-manage/add-proj", addProj, BODY_DTO(DeviceManageAddDTO::Wrapper, dto), execAddProj(dto));



private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyProj(const DeviceManageDTO::Wrapper& dto);

	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveProj(const DeviceManageIdDTO::Wrapper& dto);
	
	//������Ŀ
	Uint64JsonVO::Wrapper execExportProj(const DeviceManageIdDTO::Wrapper& dto);

	//������Ŀ
	Uint64JsonVO::Wrapper execAddProj(const DeviceManageAddDTO::Wrapper& dto);




};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEVICEMANAGE_CONTROLLER_