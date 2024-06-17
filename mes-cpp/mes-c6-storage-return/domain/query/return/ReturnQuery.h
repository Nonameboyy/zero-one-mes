#pragma once

#ifndef _RETURNQUERY_H_
#define _RETURNQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ������Ϣ�����ݴ���ģ��
 */
class ReturnQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ReturnQuery, PageQuery);
	// �˻������
	API_DTO_FIELD_DEFAULT(String, returnCode, ZH_WORDS_GETTER("return.fields.rtcode"));
	// �˻�������
	API_DTO_FIELD_DEFAULT(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"));
	// �ɹ������
	API_DTO_FIELD_DEFAULT(String, purchaseCode, ZH_WORDS_GETTER("return.fields.pucode"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorName, ZH_WORDS_GETTER("return.fields.vename"));
};

/**
* ����һ����ѯ��һ������ϸ��Ϣ�����ݴ���ģ��
*/
class ReturnDetailQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ReturnDetailQuery, oatpp::DTO);
	// �˻������
	API_DTO_FIELD(String, returnCode, ZH_WORDS_GETTER("return.fields.rtcode"), true, "notnull");
};

/**
* ����һ��������˻�������Ϣ�����ݴ���ģ��
*/
class ReturnAdd : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(ReturnAdd, oatpp::DTO);
	// �˻������
	API_DTO_FIELD(String, returnCode, ZH_WORDS_GETTER("return.fields.rtcode"), true, "RTV123");
	// �˻�������
	API_DTO_FIELD(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");
	// �ɹ������
	API_DTO_FIELD(String, purchaseCode, ZH_WORDS_GETTER("return.fields.pucode"), false, "null");
	// ��Ӧ������
	API_DTO_FIELD(String, vendorName, ZH_WORDS_GETTER("return.fields.vename"), true, "01star");
	// ���κ�
	API_DTO_FIELD(String, batchCode, ZH_WORDS_GETTER("return.fields.batchcode"), false, "null");
	// �˻�����
	API_DTO_FIELD(String, returndate, ZH_WORDS_GETTER("return.fields.rtdate"), true, "2024-5-21");
	// ����״̬
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("return.fields.status"), true, "PREPARE");
	// ��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("return.fields.remark"), false, " ");
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_RETURNQUERY_H_