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
#ifndef _EQUIPMENTDTO_H_
#define _EQUIPMENTDTO_H_

#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ȡ��ȡ�豸�б�����ݴ���ģ��
 */
class EquipmentDTO : public oatpp::DTO
{
	DTO_INIT(EquipmentDTO, DTO);
	//Ψһ��ʶ
	API_DTO_FIELD(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"), true, 1);
	//�豸����
	API_DTO_FIELD(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"), true, "M0065");
	//�豸����
	API_DTO_FIELD(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"), true, "test");
	//Ʒ��
	API_DTO_FIELD(String, brand, ZH_WORDS_GETTER("equipment.fields.brand"), true, "test");
	//����ͺ�
	API_DTO_FIELD(String, spec, ZH_WORDS_GETTER("equipment.fields.spec"), true, "test");
	//��������ID
	API_DTO_FIELD(UInt64, workshopId, ZH_WORDS_GETTER("equipment.fields.workshopid"), true, 212);
	//�����������
	API_DTO_FIELD(String, workshopCode, ZH_WORDS_GETTER("equipment.fields.workshopcode"), true, "WS078");
	//������������
	API_DTO_FIELD(String, workshopName, ZH_WORDS_GETTER("equipment.fields.workshopname"), true, "wujinchejian");
	//�豸״̬
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("equipment.fields.status"), true, "STOP");
	//����ʱ��
	API_DTO_FIELD(String, createtime, ZH_WORDS_GETTER("equipment.fields.ct"), true, "2022-04-07 00:29:30");

};
/**
 * ����һ�������豸�����ݴ���ģ��
 */
class addEquipmentDTO :public oatpp::DTO
{
	DTO_INIT(addEquipmentDTO, DTO);
	
	//�豸����
	API_DTO_FIELD_DEFAULT(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"));
	//�豸����
	API_DTO_FIELD_DEFAULT(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"));
	//Ʒ��
	API_DTO_FIELD_DEFAULT(String, brand, ZH_WORDS_GETTER("equipment.fields.brand"));
	//�豸����ID
	API_DTO_FIELD_DEFAULT(UInt64, tId, ZH_WORDS_GETTER("equipment.fields.tid"));
	//����ͺ�
	API_DTO_FIELD_DEFAULT(String,spec , ZH_WORDS_GETTER("equipment.fields.spec"));
	//��������ID
	API_DTO_FIELD_DEFAULT(UInt64, workshopId, ZH_WORDS_GETTER("equipment.fields.workshopid"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, note, ZH_WORDS_GETTER("equipment.fields.note"));

};
/**
* ����һ���豸���鴫�����
*/
class EquipmentDetailDTO : public oatpp::DTO
{
	DTO_INIT(EquipmentDetailDTO, DTO);
	//�豸ID
	API_DTO_FIELD(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"), true, 1);
	//�豸����
	API_DTO_FIELD(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"), true, "M0065");
	//�豸����
	API_DTO_FIELD(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"), true, "test");
	//Ʒ��
	API_DTO_FIELD(String, brand, ZH_WORDS_GETTER("equipment.fields.brand"), true, "test");
	//����ͺ�
	API_DTO_FIELD(String, spec, ZH_WORDS_GETTER("equipment.fields.spec"), true, "test");
	//��������ID
	API_DTO_FIELD(UInt64, workshopId, ZH_WORDS_GETTER("equipment.fields.workshopid"), true, 2);
	//�����������
	API_DTO_FIELD(String, workshopCode, ZH_WORDS_GETTER("equipment.fields.workshopcode"), true, "WS078");
	//������������
	API_DTO_FIELD(String, workshopName, ZH_WORDS_GETTER("equipment.fields.workshopname"), true, "wujinchejian");
	//�豸����Id
	API_DTO_FIELD(UInt64, tId, ZH_WORDS_GETTER("equipment.fields.tid"), true, 1);
	//�豸���ͱ���
	API_DTO_FIELD(String, tCode, ZH_WORDS_GETTER("equipment.fields.tcode"), true, "M_TYPE_002");
	//�豸��������
	API_DTO_FIELD(String, tName, ZH_WORDS_GETTER("equipment.fields.tname"), true, "zhusuji");
	//��ע
	API_DTO_FIELD(String, note, ZH_WORDS_GETTER("equipment.fields.note"), true, "wu");
};
/**
* ����һ���޸��豸�������
*/
class modifyEquipmentDTO : public addEquipmentDTO
{

	DTO_INIT(modifyEquipmentDTO, addEquipmentDTO);
	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"));
};

/**
* ����һ���豸�б��ҳ�������
*/

class EquipmentPageDTO : public PageDTO< EquipmentDTO::Wrapper>
{
	DTO_INIT(EquipmentPageDTO, PageDTO< EquipmentDTO::Wrapper>);
	
};




#include OATPP_CODEGEN_END(DTO)
#endif // 
