#pragma once
#ifndef _MATERIAL_QUERY_
#define _MATERIAL_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ҳ��ѯ����
 */
class MaterialQuery : public PageQuery
{
	DTO_INIT(MaterialQuery, PageQuery);
	// ���ϵ����
	DTO_FIELD(String, issue_id);
	DTO_FIELD_INFO(issue_id) {
		info->description = ZH_WORDS_GETTER("Material.field.issue_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MATERIALS_QUERY_