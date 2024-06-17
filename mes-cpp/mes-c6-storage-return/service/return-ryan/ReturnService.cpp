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

bool ReturnService::updateData(const ReturnDTO_r::Wrapper& dto)//传ReturnDetailDTO报错
{
	// 组装DO数据
	ReturnDO_r data;
	//rt_code rt_name po_code vendor_name batch_code rt_date status remark
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rt_id, rt_id, Rt_code, rt_code, Rt_name, rt_name, Po_code, po_code, Vendor_name, vendor_name, 
		Batch_code, batch_code, Rt_date, rt_date, Status_, status,  Remark, remark)
	// 执行数据修改
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
	//查看数据是否存在
	auto count = dao.count(query);
	//不存在返回空
	if (count < 1)
		return {};
	//查询所有数据
	auto dos = dao.selectWithPage(query, 1);
	return dos;

}

// 导入需要用到的组件
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "./FastDfsClient.h"
#include "gtest/gtest.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"
string ReturnService::exportTable(const ReturnQuery_r::Wrapper& query)
{
	ReturnDAO_r dao;
	std::vector<std::vector<std::string>> data; // Excel 的二维数组 data

	std::list<ReturnDO_r> res = dao.selectWithPage(query,1);

	data.push_back({
		ZH_WORDS_GETTER("return.fields.rt_id"),
		});

	// 填充数据
	for (ReturnDO_r item : res)
	{
		std::vector<std::string> row;
		row.push_back(std::to_string(item.getRt_id()));
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
	//return{};
	return string();
}
