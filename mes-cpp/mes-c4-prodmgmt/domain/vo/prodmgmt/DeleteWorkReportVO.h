#pragma once

#ifndef _DELETEWORKREPORT_VO_H
#define _DELETEWORKREPORT_VO_H

#include "../../GlobalInclude.h"
#include "../../dto/prodmgmt/DeleteWorkReportDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ɾ����������ʾVO
*/
class DeleteWorkReportVO : public JsonVO<DeleteWorkReportDTO::Wrapper>
{
	DTO_INIT(DeleteWorkReportVO, JsonVO<DeleteWorkReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _DELETEWORKREPORT_VO_H