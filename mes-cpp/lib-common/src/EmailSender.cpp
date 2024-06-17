/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/24 20:31:06

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
#include "pch.h"
#include "../include/EmailSender.h"
#ifdef LINUX
#include <curl/curl.h>
#endif
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>

static const std::string malil_base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static inline bool isMailBase64(unsigned char c)
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string mailBase64Encode(unsigned char const* bytes_to_encode, unsigned int in_len)
{
	std::string ret;
	int i = 0, j = 0;
	unsigned char char_array_3[3], char_array_4[4];
	while (in_len--)
	{
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3)
		{
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;
			for (i = 0; (i < 4); i++)
				ret += malil_base64_chars[char_array_4[i]];
			i = 0;
		}
	}
	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';
		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;
		for (j = 0; (j < i + 1); j++)
			ret += malil_base64_chars[char_array_4[j]];
		while ((i++ < 3))
			ret += '=';
	}
	return ret;
}

std::string mailBase64Decode(std::string const& encoded_string)
{
	int in_len = encoded_string.size();
	int i = 0, j = 0, in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;
	while (in_len-- && (encoded_string[in_] != '=') && isMailBase64(encoded_string[in_]))
	{
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i < 4; i++)
				char_array_4[i] = malil_base64_chars.find(char_array_4[i]);
			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}
	if (i)
	{
		for (j = i; j < 4; j++)
			char_array_4[j] = 0;
		for (j = 0; j < 4; j++)
			char_array_4[j] = malil_base64_chars.find(char_array_4[j]);
		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
		for (j = 0; (j < i - 1); j++)
			ret += char_array_3[j];
	}
	return ret;
}

EmailSender::EmailSender(const std::string& smtp_server,
	const int smtp_port,
	const std::string& password,
	const std::string& from_email,
	const std::string& from_name /*= "No-Reply"*/,
	const std::string& charset/* = "gb2312"*/)
{
	// 初始化设置
	m_smtp_url = "smtp://" + smtp_server + ':' + std::to_string(smtp_port);
	m_from = std::make_pair(from_email, from_name);
	m_password = password;
	setCharset(charset);
}

EmailSender::~EmailSender()
{
	m_recvs.clear();
	m_ccs.clear();
	m_attachments.clear();
}

void EmailSender::setEmailContent(const std::string& subject, const std::string& body)
{
	m_email_subject = subject;
	m_email_body = body;
}

void EmailSender::addRecvEmailAddr(const std::string& email_addr, const std::string& name)
{
	m_recvs.push_back(std::make_pair(email_addr, name));
}

void EmailSender::addCcEmailAddr(const std::string& email_addr, const std::string& name)
{
	m_ccs.push_back(std::make_pair(email_addr, name));
}

void EmailSender::addAttachment(const std::string& filename)
{
	m_attachments.push_back(filename);
}

bool EmailSender::send()
{
#ifdef LINUX
	CURL* curl;
	CURLcode res = CURLE_OK;
	curl = curl_easy_init();
	bool ret = false;
	if (curl)
	{
		/* This is the URL for your mailserver */
		curl_easy_setopt(curl, CURLOPT_URL, m_smtp_url.c_str());

		/* Login smtp server to verify */
		curl_easy_setopt(curl, CURLOPT_USERNAME, m_from.first.c_str());
		curl_easy_setopt(curl, CURLOPT_PASSWORD, m_password.c_str());

		/* If you want to connect to a site who isn't using a certificate that is
		 * signed by one of the certs in the CA bundle you have, you can skip the
		 * verification of the server's certificate. This makes the connection
		 * A LOT LESS SECURE.
		 *
		 * If you have a CA cert for the server stored someplace else than in the
		 * default bundle, then the CURLOPT_CAPATH option might come handy for you.
		 */
#ifdef SKIP_PEER_VERIFICATION  
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif  

		/* If the site you're connecting to uses a different host name that what
		 * they have mentioned in their server certificate's commonName (or
		 * subjectAltName) fields, libcurl will refuse to connect. You can skip
		 * this check, but this will make the connection less secure.
		 */
#ifdef SKIP_HOSTNAME_VERIFICATION  
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif  
		/* Note that this option isn't strictly required, omitting it will result
		 * in libcurl sending the MAIL FROM command with empty sender data. All
		 * autoresponses should have an empty reverse-path, and should be directed
		 * to the address in the reverse-path which triggered them. Otherwise,
		 * they could cause an endless loop. See RFC 5321 Section 4.5.5 for more details.
		 */
		std::string from_email_addr = '<' + m_from.first + '>';
		curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_email_addr.c_str());

		/* Add two recipients, in this particular case they correspond to the
		 * To: and Cc: addressees in the header, but they could be any kind of recipient.
		 */
		struct curl_slist* recipients = NULL;
		for (auto& email_pair : m_recvs)
		{
			std::string email_addr = '<' + email_pair.first + '>';
			recipients = curl_slist_append(recipients, email_addr.c_str());
		}
		for (auto& email_pair : m_ccs)
		{
			std::string email_addr = '<' + email_pair.first + '>';
			recipients = curl_slist_append(recipients, email_addr.c_str());
		}
		curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

		// 准备消息内容
		std::stringstream stream;
		stream.str(generateMimeMessage().c_str());
		stream.flush();

		/* We're using a callback function to specify the payload (the headers and
		 * body of the message). You could just use the CURLOPT_READDATA option to
		 * specify a FILE pointer to read from.
		 */
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, &EmailSender::payloadSource);
		curl_easy_setopt(curl, CURLOPT_READDATA, (void*)&stream);
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

		/* Since the traffic will be encrypted, it is very useful to turn on debug
		 * information within libcurl to see what is happening during the transfer
		 */
