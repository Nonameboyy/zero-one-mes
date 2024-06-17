#pragma once
#ifndef _SET_CONTROLLER_
#define _SET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/set/ProcessExportQuery.h"
#include "domain/query/set/SetProListQuery.h"

#include "domain/dto/set/SetProAddDTO.h"
#include "domain/dto/set/SetProListDTO.h"
#include "domain/vo/set/SetProListVO.h"

#include "domain/query/set/ProListQuery.h"
#include "domain/dto/set/ProListDTO.h"
#include "domain/vo/set/ProListVO.h"

#include "domain/dto/set/ProNameListDTO.h"
#include "domain/vo/set/ProNameListVO.h"

#include "domain/query/set/ProDetailQuery.h"
#include "domain/vo/set/ProDetailVO.h"

#include "domain/query/set/SetStepExportQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * �������̿�����
 */
class SetController : public oatpp::web::server::api::ApiController 
{

	API_ACCESS_DECLARE(SetController);

public:

	// 1 ��������
	ENDPOINT_INFO(queryProcessExport) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.export.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "processCode", ZH_WORDS_GETTER("set.field.code"), "R1126", false);
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("set.field.name"), "111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("set.field.flag"), "Y", false);
	}
	ENDPOINT(API_M_POST, "/pro/export-procedure", queryProcessExport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(Query, ProcessExportQuery, queryParams);
		API_HANDLER_RESP_VO(execProcessExport(Query));
	}

	// 2 ��ӹ���ӿ�����
	ENDPOINT_INFO(addSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-set", addSet, BODY_DTO(SetProAddTableDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddSet(dto, authObject->getPayload()));
	}

	// 3 �޸Ĺ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("set.modify.summary"), modifySet, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-set", modifySet, BODY_DTO(SetProAddTableDTO::Wrapper, dto), execModifySet(dto, authObject->getPayload()));

	// 4 ��ȡ�������б�ӿ�
	ENDPOINT_INFO(querySet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(SetProListPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("set.fields.processid"), 1, false);
	}
	ENDPOINT(API_M_GET, "/pro/query-list-set", querySet, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, SetProListQuery, queryParams);
		API_HANDLER_RESP_VO(execQuerySet(query, authObject->getPayload()));
	}

	// 5 ��ӹ�����ӿ�����
	ENDPOINT_INFO(addstepSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.addstep.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/addstep-set", addstepSet, BODY_DTO(SetProListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddStepSet(dto, authObject->getPayload()));
	}

	// 6 ��ȡ���������б�
	ENDPOINT_INFO(queryProNameList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary2"));
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProNameListJsonVO);
	}
	ENDPOINT(API_M_GET, "/pro/query-process-name-list", queryProNameList,  API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProNameList());
	}

	// 7 ��ȡ�����б�����+��ҳ��
	ENDPOINT_INFO(queryProList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "processCode", ZH_WORDS_GETTER("process.fields.processCode"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "processName", ZH_WORDS_GETTER("process.fields.processName"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("process.fields.enableFlag"), "Y", false);
	}
	ENDPOINT(API_M_GET, "/pro/query-process-list", queryProList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProList(query));
	}

	// 8 ��ȡ��������
	ENDPOINT_INFO(queryProcessDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.query.summary3"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProDetailJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("process.fields.processId"), 265, true);
	}
	ENDPOINT(API_M_GET, "/pro/query-process-detail", queryProcessDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProDetail(query));
	}

	// 9 �޸Ĺ�����
	ENDPOINT_INFO(modifystepSet) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.modify.summary1"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/pro/modifystep-set", modifystepSet, BODY_DTO(SetProListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyStepSet(dto, authObject->getPayload()));
	}
	// 10 ɾ��������
	ENDPOINT_INFO(deletestepSet) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("set.modify.summary2"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("set.fields.processid"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete-process-step/{id}", deletestepSet, PATH(UInt64, id), execDeleteStepSet(id));

	// 11 ����������
	ENDPOINT_INFO(SetStepExport) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("set.export.summary1"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(UInt64, "processId", ZH_WORDS_GETTER("set.fields.processid"), 1, true);
	}
	ENDPOINT(API_M_POST, "/pro/export-process-step", SetStepExport, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(setstepQuery, SetProListQuery, queryParams);
		API_HANDLER_RESP_VO(execExportStepSet(setstepQuery));
	}
	// 12 ɾ������
	ENDPOINT_INFO(DeleteSet) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("set.modify.summary3"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("set.fields.processid"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete-set/{id}", DeleteSet, PATH(UInt64, id), execDeleteSet(id));

private:
	// 1 �����ļ�
	StringJsonVO::Wrapper execProcessExport(const ProcessExportQuery::Wrapper& query);
	// 2 ��ӹ���
	Uint64JsonVO::Wrapper execAddSet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3 �޸Ĺ���
	Uint64JsonVO::Wrapper execModifySet(const SetProAddTableDTO::Wrapper& dto, const PayloadDTO& payload);
	// 4 ��ȡ�������б�
	SetProListPageJsonVO::Wrapper execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload);
	// 5 ��ӹ�����
	Uint64JsonVO::Wrapper execAddStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload);
	// 6 ��ȡ�����б�
	ProListPageJsonVO::Wrapper execQueryProList(const ProListQuery::Wrapper& query);
	// 7 ��ȡ���������б�
	ProNameListJsonVO::Wrapper execQueryProNameList();
	// 8 ��ȡ��������
	ProDetailJsonVO::Wrapper execQueryProDetail(const ProDetailQuery::Wrapper& query);
	// 9 �޸Ĺ�����
	Uint64JsonVO::Wrapper execModifyStepSet(const SetProListDTO::Wrapper& dto, const PayloadDTO& payload);
	//10 ɾ��������
	Uint64JsonVO::Wrapper execDeleteStepSet(const UInt64& id);
	//11 ����������
	StringJsonVO::Wrapper execExportStepSet(const SetProListQuery::Wrapper& query);
	//12 ɾ������
	Uint64JsonVO::Wrapper execDeleteSet(const UInt64& id);
};


#include OATPP_CODEGEN_END(ApiController) 
#endif 