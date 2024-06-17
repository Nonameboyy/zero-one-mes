#include "stdafx.h"
#include "GetAllDetailsController.h"
#include "../../service/warehouse/GetAllDetailsService.h"
#include "../ApiDeclarativeServicesHelper.h"

GetAllDetailsJsonVO::Wrapper GetAllDetailsController::execQueryGetAllDetails(const GetAllDetailsQuery::Wrapper& query, const PayloadDTO& payload)
{
    auto jvo = GetAllDetailsJsonVO::createShared();
	GetAllDetailsService service;
	auto result = service.finddetails(query);
	jvo->success(result);
	return jvo;
}