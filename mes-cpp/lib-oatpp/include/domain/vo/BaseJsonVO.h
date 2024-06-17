#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/20 10:27:42
 @description�����ﶨ������������Ͷ�Ӧ����ӦJsonVO

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
#ifndef _BASE_JSON_VO_H_
#define _BASE_JSON_VO_H_
#include "JsonVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ַ�����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class StringJsonVO : public JsonVO<String>
{
	DTO_INIT(StringJsonVO, JsonVO<String>);
};

/**
 * ������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class Int32JsonVO : public JsonVO<Int32>
{
	DTO_INIT(Int32JsonVO, JsonVO<Int32>);
};

/**
 * �޷���������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class Uint32JsonVO : public JsonVO<UInt32>
{
	DTO_INIT(Uint32JsonVO, JsonVO<UInt32>);
};

/**
 * ��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class Int64JsonVO : public JsonVO<Int64>
{
	DTO_INIT(Int64JsonVO, JsonVO<Int64>);
};

/**
 * �޷��ų�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class Uint64JsonVO : public JsonVO<UInt64>
{
	DTO_INIT(Uint64JsonVO, JsonVO<UInt64>);
};

/**
 * �����ȸ�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FloatJsonVO : public JsonVO<Float32>
{
	DTO_INIT(FloatJsonVO, JsonVO<Float32>);
};

/**
 * ˫���ȸ�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class DoubleJsonVO : public JsonVO<Float64>
{
	DTO_INIT(DoubleJsonVO, JsonVO<Float64>);
};

/**
 * ������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BooleanJsonVO : public JsonVO<Boolean>
{
	DTO_INIT(BooleanJsonVO, JsonVO<Boolean>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BASE_JSON_VO_H_