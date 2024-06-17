#pragma once
#ifndef _storage_VO_
#define _storage_VO_

#include "../../GlobalInclude.h"
#include "../../dto/storage/storageDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class storageJsonVO : public JsonVO<storageDTO::Wrapper> {
	DTO_INIT(storageJsonVO, JsonVO<storageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class storagePageJsonVO : public JsonVO<storagePageDTO::Wrapper> {
	DTO_INIT(storagePageJsonVO, JsonVO<storagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 