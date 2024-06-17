#pragma once

#ifndef _WORKWEAR_DELETE_VO_H_
#define _WORKWEAR_DELETE_VO_H_

#include "../GlobalInclude.h"
#include "../dto/Delete_Workwear_DTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class DeleteworkwearListJsonVO : public JsonVO<DeleteWorkwearDTO::Wrapper>
{
	DTO_INIT(DeleteworkwearListJsonVO, JsonVO<DeleteWorkwearDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_