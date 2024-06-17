#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/18 23:14

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
#ifndef _REPAIRCONTENT_DTO_
#define _REPAIRCONTENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ά�����ݴ������
 */
class RepaircontentDTO : public oatpp::DTO
{
	DTO_INIT(RepaircontentDTO, DTO);
	
	//��id(����primary key)
	API_DTO_FIELD(UInt64, line_id, ZH_WORDS_GETTER("repaircontent.field.line_id"), true, 1);
	//ά�޵�idΨһ��ʶ(���ص�)
	API_DTO_FIELD(UInt64, repair_id, ZH_WORDS_GETTER("repaircontent.field.repair_id"), true, 1);
	//��Ŀid
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.field.subject_id"), true, 1);
	//��Ŀ����
	API_DTO_FIELD(String, subject_code, ZH_WORDS_GETTER("repaircontent.field.subject_code"), true, "");
	//��Ŀ����
	API_DTO_FIELD(String, subject_name, ZH_WORDS_GETTER("repaircontent.field.subject_name"), true, ZH_WORDS_GETTER("repaircontent.default.subject_name"));
	//��Ŀ����
	API_DTO_FIELD(String, subject_type, ZH_WORDS_GETTER("repaircontent.field.subject_type"), true, "");
	//��Ŀ����
	API_DTO_FIELD(String, subject_content, ZH_WORDS_GETTER("repaircontent.field.subject_content"), true, "");
	//��׼
	//API_DTO_FIELD(String, subject_standard, ZH_WORDS_GETTER("repaircontent.field.subject_standard"), true, "");

	//��������
	API_DTO_FIELD(String, malfunction, ZH_WORDS_GETTER("repaircontent.field.malfunction"), true, "");
	//������Դ����
	API_DTO_FIELD(String, malfunction_url, ZH_WORDS_GETTER("repaircontent.field.malfunction_url"), true, "");
	//ά�����
	API_DTO_FIELD(String, repair_des, ZH_WORDS_GETTER("repaircontent.field.repair_des"), true, "");
	//������
	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("repaircontent.field.create_by"), true, "");
	//����ʱ��
	API_DTO_FIELD(String, create_time, ZH_WORDS_GETTER("repaircontent.field.create_time"), true, "");
	//������
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("repaircontent.field.update_by"), true, "");
	//����ʱ��
	API_DTO_FIELD(String, update_time, ZH_WORDS_GETTER("repaircontent.field.update_time"), true, "");

	//��ע
	//API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repaircontent.field.remark"), true, "");



};


class AddRepaircontentDTO : public oatpp::DTO
{
	DTO_INIT(AddRepaircontentDTO, DTO);

	//ά�޵�idΨһ��ʶ(���ص�)
	API_DTO_FIELD(UInt64, repair_id, ZH_WORDS_GETTER("repaircontent.field.repair_id"), true, 101);
	//��Ŀid
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.field.subject_id"), true, 200);
	//��������
	API_DTO_FIELD(String, malfunction, ZH_WORDS_GETTER("repaircontent.field.malfunction"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction"));
	//������Դ����
	API_DTO_FIELD(String, malfunction_url, ZH_WORDS_GETTER("repaircontent.field.malfunction_url"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction_url"));
	//ά�����
	API_DTO_FIELD(String, repair_des, ZH_WORDS_GETTER("repaircontent.field.repair_des"), true, ZH_WORDS_GETTER("repaircontent.default.repair_des"));
};

class ModifyRepaircontentDTO : public oatpp::DTO
{
	DTO_INIT(ModifyRepaircontentDTO, DTO);

	//��id(����)
	API_DTO_FIELD(UInt64, line_id, ZH_WORDS_GETTER("repaircontent.field.line_id"), true, 101);
	//��Ŀid
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.field.subject_id"), true, 200);
	//��������
	API_DTO_FIELD(String, malfunction, ZH_WORDS_GETTER("repaircontent.field.malfunction"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction"));
	//������Դ����
	API_DTO_FIELD(String, malfunction_url, ZH_WORDS_GETTER("repaircontent.field.malfunction_url"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction_url"));
	//ά�����
	API_DTO_FIELD(String, repair_des, ZH_WORDS_GETTER("repaircontent.field.repair_des"), true, ZH_WORDS_GETTER("repaircontent.default.repair_des"));

};

/**
 * ά�����ݷ�ҳ�������
 */
class RepaircontentPageDTO : public PageDTO<RepaircontentDTO::Wrapper>
{
	DTO_INIT(RepaircontentPageDTO, PageDTO<RepaircontentDTO::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRCONTENT_DTO_