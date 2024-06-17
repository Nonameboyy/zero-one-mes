#pragma once
#ifndef _storage_VO_
#define _storage_VO_

#include "../../GlobalInclude.h"
#include "../../dto/storage/storageDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class storageJsonVO : public JsonVO<storageDTO::Wrapper> {
	DTO_INIT(storageJsonVO, JsonVO<storageDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class storagePageJsonVO : public JsonVO<storagePageDTO::Wrapper> {
	DTO_INIT(storagePageJsonVO, JsonVO<storagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 