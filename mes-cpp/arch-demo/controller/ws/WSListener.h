#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/09 21:53:07

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
#ifdef HTTP_SERVER_DEMO

#ifndef _WSLISTENER_H_
#define _WSLISTENER_H_
#include "oatpp-websocket/WebSocket.hpp"
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>

/**
 * WebSocket������,���������WebSocket�¼�
 */
class WSListener : public oatpp::websocket::WebSocket::Listener
{
private:
	static constexpr const char* TAG = "Server_WSListener";
	// ��Ϣ������
	oatpp::data::stream::BufferOutputStream m_messageBuffer;
	// �û�ID
	std::string id;
	// �����������û��б�
	std::map<std::string, const WebSocket*>* conn_pool;
public:
	// ��ȡID
	const std::string& getId();
	// �����ʼ��
	WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool);
	// ��ping֡�ϵ���
	void onPing(const WebSocket& socket, const oatpp::String& message) override;
	// ��pong֡�ϵ���
	void onPong(const WebSocket& socket, const oatpp::String& message) override;
	// ��close֡�ϵ���
	void onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message) override;
	// ��ÿ����Ϣ֡�ϵ��á����һ����Ϣ���ٴε��ã�size����0��ָ����Ϣ����
	void readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size) override;
};

#endif // !_WSLISTENER_H_

#endif // HTTP_SERVER_DEMO