#include "stdafx.h"
#include "ProinSpectController.h"
#include "service/ProcessInspection/ProinSpect/ProinSpectService.h"
#include "../../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper ProinspectController::execAddrecord(const ProinspectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->qc_type || !dto->qc_id || !dto->line_id || !dto->defect_name || !dto->defect_level)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->qc_type->empty() || dto->qc_id < 0 || dto->line_id < 0 || dto->defect_name->empty() || dto->defect_level->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ProinspectService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;

}



Uint64JsonVO::Wrapper ProinspectController::execModifyrecord(const ProinspectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || !dto->record_id < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProinspectService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper  ProinspectController::execRemoverecord(const ProinspectDTO::Wrapper& dto) {


	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ProinspectService service;
	// ִ������ɾ��
	if (service.removeData(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;

}

ProinspectPageJsonVO::Wrapper ProinspectController::execQueryProcessInspectionList(const ProinspectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProinspectService service;
	// ��ѯ����
	auto result = service.queryProcessInspectionList(query);
	// ��Ӧ���
	auto jvo = ProinspectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProinspectPageJsonVO::Wrapper ProinspectController::execQueryProcessInspectionDefectList(const ProinspectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProinspectService service;
	// ��ѯ����
	auto result = service.queryProcessInspectionDefectList(query);
	// ��Ӧ���
	auto jvo = ProinspectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
