#include "stdafx.h"
#include "ReturnController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "tree/TreeUtil.h"
#include "service/return/ReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"


ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query)
{
	ReturnService service;
	auto result = service.listAll(query);
	auto jvo = ReturnPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

ReturnDetailJsonVO::Wrapper ReturnController::executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
{

	ReturnService service;
	auto result = service.getDetail(returnDetailQuery);
	auto jvo = ReturnDetailJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

Uint64JsonVO::Wrapper ReturnController::execAddDetail(const ReturnAdd::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->returnCode->empty()||dto->returnName->empty()||dto->returndate->empty()||dto->vendorName->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ReturnService service;
	auto result = service.saveData(dto);
	jvo->success(result);
	return jvo;
}
//// �޸ĵ���
//Uint64JsonVO::Wrapper ReturnController::execModifyReturn(const ReturnDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	/*if (!dto->returnId || dto->returnId <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}*/
//	// ����һ��Service
//	ReturnService service;
//	// ִ�������޸�
//	// if (service.updateData(dto))  //��Ҫdao֧�֣���δ����
//	if (true)//ֱ����Ӧ
//	{
//		jvo->success(1);
//	}
//	else
//	{
//		jvo->fail(2);
//	}
//	// ��Ӧ���
//	return jvo;
//}
//
//// ִ�е���
//Uint64JsonVO::Wrapper ReturnController::execExecuteReturn(const String& code)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	/*if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}*/
//	// ����һ��Service
//	ReturnService service;
//	// �����ݿ���ִ���˻�����
//	// if (service.removeData(id.getValue(0))) 
//
//	if (true)
//	{
//		jvo->success(1);
//	}
//	else
//	{
//		jvo->fail(2);
//	}
//	// ��Ӧ���
//	return jvo;
//}
//// ɾ������
//Uint64JsonVO::Wrapper ReturnController::execRemoveReturn(const String& code)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	/*if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}*/
//	// ����һ��Service
//	ReturnService service;
//
//	//�����ݿ��в�ѯ��Ӧid������
//	//ReturnDTO::Wrapper dto_remove;
//	//״̬��Ϊ�ݸ��޷�ɾ��
//	/*if (dto_remove->status != 0)
//	{
//		jvo->fail(id);
//	}*/
//
//	// ִ������ɾ��
//	// if (service.removeData(id.getValue(0))) 
//	if (true)
//	{
//		jvo->success(1);
//	}
//	else
//	{
//		jvo->fail(2);
//	}
//	// ��Ӧ���
//	return jvo;
//}
//// ��������
//std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ReturnController::execDownloadFile(const String& code)
//{
//	// �����ļ�ȫ·�� // ���·���޷�����
//	std::string fullPath = "C:/Users/RHY/Desktop/C6/zero-one-08mes/mes-cpp/mes-c6-storage-return/public/static/file/C6RyanTest.jpg" ;
//	// ��ȡ�ļ�
//	auto fstring = String::loadFromFile(fullPath.c_str());
//
//	// �ж��Ƿ��ȡ�ɹ�
//	if (!fstring)
//	{
//		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
//		return createResponse(Status::CODE_404, "File Not Found");
//	}
//
//	// ������Ӧͷ
//	auto response = createResponse(Status::CODE_200, fstring);
//
//	// ������Ӧͷ��Ϣ
//	response->putHeader("Content-Disposition", "attachment; code=" + code.getValue(""));
//
//	// Ӱ��ɹ����
//	return response;
//}