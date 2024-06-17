#pragma once
#ifndef _RawMaterialOp_CONTROLLER_
#define _RawMaterialOp_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ServerInfo.h"
#include "domain/dto/RawMaterialOp/RawMaterialOpDTO.h"

#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"
#include "domain/vo/RawMaterialOp/RawMaterialOpVO.h"
//=======
#include "domain/query/RawMaterialOp/RawMaterialOpQuery.h"
#include "domain/vo/RawMaterialOp/RawMaterialOpVO.h"

#include "ExcelComponent.h"

//#include "ApiHelper.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class RawMaterialOpController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RawMaterialOpController);
	// 3 ����ӿ�
public:

	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RawMaterialOp.put.summary"), modifyRawMaterialOp, Uint64JsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/rejection/mod-raw_material", modifyRawMaterialOp, BODY_DTO(RawMaterialOpDTO::Wrapper, dto), execModifyRawMaterialOp(dto));



	// ����ɾ�����ݽӿ�����
	ENDPOINT_INFO(removeRawMaterialOp)
	{
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("RawMaterialOp.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("RawMaterialOp.field.id"), 1, true);
	}

	//����ɾ�����ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rejection/del-raw_material-by-rt_id/{rt_id}", removeRawMaterialOp, PATH(UInt64, id), execRemoveRawMaterialOp(id));


	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryRawMaterialOp) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("RawMaterialOp.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RawMaterialOpJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("RawMaterialOp.field.id"), "RT20221115001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("RawMaterialOp.field.order"), "MO10023110", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse", ZH_WORDS_GETTER("RawMaterialOp.field.warehouse"), "N", false);
	}

	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/rejection/query-raw_material", queryRawMaterialOp, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) 
	{
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, RawMaterialOpQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRawMaterialOp(userQuery, authObject->getPayload()));
		
		
	}






private:
	// ɾ���������ϵ����б�֧������ɾ����
	Uint64JsonVO::Wrapper execRemoveRawMaterialOp(const UInt64& id);

	// 3.3 �޸��������ϵ�������
	Uint64JsonVO::Wrapper execModifyRawMaterialOp(const RawMaterialOpDTO::Wrapper& dto);
	//��ѯ���ݵ�������
	RawMaterialOpPageJsonVO::Wrapper execQueryRawMaterialOp(const RawMaterialOpQuery::Wrapper& query, const PayloadDTO& payload);


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End
#endif // _SAMPLE_CONTROLLER_