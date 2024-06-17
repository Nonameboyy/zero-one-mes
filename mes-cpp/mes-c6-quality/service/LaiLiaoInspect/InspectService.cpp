#include "stdafx.h"
#include "InspectService.h"
#include "../../dao/LaiLiaoInspect/InspectDAO.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"

//查询来料检验列表
InspectPageDTO::Wrapper InspectService::listAll(const InspectQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = InspectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	InspectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<InspectDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (InspectDO sub : result)
	{
		auto dto = InspectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, iqc_id, Iqc_id, iqc_code, Iqc_code, iqc_name, Iqc_name, template_id, Template_id, vendor_id, Vendor_id, vendor_code, Vendor_code, vendor_name, Vendor_name, vendor_nick, Vendor_nick, vendor_batch, Vendor_batch, item_code, Item_code, item_name, Item_name);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, quantity_recived, Quantity_recived, quantity_check, Quantity_check, quantity_unqualified, Quantity_unqualified, check_result, Check_result, recive_date, Recive_date, inspect_date, Inspect_date, inspector, Inspector, list_status, List_status);
		pages->addData(dto);
	}
	return pages;
}

//查询来料检验详情
Inspect_detailDTO::Wrapper InspectService::list_detailone(const uint64_t iqc_id)
{
	// 构建返回对象

	// 查询数据总条数
	InspectDAO dao;
	Inspect_detailDO result = dao.selectWithID(iqc_id);
	// 将DO转换成DTO
		auto dto = Inspect_detailDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, iqc_id, Iqc_id, iqc_code, Iqc_code, iqc_name, Iqc_name, vendor_id, Vendor_id, vendor_code, Vendor_code, vendor_name, Vendor_name, vendor_nick, Vendor_nick, vendor_batch, Vendor_batch, item_code, Item_code);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, result, item_name, Item_name, quantity_recived, Quantity_recived, quantity_check, Quantity_check, quantity_unqualified, Quantity_unqualified, check_result, Check_result, recive_date, Recive_date, inspect_date, Inspect_date, inspector, Inspector, list_status, List_status)
		return dto;
}

//保存数据
uint64_t InspectService::saveData(const InspectDTO::Wrapper& dto)
{
	 //组装DO数据
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Iqc_id,iqc_id, Iqc_code, iqc_code, Iqc_name, iqc_name,  Template_id, template_id,  Vendor_id, vendor_id,  Vendor_code, vendor_code,  Vendor_name, vendor_name,  Vendor_nick, vendor_nick,  Vendor_batch, vendor_batch, Item_id,item_id, Item_code, item_code,  Item_name, item_name, Unit_of_measure, unit_of_measure, Quantity_recived, quantity_recived,  Quantity_check, quantity_check,  Quantity_unqualified, quantity_unqualified,  Check_result, check_result,  Recive_date, recive_date,  Inspect_date, inspect_date,  Inspector, inspector, List_status, list_status);
		 //执行数据添加
		InspectDAO dao;
	return dao.insert(data);
}

//修改数据
bool InspectService::updateData(const InspectDTO::Wrapper& dto)
{
	// 组装DO数据
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Iqc_code, iqc_code, Iqc_name, iqc_name,  Vendor_code, vendor_code, Vendor_nick, vendor_nick, Vendor_batch, vendor_batch,Item_code, item_code, Item_name, item_name, Unit_of_measure, unit_of_measure, Quantity_recived, quantity_recived, Quantity_check, quantity_check, Quantity_unqualified, quantity_unqualified, Check_result, check_result, Recive_date, recive_date, Inspect_date, inspect_date, List_status, list_status, Remark, remark ,Iqc_id, iqc_id );
		// 执行数据修改
		InspectDAO dao;
	return dao.update(data) == 1;
}

//删除
bool InspectService::removeData(uint64_t id)
{
	InspectDAO dao;
	return dao.deleteById(id) == 1;
}

