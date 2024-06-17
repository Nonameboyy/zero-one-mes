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

// 注意：用到FastDfs的地方都要在最后在导入DFS的头文件
#include "FastDfsClient.h"

// 定义一个临时变量用于存储上次上传成功后的文件field名称
std::string tmpField = "";

/**
 * 创建一个测试夹具，用于管理Dfs客户端对象创建过程
 */
class FastDfsTest : public testing::Test {
protected:
	void SetUp() override
	{
		// 定义一个Nacos客户端对象，用于获取配置
		NacosClient ns(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		// 读取配置数据节点
		auto thirdServerConfig = ns.getConfig("third-services.yaml");
		// 从Nacos配置中心获取FastDFS客户端配置数据
		std::string config = ns.getConfigText("client.conf");
		// 定义客户端对象
		this->client = new FastDfsClient(config, false);
		// 设置一个文件上传地址
		this->filename = "/home/file/1.zip";
#else
		// 读取配置数据节点
		auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
		// +FastDFS客户端配置数据
		std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
		std::string ip = ipPort.substr(0, ipPort.find(":"));
		int port = stoi(ipPort.substr(ipPort.find(":") + 1));
		// 设置客户端对象
		this->client = new FastDfsClient(ip, port);
		// 设置一个文件上传地址
		this->filename = "E:/Images/20141011112401959.jpg.source.jpg";
#endif
		// 设置url前缀
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
	// DFS客户端连接对象
	FastDfsClient* client = nullptr;
	// 文件下载地址前缀
	std::string urlPrefix = "";
	// 声明一个上传文件的文件名
	std::string filename = "";
};

// 测试文件上传
TEST_F(FastDfsTest, Upload) {
	tmpField = client->uploadFile(filename);
	ASSERT_NE(tmpField, "");
	// 输出文件下载地址
	std::string downloadUrl = urlPrefix + tmpField;
	std::cout << "download url: " << downloadUrl << std::endl;
}

// 测试文件下载
TEST_F(FastDfsTest, Download) {
	if (tmpField.empty()) return;
	std::string path = "./public/fastdfs";
	std::string fullPath = client->downloadFile(tmpField, &path);
	ASSERT_NE(fullPath, "");
	std::cout << "download savepath is : " << fullPath << std::endl;
}

// 测试文件删除
TEST_F(FastDfsTest, Delete) {
	if (tmpField.empty()) return;
	bool res = client->deleteFile(tmpField);
	ASSERT_EQ(res, true);
}

#endif // USE_DFS