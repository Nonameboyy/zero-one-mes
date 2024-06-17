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
// �ʼ����ʹ����Ҫ���ͷ�ļ�
#include "Macros.h"
#include "NacosClient.h"
#include "EmailSender.h"

#include "gtest/gtest.h"

/**
 * ����һ�����Լо��࣬���ڹ����ʼ����Ͷ��󴴽�
 */
class MailTest : public testing::Test {
protected:
	void SetUp() override
	{
		/** ����һ��Nacos�ͻ��˶������ڻ�ȡ���� */
		NacosClient _ns(TEST_NS_ADDR, TEST_NS_NAMESPACE);
		/** ��ȡ�������ݽڵ� */
		auto _keyConfig = _ns.getConfig("key-config.yaml");
		/** ����ͻ��˶��� */
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
	// �ʼ����Ϳͻ��˶���
	EmailSender* emailSender = nullptr;
	// �����ʼ�����
	std::string topic = ZH_WORDS_GETTER("mail.topic");
};

// ���Է����ı�����
TEST_F(MailTest, SendText) {
	std::string body = ZH_WORDS_GETTER("mail.body2");
	emailSender->addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender->setEmailContent(topic, body);
	ASSERT_EQ(emailSender->send(), true);
}

// ���Է���Html����
TEST_F(MailTest, SendHtml) {
	std::string body = ZH_WORDS_GETTER("mail.body1");
	emailSender->addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender->setEmailContent(topic, body);
	ASSERT_EQ(emailSender->send(), true);
}

// ���Է��͸���
TEST_F(MailTest, SendAttach) {
	std::string body = ZH_WORDS_GETTER("mail.body1");
	emailSender->addRecvEmailAddr("2069682479@qq.com", "awei");
	emailSender->setEmailContent(topic, body);
	emailSender->addAttachment("/home/file/1.zip");
	ASSERT_EQ(emailSender->send(), true);
}
