#pragma once
#ifndef _REJECT_DTO_
#define _REJECT_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 退料列表数据模型
 */
class RejectTableDTO : public oatpp::DTO
{
	DTO_INIT(RejectTableDTO, DTO);
	// 退料单id（唯一）
	API_DTO_FIELD(UInt64, rt_id, ZH_WORDS_GETTER("reject.fields.id"), true,1);
	// 退料单编号
	API_DTO_FIELD(String, rt_code, ZH_WORDS_GETTER("reject.fields.rt_code"), true, "rt_code");
	// 退料单名称
	API_DTO_FIELD(String,rt_name, ZH_WORDS_GETTER("reject.fields.rt_name"), true, "rt_name");
	// 生产工单id
	API_DTO_FIELD(String, workorder_id, ZH_WORDS_GETTER("reject.fields.workorder_id"), true, "workorder_id");
	// 仓库名称
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("reject.fields. warehouse_name"), true, " warehouse_name");
	//库区名称
	API_DTO_FIELD(String, location_name, ZH_WORDS_GETTER("reject.fields.location_name"), true, "01star");
	//库位名称
	API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("reject.fields.area_name"), true, "01star");
	//退料日期
	API_DTO_FIELD(String, rt_date, ZH_WORDS_GETTER("reject.fields.rt_date"), true, "2024-05-17 00:29:30");
	//单据状态
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("reject.fields.status"), true, "default");
};

/**
 * 部门详情数据模型
 */
class RejectDetailDTO : public RejectTableDTO
{
	DTO_INIT(RejectDetailDTO, RejectTableDTO);
	// .......
	// 生产工单编码
	API_DTO_FIELD(String, workorder_code, ZH_WORDS_GETTER("reject.fields.workorder_code"), true, "workorder_code");
	//仓库id
	API_DTO_FIELD(String, warehouse_id, ZH_WORDS_GETTER("reject.fields.warehouse_idbh"), true, "warehouse_id");
	//仓库编码
	API_DTO_FIELD(String,warehouse_code , ZH_WORDS_GETTER("reject.fields.warehouse_code"), true, "warehouse_code");
	//库区id
	 API_DTO_FIELD(String, location_id, ZH_WORDS_GETTER("reject.fields.location_id"), true, "location_id");
	//库区编码
	 API_DTO_FIELD(String, location_code, ZH_WORDS_GETTER("reject.fields.location_code"), true, "location_code");
	//库位id
	 API_DTO_FIELD(String, area_id, ZH_WORDS_GETTER("reject.fieldsarea_id"), true, "area_id");
	//库位编码
	 API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("reject.fields.area_code"), true, "area_code");
	 //...

	//接收仓库
	API_DTO_FIELD(String, rsname, ZH_WORDS_GETTER("reject.fields.receivedstorage"), true, "receivedstorage");

	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("reject.fields.remark"), true, "remark");
};

/**
 * 退料列表分页传输对象
 */
class RejectPageDTO : public PageDTO<RejectTableDTO::Wrapper>
{
	DTO_INIT(RejectPageDTO, PageDTO<RejectTableDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_#pragma once
