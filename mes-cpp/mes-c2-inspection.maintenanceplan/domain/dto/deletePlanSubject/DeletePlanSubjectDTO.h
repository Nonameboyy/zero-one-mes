#pragma once
/*
* 
*/
#ifndef _DELETEPLANSUBJECT_H_
#define _DELETEPLANSUBJECT_H_

#include "../mes-c2-inspection.maintenanceplan/domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 列表DTO，可以将DTO分装成List
 * 列表类的设计来自：。好
 */

 // 利用列表DTO，来支持批量删除，如果其他人也需要的话，可以把这个类放成公共的
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, oatpp::DTO)
		// 数据列表
		API_DTO_FIELD(List<T>, item, ZH_WORDS_GETTER("list_dto"), false, {});
	//
public:
	// 添加一条数据
	void addItem(const T& item) {
		this->item->push_back(item);
	}
};

/**
 * 删除设备DTO
 * 设计参考来自：。好
 */

 // 继承自ListDTO
class DeletePlanSubjectDTO : public ListDTO<oatpp::String>
{
	DTO_INIT(DeletePlanSubjectDTO, ListDTO<oatpp::String>);
};

//在联表情况下是两个表的主键字段，一对多时是id+idList
// 除了list还要另一个主键，id
class DeletePlanSubjectOneToManyDTO :public ListDTO<oatpp::String>
{
	DTO_INIT(DeletePlanSubjectOneToManyDTO, ListDTO<oatpp::String>)
	API_DTO_FIELD_DEFAULT(UInt64, primaryKey, ZH_WORDS_GETTER("planSubject.inputDESC.delOneToMany.primaryKey"));
};

//----------------abf，扩充，删除操作对单表应该知道表名和主键【进入页面时就给表名，勾选就给主键，发送就开始操作

/*用于只有一个主键的表（id）*/
class DeleteTableUniqueDTO :public ListDTO<oatpp::Int64>
{
	//List
	DTO_INIT(DeleteTableUniqueDTO, ListDTO<oatpp::Int64>)
	//表名
	//API_DTO_FIELD_DEFAULT(String,tableName , ZH_WORDS_GETTER("planSubject.deleteTemplate.DESC.tableName"));
};

/*用于联表，有主次双主键（id，idList）*/
class DeleteTableSharedDTO :public ListDTO<oatpp::Int64>
{
	//List（从属表的主键序列）
	DTO_INIT(DeleteTableSharedDTO, ListDTO<oatpp::Int64>)
	//从属表的表名称
	//API_DTO_FIELD_DEFAULT(String, tableNameSec, ZH_WORDS_GETTER("deleteTemplate.DESC.tableNameSec"));
	//keyPri主表主键
	API_DTO_FIELD_DEFAULT(Int64, keyPri, ZH_WORDS_GETTER("deleteTemplate.DESC.keyPri"));
	//主表的表名称
	//API_DTO_FIELD_DEFAULT(String, tableNamePri, ZH_WORDS_GETTER("deleteTemplate.DESC.tableNamePri"));

};

//删除计划的机器
//class DeleteMachinerDTO :public DeleteTableSharedDTO
//{
//	DTO_INIT(DeleteMachinerDTO, DeleteTableSharedDTO)
//};
class DeleteMachinerDTO :public DeleteTableUniqueDTO
{
	DTO_INIT(DeleteMachinerDTO, DeleteTableUniqueDTO)
};


//删除计划的项目
//class DeleteSubjectDTO :public DeleteTableSharedDTO
//{
//	DTO_INIT(DeleteSubjectDTO, DeleteTableSharedDTO)
//};
class DeleteSubjectDTO :public DeleteTableUniqueDTO
{
	DTO_INIT(DeleteSubjectDTO, DeleteTableUniqueDTO)
};

/*删除点检/保养计划*/
class DeletePlanDTO :public DeleteTableUniqueDTO
{
	DTO_INIT(DeletePlanDTO, DeleteTableUniqueDTO)
};

//为了删除点检/保养计划记录的辅助查询

