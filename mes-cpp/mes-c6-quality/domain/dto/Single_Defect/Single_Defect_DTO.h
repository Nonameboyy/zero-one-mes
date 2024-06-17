#pragma once
#ifndef Single_Defect_DTO_H
#define Single_Defect_DTO_H

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class SingleDTO :public oatpp::DTO
{
	DTO_INIT(SingleDTO, DTO);
	//记录ID
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("inspect.single.line_id"));
	//检验单ID
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("inspect.single.iqc_id"));
	// 检测项ID
	API_DTO_FIELD_DEFAULT(UInt64, index_id, ZH_WORDS_GETTER("inspect.single.index_id"));
	//检测项编码                  
	API_DTO_FIELD_DEFAULT(String, index_code, ZH_WORDS_GETTER("inspect.single.index_code"));
	//检测项名称
	API_DTO_FIELD_DEFAULT(String, index_name, ZH_WORDS_GETTER("inspect.single.index_name"));
	//检测项类型
	API_DTO_FIELD_DEFAULT(String, index_type, ZH_WORDS_GETTER("inspect.single.index_type"));
	//检测工具
	API_DTO_FIELD_DEFAULT(String, qc_tool, ZH_WORDS_GETTER("inspect.single.qc_tool"));
	//检测要求
	API_DTO_FIELD_DEFAULT(String, check_method, ZH_WORDS_GETTER("inspect.single.check_method"));
	//标准值
	API_DTO_FIELD_DEFAULT(Float64, stander_val, ZH_WORDS_GETTER("inspect.single.stander_val"));
	//单位
	API_DTO_FIELD_DEFAULT(String, unit_of_measure, ZH_WORDS_GETTER("inspect.single.unit_of_measure"));
	//误差上限
	API_DTO_FIELD_DEFAULT(Float64, threshold_max, ZH_WORDS_GETTER("inspect.single.threshold_max"));
	//误差下限
	API_DTO_FIELD_DEFAULT(Float64, threshold_min, ZH_WORDS_GETTER("inspect.single.threshold_min"));
	//致命缺陷数量
	API_DTO_FIELD_DEFAULT(Int64, cr_quantity, ZH_WORDS_GETTER("inspect.cr_quantity"));
	//严重缺陷数量
	API_DTO_FIELD_DEFAULT(Int64, maj_quantity, ZH_WORDS_GETTER("inspect.maj_quantity"));
	//轻微缺陷数量
	API_DTO_FIELD_DEFAULT(Int64, min_quantity, ZH_WORDS_GETTER("inspect.min_quantity"));
	//检测项备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("inspect.single.index_remark"));
};

class SinglePageDTO : public PageDTO<SingleDTO::Wrapper>
{
	DTO_INIT(SinglePageDTO, PageDTO<SingleDTO::Wrapper>);
};

//缺陷信息
class DefectDTO : public oatpp::DTO
{
	DTO_INIT(DefectDTO, DTO);
	//缺陷ID(唯一标识)
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("single.record_id"));
	//来料检验单ID
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("single.iqc_id"));
	////检验单类型
	//API_DTO_FIELD_DEFAULT(String, qc_type, ZH_WORDS_GETTER("single.qc_type"));
	////检验单ID
	//API_DTO_FIELD_DEFAULT(UInt64, qc_id, ZH_WORDS_GETTER("single.qc_id"));
	//来料检验单行ID
	API_DTO_FIELD_DEFAULT(UInt64, line_id, ZH_WORDS_GETTER("single.line"));
	//缺陷描述
	API_DTO_FIELD_DEFAULT(String, defect_name, ZH_WORDS_GETTER("single.defect_name"));
	//缺陷等级
	API_DTO_FIELD_DEFAULT(String, defect_level, ZH_WORDS_GETTER("single.defect_level"));
	//缺陷数量
	API_DTO_FIELD_DEFAULT(Int64, defect_quantity, ZH_WORDS_GETTER("single.defect_quantity"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("single.remark"));
	
};

//缺陷分页
class DefectPageDTO : public PageDTO<DefectDTO::Wrapper>
{
	DTO_INIT(DefectPageDTO, PageDTO<DefectDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !Single_Defect_DTO_H
