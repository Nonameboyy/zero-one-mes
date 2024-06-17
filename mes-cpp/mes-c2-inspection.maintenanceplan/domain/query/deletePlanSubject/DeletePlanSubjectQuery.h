#pragma once
/*
*
*/
#ifndef _DELETEPLANSUBJECTQUERY__H_
#define _DELETEPLANSUBJECTQUERY__H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 获取点检保养计划详情
*/

//dv_check_plan的，删除前，辅助查询query
class DeletePlanQuery : public oatpp::DTO
{
	DTO_INIT(DeletePlanQuery, DTO);

	// 计划ID
	//DTO_FIELD(Int64, plan_id);
	//DTO_FIELD_INFO(plan_id) 
	//{
	//	info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	//}
	static v_int64 Z__PROPERTY_OFFSET_plan_id() 
	{
		char buffer[sizeof(Z__CLASS)];
		auto obj = static_cast<Z__CLASS*>((void*)buffer);
		auto ptr = &obj->plan_id;
		return (v_int64)ptr - (v_int64)buffer;
	} 
	static oatpp::data::mapping::type::BaseObject::Property* Z__PROPERTY_SINGLETON_plan_id() 
	{
		static oatpp::data::mapping::type::BaseObject::Property* property = new oatpp::data::mapping::type::BaseObject::Property(Z__PROPERTY_OFFSET_plan_id(), "plan_id", Int64::Class::getType());
		return property;
	} 
	
	static bool Z__PROPERTY_INIT_plan_id(...) 
	{
		Z__CLASS_GET_FIELDS_MAP()->pushBack(Z__PROPERTY_SINGLETON_plan_id());
		return true;
	} 
	static Int64 Z__PROPERTY_INITIALIZER_PROXY_plan_id() 
	{
		static bool initialized = Z__PROPERTY_INIT_plan_id(1, 1); 
		(void)initialized;
		return Int64();
	} 
	
	Int64 plan_id = Z__PROPERTY_INITIALIZER_PROXY_plan_id();

	static bool Z__PROPERTY_INIT_plan_id(int, ...) 
	{
		Z__PROPERTY_INIT_plan_id();
		Z__PROPERTY_ADD_INFO_plan_id(&Z__PROPERTY_SINGLETON_plan_id()->info);
		return true;
	}
	static void Z__PROPERTY_ADD_INFO_plan_id(oatpp::data::mapping::type::BaseObject::Property::Info* info)
	{
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}

	//abf为了改值加入的函数方法
public:
	void setPlan_id(Int64 id)
	{
		this->plan_id = id;
	}
};

//dv_check_subject的，删除前，辅助查询query
class DeletePlanSubjectQuery : public oatpp::DTO
{
	DTO_INIT(DeletePlanSubjectQuery, DTO);

	// 只用流水号去查询，而且是单个流水号
	DTO_FIELD(Int64, record_id);
	DTO_FIELD_INFO(record_id)
	{
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.recordId");
	}

	//abf为了改值加入的函数方法
public:
	void setRecord_id(Int64 id)
	{
		this->record_id = id;
	}
};

//dv_check_machinery的，删除前，辅助查询query
class DeletePlanMachineryQuery : public oatpp::DTO
{
	DTO_INIT(DeletePlanMachineryQuery, DTO);

	// 只用流水号去查询，而且是单个流水号
	DTO_FIELD(Int64, record_id);
	DTO_FIELD_INFO(record_id)
	{
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.recordId");
	}

	//abf为了改值加入的函数方法
public:
	void setRecord_id(Int64 id)
	{
		this->record_id = id;
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // 
