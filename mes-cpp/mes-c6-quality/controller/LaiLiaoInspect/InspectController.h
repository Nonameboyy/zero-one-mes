#pragma once
#ifndef _INSPECT_CONTROLLER_
#define _INSPECT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/LaiLiaoInspect/InspectQuery.h"
#include "domain/dto/LaiLiaoInspect/InspectDTO.h"
#include "domain/vo/LaiLiaoInspect/InspectVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ���ϼ��鵥��Ϣ�ӿڵ�ʹ��
 */
class InspectController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(InspectController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ���鵥�б�ӿ�����
	ENDPOINT_INFO(queryInspect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inspect.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(InspectPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "iqc_code", ZH_WORDS_GETTER("inspect.iqc_code"),"",false);

		API_DEF_ADD_QUERY_PARAMS(String, "vendor_code", ZH_WORDS_GETTER("inspect.vendor_code"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "vendor_name", ZH_WORDS_GETTER("inspect.vendor_name"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "vendor_batch", ZH_WORDS_GETTER("inspect.vendor_batch"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("inspect.item_code"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("inspect.item_name"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "check_result", ZH_WORDS_GETTER("inspect.check_result"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "recive_date", ZH_WORDS_GETTER("inspect.recive_date"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "inspect_date", ZH_WORDS_GETTER("inspect.inspect_date"), "", false);

		API_DEF_ADD_QUERY_PARAMS(String, "inspector", ZH_WORDS_GETTER("inspect.inspector"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/incoming-inspect/search_all", queryInspect, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, InspectQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryInspect(userQuery, authObject->getPayload()));
	}

	//3.1 �����ѯ���鵥����ӿ�����
	ENDPOINT_INFO(queryInspect_detail) {
	// ����ӿڱ���
	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inspect.detail.summary"));
	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	API_DEF_ADD_AUTH();
	// ������Ӧ������ʽ
	API_DEF_ADD_RSP_JSON_WRAPPER(Inspect_detailJsonVO);
	// ����������ѯ��������
	API_DEF_ADD_QUERY_PARAMS(UInt64, "iqc_id", ZH_WORDS_GETTER("inspect.iqc_id"), 1, true);
	}
	// 3.2 �����ѯ���ϼ�������ӿڴ���
	ENDPOINT(API_M_GET, "/incoming-inspect/detail", queryInspect_detail, QUERY(UInt64, iqc_id), API_HANDLER_AUTH_PARAME) {

		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execInspect_detail(iqc_id));
	}

	//3.1 ����鿴����ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("inspect.table.summary"), lookTable, StringJsonVO::Wrapper);
	// 3.2 ����鿴����ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/incoming-inspect/table", lookTable, BODY_DTO(oatpp::List<UInt64>, ids), execLookTable(ids));

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addInspect) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inspect.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/incoming-inspect/add", addInspect, BODY_DTO(InspectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddInspect(dto));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("inspect.change.summary"), modifyInspect, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming-inspect/change", modifyInspect, BODY_DTO(InspectDTO::Wrapper, dto), execModifyInspect(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeInspect) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("inspect.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "iqc_id", ZH_WORDS_GETTER("Inspect.iqc_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/incoming-inspect/delete/{iqc_id}", removeInspect, PATH(UInt64, iqc_id), execRemoveInspect(iqc_id));

	ENDPOINT_INFO(exportInspect) {
		// ����ӿ���������
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("inspect.export.summary"));
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ����������������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "iqc_id",
			ZH_WORDS_GETTER("inspect.iqc_id"), 1, true);
	}

	ENDPOINT(API_M_GET, "/incoming-inspect/export", exportInspect,
		QUERIES(QueryParams, queryParams))
	{
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, Inspect_tableQuery, queryParams);
		// ����ִ�к���
		API_HANDLER_RESP_VO(execExportInspect(query));
	}


	// 3.1 ����ȷ�ϼ��鵥�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("inspect.is_ok.summary"), Is_OkInspect, Uint64JsonVO::Wrapper);
	// 3.2 ����ȷ�ϼ��鵥�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming-inspect/is_ok", Is_OkInspect, BODY_DTO(Item_idDTO::Wrapper, dto), execIs_OkInspect(dto));

	// 3.1 ������ɼ��鵥�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("inspect.finished.summary"), Is_FinishedInspect, Uint64JsonVO::Wrapper);
	// 3.2 ������ɼ��鵥�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/incoming-inspect/finished", Is_FinishedInspect, BODY_DTO(Item_idDTO::Wrapper, dto),execIs_FinishedInspect(dto));


private:
	// 3.3 ��ҳ��ѯ�����б�����
	InspectPageJsonVO::Wrapper execQueryInspect(const InspectQuery::Wrapper& query, const PayloadDTO& payload);
	//3.3 ��ѯ���ϼ��������
	Inspect_detailJsonVO::Wrapper execInspect_detail(const int& iqc_id);
	//3.3�鿴����(һ��ֻ�ܲ�һ��)
	StringJsonVO::Wrapper execLookTable(const oatpp::List<UInt64>& ids);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddInspect(const InspectDTO::Wrapper& dto);
	// 3.3 �޸�����
	Uint64JsonVO::Wrapper execModifyInspect(const InspectDTO::Wrapper& dto);
	// 3.3 ɾ������
	Uint64JsonVO::Wrapper execRemoveInspect(const UInt64& id);
	// 3.3��������
	//StringJsonVO::Wrapper execExportInspect(const oatpp::UInt64& ids);

	StringJsonVO::Wrapper execExportInspect(const Inspect_tableQuery::Wrapper& query);

	//3.3ȷ�ϼ��鵥(���鵥״̬��Ϊ�ݸ�״̬)
	Uint64JsonVO::Wrapper execIs_OkInspect(const Item_idDTO::Wrapper& dto);
	//3.3��ɼ��鵥(���鵥״̬��Ϊ��ȷ��״̬)
	Uint64JsonVO::Wrapper execIs_FinishedInspect(const Item_idDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _INSPECT_CONTROLLER_