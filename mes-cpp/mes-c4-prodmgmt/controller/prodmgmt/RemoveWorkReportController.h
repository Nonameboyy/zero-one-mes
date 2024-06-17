#pragma once

#ifndef _REMOVEWORKREPORT_CONTROLLER_H
#define _REMOVEWORKREPORT_CONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/prodmgmt/DeleteWorkReportDTO.h"
#include "../../domain/vo/prodmgmt/DeleteWorkReportVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class RemoveWorkReportController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(RemoveWorkReportController);

public: // ����ӿ�
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeWorkReport) {
		// �������ͷ��������Լ���Ȩ֧��
		//API_DEF_ADD_COMMON(ZH_WORDS_GETTER("prodmgmt.delete.describe.name"), Uint64JsonVO::Wrapper);
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("prodmgmt.delete.describe.name"), Uint64JsonVO::Wrapper);

		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "recordId", ZH_WORDS_GETTER("prodmgmt.delete.fields.recordId"), 1, false);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/prodmgmt/prodreport/delete/{recordId}", removeWorkReport, PATH(UInt64, recordId), execRemoveWorkReport(recordId));




private: // ����ӿ�ִ�к���
	Uint64JsonVO::Wrapper execRemoveWorkReport(const UInt64& recordId);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _REMOVEWORKREPORT_CONTROLLER_H