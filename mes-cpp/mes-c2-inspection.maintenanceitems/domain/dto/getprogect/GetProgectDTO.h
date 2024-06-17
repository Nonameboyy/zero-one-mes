#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ksw12355
 @Date: 2024/5/20

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
#ifndef _GETPROGECTDTO_H_
#define _GETPROGECTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ��Ŀ�б�����ݴ���ģ��
 */
class GetProgectDTO : public oatpp::DTO
{
	DTO_INIT(GetProgectDTO, DTO);
	//Ψһ��ʶ
	//API_DTO_FIELD(String, pId, ZH_WORDS_GETTER("get-project.fields.pid"), true, "1");
	DTO_FIELD(UInt64, pId);
	DTO_FIELD_INFO(pId) {
		info->description = ZH_WORDS_GETTER("get-project.fields.pid");
	}
	//��Ŀ����
	API_DTO_FIELD(String, pCode, ZH_WORDS_GETTER("project.fields.pcode"), true, "01star");
	//��Ŀ����
	API_DTO_FIELD(String, pType, ZH_WORDS_GETTER("project.fields.ptype"), true, "QW");
	//��Ŀ����
	API_DTO_FIELD(String, pContent, ZH_WORDS_GETTER("project.fields.pcontent"), true, "Q1001");
	//��׼
	API_DTO_FIELD(String, standard, ZH_WORDS_GETTER("project.fields.standard"), true, "w1");
	//�Ƿ�����
	API_DTO_FIELD(String, enable, ZH_WORDS_GETTER("project.fields.enable"), true, "enable");
	//��ע
	API_DTO_FIELD(String, note, ZH_WORDS_GETTER("project.fields.note"), true, "asdef");
	

};


/**
* ����һ����Ŀ�б��ҳ�������
*/

class GetProgectPageDTO : public PageDTO< GetProgectDTO::Wrapper>
{
	DTO_INIT(GetProgectPageDTO, PageDTO< GetProgectDTO::Wrapper>);
	
};
/**
* ����һ���豸���鴫�����
*/
class GetProgectDetailDTO : public oatpp::DTO
{
	DTO_INIT(GetProgectDetailDTO, DTO);
	DTO_FIELD(UInt64, pId);
	DTO_FIELD_INFO(pId) {
		info->description = ZH_WORDS_GETTER("project.fields.pid");
	}
	//��Ŀ����
	API_DTO_FIELD(String, pCode, ZH_WORDS_GETTER("project.fields.pcode"), true, "01star");
	//��Ŀ����
	API_DTO_FIELD(String, pName, ZH_WORDS_GETTER("project.fields.pname"), true, "01");
	//��Ŀ����
	API_DTO_FIELD(String, pType, ZH_WORDS_GETTER("project.fields.ptype"), true, "QW");
	//��Ŀ����
	API_DTO_FIELD(String, pContent, ZH_WORDS_GETTER("project.fields.pcontent"), true, "Q1001");
	//��׼
	API_DTO_FIELD(String, standard, ZH_WORDS_GETTER("project.fields.standard"), true, "w1");
	//�Ƿ�����
	API_DTO_FIELD(String, enable, ZH_WORDS_GETTER("project.fields.enable"), true, "enable");

};



#include OATPP_CODEGEN_END(DTO)
#endif // 

