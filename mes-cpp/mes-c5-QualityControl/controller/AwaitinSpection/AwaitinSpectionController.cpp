#include "stdafx.h"
#include "AwaitinSpectionController.h"
#include "../../service/AwaitinSpection/AwaitinSpectionService.h"
#include "../ApiDeclarativeServicesHelper.h"

AwaitinSpectionPageJsonVO::Wrapper AwaitinSpectionController::execQueryAwaitInspection(const AwaitinSpectionQuery::Wrapper& query, const PayloadDTO& payload)
{
	AwaitinSpectionService service;
	auto res = service.listAll(query);
	auto jvo = AwaitinSpectionPageJsonVO::createShared();
	jvo->success(res);
	return jvo;
}