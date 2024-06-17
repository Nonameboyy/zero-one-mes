#pragma once

#ifndef _DELETEWORKREPORT_DTO_H
#define _DELETEWORKREPORT_DTO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个删除报工的数据传输模型
 */
class DeleteWorkReportDTO : public oatpp::DTO
{
	DTO_INIT(DeleteWorkReportDTO, DTO);
	// 数据库的表： pro_feedback
	// 
	// 记录ID
	API_DTO_FIELD_DEFAULT(Int64, recordId, ZH_WORDS_GETTER("prodmgmt.delete.fields.recordId"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // _DELETEWORKREPORT_DTO_H