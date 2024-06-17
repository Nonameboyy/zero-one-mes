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
#ifndef _PROINSPECT_DTO_H_
#define _PROINSPECT_DTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class  ProinspectDTO : public oatpp::DTO
{
	DTO_INIT(ProinspectDTO, DTO);
	// ȱ��ID
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.record_id");
	}
	// ���鵥����
	DTO_FIELD(String, qc_type);
	DTO_FIELD_INFO(qc_type) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.qc_type");
	}
	//���鵥ID
	DTO_FIELD(UInt64, qc_id);
	DTO_FIELD_INFO(qc_id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.qc_id");
	}
	// ���鵥��ID
	DTO_FIELD(UInt64, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.line_id");
	}
	// ȱ������
	DTO_FIELD(String, defect_name);
	DTO_FIELD_INFO(defect_name) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.defect_name");
	}
	//ȱ�ݵȼ�
	DTO_FIELD(String, defect_level);
	DTO_FIELD_INFO(defect_level) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.defect_level");
	}

	//ȱ������
	DTO_FIELD(UInt32, defect_quantity);
	DTO_FIELD_INFO(defect_quantity) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.defect_quantity");
	}

	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.remark");
	}

	//����������
	DTO_FIELD(String, index_name);
	DTO_FIELD_INFO(index_name) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.index_name");
	}

	//����������
	DTO_FIELD(String, index_type);
	DTO_FIELD_INFO(index_type) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.index_type");
	}

	//���鹤��
	DTO_FIELD(String, qc_tool);
	DTO_FIELD_INFO(qc_tool) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.qc_tool");
	}

	//����Ҫ��
	DTO_FIELD(String, check_method);
	DTO_FIELD_INFO(check_method) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.check_method");
	}

	//��׼ֵ
	DTO_FIELD(Float64, stander_val);
	DTO_FIELD_INFO(stander_val) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.stander_val");
	}

	//��λ
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.unit_of_measure");
	}

	//�������
	DTO_FIELD(Float64, threshold_max);
	DTO_FIELD_INFO(threshold_max) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.threshold_max");
	}

	//�������
	DTO_FIELD(Float64, threshold_min);
	DTO_FIELD_INFO(threshold_min) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.threshold_min");
	}

	//����ȱ������
	DTO_FIELD(Float64, cr_quantity);
	DTO_FIELD_INFO(cr_quantity) {
		info->description = ZH_WORDS_GETTER("processinspection.filed.cr_quantity");
	}

	//����ȱ������
	DTO_FIELD(Float64, maj_quantity);
	DTO_FIELD_INFO(maj_quantity) {
		info->description = ZH_WORDS_GETTER("processinspection.filed.maj_quantity");
	}

	//��΢ȱ������
	DTO_FIELD(Float64, min_quantity);
	DTO_FIELD_INFO(min_quantity) {
		info->description = ZH_WORDS_GETTER("processinspection.filed.min_quantity");
	}
};

/**
 * ���ģ���ҳ�������
 */
class ProinspectPageDTO : public PageDTO<ProinspectDTO::Wrapper> {
	DTO_INIT(ProinspectPageDTO, PageDTO<ProinspectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_