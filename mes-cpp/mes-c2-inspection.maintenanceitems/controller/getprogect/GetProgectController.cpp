/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/18 20:16:53

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "stdafx.h"
#include "GetProgectController.h"
#include "../../service/getprogect/GetProgectService.h"
#include "GetProgectController.h"
#include "../ApiDeclarativeServicesHelper.h"

GetProgectPageJsonVO::Wrapper GetProgectController::execGetProgect(const GetProgectQuery::Wrapper& query)
{
	
	// ����һ��Service
	GetProgectService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetProgectPageJsonVO::createShared();
	jvo->success(result);/////////////////result GetProgectPageDTO jvo GetProgectPageJsonVO
	return jvo;
}

GetProgectDetailJsonVO::Wrapper GetProgectController::execProgectDetail(const GetProgectDetailQuery::Wrapper& query)//uint64_t��UInt64
{

	// ����һ��Service
	GetProgectService service;
	// ��ѯ����
	uint64_t id = query->pId;
	auto result = service.listSome(query);
	// ��Ӧ���
	auto jvo = GetProgectDetailJsonVO::createShared();
	jvo->success(result);///////////////result GetProgectDetailDTO jvo GetProgectDetailJsonVO
	
	return jvo;
}

