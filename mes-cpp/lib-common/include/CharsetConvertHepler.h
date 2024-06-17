#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 15:31:10

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
#ifndef _CHARSETCONVERTHEPLER_H_
#define _CHARSETCONVERTHEPLER_H_
#include <string>
/**
 * �ַ�������ת�빤����
 */
class CharsetConvertHepler final
{
public:
	//************************************
	// Method:    unicodeToUtf8
	// FullName:  CharsetConvertHepler::unicodeToUtf8
	// Access:    public static 
	// Returns:   std::string ����ת������ַ���
	// Description: ��Unicode�ַ���ת����UTF8�ַ���
	// Parameter: const std::wstring& wstr Unicode�ַ���
	//************************************
	static std::string unicodeToUtf8(const std::wstring& wstr);

	//************************************
	// Method:    utf8ToUnicode
	// FullName:  CharsetConvertHepler::utf8ToUnicode
	// Access:    public static 
	// Returns:   std::wstring ����ת������ַ���
	// Description: ��UTF8�ַ���ת����Unicode�ַ���
	// Parameter: const std::string& str UTF8�ַ���
	//************************************
	static std::wstring utf8ToUnicode(const std::string& str);

	//************************************
	// Method:    unicodeToAnsi
	// FullName:  CharsetConvertHepler::unicodeToAnsi
	// Access:    public static 
	// Returns:   std::string ����ת������ַ���
	// Description: ��Unicode�ַ���ת����ANSI�ַ���
	// Parameter: const std::wstring& wstr Unicode�ַ���
	//************************************
	static std::string unicodeToAnsi(const std::wstring& wstr);

	//************************************
	// Method:    ansiToUnicode
	// FullName:  CharsetConvertHepler::ansiToUnicode
	// Access:    public static 
	// Returns:   std::wstring ����ת������ַ���
	// Description: ��ANSI�ַ���ת����Unicode�ַ���
	// Parameter: const std::string& str ANSI�ַ���
	//************************************
	static std::wstring ansiToUnicode(const std::string& str);

	//************************************
	// Method:      utf8ToAnsi
	// FullName:    CharsetConvertHepler::utf8ToAnsi
	// Access:      public static 
	// Returns:     std::string ����ת������ַ���
	// Description:  ��UTF8�ַ���ת����ANSI�ַ���
	// Parameter:   const std::string& str UTF8�ַ���
	//************************************
	static std::string utf8ToAnsi(const std::string& str);

	//************************************
	// Method:    ansiToUtf8
	// FullName:  CharsetConvertHepler::ansiToUtf8
	// Access:    public static 
	// Returns:   std::string
	// Description: ��ANSI�ַ���ת����UTF8�ַ���
	// Parameter: const std::string& str ANSI�ַ���
	//************************************
	static std::string ansiToUtf8(const std::string& str);

	// �ַ���utf8����ת��gbk����
	static std::string utf8ToGbk(const std::string& str);

	// �ַ���gbk����ת��utf8����
	static std::string gbkToUtf8(const std::string& str);
};
#endif // _CHARSETCONVERTHEPLER_H_
