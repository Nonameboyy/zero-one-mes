#include "stdafx.h"
#include "Single_Defect_Controller.h"
#include "../../service/Single_Defect/Single_Defect_Service.h"
#include "../ApiDeclarativeServicesHelper.h"

SinglePageJsonVO::Wrapper Single_Defect_Controller::execQuerySingle(const SingleQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	Single_Defect_Service service;
	// ��ѯ����
	auto result = service.listAll_Index(query);
	// ��Ӧ���
	auto jvo = SinglePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

DefectPageJsonVO::Wrapper Single_Defect_Controller::execQueryDefect(const DefectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	Single_Defect_Service service;
	// ��ѯ����
	auto result = service.listAll_Defect(query);
	// ��Ӧ���
	auto jvo = DefectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
 
Uint64JsonVO::Wrapper Single_Defect_Controller::execAddDefect(const DefectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->record_id || !dto->iqc_id || !dto->line_id || !dto->defect_name || !dto->defect_level || !dto->defect_quantity || !dto->remark)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ЧֵУ��
	if (dto->defect_quantity<=0|| dto->record_id<=0 || dto->iqc_id<0 || dto->line_id<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	Single_Defect_Service service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0)
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	jvo->success(UInt64(id));
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper Single_Defect_Controller::execModifyDefect(const DefectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->record_id || !dto->iqc_id || !dto->line_id || !dto->defect_name || !dto->defect_level|| !dto->defect_quantity)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ЧֵУ��
	if (dto->defect_quantity <= 0 || dto->record_id <= 0 || dto->iqc_id <=0 || dto->line_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	Single_Defect_Service service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->iqc_id);
	}
	else
	{
		jvo->fail(dto->iqc_id);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper Single_Defect_Controller::execRemoveDefect(const UInt64& record_id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!record_id || record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	Single_Defect_Service service;
	// ִ������ɾ��
	if (service.removeData(record_id.getValue(0))) {
		jvo->success(record_id);
	}
	else
	{
		jvo->fail(record_id);
	}
	// ��Ӧ���
	return jvo;
}



