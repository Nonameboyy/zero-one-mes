#include "stdafx.h"
#include "DeleteWorkReportService.h"
#include "../../dao/prodmgmt/DeleteWorkReportDAO.h"

bool DeleteWorkReportService::removeData(uint64_t id)
{
	DeleteWorkReportDAO dao;
	return dao.deleteById(id) == 1;
}