//确认检验单
bool InspectService::Is_Ok(const Item_idDTO::Wrapper& dto)
{
	// 组装DO数据
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Iqc_id, iqc_id);
	// 执行数据修改
	InspectDAO dao;

	return dao.Is_Ok(data) == 1;
}

//完成检验单
bool InspectService::Finished(const Item_idDTO::Wrapper& dto)
{
	// 组装DO数据
	InspectDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Iqc_id, iqc_id);
	// 执行数据修改
	InspectDAO dao;
	return dao.Finished(data) == 1;
}


// 导入需要用到的组件
#include "NacosClient.h"
#include "ExcelComponent.h"
#include "./FastDfsClient.h"
#include "gtest/gtest.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"
//导出检验单
string InspectService::exportTable(const Inspect_tableQuery::Wrapper& query)
{
	InspectDAO dao;
	std::vector<std::vector<std::string>> data; // Excel 的二维数组 data

	std::list<InspectDO> res = dao.selectAll(query);

	data.push_back({
		ZH_WORDS_GETTER("inspect.iqc_code"),
		ZH_WORDS_GETTER("inspect.iqc_name"),
		ZH_WORDS_GETTER("inspect.vendor_code"),
		ZH_WORDS_GETTER("inspect.vendor_name"),
		ZH_WORDS_GETTER("inspect.item_id"),
		ZH_WORDS_GETTER("inspect.item_code"),
		ZH_WORDS_GETTER("inspect.item_name"),
		ZH_WORDS_GETTER("inspect.specification"),
		ZH_WORDS_GETTER("inspect.unit_of_measure"),
		ZH_WORDS_GETTER("inspect.quantity_min_check"),
		ZH_WORDS_GETTER("inspect.quantity_max_unqualified"),
		ZH_WORDS_GETTER("inspect.quantity_recived"),
		ZH_WORDS_GETTER("inspect.quantity_check"),
		ZH_WORDS_GETTER("inspect.quantity_unqualified"),
		ZH_WORDS_GETTER("inspect.maj_rate"),
		ZH_WORDS_GETTER("inspect.min_rate"),
		ZH_WORDS_GETTER("inspect.cr_rate"),	
		ZH_WORDS_GETTER("inspect.maj_quantity"),
		ZH_WORDS_GETTER("inspect.min_quantity"),
		ZH_WORDS_GETTER("inspect.cr_quantity"),
		ZH_WORDS_GETTER("inspect.check_result"),
		ZH_WORDS_GETTER("inspect.recive_date"),
		ZH_WORDS_GETTER("inspect.inspect_date"),
		ZH_WORDS_GETTER("inspect.inspector"),
		ZH_WORDS_GETTER("inspect.list_status"),
		});

	// 填充数据
	for (InspectDO item : res)
	{
		std::vector<std::string> row;
		row.push_back(item.getIqc_code());
		row.push_back(item.getIqc_name());
		row.push_back(item.getVendor_code());
		row.push_back(item.getVendor_name());
		row.push_back(std::to_string(item.getItem_id()));
		row.push_back(item.getItem_code());
		row.push_back(item.getItem_name());
		row.push_back(item.getSpecification());
		row.push_back(item.getUnit_of_measure());
		row.push_back(std::to_string(item.getQuantity_min_check()));
		row.push_back(std::to_string(item.getQuantity_max_unqualified()));
		row.push_back(std::to_string(item.getQuantity_recived()));
		row.push_back(std::to_string(item.getQuantity_check()));
		row.push_back(std::to_string(item.getQuantity_unqualified()));
		row.push_back(std::to_string(item.getMaj_rate()));
		row.push_back(std::to_string(item.getMin_rate()));
		row.push_back(std::to_string(item.getCr_rate()));
		row.push_back(std::to_string(item.getMaj_quantity()));
		row.push_back(std::to_string(item.getMin_quantity()));
		row.push_back(std::to_string(item.getCr_quantity()));
		row.push_back(item.getCheck_result());
		row.push_back(item.getRecive_date());
		row.push_back(item.getInspect_date());
		row.push_back(item.getInspector());
		row.push_back(item.getList_status());
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
}