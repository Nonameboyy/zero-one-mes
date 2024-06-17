#pragma once
#ifndef _PROCESS_CONTROLLER_
#define _PROCESS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/process/ProcessListVo.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"

#include "domain/query/process/ProcessProductsQuery.h"
#include "domain/dto/process/ProcessProductsDTO.h"
#include "domain/vo/process/ProcessProductsVO.h"
#include "domain/query/process/ProcessQuery.h"

#include "domain/vo/process/ComProVo.h"
#include "domain/dto/process/ComProDTO.h"
#include "domain/query/process/ComProQuery.h"

#include "domain/vo/process/RelateProVO.h"
#include "domain/dto/process/RelateProDTO.h"
#include "domain/dto/process/ProMaterialDTO.h"
#include "domain/vo/process/ProMaterialVO.h"
#include "domain/query/process/ProMaterialQuery.h"

#include "domain/query/process/outputRouteProductQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������-�������̿�����
 */
class ProcessController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(ProcessController);

public:
	// 1 ��ȡ�����б�
	ENDPOINT_INFO(queryProcessList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessListJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "routeCode", ZH_WORDS_GETTER("process.field.routecode"), "R1126", false);
		API_DEF_ADD_QUERY_PARAMS(String, "routeName", ZH_WORDS_GETTER("process.field.name"), "111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("process.field.flag"), "Y", false);
	}
	ENDPOINT(API_M_GET, "/pro/get-list", queryProcessList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ProcessListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcessList(Query));
	}

	// 2 ��ȡ��������
	ENDPOINT_INFO(queryProcessDetail) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary2"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessDetailJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "routeId", ZH_WORDS_GETTER("process.field.id"), 239, true);
	}
	ENDPOINT(API_M_GET, "/pro/get-detail", queryProcessDetail, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ProcessDetailQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcessDetail(Query));
	}

	// 3 ��ӹ�������
	ENDPOINT_INFO(addProcess) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.post.summary1"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-process", addProcess, BODY_DTO(ProcessAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProcess(dto, authObject->getPayload()));
	}

	// 4 �޸Ĺ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("process.put.summary1"), modifyProcess, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-process", modifyProcess, BODY_DTO(ProcessDTO::Wrapper, dto), execModifyBasicProcess(dto, authObject->getPayload()));

	// 5 ��ȡ���չ�����Ʒ�б�
	ENDPOINT_INFO(queryCorrProduct) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary3"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProductsPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "routeid", ZH_WORDS_GETTER("product.field.routeid"), "249", false);

	}
	ENDPOINT(API_M_GET, "/pro/get-corrprocess", queryCorrProduct, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProcessProductsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProducts(userQuery));
	}

	// 6 ɾ����ɹ���
	ENDPOINT_INFO(removeProcess) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("process.delete.summary1"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete-process/{id}", removeProcess, BODY_DTO(List<UInt64>, id), execRemoveProcess(id));

	// 7 ���յ���
	ENDPOINT_INFO(queryProcess) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get_field.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "routeCode", ZH_WORDS_GETTER("process.field.route_code"), "R1121", false);
		API_DEF_ADD_QUERY_PARAMS(String, "routeName", ZH_WORDS_GETTER("process.field.route_name"), ZH_WORDS_GETTER("process.field.example"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "enableFlag", ZH_WORDS_GETTER("process.field.enable_flag"), "Y", false);
	}
	ENDPOINT(API_M_POST, "/set/export-process", queryProcess, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, ProcessListQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProcess(userQuery));
	}

	// 8 ��ȡ��ɹ����б�
	ENDPOINT_INFO(QueryProTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.get.summary4"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt32, "route_id", ZH_WORDS_GETTER("pro.fields.proName"), 1 , false);
		
	}
	ENDPOINT(API_M_GET, "/pro/query-pro-table", QueryProTable, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(Query, ProQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execProTable(Query));
	}

	// 9 �����ɹ���
	ENDPOINT_INFO(addComProcess) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-comprocess", addComProcess, BODY_DTO(NewProcessDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execaddComProcess(dto, authObject->getPayload()));
	}

	// 10 �޸���ɹ���
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("process.modify.summary"), ModifyProcess, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-comprocess", ModifyProcess, BODY_DTO(ModifyProDTO::Wrapper, dto), execModifyProcess(dto, authObject->getPayload()));

	//11 ��ӹ��չ�����Ʒ
	ENDPOINT_INFO(addRelatePro) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("RelatePro.summary.AddRelatePro"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-relatepro", addRelatePro, BODY_DTO(AddRelateProDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddRelatePro(dto,authObject->getPayload()));
	}

	// 12 �޸Ĺ��չ�����Ʒ
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RelatePro.summary.ModRelatePro"), modifyRelatePro, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-relatepro", modifyRelatePro, BODY_DTO(ModRelateProDTO::Wrapper, dto), execModifyRelatePro(dto, authObject->getPayload()));

	// 13 ��ȡ��Ʒ�Ƴ�����BOM�б�
	ENDPOINT_INFO(queryProMaterial) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("RelatePro.summary.ProMaterial"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProMaterialPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(UInt64, "route_id", ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.route_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "process_id", ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.process_id"), 1, false);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "product_id", ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.product_id"), 1, false);
	}
	ENDPOINT(API_M_GET, "/pro/query-promaterial-table", queryProMaterial, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, ProMaterialQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryProMaterial(query));
	}

	// 14 ����ɾ���������̽ӿ�
	ENDPOINT_INFO(removeProRoute) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("process.route.delete1"), Uint64JsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/route/{id}", removeProRoute, BODY_DTO(List<UInt64>, id), execRemoveProRoute(id));


	// 15 ����ɾ�����չ�����Ʒ�ӿ�
	ENDPOINT_INFO(removeRouteProduct) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("process.route.delete2"), Uint64JsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/route/product/{id}", removeRouteProduct, BODY_DTO(List<UInt64>, id), execRemoveRouteProduct(id));

	// 16 ���幤�չ�����Ʒ�����ӿ�
	ENDPOINT_INFO(exportRouteProduct) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.route.output"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

	}
	ENDPOINT(API_M_POST, "/pro/route/{id}", exportRouteProduct, BODY_DTO(List<UInt64>, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execExportRouteProduct(id));
	}

	// 17 ɾ����Ʒ�Ƴ�����BOM
	ENDPOINT_INFO(removeProcessBOM) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("process.delete.summary2"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("process.field.record_id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pro/delete/{id}", removeProcessBOM, PATH(UInt64, id), execRemoveProcessBOM(id));

	// 18 ��Ӳ�Ʒ�Ƴ�����BOM
	ENDPOINT_INFO(addProductMaterial) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.post.summary2"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/pro/add-productmaterial", addProductMaterial, BODY_DTO(ProductMaterialDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProductMaterial(dto, authObject->getPayload()));
	}

	// 19 �޸Ĳ�Ʒ�Ƴ�BOM
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("process.put.summary2"), modifyProductMaterial, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pro/modify-productmaterial", modifyProductMaterial, BODY_DTO(ProductModefyMaterialDTO::Wrapper, dto), execModifyProductMaterial(dto, authObject->getPayload()));

