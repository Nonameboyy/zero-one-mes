
#include "stdafx.h"
#include "FeedBackController.h"
#include "../../service/FeedBack/FeedBackService.h"
#include "../ApiDeclarativeServicesHelper.h"

FeedBackPageJsonVO::Wrapper FeedBackController::execQueryFeedBack(const FeedBackQuery::Wrapper& query)
{
	// ����һ��Service
	FeedBackService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FeedBackPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
