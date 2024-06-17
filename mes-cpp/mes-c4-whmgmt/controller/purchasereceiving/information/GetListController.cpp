#include "GetListController.h"


GetListPageJsonVO::Wrapper GetListController::execQueryGetList(const GetListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GetListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
