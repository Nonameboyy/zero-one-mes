/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 22:26:26

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include <sstream>
#include "stdafx.h"
#include "Macros.h"
#include "ImportDeviceService.h"

#include "dao/ImportDevice/ImportDeviceDAO.h"

#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "NacosClient.h"
#include "ServerInfo.h"
#include "FastDfsClient.h"
#include "CharsetConvertHepler.h"

std::string ImportDeviceService::uploadDeviceFile(
	std::shared_ptr<oatpp::web::protocol::http::incoming::Request> request)
{
	// ��ʼ��
	API_MULTIPART_INIT(container, reader);

	time_t t = time(NULL);
	std::string fileName = "./public/static/" + to_string(t) + ".xlsx";

	// ��ȡ������
	API_MULTIPART_CONFIG_FILE(reader, "file", fileName);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// ��ȡ����
	request->transferBody(&reader);
	// ��ӡ�ϴ�������
	OATPP_LOGD("Mutipart", "parts_count=%d", container->count());
	
	// ��������
	// ��������Ϊfile
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	
	// �����ļ��Ƿ��ȡ��
	OATPP_ASSERT_HTTP(partfile, Status::CODE_400, "file is null");

	// ��ȡ�û��ϴ����ļ���
	std::string filename = partfile->getFilename().getValue("");
	// ��ȡ�ļ�����չ��
	std::string suffix = "";
	size_t pos = filename.rfind(".");
	if (pos != std::string::npos) {
		suffix = filename.substr(pos + 1);
	}
	// ����Ϊ'xlsx'�򷵻�error
	if (suffix.compare("xlsx") != 0) {
		remove(filename.c_str());
		return "format error";
	}
	OATPP_LOGD("Multipart", "file save path: %s", partfile->getPayload()->getLocation()->c_str());
	return fileName;
}

ImportDeviceDTO::Wrapper ImportDeviceService::importDevice(oatpp::String fileName)
{
	std::vector<std::vector<std::string>> data;
	ExcelComponent excel;
	auto readData = excel.readIntoVector(fileName, "sheet1");

	int success_count = 0;
	int fail_count = 0;

	for (int i = 1; i < readData.size(); i++) 
	{
		ImportDeviceDAO dao;

		auto row = readData[i];
		dvMachineryDO Do;
		Do.setMachineryCode(row[0]);
		Do.setMachineryName(row[1]);
		Do.setMachineryBrand(row[2]);
		Do.setMachinerySpec(row[3]);
		Do.setMachineryTypeId(atoll(row[4].c_str()));
		Do.setMachineryTypeCode(row[5]);
		Do.setMachineryTypeName(row[6]);
		Do.setWorkshopId(atoll(row[7].c_str()));
		Do.setWorkshopName(row[8]);
		Do.setStatus(row[9]);
		Do.setAttr3(0);
		Do.setAttr4(0);
		if (dao.insertOne(Do))
			success_count++;
		else
			fail_count++;
	}

	auto res = ImportDeviceDTO::createShared();
	res->success_count = success_count;
	res->fail_count = fail_count;
	return res;
}
