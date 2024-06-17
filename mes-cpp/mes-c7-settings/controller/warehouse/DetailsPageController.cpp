#include "stdafx.h"
#include "DetailsPageController.h"
#include "../../service/warehouse/DetailsPageService.h"
#include "../ApiDeclarativeServicesHelper.h"



DetailsPageJsonVO::Wrapper DetailsPageController::execQueryDetailsPage(const DetailsPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	DetailsPageService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DetailsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}