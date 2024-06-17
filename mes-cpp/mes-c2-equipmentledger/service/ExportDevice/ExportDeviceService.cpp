/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����
 @Date: 2024/05/26 10:27:23

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
#include "ExportDeviceService.h"
#include "dao/ExportDevice/ExportDeviceDAO.h"
#include "domain/do/dv_machinery/dvMachineryDO.h"
#include "Macros.h"
// ������Ҫ�õ������
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "./FastDfsClient.h"
#include "gtest/gtest.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"

std::string ExportDeviceService::exportDevice(const ExportDeviceQuery::Wrapper& query)
{
	ExportDeviceDAO dao;
	std::vector<std::vector<std::string>> data; // Excel �Ķ�ά���� data

	std::list<dvMachineryDO> res = dao.selectAll(query);

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

	// �������
	for (dvMachineryDO item : res)
	{
		std::vector<std::string> row;
		row.push_back(item.getMachineryCode());
		row.push_back(item.getMachineryName());
		row.push_back(item.getMachineryBrand());
		row.push_back(item.getMachinerySpec());
		row.push_back(to_string(item.getMachineryTypeId()));
		row.push_back(item.getMachineryTypeCode());
		row.push_back(item.getMachineryTypeName());
		row.push_back(to_string(item.getWorkshopId()));
		row.push_back(item.getWorkshopName());
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