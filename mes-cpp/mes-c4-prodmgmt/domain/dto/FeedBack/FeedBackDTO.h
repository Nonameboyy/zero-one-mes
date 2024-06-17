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
#ifndef _FEEDBACK_DTO_
#define _FEEDBACK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����������
 */
class FeedBackDTO : public oatpp::DTO
{
	DTO_INIT(FeedBackDTO,DTO);
	//��������
	DTO_FIELD(String, feedback_type);
	DTO_FIELD_INFO(feedback_type) {
		info->description = ZH_WORDS_GETTER("prod1.field.feedback_type");
	}
	//����վ����
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.workstation_name");
	}
	//����������� 
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("prod1.field.workorder_code");
	}
	//��Ʒ���ϱ�� 
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("prod1.field.item_code");
	}
	//��Ʒ������ 
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.item_name");
	}
	//����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("prod1.field.specification");
	}
	//��������
	DTO_FIELD(UInt64, quantity_feedback);
	DTO_FIELD_INFO(quantity_feedback) {
		info->description = ZH_WORDS_GETTER("prod1.field.quantity_feedback");
	}
	//������
	DTO_FIELD(String, user_name);
	DTO_FIELD_INFO(user_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.user_name");
	}
	//����ʱ��
	DTO_FIELD(String, feedback_time);
	DTO_FIELD_INFO(feedback_time) {
		info->description = ZH_WORDS_GETTER("prod1.field.feedback_time");
	}
	//�����
	DTO_FIELD(String, record_user);
	DTO_FIELD_INFO(record_user) {
		info->description = ZH_WORDS_GETTER("prod1.field.record_user");
	}
	//״̬
	DTO_FIELD(String, _status);
	DTO_FIELD_INFO(_status) {
		info->description = ZH_WORDS_GETTER("prod1.field.status");
	}
};

/**
 * ʾ����ҳ�������
 */
class FeedBackPageDTO : public PageDTO<FeedBackDTO::Wrapper>
{
	DTO_INIT(FeedBackPageDTO, PageDTO<FeedBackDTO::Wrapper>);
	//��������
	DTO_FIELD(String, feedback_type);
	DTO_FIELD_INFO(feedback_type) {
		info->description = ZH_WORDS_GETTER("prod1.field.feedback_type");
	}
	//����վ����
	DTO_FIELD(String, workstation_name);
	DTO_FIELD_INFO(workstation_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.workstation_name");
	}
	//����������� 
	DTO_FIELD(String, workorder_code);
	DTO_FIELD_INFO(workorder_code) {
		info->description = ZH_WORDS_GETTER("prod1.field.workorder_code");
	}
	//��Ʒ���ϱ�� 
	DTO_FIELD(String, item_code);
	DTO_FIELD_INFO(item_code) {
		info->description = ZH_WORDS_GETTER("prod1.field.item_code");
	}
	//��Ʒ������ 
	DTO_FIELD(String, item_name);
	DTO_FIELD_INFO(item_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.item_name");
	}
	//����ͺ�
	DTO_FIELD(String, specification);
	DTO_FIELD_INFO(specification) {
		info->description = ZH_WORDS_GETTER("prod1.field.specification");
	}
	//��������
	DTO_FIELD(String, quantity_feedback);
	DTO_FIELD_INFO(quantity_feedback) {
		info->description = ZH_WORDS_GETTER("prod1.field.quantity_feedback");
	}
	//������
	DTO_FIELD(String, user_name);
	DTO_FIELD_INFO(user_name) {
		info->description = ZH_WORDS_GETTER("prod1.field.user_name");
	}
	//����ʱ��
	DTO_FIELD(String, feedback_time);
	DTO_FIELD_INFO(feedback_time) {
		info->description = ZH_WORDS_GETTER("prod1.field.feedback_time");
	}
	//�����
	DTO_FIELD(String, record_user);
	DTO_FIELD_INFO(record_user) {
		info->description = ZH_WORDS_GETTER("prod1.field.record_user");
	}
	//״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("prod1.field.status");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FEEDBACK_DTO_