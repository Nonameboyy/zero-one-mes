#include "stdafx.h"
#include "WorkeChange_Controller.h"
#include "../mes-c1-workstation/service/wk_changeservice/ChangeSerice.h"


Uint64JsonVO::Wrapper ChangeWorkwearController::exeChangeWorkwear(const ChangeWorkwearDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->workwearId || dto->workwearId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ChangeService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->workwearId);
	}
	else
	{
		jvo->fail(dto->workwearId);
	}
	// ��Ӧ���
	return jvo;
}
