#pragma once
#ifndef _ADDVO_H_
#define _ADDVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/add-mj/AddDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����Ŀ�б���ʾVO
 */
class AddTableJsonVO : public JsonVO<List<AddDTO::Wrapper>>
{
	DTO_INIT(AddTableJsonVO, JsonVO<List<AddDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_