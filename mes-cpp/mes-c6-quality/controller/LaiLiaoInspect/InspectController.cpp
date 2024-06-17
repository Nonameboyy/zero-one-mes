#include "stdafx.h"
#include "InspectController.h"
#include "../../service/LaiLiaoInspect/InspectService.h"
#include "../ApiDeclarativeServicesHelper.h"

InspectPageJsonVO::Wrapper InspectController::execQueryInspect(const InspectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	InspectService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = InspectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Inspect_detailJsonVO::Wrapper InspectController::execInspect_detail(const int& iqc_id)
{
	// ����һ��Service
	InspectService service;
	// ��ѯ����
	auto result = service.list_detailone(iqc_id);
	// ��Ӧ���
	auto jvo = Inspect_detailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//�鿴����
StringJsonVO::Wrapper InspectController::execLookTable(const oatpp::List<UInt64>& ids)
{
	/*return StringJsonVO::Wrapper();*/
	return {};
}

Uint64JsonVO::Wrapper InspectController::execAddInspect(const InspectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if ( !dto->iqc_code || !dto->iqc_name || !dto->vendor_code || !dto->item_code || !dto->quantity_recived || !dto->quantity_check  || !dto->recive_date || !dto->inspect_date)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	 //��ЧֵУ��
	if ( dto->item_code->empty() || dto->item_name->empty() || (dto->quantity_check> dto->quantity_recived) || dto->quantity_recived<0|| dto->quantity_check<0 || dto->quantity_unqualified>dto->quantity_check)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	InspectService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	/*if (id > 0) 
	{
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}*/
	jvo->success(UInt64(id));
	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper InspectController::execModifyInspect(const InspectDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->iqc_id || dto->iqc_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	InspectService service;
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

Uint64JsonVO::Wrapper InspectController::execRemoveInspect(const UInt64& iqc_id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!iqc_id || iqc_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	InspectService service;
	// ִ������ɾ��
	if (service.removeData(iqc_id.getValue(0))) {
		jvo->success(iqc_id);
	}
	else
	{
		jvo->fail(iqc_id);
	}
	// ��Ӧ���
	return jvo;
}

//����
//StringJsonVO::Wrapper InspectController::execExportInspect(const oatpp::List<UInt64>& ids)
//{
//	return StringJsonVO::Wrapper();
//}

StringJsonVO::Wrapper InspectController::execExportInspect(const Inspect_tableQuery::Wrapper& query)
{
	auto res = StringJsonVO::createShared();

	InspectService service;
	auto url = service.exportTable(query);

	if (url != "")
		res->success(url);
	else
		res->fail("");
	return res;
}


//ȷ�ϼ����
Uint64JsonVO::Wrapper InspectController::execIs_OkInspect(const Item_idDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->iqc_id || dto->iqc_id <= 0 || !dto->check_result )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	InspectService service;

	// �޸ļ��鵥״̬Ϊȷ��
	if (service.Is_Ok(dto)) {
		jvo->success(dto->iqc_id);
	}
	else
	{
		jvo->fail(dto->iqc_id);
	}
	// ��Ӧ���
	return jvo;
}

//��ɼ����
Uint64JsonVO::Wrapper InspectController::execIs_FinishedInspect(const Item_idDTO::Wrapper& dto)
{

	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->iqc_id || dto->iqc_id <= 0 || !dto->check_result)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	InspectService service;

	// �޸ļ��鵥״̬Ϊȷ��
	if (service.Finished(dto)) {
		jvo->success(dto->iqc_id);
	}
	else
	{
		jvo->fail(dto->iqc_id);
	}
	// ��Ӧ���
	return jvo;
}
