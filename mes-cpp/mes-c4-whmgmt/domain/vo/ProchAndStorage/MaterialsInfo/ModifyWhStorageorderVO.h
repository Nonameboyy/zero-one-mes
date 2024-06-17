#pragma once
#ifndef _MODIFYWHSTORAGEORDERVO_H_
#define _MODIFYWHSTORAGEORDERVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/*
定义一个入库单行修改后显示的IsonVO对象，用于响应给客户端
*/

class ModifyWhStorageorderVO : public JsonVO<ModifyWhStorageorderDTO::Wrapper>
{
	DTO_INIT(ModifyWhStorageorderVO, JsonVO<ModifyWhStorageorderDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _MODIFYWHSTORAGEORDERVO