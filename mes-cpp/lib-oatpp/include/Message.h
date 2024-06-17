#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:22:57

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
#ifndef _MESSAGE_
#define _MESSAGE_

#include "ResultStatus.h"

/**
 * ����״̬��ʾ��Ϣ
 */
#ifdef LINUX
#define RS_UNAUTHORIZED ResultStatus("no login or token expired", 401)
#define RS_FORBIDDEN ResultStatus("no permissions", 403)
#define RS_SERVER_ERROR ResultStatus("server error", 9994)
#define RS_PARAMS_INVALID ResultStatus("uploading parameters are abnormal", 9995)
#define RS_CONTENT_TYPE_ERR ResultStatus("contenttype error", 9996)
#define RS_API_UN_IMPL ResultStatus("the interface is not implemented yet", 9997)
#define RS_SERVER_BUSY ResultStatus("busy server", 9998)
#define RS_FAIL ResultStatus("the operation failure", 9999)
#define RS_SUCCESS ResultStatus("operation is successful")
#else
#define RS_UNAUTHORIZED ResultStatus(u8"��δ��¼��TOKEN�Ѿ�����", 401)
#define RS_FORBIDDEN ResultStatus(u8"û�����Ȩ��", 403)
#define RS_SERVER_ERROR ResultStatus(u8"����������", 9994)
#define RS_PARAMS_INVALID ResultStatus(u8"�ϴ������쳣", 9995)
#define RS_CONTENT_TYPE_ERR ResultStatus(u8"ContentType����", 9996)
#define RS_API_UN_IMPL ResultStatus(u8"�ӿ���δʵ��", 9997)
#define RS_SERVER_BUSY ResultStatus(u8"��������æ", 9998)
#define RS_FAIL ResultStatus(u8"����ʧ��", 9999)
#define RS_SUCCESS ResultStatus(u8"�����ɹ�")
#endif

#endif // !_MESSAGE_