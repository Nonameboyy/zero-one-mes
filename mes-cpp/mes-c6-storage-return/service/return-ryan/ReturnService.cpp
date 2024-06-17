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
#include "ReturnService.h"
#include "../../domain/do/return-ryan/ReturnDO_r.h"
#include "../../dao/return-ryan/ReturnDAO_r.h"

ReturnPageDTO_r::Wrapper ReturnService::listAll_r(const ReturnQuery_r::Wrapper& query)
{
	return {};
}

uint64_t ReturnService::saveData_r(const ReturnDTO_r::Wrapper& dto)
{
	return 0;
}

bool ReturnService::updateData(const ReturnDTO_r::Wrapper& dto)//��ReturnDetailDTO����
{
	// ��װDO����
	ReturnDO_r data;
	//rt_code rt_name po_code vendor_name batch_code rt_date status remark
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rt_id, rt_id, Rt_code, rt_code, Rt_name, rt_name, Po_code, po_code, Vendor_name, vendor_name, 
		Batch_code, batch_code, Rt_date, rt_date, Status_, status,  Remark, remark)
	// ִ�������޸�
	ReturnDAO_r dao;
	return dao.update(data) == 1;
}

bool ReturnService::removeData(uint64_t id)
{
	ReturnDAO_r dao;
	return dao.deleteById(id) == 1;
}

bool ReturnService::excuteData(uint64_t id)
{
	ReturnDAO_r dao;
	return dao.updateStatusById(id) == 1;
}

list<ReturnDO_r> ReturnService::listAllExort(const ReturnQuery_r::Wrapper& query)
{
	ReturnDAO_r dao;
	//�鿴�����Ƿ����
	auto count = dao.count(query);
	//�����ڷ��ؿ�
	if (count < 1)
		return {};
	//��ѯ��������
	auto dos = dao.selectWithPage(query, 1);
	return dos;

}

// ������Ҫ�õ������
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "./FastDfsClient.h"
#include "gtest/gtest.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"
string ReturnService::exportTable(const ReturnQuery_r::Wrapper& query)
{
	ReturnDAO_r dao;
	std::vector<std::vector<std::string>> data; // Excel �Ķ�ά���� data

	std::list<ReturnDO_r> res = dao.selectWithPage(query,1);

	data.push_back({
		ZH_WORDS_GETTER("return.fields.rt_id"),
		});

	// �������
	for (ReturnDO_r item : res)
	{
		std::vector<std::string> row;
		row.push_back(std::to_string(item.getRt_id()));
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
	//return{};
	return string();
}
