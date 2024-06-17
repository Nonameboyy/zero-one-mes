#pragma once
#ifndef _MODIFYWHSTORAGEORDERCONTROLLER_H_
#define _MODIFYWHSTORAGEORDERCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDTO.h"
#include "../../../domain/vo/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyWhStorageorderController :public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyWhStorageorderController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("whstorageorder.modify.summary"), modifyWhStorageorder, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/whmgmt/purchase/modify2", modifyWhStorageorder, BODY_DTO(ModifyWhStorageorderDTO::Wrapper, dto), execModifyWhStorageorder(dto));

	
private://����ӿ�ִ�к���
	//��ʾ��������
	Uint64JsonVO::Wrapper execModifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_MODIFYWHSTORAGEORDERCONTROLLER_H_
