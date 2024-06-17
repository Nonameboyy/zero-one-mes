#ifndef _DELETEPLANSUBJECTCONTROLLER_H_
#define _DELETEPLANSUBJECTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
//---
#include "../../domain/vo/deletePlanSubject/DeletePlanSubjectVO.h"
#include "../../domain/dto/deletePlanSubject/DeletePlanSubjectDTO.h"
#include "../../domain/query/deletePlanSubject/DeletePlanSubjectQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

// ɾ�����ݲ���Ҫ�Զ���JsonVO��ֻҪ����true��false���ɣ�ֱ��ʹ��ѧ����BaseJsonVO.h�ж����BooleanJsonVO����
// ɾ�����ݲ���ҪQuery������û�з�ҳ��ѯ������������Ĳ���������ɾ����ͨ��ǰ�����û��ڻ������������й�ѡ�õ���

class DeletePlanSubjectController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DeletePlanSubjectController)
public: // ����ӿ�
	/*
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("planSubject.op.deleteT"), deletePlanSubject, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/inspection-maintennace/delete-opration", deletePlanSubject, BODY_DTO(DeletePlanSubjectDTO::Wrapper, dto), execDeletePlanSubject(dto))

	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("planSubject.op.deleteOneToMany"), deletePlanSubjectOneToMany, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/inspection-maintennace/del-one-to-many", deletePlanSubjectOneToMany, BODY_DTO(DeletePlanSubjectOneToManyDTO::Wrapper, dto), execDeletePlanSubjectOneToMany(dto))
	*/
	/*
	//-------------��abf�����䣨ʾ����
	//��һ����
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteTemplate.summary.deleteUnique"), deleteUnique, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/delete-template/keyUnique", deleteUnique, BODY_DTO(DeleteTableUniqueDTO::Wrapper, dto), execDeleteUnique(dto))
	//��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteTemplate.summary.deleteShared"), deleteShared, BooleanJsonVO::Wrapper)
	API_HANDLER_ENDPOINT(API_M_DEL, "/delete-template/keyShared", deleteShared, BODY_DTO(DeleteTableSharedDTO::Wrapper, dto), execDeleteShared(dto))
	*/
	//----��abf��ɾ�����ƻ����ƻ��漰����Ŀ���ƻ��漰���豸��

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("deleteOP.summary.machiner"), deletePlanMachiner, BooleanJsonVO::Wrapper)
		API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/equipment-ledger/inspe-matain/delete-plan-machiner", deletePlanMachiner, BODY_DTO(DeleteMachinerDTO::Wrapper, dto), execDeletePlanMachiner(dto))

		API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("deleteOP.summary.subject"), deletePlanSubject, BooleanJsonVO::Wrapper)
		API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/equipment-ledger/inspe-matain/delete-plan-subject", deletePlanSubject, BODY_DTO(DeleteSubjectDTO::Wrapper, dto), execDeletePlanSubject(dto))
		//��ʱ������
		API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("deleteOP.summary.plan"), deletePlan, BooleanJsonVO::Wrapper)
		API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/equipment-ledger/inspe-matain/delete-plan", deletePlan, BODY_DTO(DeletePlanDTO::Wrapper, dto), execDeletePlan(dto))

		//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("machinery-plan.query-details.summary"), deletePlanQuery, DeletePlanQueryJsonVO::Wrapper)
		//API_HANDLER_ENDPOINT(API_M_GET, "/device-manage/delete-plan", deletePlanQuery, BODY_DTO(DeletePlanQuery::Wrapper, dto), execDeletePlanQuery(dto))

		//----�������ǿ��ŵĽӿ�
		//--------����һ�������������ǲ��Եĸ����ӿڲ���

		//1������plan���ɾ��ǰ��ѯ
		// ������/�����豸�ƻ��б�ӿ�����
		/*
		ENDPOINT_INFO(deletePlanQuery) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("deleteOP.summary.planDelete"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(DeletePlanQueryJsonVO);
		// ����������������
		API_DEF_ADD_QUERY_PARAMS(Int64, "plan_id", ZH_WORDS_GETTER("machinery-plan.field.plan-id"), 69, true);
		}
		// �����ѯ�豸�嵥�б�ӿڴ���
		//ENDPOINT(API_M_GET, "/device-manage/delete-plan-query", deletePlanQuery, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
		template<class T> static typename std::shared_ptr<Handler<T>> Z__ENDPOINT_HANDLER_GET_INSTANCE_deletePlanQuery(T* controller)
		{
			auto handler = std::static_pointer_cast<Handler<T>>(controller->getEndpointHandler("deletePlanQuery"));
			if (!handler)
			{
				handler = Handler<T>::createShared(controller, &T::Z__PROXY_METHOD_deletePlanQuery, nullptr);
				controller->setEndpointHandler("deletePlanQuery", handler);
			}
			return handler;
		}

		std::shared_ptr<oatpp::web::server::api::Endpoint::Info> Z__EDNPOINT_INFO_GET_INSTANCE_deletePlanQuery()
		{
			std::shared_ptr<oatpp::web::server::api::Endpoint::Info> info = getEndpointInfo("deletePlanQuery");
			if (!info)
			{
				info = oatpp::web::server::api::Endpoint::Info::createShared();
				setEndpointInfo("deletePlanQuery", info);
			}
			return info;
		}

		EndpointInfoBuilder Z__CREATE_ENDPOINT_INFO_deletePlanQuery = [this]()
			{
				auto info = Z__EDNPOINT_INFO_GET_INSTANCE_deletePlanQuery();
				info->name = "deletePlanQuery";
				info->path = ((m_routerPrefix != nullptr) ? m_routerPrefix + "/device-manage/delete-plan-query" : "/device-manage/delete-plan-query");
				info->method = "GET";
				auto __param_obj_authObject = ApiController::getDefaultAuthorizationHandler();
				if (__param_obj_authObject)
				{
					info->headers.add(oatpp::web::protocol::http::Header::AUTHORIZATION, oatpp::String::Class::getType());
					info->headers[oatpp::web::protocol::http::Header::AUTHORIZATION].description = __param_obj_authObject->getScheme();
					info->authorization = __param_obj_authObject->getScheme();
				}
				else
				{
					throw oatpp::web::protocol::http::HttpError(Status::CODE_500, "No authorization handler set up in controller before controller was added to router or swagger-doc.");
				}
				return info;
			};

		const std::shared_ptr<oatpp::web::server::api::Endpoint> Z__ENDPOINT_deletePlanQuery = createEndpoint(m_endpoints, Z__ENDPOINT_HANDLER_GET_INSTANCE_deletePlanQuery(this), Z__CREATE_ENDPOINT_INFO_deletePlanQuery);

		std::shared_ptr<oatpp::web::protocol::http::outgoing::Response> Z__PROXY_METHOD_deletePlanQuery(const std::shared_ptr<oatpp::web::protocol::http::incoming::Request>& __request)
		{
			const auto& queryParams = __request->getQueryParameters();
			auto __param_str_val_authObject = __request->getHeader(oatpp::web::protocol::http::Header::AUTHORIZATION); std::shared_ptr<oatpp::web::server::handler::AuthorizationObject> __param_aosp_val_authObject = ApiController::handleDefaultAuthorization(__param_str_val_authObject);
			std::shared_ptr<CustomerAuthorizeObject> authObject = std::static_pointer_cast<std::shared_ptr<CustomerAuthorizeObject>::element_type>(__param_aosp_val_authObject);
			return deletePlanQuery(queryParams, authObject);
		}

		std::shared_ptr<oatpp::web::protocol::http::outgoing::Response> deletePlanQuery(const QueryParams& queryParams, const std::shared_ptr<CustomerAuthorizeObject>& authObject)

		{

		// ��������ģ��
		//API_HANDLER_QUERY_PARAM(query_delete_plan, DeletePlanQuery, queryParams);
			auto query_delete_plan = DeletePlanQuery::createShared();
			for (auto& param : queryParams.getAll()) {
				auto data = param.second.getMemoryHandle().get();
				auto typeval = query_delete_plan[param.first.toString()].getValueType();
				if (typeval == oatpp::data::mapping::type::__class::String::getType()) query_delete_plan[param.first.toString()] = oatpp::String(URIUtil::urlDecode(data->c_str()));
				else if (typeval == oatpp::data::mapping::type::__class::Int32::getType()) query_delete_plan[param.first.toString()] = oatpp::Int32(stoi(*data));
				else if (typeval == oatpp::data::mapping::type::__class::UInt32::getType()) query_delete_plan[param.first.toString()] = oatpp::UInt32(stoi(*data));
				else if (typeval == oatpp::data::mapping::type::__class::Int64::getType()) query_delete_plan[param.first.toString()] = oatpp::Int64(stoll(*data));
				else if (typeval == oatpp::data::mapping::type::__class::UInt64::getType()) query_delete_plan[param.first.toString()] = oatpp::UInt64(stoull(*data));
				else if (typeval == oatpp::data::mapping::type::__class::Float32::getType()) query_delete_plan[param.first.toString()] = oatpp::Float32(stof(*data));
				else if (typeval == oatpp::data::mapping::type::__class::Float64::getType()) query_delete_plan[param.first.toString()] = oatpp::Float64(stod(*data));
				else if (typeval == oatpp::data::mapping::type::__class::Boolean::getType()) query_delete_plan[param.first.toString()] = oatpp::Boolean(*data == "true" || *data == "1");
			};

		// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execDeletePlanQuery(query_delete_plan));
		return createDtoResponse(Status::CODE_200, execDeletePlanQuery(query_delete_plan));


		}
		*/

		// 2��dv_check_subjectɾ��������ѯ


		//// ������/�����豸�ƻ��б�ӿ�����
		//ENDPOINT_INFO(deletePlanQuery)
		//{
		//	// ����ӿڱ���
		//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("machinery-plan.query-details.summary"));
		//    // ����Ĭ����Ȩ����
		//    API_DEF_ADD_AUTH();
		//    // ������Ӧ������ʽ
		//    API_DEF_ADD_RSP_JSON_WRAPPER(DeletePlanQueryJsonVO);
		//    // ����������������
		//    API_DEF_ADD_QUERY_PARAMS(String, "plan_id", ZH_WORDS_GETTER("machinery-plan.field.plan-id"), "65", true);
		//}
		//// �����ѯ�豸�嵥�б�ӿڴ���
		//ENDPOINT(API_M_GET, "/device-manage/delete-plan-query", deletePlanQuery, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) 
		//{
		//// ��������ģ��
		//API_HANDLER_QUERY_PARAM(queryPlan, DeletePlanQueryJsonVO, queryParams);
		//// ����ִ�к�����Ӧ���
		//API_HANDLER_RESP_VO(execDeletePlanQuery(queryPlan));
		//}

		//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("deleteOP.summary.plan"), deletePlan, BooleanJsonVO::Wrapper)
		//API_HANDLER_ENDPOINT(API_M_DEL, "/device-manage/delete-plan", deletePlan, BODY_DTO(DeletePlanDTO::Wrapper, dto), execDeletePlan(dto))