#ifdef _DEBUG
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
#else
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
#endif


		/* Send the message */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		else
			ret = true;

		/* Free the list of recipients */
		curl_slist_free_all(recipients);
		/* Always cleanup */
		curl_easy_cleanup(curl);
	}
	return ret;
#else
	std::cerr << "windows not support send mail !!!" << std::endl;
	return false;
#endif
}

std::string EmailSender::getCharset() const
{
	return m_charset;
}

void EmailSender::setCharset(std::string val)
{
	m_charset = val;
}

void EmailSender::enableSSL()
{
	size_t pos = m_smtp_url.find("smtp://");
	if (pos != std::string::npos)
	{
		m_smtp_url.replace(pos, 4, "smtps");
	}
}

void EmailSender::disableSSL()
{
	size_t pos = m_smtp_url.find("smtps://");
	if (pos != std::string::npos)
	{
		m_smtp_url.replace(pos, 5, "smtp");
	}
}

size_t EmailSender::payloadSource(void* ptr, size_t size, size_t nmemb, void* stream)
{
	size_t num_bytes = size * nmemb;
	char* data = (char*)ptr;
	std::stringstream* strstream = (std::stringstream*)stream;
	strstream->read(data, num_bytes);
	return strstream->gcount();
}

std::string EmailSender::generateMimeMessage()
{
	std::string message;
	// 发送人
	message += "From: ";
	message += m_from.second + '<' + m_from.first + '>' + "\r\n";
	// 接收人
	message += "To: ";
	for (int i = 0; i < m_recvs.size(); i++)
	{
		message += m_recvs[i].second += '<' + m_recvs[i].first + '>';
		if (i != m_recvs.size() - 1)
			message += ',';
	}
	message += "\r\n";
	// 抄送人
	if (!m_ccs.empty())
	{
		message += "Cc: ";
		for (int i = 0; i < m_ccs.size(); i++)
		{
			message += m_ccs[i].second += '<' + m_ccs[i].first + '>';
			if (i != m_ccs.size() - 1)
				message += ',';
		}
		message += "\r\n";
	}
	// 主题
	message += "Subject: ";
	message += m_email_subject;
	message += "\r\nMime-Version: 1.0";
	message += "\r\nContent-Type: multipart/mixed;boundary=\"simple boundary\"";
	message += "\r\n";
	// 内容
	message += "\r\n--simple boundary";
	message += "\r\nContent-Type: text/html;charset=" + getCharset();
	message += "\r\nContent-Transfer-Encoding: 7bit";
	message += "\r\n\r\n"; // 注意：内容和描述信息之间必须要有一个空行不然会在网易邮箱出现无内容bug
	message += m_email_body;
	message += "\r\n\r\n";
	// 附件
	if (!m_attachments.empty())
	{
		std::string filename = "";
		std::string filetype = "";
		for (std::string& path : m_attachments)
		{
			getFileName(path, filename);
			getFileContentType(path, filetype);
			message += "\r\n--simple boundary";
			message += "\r\nContent-Type: " + filetype + "\tname=" + filename;
			message += "\r\nContent-Disposition: attachment;filename=" + filename;
			message += "\r\nContent-Transfer-Encoding: base64";
			message += "\r\n\r\n";

			FILE* pt = NULL;
			if ((pt = fopen(path.c_str(), "rb")) == NULL)
			{
				std::cerr << "open file fail: " << path << std::endl;
				continue;
			}
			fseek(pt, 0, SEEK_END);
			int len = ftell(pt);
			fseek(pt, 0, SEEK_SET);
			int rlen = 0;
			char buf[55];
			for (size_t i = 0; i < len / 54 + 1; i++)
			{
				memset(buf, 0, 55);
				rlen = fread(buf, sizeof(char), 54, pt);
				message += mailBase64Encode((const unsigned char*)buf, rlen);
				message += "\r\n";
			}
			fclose(pt);
			pt = NULL;
		}
		message += "\r\n--simple boundary--\r\n";
	}
	return message;
}

void EmailSender::getFileName(const std::string& path, std::string& filename)
{
	auto p = path.find_last_of('/');
	if (p == std::string::npos) p = path.find_last_of('\\');
	if (p != std::string::npos)
	{
		p += 1;
		filename = path.substr(p, path.length() - p);
	}
	std::string tmp = "=?";
	tmp += getCharset();
	tmp += "?B?";
	tmp += mailBase64Encode((unsigned char*)filename.c_str(), filename.size());
	tmp += "?=";
	filename = "\"" + tmp + "\"";
}

void EmailSender::getFileContentType(const std::string& path, std::string& contentType)
{
	// 获取文件后缀
	std::string suffix = "";
	auto p = path.find_last_of('.');
	if (p != std::string::npos)
	{
		p += 1;
		suffix = path.substr(p, path.length() - p);
	}
	// 根据后缀设置contentType
	if (suffix == "txt") contentType = "plain/text;";
	else if (suffix == "xml") contentType = "text/xml;";
	else if (suffix == "html") contentType = "text/html;";
	else if (suffix == "jpeg" || suffix == "jpg") contentType = "image/jpeg;";
	else if (suffix == "png") contentType = "image/png;";
	else if (suffix == "gif") contentType = "image/gif;";
	else if (suffix == "exe") contentType = "application/x-msdownload;";
	else contentType = "application/octet-stream;";
}
