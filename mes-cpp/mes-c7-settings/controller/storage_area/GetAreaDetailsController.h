#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _GETAREADETAILS_CONTROLLER_
#define _GETAREADETAILS_CONTROLLER_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/storage_area/GetAreaDetailsQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/storage_area/GetAreaDetailsVO.h"


using namespace oatpp;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class GetAreaDetailsController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(GetAreaDetailsController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryGetAreaDatails) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("area.get.summary"), GetAreaDetailsJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("user.field.nickname"), "li ming", true);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/settings/area/get", queryGetAreaDatails, GetAreaDetailsQuery, executeQueryAll(query));
private:
	// ��ѯ����
	GetAreaDetailsPageJsonVO::Wrapper executeQueryAll(const GetAreaDetailsQuery::Wrapper& userQuery);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_