/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:41:19
 
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
#include "../include/StringUtil.h"

#ifdef LINUX
#include <string.h>
#define SCPY(de, len, sr) snprintf(de, len, "%s", sr.c_str());
#define STOK strtok_r
#else
#define SCPY(de, len, sr) strcpy_s(de, len, sr.c_str());
#define STOK strtok_s
#endif

vector<string> StringUtil::split(const string& str, const string& delim)
{
	vector<string> res;
	//���ַ�����
	if ("" == str) return res;

	//�ַ�����string����ת��Ϊchar*����
	char* source = new char[str.length() + 1];
	SCPY(source, str.length() + 1, str);
	char* d = new char[delim.length() + 1];
	SCPY(d, delim.length() + 1, delim);

	//����ַ����߼�
	char* nextToken = NULL;
	char* strToken = STOK(source, d, &nextToken);
	while (strToken) {
		//�ָ�õ����ַ���ת��Ϊstring����
		string s = strToken;
		//����������
		res.push_back(s);
		//�����ָ�
		strToken = STOK(NULL, d, &nextToken);
	}
	delete[] source;
	delete[] d;
	return res;
}

void StringUtil::trim(string* str)
{
	if (str && !str->empty())
	{
		str->erase(0, str->find_first_not_of(" "));
		str->erase(str->find_last_not_of(" ") + 1);
	}
}

void StringUtil::replace(string* base, const string& src, const string& dst)
{
	if (!base) return;
	size_t pos = 0, srclen = src.size(), dstlen = dst.size();
	while ((pos = base->find(src, pos)) != string::npos)
	{
		base->replace(pos, srclen, dst);
		pos += dstlen;
	}
}
