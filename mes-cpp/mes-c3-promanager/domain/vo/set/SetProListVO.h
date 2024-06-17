#pragma once
#ifndef _SETPROLIST_VO_
#define _SETPROLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/set/SetProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�������б�����+��ҳ��
 */
class SetProListJsonVO : public JsonVO<SetProListDTO::Wrapper> {
	DTO_INIT(SetProListJsonVO, JsonVO<SetProListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SetProListPageJsonVO : public JsonVO<SetProListPageDTO::Wrapper> {
	DTO_INIT(SetProListPageJsonVO, JsonVO<SetProListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SETPROSTEPLIST_VO_