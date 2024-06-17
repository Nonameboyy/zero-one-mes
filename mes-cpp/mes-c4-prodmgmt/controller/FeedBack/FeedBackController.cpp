
#include "stdafx.h"
#include "FeedBackController.h"
#include "../../service/FeedBack/FeedBackService.h"
#include "../ApiDeclarativeServicesHelper.h"

FeedBackPageJsonVO::Wrapper FeedBackController::execQueryFeedBack(const FeedBackQuery::Wrapper& query)
{
	// 定义一个Service
	FeedBackService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FeedBackPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
