#pragma once
#ifndef _MODIFYWHSTORAGEORDERVO_H_
#define _MODIFYWHSTORAGEORDERVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/*
����һ����ⵥ���޸ĺ���ʾ��IsonVO����������Ӧ���ͻ���
*/

class ModifyWhStorageorderVO : public JsonVO<ModifyWhStorageorderDTO::Wrapper>
{
	DTO_INIT(ModifyWhStorageorderVO, JsonVO<ModifyWhStorageorderDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _MODIFYWHSTORAGEORDERVO