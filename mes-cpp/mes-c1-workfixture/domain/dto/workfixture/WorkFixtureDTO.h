#pragma once
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 工装夹具数据模型（列表数据相比详情数据只少了一个备注，因此直接放置到一个类中）
 */
class WorkFixtureDTO : public oatpp::DTO
{
	DTO_INIT(WorkFixtureDTO, DTO);
	// 工装夹具唯一标识（注：唯一标识的获取需要和其他模块交互，调用外部接口）
	API_DTO_FIELD(UInt64, toolId, ZH_WORDS_GETTER("workfixture.fields.id"), true, 1);
	// 工装夹具编号
	API_DTO_FIELD_DEFAULT(String, toolCode, ZH_WORDS_GETTER("workfixture.fields.code"));
	// 工装夹具名称
	API_DTO_FIELD(String, toolName, ZH_WORDS_GETTER("workfixture.fields.name"), true, "");
	// 品牌
	API_DTO_FIELD_DEFAULT(String, brand, ZH_WORDS_GETTER("workfixture.fields.brand"));
	// 型号
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("workfixture.fields.spec"));
	// 工装夹具类型ID
	API_DTO_FIELD(Int64, toolTypeId, ZH_WORDS_GETTER("workfixture.type.fields.id"), true, 1);
	// 工装夹具类型编号
	API_DTO_FIELD(String, toolTypeCode, ZH_WORDS_GETTER("workfixture.type.fields.code"), true, "");
	// 工装夹具类型名称
	API_DTO_FIELD(String, toolTypeName, ZH_WORDS_GETTER("workfixture.type.fields.name"), true, "");
	// 数量（库存）
	API_DTO_FIELD(Int32, quantity, ZH_WORDS_GETTER("workfixture.fields.quantity"), true, 0);
	// 可用数量
	API_DTO_FIELD_DEFAULT(Int32, quantityAvail, ZH_WORDS_GETTER("workfixture.fields.aquantity"));
	// 保养维护类型
	API_DTO_FIELD_DEFAULT(String, maintenType, ZH_WORDS_GETTER("workfixture.fields.mtype"));
	// 下次保养周期（添加和修改操作均不涉及这个字段，暂时忽略）
	// API_DTO_FIELD_DEFAULT(Int32, nextMaintenPeriod, ZH_WORDS_GETTER("workfixture.fields.nmperiod"), false);
	// 下次保养日期
	API_DTO_FIELD_DEFAULT(String, nextMaintenDate, ZH_WORDS_GETTER("workfixture.fields.nmdate"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("workfixture.fields.status"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("workfixture.fields.remark"));
};

/**
 * 工装夹具分页传输对象
 */
class WorkFixturePageDTO : public PageDTO<WorkFixtureDTO::Wrapper>
{
	DTO_INIT(WorkFixturePageDTO, PageDTO<WorkFixtureDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)