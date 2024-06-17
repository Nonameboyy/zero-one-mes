
#pragma once
#ifndef _REJECT_VO_
#define _REJECT_VO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../dto/rejection/RejectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б���ʾVO
 */
class RejectJsonVO : public JsonVO<RejectTableDTO::Wrapper> {
	DTO_INIT(RejectJsonVO, JsonVO<RejectTableDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RejectPageJsonVO : public JsonVO<RejectPageDTO::Wrapper> {
	DTO_INIT(RejectPageJsonVO, JsonVO<RejectPageDTO::Wrapper>);
};

//��ϸ��Ϣvo
class RejectDetailJsonVO :public JsonVO<RejectDetailDTO::Wrapper> {
	DTO_INIT(RejectDetailJsonVO, JsonVO<RejectDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // vo