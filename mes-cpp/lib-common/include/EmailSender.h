#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/24 20:30:25

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
#ifndef _EMAILSENDER_H_
#define _EMAILSENDER_H_

#include <string>
#include <vector>

/**
 * 书写一个邮件发送工具类
 */
class EmailSender
{
public:
	//************************************
	// Method:    EmailSender
	// FullName:  EmailSender::EmailSender
	// Access:    public 
	// Returns:   
	// Description: 构造初始化
	// Parameter: const std::string& smtp_server 邮件服务器，如smtp.163.com
	// Parameter: const int smtp_port 服务器端口，如25
	// Parameter: const std::string& password 授权密码
	// Parameter: const std::string& from_email 邮件发送人邮箱地址
	// Parameter: const std::string& from_name  邮件发送人名称，默认值No-Reply
	// Parameter: const std::string& charset 内容编码，默认值gb2312
	//************************************
	EmailSender(
		const std::string& smtp_server,
		const int smtp_port,
		const std::string& password,
		const std::string& from_email,
		const std::string& from_name = "No-Reply",
		const std::string& charset = "gb2312");
	~EmailSender();
	// 设置邮件主题和内容，可以是HTML格式或纯文本
	void setEmailContent(const std::string& subject = "", const std::string& body = "");
	// 添加邮件接收人
	void addRecvEmailAddr(const std::string& email_addr, const std::string& name = "");
	// 添加邮件抄送人
	void addCcEmailAddr(const std::string& email_addr, const std::string& name = "");
	// 添加附件
	void addAttachment(const std::string& filename);
	// 执行发送
	bool send();
	// 获取编码
	std::string getCharset() const;
	// 设置编码
	void setCharset(std::string val);
	// 启用SSL协议
	void enableSSL();
	// 禁用SSL协议
	void disableSSL();
private:
	// smtp服务器
	std::string m_smtp_url;
	// 内容编码，默认gb2312
	std::string m_charset;
	// 邮件发送人 key 邮件地址 val 发送人名称
	std::pair<std::string, std::string> m_from;
	// 邮件服务器授权密码
	std::string m_password;
	// 邮件接收人 key 邮件地址 val 接收人名称
	std::vector<std::pair<std::string, std::string>> m_recvs;
	// 邮件抄送人 key 邮件地址 val 抄送人名称
	std::vector<std::pair<std::string, std::string>> m_ccs;
	// 邮件主题
	std::string m_email_subject;
	// 邮件内容
	std::string m_email_body;
	// 邮件附件文件列表（文件的绝对或相对路径）
	std::vector<std::string> m_attachments;
	// 回调函数，将MIME协议的拼接的字符串由libcurl发出
	static size_t payloadSource(void* ptr, size_t size, size_t nmemb, void* stream);
	// 创建邮件MIME内容
	std::string generateMimeMessage();
	// 获取附件文件名
	void getFileName(const std::string& path, std::string& filename);
	// 获取附件文件类型  
	void getFileContentType(const std::string& path, std::string& contentType);
};

#endif // !_EMAILSENDER_H_