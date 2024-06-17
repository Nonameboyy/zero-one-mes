#pragma once
/*
* 
*/
#ifndef _DELETEPLANSUBJECT_H_
#define _DELETEPLANSUBJECT_H_

#include "../mes-c2-inspection.maintenanceplan/domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �б�DTO�����Խ�DTO��װ��List
 * �б����������ԣ�����
 */

 // �����б�DTO����֧������ɾ�������������Ҳ��Ҫ�Ļ������԰������ųɹ�����
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, oatpp::DTO)
		// �����б�
		API_DTO_FIELD(List<T>, item, ZH_WORDS_GETTER("list_dto"), false, {});
	//
public:
	// ���һ������
	void addItem(const T& item) {
		this->item->push_back(item);
	}
};

/**
 * ɾ���豸DTO
 * ��Ʋο����ԣ�����
 */

 // �̳���ListDTO
class DeletePlanSubjectDTO : public ListDTO<oatpp::String>
{
	DTO_INIT(DeletePlanSubjectDTO, ListDTO<oatpp::String>);
};

//�������������������������ֶΣ�һ�Զ�ʱ��id+idList
// ����list��Ҫ��һ��������id
class DeletePlanSubjectOneToManyDTO :public ListDTO<oatpp::String>
{
	DTO_INIT(DeletePlanSubjectOneToManyDTO, ListDTO<oatpp::String>)
	API_DTO_FIELD_DEFAULT(UInt64, primaryKey, ZH_WORDS_GETTER("planSubject.inputDESC.delOneToMany.primaryKey"));
};

//----------------abf�����䣬ɾ�������Ե���Ӧ��֪������������������ҳ��ʱ�͸���������ѡ�͸����������;Ϳ�ʼ����

/*����ֻ��һ�������ı�id��*/
class DeleteTableUniqueDTO :public ListDTO<oatpp::Int64>
{
	//List
	DTO_INIT(DeleteTableUniqueDTO, ListDTO<oatpp::Int64>)
	//����
	//API_DTO_FIELD_DEFAULT(String,tableName , ZH_WORDS_GETTER("planSubject.deleteTemplate.DESC.tableName"));
};

/*��������������˫������id��idList��*/
class DeleteTableSharedDTO :public ListDTO<oatpp::Int64>
{
	//List����������������У�
	DTO_INIT(DeleteTableSharedDTO, ListDTO<oatpp::Int64>)
	//������ı�����
	//API_DTO_FIELD_DEFAULT(String, tableNameSec, ZH_WORDS_GETTER("deleteTemplate.DESC.tableNameSec"));
	//keyPri��������
	API_DTO_FIELD_DEFAULT(Int64, keyPri, ZH_WORDS_GETTER("deleteTemplate.DESC.keyPri"));
	//����ı�����
	//API_DTO_FIELD_DEFAULT(String, tableNamePri, ZH_WORDS_GETTER("deleteTemplate.DESC.tableNamePri"));

};

//ɾ���ƻ��Ļ���
//class DeleteMachinerDTO :public DeleteTableSharedDTO
//{
//	DTO_INIT(DeleteMachinerDTO, DeleteTableSharedDTO)
//};
class DeleteMachinerDTO :public DeleteTableUniqueDTO
{
	DTO_INIT(DeleteMachinerDTO, DeleteTableUniqueDTO)
};


//ɾ���ƻ�����Ŀ
//class DeleteSubjectDTO :public DeleteTableSharedDTO
//{
//	DTO_INIT(DeleteSubjectDTO, DeleteTableSharedDTO)
//};
class DeleteSubjectDTO :public DeleteTableUniqueDTO
{
	DTO_INIT(DeleteSubjectDTO, DeleteTableUniqueDTO)
};

/*ɾ�����/�����ƻ�*/
class DeletePlanDTO :public DeleteTableUniqueDTO
{
	DTO_INIT(DeletePlanDTO, DeleteTableUniqueDTO)
};

//Ϊ��ɾ�����/�����ƻ���¼�ĸ�����ѯ

/**
* ���/�����ƻ��б������
*/
//��DTO���ڸ���ɾ��dv_check_plan��Ĳ�ѯ
class DeletePlanQueryDTO : public oatpp::DTO
{
	DTO_INIT(DeletePlanQueryDTO, DTO);

	// �ƻ�ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}
	// �ƻ�����
	DTO_FIELD(String, plan_code);
	DTO_FIELD_INFO(plan_code) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-code");
	}
	// �ƻ�����
	DTO_FIELD(String, plan_name);
	DTO_FIELD_INFO(plan_name) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-name");
	}
};

//��DTO���ڸ���ɾ��dv_check_subject��Ĳ�ѯ
class DeletePlanSubjectQueryDTO : public oatpp::DTO
{
	DTO_INIT(DeletePlanSubjectQueryDTO, DTO);

	// 1����ˮ��
	DTO_FIELD(Int64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.recordId");
	}
	// 2���ƻ�ID
	DTO_FIELD(Int64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.planId");
	}
	/// 3����Ŀid
	DTO_FIELD(Int64, subject_id);
	DTO_FIELD_INFO(subject_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.subjectId");
	}
	// 4����Ŀ����
	DTO_FIELD(String, subject_code);
	DTO_FIELD_INFO(subject_code) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.subjectCode");
	}
	// 5����Ŀ����
	DTO_FIELD(String, subject_name);
	DTO_FIELD_INFO(subject_name) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.subjectName");
	}
};

//��DTO���ڸ���ɾ��dv_check_machinery��Ĳ�ѯ
class DeletePlanMachineryQueryDTO : public oatpp::DTO
{
	DTO_INIT(DeletePlanMachineryQueryDTO, DTO);

	// 1����ˮ��
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.recordId");
	}
	// 2���ƻ�ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.planId");
	}
	/// 3���豸id
	DTO_FIELD(UInt64, machinery_id);
	DTO_FIELD_INFO(machinery_id) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.machineryId");
	}
	// 4���豸����
	DTO_FIELD(String, machinery_code);
	DTO_FIELD_INFO(machinery_code) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.machineryCode");
	}
	// 5���豸����
	DTO_FIELD(String, machinery_name);
	DTO_FIELD_INFO(machinery_name) {
		info->description = ZH_WORDS_GETTER("deleteQuery.planSubject.machineryName");
	}
};

//
///**
//* ���/�����ƻ��б��ҳ�������
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
//	// ��ע
//	DTO_FIELD(String, remark);
//	DTO_FIELD_INFO(remark) {
//		info->description = ZH_WORDS_GETTER("machinery-plan.field.remark");
//	}
//	//---abf��չ
//
//	/**
//	 * ���ݵ�������
//	 */
//	DTO_FIELD(Int64, total) = 9;
//	DTO_FIELD_INFO(total) {
//		info->required = true;
//#ifndef LINUX
//		info->description = u8"���ݵ�������";
//#else
//		info->description = "total";
//#endif
//	}
//
//	/**
//	 * ��ǰҳ�����б�
//	 */
//	DTO_FIELD(List<MachineryPlanDTO::Wrapper>, rows) = {};
//	DTO_FIELD_INFO(rows) {
//#ifndef LINUX
//		info->description = u8"��ǰҳ�����б�";
//#else
//		info->description = "page data list";
//#endif
//	}
//
//	MachineryPlanDetailsDTO() {
//		this->total = v_int64(0);
//	}
//	// ��ʼ����������
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
