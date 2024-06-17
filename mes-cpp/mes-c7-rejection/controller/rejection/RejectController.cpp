#include "stdafx.h"
#include "RejectController.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/PayloadDTO.h"
#include "domain/dto/PayloadDTO.h"
#include"service/rejectionQueryService/rejectionQuery.h"

RejectPageJsonVO::Wrapper RejectController::execQueryReject(const RejectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	RejectTableQueryService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RejectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;


}

RejectDetailJsonVO::Wrapper RejectController::execQueryRejectDetail(const RejectDetailQuery::Wrapper& query)
{
	// ����һ��Service
	RejectTableQueryService service;
	// ��ѯ����
	auto result = service.queryDetail(query);
	// ��Ӧ���
	auto jvo = RejectDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


Uint64JsonVO::Wrapper RejectController::execAddReject(const RejectDetailDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->rt_code || !dto->workorder_code || !dto->warehouse_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->rt_code->empty() || dto->workorder_code->empty() || dto->warehouse_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	RejectTableQueryService service;
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

Uint64JsonVO::Wrapper RejectController::execModifyReject(const RejectDetailDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->rt_id || dto->rt_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RejectTableQueryService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->rt_id);
	}
	else
	{
		jvo->fail(dto->rt_id);
	}
	// ��Ӧ���
	return jvo;



}
