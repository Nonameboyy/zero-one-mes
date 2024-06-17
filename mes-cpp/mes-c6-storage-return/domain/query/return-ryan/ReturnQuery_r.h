#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _RETURNQUERY_R_H_
#define _RETURNQUERY_R_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ������Ϣ�����ݴ���ģ��
 */
class ReturnQuery_r : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ReturnQuery_r, PageQuery);
	// �˻������
	API_DTO_FIELD_DEFAULT(String, rt_code, ZH_WORDS_GETTER("return.fields.rt_code"));
	// �˻�������
	API_DTO_FIELD_DEFAULT(String, rt_name, ZH_WORDS_GETTER("return.fields.rt_name"));
	// ����
	API_DTO_FIELD_DEFAULT(String, po_code, ZH_WORDS_GETTER("return.fields.po_code"));

};

/**
* ����һ����ѯ��һ������ϸ��Ϣ�����ݴ���ģ��
*/
class ReturnDetailQuery_r : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ReturnDetailQuery_r, oatpp::DTO);
	// �˻������
	/*API_DTO_FIELD(String, returnId, ZH_WORDS_GETTER("return.fields.rtid"), true, "null");*/
};

/**
* ����һ��������˻�������Ϣ�����ݴ���ģ��
*/
class ReturnAdd_r : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ReturnAdd_r, oatpp::DTO);
	//// �˻������
	//API_DTO_FIELD(String, returnId, ZH_WORDS_GETTER("return.fields.rtid"), true, "RTV123");
	//// �˻�������
	//API_DTO_FIELD(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");
	//// �ɹ������
	//API_DTO_FIELD(String, purchaseId, ZH_WORDS_GETTER("return.fields.puid"), false, "null");
	//// ��Ӧ������
	//API_DTO_FIELD(String, vendorName, ZH_WORDS_GETTER("return.fields.vename"), true, "01star");
	//// ���κ�
	//API_DTO_FIELD(String, batchCode, ZH_WORDS_GETTER("return.fields.batchcode"), false, "null");
	//// �˻�����
	//API_DTO_FIELD(String, returndate, ZH_WORDS_GETTER("return.fields.rtdate"), true, "2024-5-21");
	//// ����״̬
	//API_DTO_FIELD(String, status, ZH_WORDS_GETTER("return.fields.status"), true, "PREPARE");
	//// ��ע
	//API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("return.fields.remark"), false, " ");
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_RETURNQUERY_H_