private: // ����ӿ�ִ�к���

	// ǰ�˷�������dto���������ִ��
	/*
	BooleanJsonVO::Wrapper execDeletePlanSubject(const DeletePlanSubjectDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeletePlanSubjectOneToMany(const DeletePlanSubjectOneToManyDTO::Wrapper& dto);
	*/

	/*
	//----------------��abf�����䣨ʾ����
	BooleanJsonVO::Wrapper execDeleteUnique(const DeleteTableUniqueDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeleteShared(const DeleteTableSharedDTO::Wrapper& dto);
	//----��abf��ɾ�����ƻ����ƻ��漰����Ŀ���ƻ��漰���豸��
	*/
	BooleanJsonVO::Wrapper execDeletePlanMachiner(const DeleteMachinerDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeletePlanSubject(const DeleteSubjectDTO::Wrapper& dto);
	BooleanJsonVO::Wrapper execDeletePlan(const DeletePlanDTO::Wrapper& dto);
	DeletePlanQueryJsonVO::Wrapper execDeletePlanQuery(const DeletePlanQuery::Wrapper& query);


	//MachineryPlanDetailsJsonVO::Wrapper execQueryMachineryPlanDetails(const MachineryPlanDetailsQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_REMOVEDEVICECONTROLLER_H_
