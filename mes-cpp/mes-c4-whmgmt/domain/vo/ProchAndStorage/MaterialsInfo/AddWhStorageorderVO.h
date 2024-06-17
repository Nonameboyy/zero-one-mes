#pragma once
#ifndef _ADDWHSTORAGEORDERVO_H_
#define _ADDWHSTORAGEORDERVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/ProchAndStorage/MaterialsInfo/AddWhStorageorderDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)
/*
����һ����ⵥ����Ӻ���ʾ��IsonVO����������Ӧ���ͻ���
*/

class AddWhStorageorderVO : public JsonVO<AddWhStorageorderDTO::Wrapper>
{
	DTO_INIT(AddWhStorageorderVO, JsonVO<AddWhStorageorderDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _ADDWHSTORAGEORDERVO_H_