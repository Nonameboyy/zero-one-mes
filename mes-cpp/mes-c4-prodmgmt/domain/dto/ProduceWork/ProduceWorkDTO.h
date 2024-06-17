#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _ADD_DTO_
#define _ADD_DTO_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������������
 */
class ProduceWorkDTO : public oatpp::DTO
{
	DTO_INIT(ProduceWorkDTO, DTO);

	// ��¼id
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"));
	//��������
	API_DTO_FIELD_DEFAULT(String, feedback_type, ZH_WORDS_GETTER("ProduceWork.fields.record_id"));
	// ��������  - ���ع�������
	API_DTO_FIELD_DEFAULT(String, workorder_code, ZH_WORDS_GETTER("ProduceWork.add.feedback_code"));
	// �������� - ���� ����������
	API_DTO_FIELD_DEFAULT(String, task_code, ZH_WORDS_GETTER("ProduceWork.add.task_code"));
	// ���ű���
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("ProduceWork.add.product_code"));
	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("ProduceWork.add.product_name"));
	//��λ
	API_DTO_FIELD_DEFAULT(String, unit_of_measure, ZH_WORDS_GETTER("ProduceWork.add.unit_of_measure"));
	//�������
	API_DTO_FIELD_DEFAULT(String, specification, ZH_WORDS_GETTER("ProduceWork.add.product_spc"));
	//��������
	API_DTO_FIELD_DEFAULT(Float32, quantity_feedback, ZH_WORDS_GETTER("ProduceWork.add.quantity_feedback"));
	//���������
	API_DTO_FIELD_DEFAULT(Float32, quantity_uncheck, ZH_WORDS_GETTER("ProduceWork.add.quantity_uncheck"));
	//������
	API_DTO_FIELD_DEFAULT(String, nick_name, ZH_WORDS_GETTER("ProduceWork.add.nick_nameA"));
	//�����
	API_DTO_FIELD_DEFAULT(String, record_nick, ZH_WORDS_GETTER("ProduceWork.add.nick_nameB"));
	//����ʱ��
	SimpleDateTimeFormat Sdatetime;
	API_DTO_FIELD(String, feedback_time, ZH_WORDS_GETTER("ProduceWork.add.feedback_time"),true, Sdatetime.format());
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("ProduceWork.add.remark"));


	// ��ҵ����ص������ֶ�
	/*API_DTO_FIELD(UInt64, workstation_id, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"), true, 1);

	API_DTO_FIELD(UInt64, workorder_id, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"), true, 1);

	API_DTO_FIELD(UInt64, route_id, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"), true, 1);

	API_DTO_FIELD(UInt64, process_id, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"), true, 1);

	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"), true, 1);*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_