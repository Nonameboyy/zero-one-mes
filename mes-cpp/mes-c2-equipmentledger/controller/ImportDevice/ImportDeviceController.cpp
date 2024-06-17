/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/19 14:32:00

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
#include "stdafx.h"
#include "ImportDeviceController.h"
#include "service/ImportDevice/ImportDeviceService.h"
#include"../../mes-c2-equipmentledger/domain/dto/ImportDeviceDTo.h"
StringJsonVO::Wrapper ImportDeviceController::
	execUploadFile(std::shared_ptr<IncomingRequest> request)
{
	auto res = StringJsonVO::createShared();

	/**
	 * 调用service层，将文件保存到服务器
	 */
	
	ImportDeviceService service;
	auto path = service.uploadDeviceFile(request);
	if (path != "")
		res->success(path);
	else
		res->fail("");
	return res;
}

ImportDeviceJsonVO::Wrapper ImportDeviceController::
	execImportDevice(String filename)
{
	auto res = ImportDeviceJsonVO::createShared();

	ImportDeviceService service;

	if (filename != "") {
		auto dto = service.importDevice(filename);
		if (dto->fail_count == -1)
			res->fail(dto);
		else
			res->success(dto);
	}
	else {
		res->fail(ImportDeviceDTO::Wrapper{});
	}
	
	return res;
}