/**
* 点检/保养计划列表传输对象
*/
//该DTO用于辅助删除dv_check_plan表的查询
class DeletePlanQueryDTO : public oatpp::DTO
{
	DTO_INIT(DeletePlanQueryDTO, DTO);

	// 计划ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}
	// 计划编码
	DTO_FIELD(String, plan_code);
	DTO_FIELD_INFO(plan_code) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-code");
	}
	// 计划名称
	DTO_FIELD(String, plan_name);
	DTO_FIELD_INFO(plan_name) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-name");
	}
};

//该DTO用于辅助删除dv_check_subject表的查询
class DeletePlanSubjectQueryDTO : public oatpp::DTO
{
	DTO_INIT(DeletePlanSubjectQueryDTO, DTO);

	// 1、流水号
	DTO_FIELD(Int64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.recordId");
	}
	// 2、计划ID
	DTO_FIELD(Int64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.planId");
	}
	/// 3、项目id
	DTO_FIELD(Int64, subject_id);
	DTO_FIELD_INFO(subject_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.subjectId");
	}
	// 4、项目编码
	DTO_FIELD(String, subject_code);
	DTO_FIELD_INFO(subject_code) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.subjectCode");
	}
	// 5、项目名称
	DTO_FIELD(String, subject_name);
	DTO_FIELD_INFO(subject_name) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.subjectName");
	}
};

//该DTO用于辅助删除dv_check_machinery表的查询
class DeletePlanMachineryQueryDTO : public oatpp::DTO
{
	DTO_INIT(DeletePlanMachineryQueryDTO, DTO);

	// 1、流水号
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.recordId");
	}
	// 2、计划ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.planId");
	}
	/// 3、设备id
	DTO_FIELD(UInt64, machinery_id);
	DTO_FIELD_INFO(machinery_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.machineryId");
	}
	// 4、设备编码
	DTO_FIELD(String, machinery_code);
	DTO_FIELD_INFO(machinery_code) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.machineryCode");
	}
	// 5、设备名称
	DTO_FIELD(String, machinery_name);
	DTO_FIELD_INFO(machinery_name) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.machineryName");
	}
};

//
///**
//* 点检/保养计划列表分页传输对象
//*/
//
//class MachineryPlanPageDTO : public PageDTO<MachineryPlanDTO::Wrapper>
//{
//	DTO_INIT(MachineryPlanPageDTO, PageDTO<MachineryPlanDTO::Wrapper>);
//};
//
////template <class T>
//class MachineryPlanDetailsDTO : public MachineryPlanDTO
//{
//	DTO_INIT(MachineryPlanDetailsDTO, MachineryPlanDTO);
//
//	// 备注
//	DTO_FIELD(String, remark);
//	DTO_FIELD_INFO(remark) {
//		info->description = ZH_WORDS_GETTER("machinery-plan.field.remark");
//	}
//	//---abf扩展
//
//	/**
//	 * 数据的总条数
//	 */
//	DTO_FIELD(Int64, total) = 9;
//	DTO_FIELD_INFO(total) {
//		info->required = true;
//#ifndef LINUX
//		info->description = u8"数据的总条数";
//#else
//		info->description = "total";
//#endif
//	}
//
//	/**
//	 * 当前页数据列表
//	 */
//	DTO_FIELD(List<MachineryPlanDTO::Wrapper>, rows) = {};
//	DTO_FIELD_INFO(rows) {
//#ifndef LINUX
//		info->description = u8"当前页数据列表";
//#else
//		info->description = "page data list";
//#endif
//	}
//
//	MachineryPlanDetailsDTO() {
//		this->total = v_int64(0);
//	}
//	// 初始化所有内容
//	void initAll(Int64 total, List<MachineryPlanDTO::Wrapper> rows) {
//		this->total = total;
//		this->rows = rows;
//	}
//	void addData(MachineryPlanDTO::Wrapper one) {
//		this->rows->push_back(one);
//	}
//};


#include OATPP_CODEGEN_END(DTO)
//one - to - many
#endif // !_REMOVEDEVICEDTO_H_
