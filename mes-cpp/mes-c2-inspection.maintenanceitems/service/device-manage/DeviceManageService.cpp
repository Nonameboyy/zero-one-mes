/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "oatpp/core/data/mapping/ObjectMapper.hpp"
#include "DeviceManageService.h"
#include "../../dao/device-manage/DeviceMangeDAO.h"
#include "../lib-common/include/ExcelComponent.h"
#include "../lib-common/include/NacosClient.h"
#include "../lib-common/include/FastDfsClient.h"


bool DeviceManageService::updateData(const DeviceManageDTO::Wrapper& dto)
{


	// 组装DO数据
	DeviceManageDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SubjectId, subjectId, SubjectCode, subjectCode, SubjectName, subjectName, 
		SubjectType, subjectType, SubjectContent, subjectContent, SubjectStandard, subjectStandard, EnableFlag, enableFlag);


	// 执行数据修改
	DeviceManageDAO dao;
	return dao.update(data) == 1;
}

string DeviceManageService::creatExcel(const DeviceManageIdDTO::Wrapper& dto) 
{
	DeviceManageIdDO data;

	DeviceManageDAO dao;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SubjectId, subjectId);

	list<DeviceManageDO> result = dao.queryById(data);

	std::vector<std::vector<std::string>> vvexcel;
	vvexcel.insert(vvexcel.begin(), {
		ZH_WORDS_GETTER("device-manage.field.subjectId"),
		ZH_WORDS_GETTER("device-manage.field.subjectCode"),
		ZH_WORDS_GETTER("device-manage.field.subjectName"),
		ZH_WORDS_GETTER("device-manage.field.subjectType"),
		ZH_WORDS_GETTER("device-manage.field.subjectContent"),
		ZH_WORDS_GETTER("device-manage.field.subjectStandard"),
		ZH_WORDS_GETTER("device-manage.field.enableFlag"),
		});
	for (DeviceManageDO sub : result)
	{
		std::vector<string> v;
		v.push_back(sub.getSubjectId());
		v.push_back(sub.getSubjectCode());
		v.push_back(sub.getSubjectName());
		v.push_back(sub.getSubjectType());
		v.push_back(sub.getSubjectContent());
		v.push_back(sub.getSubjectStandard());
		v.push_back(sub.getEnableFlag());

		vvexcel.push_back(v);
	}


	//生成excel文件
	ExcelComponent excel;
	excel.writeVectorToFile(ZH_WORDS_GETTER("device-manage.excel.filePath"), ZH_WORDS_GETTER("device-manage.excel.sheetName"), vvexcel);

	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	// 获取文件后缀名
	string suffix = "";
	size_t pos = ZH_WORDS_GETTER("device-manage.excel.filePath").rfind(".");
	if (pos != string::npos)
	{
		suffix = ZH_WORDS_GETTER("device-manage.excel.filePath").substr(pos + 1);
	}
	// 上传文件
	string downloadUrl = dfs.uploadFile(ZH_WORDS_GETTER("device-manage.excel.filePath"));
	downloadUrl = urlPrefix + downloadUrl;

	OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());


	//删除本地生成的excel文件
	std::remove(ZH_WORDS_GETTER("device-manage.excel.filePath").c_str());
	return downloadUrl;
}


bool DeviceManageService::removeData(const DeviceManageIdDTO::Wrapper& dto)
{
	DeviceManageIdDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, SubjectId, subjectId);

	DeviceManageIdDAO dao;
	return dao.deleteById(data) >= 1;
}

uint64_t DeviceManageService::saveData(const DeviceManageAddDTO::Wrapper& dto)
{
	// 组装DO数据
	DeviceManageAddDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,SubjectCode, subjectCode, SubjectName, subjectName,
		SubjectType, subjectType, SubjectContent, subjectContent, SubjectStandard, subjectStandard, EnableFlag, enableFlag);
	// 执行数据添加
	DeviceManageDAO dao;
	return dao.insert(data);
}

