/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/09 11:01:27

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
#ifdef USE_DFS
#include <iostream>
#include "Macros.h"
#include "NacosClient.h"
#include "gtest/gtest.h"

// ע�⣺�õ�FastDfs�ĵط���Ҫ������ڵ���DFS��ͷ�ļ�
#include "FastDfsClient.h"

// ����һ����ʱ�������ڴ洢�ϴ��ϴ��ɹ�����ļ�field����
std::string tmpField = "";

/**
 * ����һ�����Լоߣ����ڹ���Dfs�ͻ��˶��󴴽�����
 */
class FastDfsTest : public testing::Test {
protected:
	void SetUp() override
	{
		// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
		NacosClient ns(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		// ��ȡ�������ݽڵ�
		auto thirdServerConfig = ns.getConfig("third-services.yaml");
		// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
		std::string config = ns.getConfigText("client.conf");
		// ����ͻ��˶���
		this->client = new FastDfsClient(config, false);
		// ����һ���ļ��ϴ���ַ
		this->filename = "/home/file/1.zip";
#else
		// ��ȡ�������ݽڵ�
		auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
		// +FastDFS�ͻ�����������
		std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
		std::string ip = ipPort.substr(0, ipPort.find(":"));
		int port = stoi(ipPort.substr(ipPort.find(":") + 1));
		// ���ÿͻ��˶���
		this->client = new FastDfsClient(ip, port);
		// ����һ���ļ��ϴ���ַ
		this->filename = "E:/Images/20141011112401959.jpg.source.jpg";
#endif
		// ����urlǰ׺
		this->urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	}
	void TearDown() override
	{
		if (client)
		{
			delete client;
			client = nullptr;
		}
	}
	// DFS�ͻ������Ӷ���
	FastDfsClient* client = nullptr;
	// �ļ����ص�ַǰ׺
	std::string urlPrefix = "";
	// ����һ���ϴ��ļ����ļ���
	std::string filename = "";
};

// �����ļ��ϴ�
TEST_F(FastDfsTest, Upload) {
	tmpField = client->uploadFile(filename);
	ASSERT_NE(tmpField, "");
	// ����ļ����ص�ַ
	std::string downloadUrl = urlPrefix + tmpField;
	std::cout << "download url: " << downloadUrl << std::endl;
}

// �����ļ�����
TEST_F(FastDfsTest, Download) {
	if (tmpField.empty()) return;
	std::string path = "./public/fastdfs";
	std::string fullPath = client->downloadFile(tmpField, &path);
	ASSERT_NE(fullPath, "");
	std::cout << "download savepath is : " << fullPath << std::endl;
}

// �����ļ�ɾ��
TEST_F(FastDfsTest, Delete) {
	if (tmpField.empty()) return;
	bool res = client->deleteFile(tmpField);
	ASSERT_EQ(res, true);
}

#endif // USE_DFS