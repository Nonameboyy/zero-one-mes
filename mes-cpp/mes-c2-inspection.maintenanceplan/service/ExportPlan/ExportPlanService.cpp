/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
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
// ������Ҫ�õ������
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "./FastDfsClient.h"
#include "gtest/gtest.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"

std::string ExportPlanService::exportPlan(const ExportPlanQuery::Wrapper& query)
{
	ExportPlanDAO dao;
	std::vector<std::vector<std::string>> data; // Excel �Ķ�ά���� data

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

	// �������
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

	// ����Excel���д��Excel�ļ�����ȡ�ļ�����·��
	auto saveToExcel = [](const std::vector<std::vector<std::string>>& data,
		const std::string& sheet = "sheet1") -> std::string
	{
		// ���屣���λ�ú�sheet��
		std::stringstream ss;
		ss << "./public/excel/";
		ss << SimpleDateTimeFormat::format("%Y%m%d_%H%M%S");
		ss << ".xlsx";

		std::string fileName = ss.str();
		std::string sheetName = CharsetConvertHepler::ansiToUtf8(sheet);

		// ���浽�ļ�
		ExcelComponent excel;
		excel.writeVectorToFile(fileName, sheetName, data);
		return fileName; // ������ǰ׺�ͺ�׺
	};

	// Excel�ļ�
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

		// ����һ�����ñ���ɫ
		xlnt::fill back_color = xlnt::fill::solid(xlnt::color::black());
		xlnt::font title_color = xlnt::font().color(xlnt::color::white());
		xlnt::font font_size = xlnt::font().size(14);
		for (auto cell : ws.rows().front()) {
			cell.font(font_size);
			cell.font(title_color);
			cell.fill(back_color);
		}


		// �������е�Ԫ��ʹ�����
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

	// ����FastDFS����ϴ��ļ�������������ȡ��������
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);

	std::string downloadUrl = dfs.uploadFile(file);
	return urlPrefix + downloadUrl;
}