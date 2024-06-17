#pragma once
#ifndef _PROINSPECT_CONTROLLER_
#define _PROINSPECT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../../../domain/do/ProinSpect/ProinSpectDO.h"
#include "../../../domain/dto/ProcessInspection/ProinSpect/ProinSpectDTO.h"
#include "../../../domain/vo/ProcessInspection/ProinSpect/ProinSpectVO.h"
#include "../../../domain/query/ProcessInspection/ProinSpect/ProinSpectQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
class ProinspectController : public oatpp::web::server::api::ApiController {
	// 2 ����������������
	API_ACCESS_DECLARE(ProinspectController);
	// 3 ����ӿ�
public:
	ENDPOINT_INFO(addrecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("qualitycontrol.defect.addre"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

	}
	ENDPOINT(API_M_POST, "/qc/process-inspection/proinspect/add", addrecord, BODY_DTO(ProinspectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddrecord(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.setre"), execModifyrecord, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/qc/process-inspection/proinspect/modify", execModifyrecord, BODY_DTO(ProinspectDTO::Wrapper, dto), execModifyrecord(dto));


	// 3.1 ����ɾ���ӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.record_id"), execRemoverecord, Uint64JsonVO::Wrapper);
	ENDPOINT_INFO(removerecord) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.delre"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qc/process-inspection/proinspect/remove/{record_id}", removerecord, BODY_DTO(ProinspectDTO::Wrapper, dto), execRemoverecord(dto));

	//  �����ȡ���̼��鵥���б�ӿ�����
	ENDPOINT_INFO(queryProinspectList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("processinspection.queryProcessInspectionList.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProinspectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "ipqc_id", ZH_WORDS_GETTER("qualitycontrol.defect.qc_id"), , true);
	}
	//  �����ȡ���̼��鵥���б�ӿڴ���
	ENDPOINT(API_M_GET, "/qc/process-inspection/proinspect/query-by-id", queryProinspectList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProinspectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcessInspectionList(userQuery, authObject->getPayload()));
	}
	
	//  �����ȡ���̼��鵥��ȱ���б�ӿ�����
	ENDPOINT_INFO(queryProcessInspectionDefectList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("processinspection.queryProcessInspectionDefectList.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProinspectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "line_id", ZH_WORDS_GETTER("qualitycontrol.defect.line_id"), , true);
	}
	//  �����ȡ���̼��鵥��ȱ���б�ӿڴ���
	ENDPOINT(API_M_GET, "/qc/process-inspection/proinspect-defect/query-by-id", queryProcessInspectionDefectList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProinspectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcessInspectionDefectList(userQuery, authObject->getPayload()));
	}

private:
	//�������
	Uint64JsonVO::Wrapper execAddrecord(const ProinspectDTO::Wrapper& dto);
	// 3.3 �޸�����                           
	Uint64JsonVO::Wrapper execModifyrecord(const ProinspectDTO::Wrapper& dto);
	// 3.3 ɾ������
	Uint64JsonVO::Wrapper execRemoverecord(const ProinspectDTO::Wrapper& dto);
	//  ��ȡ���̼��鵥���б�
	ProinspectPageJsonVO::Wrapper execQueryProcessInspectionList(const ProinspectQuery::Wrapper& query, const PayloadDTO& payload);
	//  ��ȡ���̼��鵥��ȱ���б�
	ProinspectPageJsonVO::Wrapper execQueryProcessInspectionDefectList(const ProinspectQuery::Wrapper& query, const PayloadDTO& payload);
};







// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_