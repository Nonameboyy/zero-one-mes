#pragma once
#ifndef _RawMaterialOp_VO_
#define _RawMaterialOp_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RawMaterialOp/RawMaterialOpDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RawMaterialOpJsonVO : public JsonVO<RawMaterialOpDTO::Wrapper> {
	DTO_INIT(RawMaterialOpJsonVO, JsonVO<RawMaterialOpDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RawMaterialOpPageJsonVO : public JsonVO<RawMaterialOpPageDTO::Wrapper> {
	DTO_INIT(RawMaterialOpPageJsonVO, JsonVO<RawMaterialOpPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 