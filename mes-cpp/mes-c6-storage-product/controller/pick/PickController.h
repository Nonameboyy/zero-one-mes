#pragma once

#ifndef _PICK_CONTROLLER_
#define _PICK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/pick/PickQuery.h"
#include "domain/dto/pick/PickDTO.h"
#include "domain/vo/pick/PickVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PickController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PickController);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPick) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pick.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/incoming/add-1", addPick, BODY_DTO(PickDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddPick(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("pick.put.summary"), modifyPick, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming/change-1", modifyPick, BODY_DTO(PickDTO::Wrapper, dto), execModifyPick(dto));

	// ����ִ����ȡ���Ͻӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("pick.execute-get.summary"), executeGet, Uint64JsonVO::Wrapper);
	// ����ִ����ȡ���Ͻӿڴ��� "/pick/{Id}"�����Ӧ
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming/do/{getId}", executeGet, PATH(UInt64, getId), executeExecuteGet(getId));

	// ����ɾ�����ݽӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("pick.delete.summary"), removeReturn, Uint64JsonVO::Wrapper);
	// ����ɾ�����ݽӿڴ��� "/pick/{Id}"�����Ӧ
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/incoming/delete1/{deleteId}", removeReturn, PATH(UInt64, deleteId), executeRemoveReturn(deleteId));

	
	// 3.1 ���嵼���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("pick.download.summary"), downloadFile, StringJsonVO::Wrapper);
	// 3.2 ���嵼���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/incoming/download-1", downloadFile, BODY_DTO(oatpp::List<UInt64>, ids), executeDownloadFile(ids));

private:
	// ��������
	Uint64JsonVO::Wrapper execAddPick(const PickDTO::Wrapper& dto);
	// �޸�����
	Uint64JsonVO::Wrapper execModifyPick(const PickDTO::Wrapper& dto);
	// ִ�е���
	Uint64JsonVO::Wrapper executeExecuteGet(const UInt64& id);
	// ɾ������
	Uint64JsonVO::Wrapper executeRemoveReturn(const UInt64& id);
	// ��������
	StringJsonVO::Wrapper executeDownloadFile(const oatpp::List<UInt64>& ids);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PICK_CONTROLLER_