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
 * 定义一个获取获取设备列表的数据传输模型
 */
class EquipmentDTO : public oatpp::DTO
{
	DTO_INIT(EquipmentDTO, DTO);
	//唯一标识
	API_DTO_FIELD(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"), true, 1);
	//设备编码
	API_DTO_FIELD(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"), true, "M0065");
	//设备名称
	API_DTO_FIELD(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"), true, "test");
	//品牌
	API_DTO_FIELD(String, brand, ZH_WORDS_GETTER("equipment.fields.brand"), true, "test");
	//规格型号
	API_DTO_FIELD(String, spec, ZH_WORDS_GETTER("equipment.fields.spec"), true, "test");
	//所属车间ID
	API_DTO_FIELD(UInt64, workshopId, ZH_WORDS_GETTER("equipment.fields.workshopid"), true, 212);
	//所属车间编码
	API_DTO_FIELD(String, workshopCode, ZH_WORDS_GETTER("equipment.fields.workshopcode"), true, "WS078");
	//所属车间名称
	API_DTO_FIELD(String, workshopName, ZH_WORDS_GETTER("equipment.fields.workshopname"), true, "wujinchejian");
	//设备状态
	API_DTO_FIELD(String, status, ZH_WORDS_GETTER("equipment.fields.status"), true, "STOP");
	//创建时间
	API_DTO_FIELD(String, createtime, ZH_WORDS_GETTER("equipment.fields.ct"), true, "2022-04-07 00:29:30");

};
/**
 * 定义一个新增设备的数据传输模型
 */
class addEquipmentDTO :public oatpp::DTO
{
	DTO_INIT(addEquipmentDTO, DTO);
	
	//设备编码
	API_DTO_FIELD_DEFAULT(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"));
	//设备名称
	API_DTO_FIELD_DEFAULT(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"));
	//品牌
	API_DTO_FIELD_DEFAULT(String, brand, ZH_WORDS_GETTER("equipment.fields.brand"));
	//设备分类ID
	API_DTO_FIELD_DEFAULT(UInt64, tId, ZH_WORDS_GETTER("equipment.fields.tid"));
	//规格型号
	API_DTO_FIELD_DEFAULT(String,spec , ZH_WORDS_GETTER("equipment.fields.spec"));
	//所属车间ID
	API_DTO_FIELD_DEFAULT(UInt64, workshopId, ZH_WORDS_GETTER("equipment.fields.workshopid"));
	//备注
	API_DTO_FIELD_DEFAULT(String, note, ZH_WORDS_GETTER("equipment.fields.note"));

};
/**
* 定义一个设备详情传输对象
*/
class EquipmentDetailDTO : public oatpp::DTO
{
	DTO_INIT(EquipmentDetailDTO, DTO);
	//设备ID
	API_DTO_FIELD(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"), true, 1);
	//设备编码
	API_DTO_FIELD(String, eCode, ZH_WORDS_GETTER("equipment.fields.ecode"), true, "M0065");
	//设备名称
	API_DTO_FIELD(String, eName, ZH_WORDS_GETTER("equipment.fields.ename"), true, "test");
	//品牌
	API_DTO_FIELD(String, brand, ZH_WORDS_GETTER("equipment.fields.brand"), true, "test");
	//规格型号
	API_DTO_FIELD(String, spec, ZH_WORDS_GETTER("equipment.fields.spec"), true, "test");
	//所属车间ID
	API_DTO_FIELD(UInt64, workshopId, ZH_WORDS_GETTER("equipment.fields.workshopid"), true, 2);
	//所属车间编码
	API_DTO_FIELD(String, workshopCode, ZH_WORDS_GETTER("equipment.fields.workshopcode"), true, "WS078");
	//所属车间名称
	API_DTO_FIELD(String, workshopName, ZH_WORDS_GETTER("equipment.fields.workshopname"), true, "wujinchejian");
	//设备类型Id
	API_DTO_FIELD(UInt64, tId, ZH_WORDS_GETTER("equipment.fields.tid"), true, 1);
	//设备类型编码
	API_DTO_FIELD(String, tCode, ZH_WORDS_GETTER("equipment.fields.tcode"), true, "M_TYPE_002");
	//设备类型名称
	API_DTO_FIELD(String, tName, ZH_WORDS_GETTER("equipment.fields.tname"), true, "zhusuji");
	//备注
	API_DTO_FIELD(String, note, ZH_WORDS_GETTER("equipment.fields.note"), true, "wu");
};
/**
* 定义一个修改设备传输对象
*/
class modifyEquipmentDTO : public addEquipmentDTO
{

	DTO_INIT(modifyEquipmentDTO, addEquipmentDTO);
	//唯一标识
	API_DTO_FIELD_DEFAULT(UInt64, eId, ZH_WORDS_GETTER("equipment.fields.id"));
};

/**
* 定义一个设备列表分页传输对象
*/

class EquipmentPageDTO : public PageDTO< EquipmentDTO::Wrapper>
{
	DTO_INIT(EquipmentPageDTO, PageDTO< EquipmentDTO::Wrapper>);
	
};




#include OATPP_CODEGEN_END(DTO)
#endif // 
