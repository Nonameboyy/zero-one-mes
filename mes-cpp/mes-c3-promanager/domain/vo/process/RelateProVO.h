#pragma once
#ifndef _RELATEPTO_VO_H_
#define _RELATEPTO_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/process/RelateProDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӹ��չ�����Ʒ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class AddRelateProJsonVO : public JsonVO<AddRelateProDTO::Wrapper>
{
	DTO_INIT(AddRelateProJsonVO, JsonVO<AddRelateProDTO::Wrapper>);
};

/**
 * �޸Ĺ��չ�����Ʒ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ModRelateProJsonVO : public JsonVO<ModRelateProDTO::Wrapper>
{
	DTO_INIT(ModRelateProJsonVO, JsonVO<ModRelateProDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RELATEPTO_VO_