#pragma once
#ifndef _DELETEWHSTORAGEORDERCONTROLLER_H_
#define _DELETEWHSTORAGEORDERCONTROLLER_H_
#include "../../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../../domain/dto/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDTO.h"
#include "../../../domain/vo/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DeleteWhStorageorderController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(DeleteWhStorageorderController);
	// 3 ����ӿ�
public:
	//3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(deleteWhStorageorders) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("whstorageorder.delete.summary"), Uint64JsonVO::Wrapper);
		// ��Ӱ�ȫ��֤
		API_DEF_ADD_AUTH();
	}
	// 3.2 ��������ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/whmgmt/purchase/delete1", deleteWhStorageorders, BODY_DTO(List<UInt64>, ids), execDeleteWhStorageorder(ids));

private:
	//3.3 ��ʾɾ����ⵥ��
	Uint64JsonVO::Wrapper execDeleteWhStorageorder(const List<UInt64>& ids);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _DELETEWHSTORAGEORDERCONTROLLER_H_