#include "stdafx.h"
#include "ApprovalStage.h"
#include "../../service/ApprovalStage/ApprovalStageService.h"
#include "../ApiDeclarativeServicesHelper.h"
//ִ�������޸�
// �ύ����
Uint64JsonVO::Wrapper ApprovalStage::execModifyAubmitForApproval(const ApprovalStageDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ApprovalStageService service;
	// ִ�������޸�
	if (service.submitForApproval(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}
//����ͨ��
Uint64JsonVO::Wrapper ApprovalStage::execModifyApprovalPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ApprovalStageService service;
	// ִ�������޸�
	if (service.approvalPassed(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}
//������ͨ��
Uint64JsonVO::Wrapper ApprovalStage::execModifyApprovalNotPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->record_id || dto->record_id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ApprovalStageService service;
	// ִ�������޸�
	if (service.approvalNotPassed(dto)) {
		jvo->success(dto->record_id);
	}
	else
	{
		jvo->fail(dto->record_id);
	}
	// ��Ӧ���
	return jvo;
}