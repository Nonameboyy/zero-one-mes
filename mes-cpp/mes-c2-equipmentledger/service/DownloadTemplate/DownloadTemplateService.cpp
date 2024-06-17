/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/05/26 21:31:39

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

#include <vector>
#include <sstream>
#include "stdafx.h"
#include "DownloadTemplateService.h"
#include "Macros.h"
#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "gtest/gtest.h"
#include "CharsetConvertHepler.h"

std::string DownloadTemplateService::download()
{
	std::vector<std::vector<std::string>> data;

	YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "1.1.1");

	data.push_back({
		ZH_WORDS_GETTER("equipment.fields.ecode"),
		ZH_WORDS_GETTER("equipment.fields.ename"),
		ZH_WORDS_GETTER("equipment.fields.brand"),
		ZH_WORDS_GETTER("equipment.fields.spec"),
		ZH_WORDS_GETTER("equipment.fields.tid"),
		ZH_WORDS_GETTER("equipment.fields.tcode"),
		ZH_WORDS_GETTER("equipment.fields.tname"),
		ZH_WORDS_GETTER("equipment.fields.workshopid"),
		ZH_WORDS_GETTER("equipment.fields.workshopname"),
		ZH_WORDS_GETTER("equipment.fields.status"),
	});

	// 调用Excel组件写入Excel文件，获取文件保存路径
	auto saveToExcel = [](const std::vector<std::vector<std::string>>& data,
		const std::string& sheet = "sheet1") -> std::string
		{
			// 定义保存的位置和sheet名
			std::stringstream ss;
			ss << "./public/excel/";
			ss << "ImportTemplate";
			ss << ".xlsx";

			std::string fileName = ss.str();
			std::string sheetName = CharsetConvertHepler::ansiToUtf8(sheet);

			// 保存到文件
			ExcelComponent excel;
			excel.writeVectorToFile(fileName, sheetName, data);
			return fileName; // 包括了前缀和后缀
		};
	
	std::string file = saveToExcel(data);

	auto changeFormat = [=]() -> bool
	{
		xlnt::workbook wb;
		try {
			wb.load(file);
		}
		catch (const xlnt::exception& e) {
			std::cerr << "xlnt Exception: " << e.what() << std::endl;
			return false;
		}

		auto ws = wb.active_sheet();
		// 将第一行设置背景色
		xlnt::fill back_color = xlnt::fill::solid(xlnt::color::black());
		xlnt::font title_color = xlnt::font().color(xlnt::color::white());
		xlnt::font font_size = xlnt::font().size(14);
		for (auto cell : ws.rows().front()) {
			cell.font(font_size);
			cell.font(title_color);
			cell.fill(back_color);
		}
		wb.save(file);
		return true;
	};
	
	if (!changeFormat()) {
		return "xlsx format error\n";
	}

	// 调用FastDFS组件上传文件到服务器，获取下载链接
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);

	std::string downloadUrl = dfs.uploadFile(file);
	return urlPrefix + downloadUrl;
}