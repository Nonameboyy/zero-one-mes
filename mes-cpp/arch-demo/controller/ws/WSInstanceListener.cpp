/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/10 21:58:06

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

#ifdef HTTP_SERVER_DEMO
#include "WSInstanceListener.h"
#include "WSListener.h"
#include <memory>

std::atomic<v_int32> WSInstanceListener::SOCKETS(0);

void WSInstanceListener::onAfterCreate(const WebSocket& socket, const std::shared_ptr<const ParameterMap>& params)
{
	// ��ȡ�ͻ���ID
	std::string id = params->at("id")->c_str();
	// �жϿͻ��˶����Ƿ����
	std::lock_guard<std::mutex> guard(instance_mutex);
	if (conn_pool.find(id) != conn_pool.end()) {
		// �رվܾ�����
		socket.sendClose(9999, u8"reason id has been used");
		OATPP_LOGD(TAG, "New Incoming Connection. Connection has been refuse.");
		return;
	}

	// ��ӵ����ӳ���
	conn_pool.insert(std::make_pair(id, &socket));
	OATPP_LOGD(TAG, "client(%s): open connection", id.c_str());

	// ������������
	SOCKETS++;
	OATPP_LOGD(TAG, "New Incoming Connection. Connection count=%d", SOCKETS.load());

	// �����Ϣ���������
	socket.setListener(std::make_shared<WSListener>(id, &conn_pool));
}

void WSInstanceListener::onBeforeDestroy(const WebSocket& socket)
{
	auto peer = std::static_pointer_cast<WSListener>(socket.getListener());
	if (peer)
	{
		// ��ȡ�ͻ���ID
		std::string id = peer->getId();

		// ����ͻ����Ƴ�
		OATPP_LOGD(TAG, "client(%s): close connection", id.c_str());

		// �����Ӷ����map���Ƴ�
		std::lock_guard<std::mutex> guard(instance_mutex);
		conn_pool.erase(id);
		socket.setListener(nullptr);

		// ������������
		SOCKETS--;
		OATPP_LOGD(TAG, "Connection closed. Connection count=%d", SOCKETS.load());
	}
}

#endif // HTTP_SERVER_DEMO