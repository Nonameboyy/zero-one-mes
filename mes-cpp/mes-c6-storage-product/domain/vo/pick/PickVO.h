#pragma once

#ifndef _PICK_VO_
#define _PICK_VO_

#include "../../GlobalInclude.h"
#include "../../dto/pick/PickDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PickJsonVO : public JsonVO<PickDTO::Wrapper> {
	DTO_INIT(PickJsonVO, JsonVO<PickDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PickPageJsonVO : public JsonVO<PickPageDTO::Wrapper> {
	DTO_INIT(PickPageJsonVO, JsonVO<PickPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PICK_VO_