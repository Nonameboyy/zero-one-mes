#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _GETALLDETAILS_QUERY_
#define   _GETALLDETAILS_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//��ѯ�ֿ���������

class GetAllDetailsQuery :public oatpp::DTO
{
	DTO_INIT(GetAllDetailsQuery,DTO);
	// �ֿ�ID
	DTO_FIELD(UInt64, warehouse_id);
	DTO_FIELD_INFO(warehouse_id) {
		info->description = ZH_WORDS_GETTER("warehouse.field.warehouse_id");
	}
	//// �ֿ����
	//DTO_FIELD(UInt64, warehouse_code);
	//DTO_FIELD_INFO(warehouse_code) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.warehouse_code");
	//}
	//// �ֿ�����
	//DTO_FIELD(String, warehouse_name);
	//DTO_FIELD_INFO(warehouse_name) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.warehouse_name");
	//}
	//// λ��
	//DTO_FIELD(String, location);
	//DTO_FIELD_INFO(location) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.location");
	//}
	//// ���
	//DTO_FIELD(Float32, area);
	//DTO_FIELD_INFO(area) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.area");
	//}
	////������
	//DTO_FIELD(String, charge);
	//DTO_FIELD_INFO(charge) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.charge");
	//}
	////��ע
	//DTO_FIELD(String, remark);
	//DTO_FIELD_INFO(remark) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.remark");
	//}
	//// Ԥ���ֶ�1
	//DTO_FIELD(String, attr1);
	//DTO_FIELD_INFO(attr1) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.attr1");
	//}
	//// Ԥ���ֶ�2
	//DTO_FIELD(String, attr2);
	//DTO_FIELD_INFO(attr2) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.attr2");
	//}
	//// Ԥ���ֶ�3
	//DTO_FIELD(UInt64, attr3);
	//DTO_FIELD_INFO(attr3) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.attr3");
	//}
	//// Ԥ���ֶ�4
	//DTO_FIELD(UInt64, attr4);
	//DTO_FIELD_INFO(attr4) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.attr4");
	//}
	//// ������
	//DTO_FIELD(String, create_by);
	//DTO_FIELD_INFO(create_by) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.create_by");
	//}
	////����ʱ��
	//DTO_FIELD(String, create_time);
	//DTO_FIELD_INFO(create_time) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.create_time");
	//}
	//// ������
	//DTO_FIELD(String, update_by);
	//DTO_FIELD_INFO(update_by) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.update_by");
	//}
	//// ����ʱ��
	//DTO_FIELD(String, update_time);
	//DTO_FIELD_INFO(update_time) {
	//	info->description = ZH_WORDS_GETTER("warehouse.field.update_time");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_