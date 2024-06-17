#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/05/21 17:08

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
#ifndef _ADDRETURNDTO_H_
#define _ADDRETURNDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���������ݵ����ݴ���DTO
 */
class AddReturnDTO : public oatpp::DTO
{
	DTO_INIT(AddReturnDTO, DTO);
	// �˻���ID
	API_DTO_FIELD_DEFAULT(UInt64, rtid, ZH_WORDS_GETTER("material.rtid"));
	// �˻������
	API_DTO_FIELD_DEFAULT(String, rtcode, ZH_WORDS_GETTER("material.rtcode"));
	// �˻�������
	API_DTO_FIELD_DEFAULT(String, rtname, ZH_WORDS_GETTER("material.rtname"));
	// �ɹ��������
	API_DTO_FIELD_DEFAULT(String, pocode, ZH_WORDS_GETTER("material.pocode"));
	// ��Ӧ�̱���
	//API_DTO_FIELD_DEFAULT(String, vendorcode, ZH_WORDS_GETTER("material.vendorcode"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorname, ZH_WORDS_GETTER("material.vendorname"));
	// ���κ�
	API_DTO_FIELD_DEFAULT(String, batchcode, ZH_WORDS_GETTER("material.batchcode"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(String, rtdate, ZH_WORDS_GETTER("material.rtdate"));
	// ����״̬
	API_DTO_FIELD_DEFAULT(String, statuss, ZH_WORDS_GETTER("material.status"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("material.remark"));

};
/**
 * ����һ���޸����ݵ����ݴ���DTO
 */
class ModifyReturnDTO :public AddReturnDTO
{
	DTO_INIT(ModifyReturnDTO, DTO);
	// ��ID
	API_DTO_FIELD_DEFAULT(UInt64, lineid, ZH_WORDS_GETTER("material.lineid"));
	// ��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, itemcode, ZH_WORDS_GETTER("material.itemcode"));
	// ��Ʒ��������
	API_DTO_FIELD_DEFAULT(String, itemname, ZH_WORDS_GETTER("material.itemname"));
	// �˻�����
	API_DTO_FIELD_DEFAULT(Float64, quantityrted, ZH_WORDS_GETTER("material.quantityrted"));
	// ����ͺ�
	API_DTO_FIELD_DEFAULT(String, specification, ZH_WORDS_GETTER("material.specification"));
	// ��λ
	API_DTO_FIELD_DEFAULT(String, unitofmeasure, ZH_WORDS_GETTER("material.unitofmeasure"));
	// ���κ�
	API_DTO_FIELD_DEFAULT(String, batchcode, ZH_WORDS_GETTER("material.batchcode"));
	// �ֿ�ID
	API_DTO_FIELD_DEFAULT(UInt64, warehouseid, ZH_WORDS_GETTER("material.warehouseid"));
	// �ֿ�����
	API_DTO_FIELD_DEFAULT(String, warehousename, ZH_WORDS_GETTER("material.warehousename"));
	// ����ID
	API_DTO_FIELD_DEFAULT(UInt64, locationid, ZH_WORDS_GETTER("material.locationid"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, locationname, ZH_WORDS_GETTER("material.locationname"));
	// ��λID
	API_DTO_FIELD_DEFAULT(UInt64, areaid, ZH_WORDS_GETTER("material.areaid"));
	// ��λ����
	API_DTO_FIELD_DEFAULT(String, areaname, ZH_WORDS_GETTER("material.areaname"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("material.remark"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // _ADDRETURNDTO_H_
