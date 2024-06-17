/*
 Copyright Zero One Star. All rights reserved.

 @Author: 独自
 @Date: 2024/05/7 18:45:23

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
#include "ExportPlanService.h"
#include "dao/ExportPlan/ExportPlanDAO.h"
#include "domain/do/dv_check_plan/dv_check_planDO.h"
#include "Macros.h"
// 导入需要用到的组件
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "./FastDfsClient.h"
#include "gtest/gtest.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"

std::string ExportPlanService::exportPlan(const ExportPlanQuery::Wrapper& query)
{
	ExportPlanDAO dao;
	std::vector<std::vector<std::string>> data; // Excel 的二维数组 data

	std::list<Dv_check_planDO> res = dao.selectAll(query);

	data.push_back({
		ZH_WORDS_GETTER("maintenanceplan.fields.plancode"),
		ZH_WORDS_GETTER("maintenanceplan.fields.planname"),
		ZH_WORDS_GETTER("maintenanceplan.fields.plantype"),
		ZH_WORDS_GETTER("maintenanceplan.fields.startdate"),
		ZH_WORDS_GETTER("maintenanceplan.fields.enddata"),
		ZH_WORDS_GETTER("maintenanceplan.fields.cycletype"),
		ZH_WORDS_GETTER("maintenanceplan.fields.cyclecount"),
		ZH_WORDS_GETTER("maintenanceplan.fields.status"),
		
		});

	// 填充数据
	for (Dv_check_planDO item : res)
	{
		std::vector<std::string> row;
		row.push_back(item.getPlan_code());
		row.push_back(item.getPlan_name());
		row.push_back(item.getPlan_type());
		row.push_back(item.getStart_date());
		row.push_back(item.getEnd_date());
		row.push_back(item.getCycle_type());
		row.push_back(to_string(item.getCycle_count()));
		row.push_back(item.getStatus());
		data.push_back(row);
	}

	// 调用Excel组件写入Excel文件，获取文件保存路径
	auto saveToExcel = [](const std::vector<std::vector<std::string>>& data,
		const std::string& sheet = "sheet1") -> std::string
	{
		// 定义保存的位置和sheet名
		std::stringstream ss;
		ss << "./public/excel/";
		ss << SimpleDateTimeFormat::format("%Y%m%d_%H%M%S");
		ss << ".xlsx";

		std::string fileName = ss.str();
		std::string sheetName = CharsetConvertHepler::ansiToUtf8(sheet);

		// 保存到文件
		ExcelComponent excel;
		excel.writeVectorToFile(fileName, sheetName, data);
		return fileName; // 包括了前缀和后缀
	};

	// Excel文件
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


		// 遍历所有单元格，使其对齐
		xlnt::alignment center_align;
		center_align.horizontal(xlnt::horizontal_alignment::center);
		center_align.vertical(xlnt::vertical_alignment::center);
		for (auto row : ws.rows())
			for (auto cell : row)
				cell.alignment(center_align);


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