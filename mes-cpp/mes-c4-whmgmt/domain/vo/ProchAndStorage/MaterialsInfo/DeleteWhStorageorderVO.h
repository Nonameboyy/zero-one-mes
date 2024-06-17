#pragma once
#ifndef _DELETEWHSTORAGEORDER_VO_
#define _DELETEWHSTORAGEORDER_VO_

#include "../../../GlobalInclude.h"
#include "../../../dto/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ɾ����ⵥ�е�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class DeleteWhStorageorderVO :public JsonVO<DeleteWhStorageorderDTO::Wrapper> {
	DTO_INIT(DeleteWhStorageorderVO, JsonVO<DeleteWhStorageorderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETEWHSTORAGEORDER_VO_
