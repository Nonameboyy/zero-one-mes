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
#ifndef _ADD_DTO_H_
#define _ADD_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ŀ�б�
 */
class AddPlanDTO : public oatpp::DTO
{
	DTO_INIT(AddPlanDTO, DTO);
	// �ƻ�����
	API_DTO_FIELD(String, planCode, ZH_WORDS_GETTER("add-mj.fields.pid"),true,"plancode");
	//�ƻ�����
	API_DTO_FIELD(String, planName, ZH_WORDS_GETTER("add-mj.fields.pname"),true, "planname");
	//�ƻ�����
	API_DTO_FIELD(String, planType, ZH_WORDS_GETTER("add-mj.fields.ptype"),true, "plan_type");

	//Ƶ��
	API_DTO_FIELD(String, cycleType, ZH_WORDS_GETTER("add-mj.fields.ctype"),false, "cycle_type");
	//����
	API_DTO_FIELD(UInt32, cycleCount, ZH_WORDS_GETTER("add-mj.fields.ccount"),true, 1);
	//��ʼ����
	API_DTO_FIELD(String, startDate, ZH_WORDS_GETTER("add-mj.fields.sdate"), false, "2024-05-05 00:00:00");
	//��������
	API_DTO_FIELD(String, endDate, ZH_WORDS_GETTER("add-mj.fields.edate"), false, "2024-05-05 00:00:00");
	//״̬
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("add-mj.fields.status"), false, "status");
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("add-mj.fields.remark"), false,"remark");
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_