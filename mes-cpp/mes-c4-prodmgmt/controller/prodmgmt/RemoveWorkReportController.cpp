
#include "stdafx.h"
#include "RemoveWorkReportController.h"
#include <iostream>
#include "../../service/prodmgmt/DeleteWorkReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper RemoveWorkReportController::execRemoveWorkReport(const UInt64& recordId)
{
	//// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!recordId || recordId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ����һ��Service
	DeleteWorkReportService service;

	// ִ������ɾ��
	if (service.removeData(recordId.getValue(0))) {
		jvo->success(recordId);
	}
	else
	{
		jvo->fail(recordId);
	}
	//// ��Ӧ���
	return jvo;
}
