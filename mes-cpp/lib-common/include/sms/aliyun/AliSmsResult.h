#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/25 16:10:25

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
#ifndef _ALISMSRESULT_H_
#define _ALISMSRESULT_H_
#include <string>

/**
 * 发送消息响应结果
 */
class AliSmsResult
{
private:
	/**
	 * 请求状态码。
	 * 返回OK代表请求成功。
	 * 其他错误码，API错误码请参见:https://help.aliyun.com/document_detail/101346.html
	 */
	std::string code;
	/**
	 * 状态码的描述。
	 */
	std::string message;
	/**
	 * 发送回执ID。
	 * 可根据发送回执ID在接口QuerySendDetails中查询具体的发送状态。
	 */
	std::string bizId;
	/**
	 * 请求ID。
	 */
	std::string requestId;
public:
	std::string Code() const { return code; }
	void Code(std::string val) { code = val; }
	std::string Message() const { return message; }
	void Message(std::string val) { message = val; }
	std::string BizId() const { return bizId; }
	void BizId(std::string val) { bizId = val; }
	std::string RequestId() const { return requestId; }
	void RequestId(std::string val) { requestId = val; }
};

#endif // !_ALISMSRESULT_H_