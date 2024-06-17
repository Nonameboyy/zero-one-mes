/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 21:03:54

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
// 邮件组件使用需要相关头文件
#include "Macros.h"
#include "NacosClient.h"
#include "EmailSender.h"

#include "gtest/gtest.h"

/**
 * 定义一个测试夹具类，用于管理邮件发送对象创建
 */
class MailTest : public testing::Test {
protected:
	void SetUp() override
	{
		/** 定义一个Nacos客户端对象，用于获取配置 */
		NacosClient _ns(TEST_NS_ADDR, TEST_NS_NAMESPACE);
		/** 读取配置数据节点 */
		auto _keyConfig = _ns.getConfig("key-config.yaml");
		/** 定义客户端对象 */
		YamlHelper _yh;
		this->emailSender = new EmailSender(
			_yh.getString(&_keyConfig, "spring.mail.host"),
			std::stoi(_yh.getString(&_keyConfig, "spring.mail.port")),
			_yh.getString(&_keyConfig, "spring.mail.password"),
			_yh.getString(&_keyConfig, "spring.mail.username"),
			_yh.getString(&_keyConfig, "spring.mail.properties.name"));
		this->emailSender->setCharset("utf8");
	}
	void TearDown() override
	{
		if (emailSender)
		{
			delete emailSender;
			emailSender = nullptr;
		}
	}
	// 邮件发送客户端对象
	EmailSender* emailSender = nullptr;
	// 测试邮件主题
	std::string topic = ZH_WORDS_GETTER("mail.topic");
};

// 测试发送文本内容
TEST_F(MailTest, SendText) {
	std::string body = ZH_WORDS_GETTER("mail.body2");
	emailSender->addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender->setEmailContent(topic, body);
	ASSERT_EQ(emailSender->send(), true);
}

// 测试发送Html内容
TEST_F(MailTest, SendHtml) {
	std::string body = ZH_WORDS_GETTER("mail.body1");
	emailSender->addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender->setEmailContent(topic, body);
	ASSERT_EQ(emailSender->send(), true);
}

// 测试发送附件
TEST_F(MailTest, SendAttach) {
	std::string body = ZH_WORDS_GETTER("mail.body1");
	emailSender->addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender->setEmailContent(topic, body);
	emailSender->addAttachment("/home/file/1.zip");
	ASSERT_EQ(emailSender->send(), true);
}
