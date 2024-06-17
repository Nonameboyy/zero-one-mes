/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "DeviceManageController.h"
#include "../../service/device-manage/DeviceManageService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper DeviceManageController::execModifyProj(const DeviceManageDTO::Wrapper& dto)
{

	


	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->subjectId)
	{
		jvo->init(UInt64(-1), ResultStatus(u8"subjectId error", 9995));
		return jvo;
	}

	if (std::strcmp(dto->subjectType->c_str(), "CHECK") != 0 && std::strcmp(dto->subjectType->c_str(), "MAINTEN") != 0)
	{
		jvo->init(UInt64(-1), ResultStatus(u8"subjectType only support 'CHECK' or 'MAINTEN'", 9995));
		return jvo;
	}

	if (dto->enableFlag != "Y" && dto->enableFlag != "N")
	{
		//jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		jvo->init(UInt64(-1), ResultStatus(u8"enableFlag only support 'Y' or 'N'", 9995));
		return jvo;
	}

	// 定义一个Service
	DeviceManageService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(std::atoi(dto->subjectId->c_str()));
	}
	else
	{
		jvo->fail(std::atoi(dto->subjectId->c_str()));
	}
	// 响应结果
	return jvo;
}


Uint64JsonVO::Wrapper DeviceManageController::execRemoveProj(const DeviceManageIdDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->subjectId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return  jvo;
	}

	// 定义一个Service
	DeviceManageService service;
	// 执行数据修改
	if (service.removeData(dto))
	{
		jvo->init(atoi(dto->subjectId->c_str()), ResultStatus(u8"remove data successfully"));

	}
	else
	{

		jvo->init(atoi(dto->subjectId->c_str()), ResultStatus(u8"fail to remove data",9995));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper DeviceManageController::execExportProj(const DeviceManageIdDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	// 参数校验
	if (!dto->subjectId)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return  jvo;
	}

	// 定义一个Service
	DeviceManageService service;

	//创建excel文件
	string url = service.creatExcel(dto);
	if (url.empty())
	{
		jvo->init(atoi(dto->subjectId->c_str()), ResultStatus(u8"fail to export data",9995));
	}
	else
	{
		jvo->init(atoi(dto->subjectId->c_str()), ResultStatus(url));
	}
	return jvo;
}


Uint64JsonVO::Wrapper DeviceManageController::execAddProj(const DeviceManageAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->subjectCode || !dto->subjectName || !dto->subjectType || !dto->subjectStandard || !dto->subjectContent || !dto->enableFlag)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	if (std::strcmp(dto->subjectType->c_str(), "CHECK") != 0 && std::strcmp(dto->subjectType->c_str(), "MAINTEN") != 0)
	{
		jvo->init(UInt64(-1), ResultStatus(u8"subjectType only support 'CHECK' or 'MAINTEN'", 9995));
		return jvo;
	}
	// 定义一个Service
	DeviceManageService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

