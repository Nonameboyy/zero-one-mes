#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/user/UserQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/user/UserVO.h"
#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class UserController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(UserController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAllUser) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("user.query-all.summary"), UserPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("user.field.nickname"), "li ming", true);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/user/query-all", queryAllUser, UserQuery, executeQueryAll(query));

	// �����޸��û���Ϣ�˵�����
	ENDPOINT_INFO(modifyUser) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("user.modify-user.summary"), StringJsonVO::Wrapper);
		// �����޸Ĳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(Int32, "age", ZH_WORDS_GETTER("user.field.age"), 100, false);
		API_DEF_ADD_QUERY_PARAMS(String, "nickname", ZH_WORDS_GETTER("user.field.nickname"), "feifei", false);
		// ���������������ʽ������ѡ���ϴ��ļ�
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
	}
	// �����޸��û���Ϣ�˵㴦��ע�⣺�˷�ʽֻ֧�ֵ��ļ��ϴ������Ҹ����ֶβ��Ǻܶ�ĳ���ʹ�ã�
	ENDPOINT(API_M_POST, "/user/modify-user", modifyUser, BODY_STRING(String, fileBody), QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(dto, UserDTO, qps);
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(executeModifyUser(fileBody, dto));
	}

	// �����ѯ�û��˵��ӿڶ˵�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("user.query-menu.summary"), queryMenu, MenuJsonVO::Wrapper);
	// �����ѯ�û��˵��ӿڶ˵㴦��
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/user/query-menu", queryMenu, executeQueryMenu(authObject->getPayload()))
private:
	// ��ѯ����
	UserPageJsonVO::Wrapper executeQueryAll(const UserQuery::Wrapper& userQuery);
	// �޸��û���Ϣ
	StringJsonVO::Wrapper executeModifyUser(const String& fileBody, const UserDTO::Wrapper& dto);
	// ���Բ˵�
	MenuJsonVO::Wrapper executeQueryMenu(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_