#pragma once
#ifndef _PROMATERIAL_VO_H_
#define _PROMATERIAL_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/process/ProMaterialDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��Ʒ�Ƴ�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProMaterialJsonVO : public JsonVO<ProMaterialDTO::Wrapper>
{
	DTO_INIT(ProMaterialJsonVO, JsonVO<ProMaterialDTO::Wrapper>);

};

/**
 * ��ȡ��Ʒ�Ƴ����Ϸ�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ProMaterialPageJsonVO : public JsonVO<ProMaterialPageDTO::Wrapper>
{
	DTO_INIT(ProMaterialPageJsonVO, JsonVO<ProMaterialPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROMATERIAL_VO_