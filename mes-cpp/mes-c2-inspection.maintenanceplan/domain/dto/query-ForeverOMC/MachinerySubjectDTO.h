#ifndef _MACHINERY_SUBJECT_DTO_
#define _MACHINERY_SUBJECT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 点检/保养设备列表传输对象
*/
class MachinerySubjectDTO : public oatpp::DTO
{
	DTO_INIT(MachinerySubjectDTO, DTO);

	// 流水号
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.record-id");
	}

	//项目编码
	DTO_FIELD(String, subject_code);
	DTO_FIELD_INFO(subject_code) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-code");
	}

	//项目名称
	DTO_FIELD(String, subject_name);
	DTO_FIELD_INFO(subject_name) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-name");
	}

	//项目类型
	DTO_FIELD(String, subject_type);
	DTO_FIELD_INFO(subject_type) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-type");
	}

	//项目内容
	DTO_FIELD(String, subject_content);
	DTO_FIELD_INFO(subject_content) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-content");
	}

	//标准
	DTO_FIELD(String, subject_standard);
	DTO_FIELD_INFO(subject_standard) {
		info->description = ZH_WORDS_GETTER("machinery-subject.field.subject-standard");
	}
};

/**
* 点检/保养设备列表分页传输对象
*/
class MachinerySubjectPageDTO : public PageDTO<MachinerySubjectDTO::Wrapper>
{
	DTO_INIT(MachinerySubjectPageDTO, PageDTO<MachinerySubjectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_SUBJECT_DTO_