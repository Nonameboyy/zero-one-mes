#include "stdafx.h"
#include "DetailsPageController.h"
#include "../../service/warehouse/DetailsPageService.h"
#include "../ApiDeclarativeServicesHelper.h"



DetailsPageJsonVO::Wrapper DetailsPageController::execQueryDetailsPage(const DetailsPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	DetailsPageService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = DetailsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}