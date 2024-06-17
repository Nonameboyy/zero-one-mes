#pragma once
#ifndef _PROCESSLIST_DTO_
#define _PROCESSLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӹ������̴������
 */
class ProcessAddDTO : public oatpp::DTO
{
	DTO_INIT(ProcessAddDTO, DTO);

	// ·�߱��
	DTO_FIELD(String, routeCode);
	DTO_FIELD_INFO(routeCode) {
		info->description = ZH_WORDS_GETTER("process.field.code");
	}
	// ·������
	DTO_FIELD(String, routeName);
	DTO_FIELD_INFO(routeName) {
		info->description = ZH_WORDS_GETTER("process.field.name");
	}
	// ·��˵��
	DTO_FIELD(String, routeDesc);
	DTO_FIELD_INFO(routeDesc) {
		info->description = ZH_WORDS_GETTER("process.field.desc");
	}
	// �Ƿ�����
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("process.field.flag");
	}
	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("process.field.remark");
	}
};
/**
 * �����б������,���ȡ��������һ��
 */
class ProcessDTO : public ProcessAddDTO
{
	DTO_INIT(ProcessDTO, ProcessAddDTO);

	// Ψһ��ʶ
	DTO_FIELD(UInt64, routeId);
	DTO_FIELD_INFO(routeId) {
		info->description = ZH_WORDS_GETTER("process.field.id");
	}

};

/**
 * �����б��ҳ�������
 */
class ProcessListDTO : public PageDTO<ProcessDTO::Wrapper>
{
	DTO_INIT(ProcessListDTO, PageDTO<ProcessDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