private:
	// 1 ��ȡ�����б�����
	ProcessListJsonVO::Wrapper execQueryProcessList(const ProcessListQuery::Wrapper& query);
	// 2 ��ѯ��������
	ProcessDetailJsonVO::Wrapper execQueryProcessDetail(const ProcessDetailQuery::Wrapper& query);
	// 3 ��ӹ�������
	Uint64JsonVO::Wrapper execAddProcess(const ProcessAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 4 �޸Ĺ��ջ�������
	Uint64JsonVO::Wrapper execModifyBasicProcess(const ProcessDTO::Wrapper& dto, const PayloadDTO& payload);
	// 5 ��ȡ���չ�����Ʒ�б�
	ProductsPageJsonVO::Wrapper execQueryProducts(const ProcessProductsQuery::Wrapper& query);
	// 6 ɾ����ɹ���֧������ɾ����
	Uint64JsonVO::Wrapper execRemoveProcess(const List<UInt64>& id);
	// 7 ���յ���
	StringJsonVO::Wrapper execQueryProcess(const ProcessListQuery::Wrapper& query);
	// 8 ��ȡ��ɹ����б�
	ProJsonVO::Wrapper execProTable(const ProQuery::Wrapper& query);
	// 9 �����ɹ���
	Uint64JsonVO::Wrapper execaddComProcess(const NewProcessDTO::Wrapper& dto, const PayloadDTO& payload);
	// 10 �޸���ɹ���
	Uint64JsonVO::Wrapper execModifyProcess(const ModifyProDTO::Wrapper& dto, const PayloadDTO& payload);
	// 11 ��ӹ��չ�����Ʒ
	Uint64JsonVO::Wrapper execAddRelatePro(const AddRelateProDTO::Wrapper& dto, const PayloadDTO& payload);
	// 12 �޸Ĺ��չ�����Ʒ
	Uint64JsonVO::Wrapper execModifyRelatePro(const ModRelateProDTO::Wrapper& dto, const PayloadDTO& payload);
	// 13 ��ȡ��Ʒ�Ƴ�����BOM�б�
	ProMaterialPageJsonVO::Wrapper execQueryProMaterial(const ProMaterialQuery::Wrapper& query);
	// 14 ɾ����������
	List<Uint64JsonVO::Wrapper> execRemoveProRoute(const List<UInt64>& id);
	// 15 ɾ�����չ�����Ʒ
	List<Uint64JsonVO::Wrapper> execRemoveRouteProduct(const List<UInt64>& id);
	// 16 �������չ�����Ʒ
	StringJsonVO::Wrapper execExportRouteProduct(const List<UInt64>& id);
	// 17 ɾ����Ʒ�Ƴ�����BOM
	Uint64JsonVO::Wrapper execRemoveProcessBOM(const UInt64& id);
	// 18 ��Ӳ�Ʒ�Ƴ�����BOM
	Uint64JsonVO::Wrapper execAddProductMaterial(const ProductMaterialDTO::Wrapper& dto, const PayloadDTO& payload);
	// 19 �޸Ĳ�Ʒ�Ƴ�����BOM
	Uint64JsonVO::Wrapper execModifyProductMaterial(const ProductModefyMaterialDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_


