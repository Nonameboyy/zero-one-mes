#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/18 23:14

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
#ifndef _REPAIRCONTENT_DTO_
#define _REPAIRCONTENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 维修内容传输对象
 */
class RepaircontentDTO : public oatpp::DTO
{
	DTO_INIT(RepaircontentDTO, DTO);
	
	//行id(主键primary key)
	API_DTO_FIELD(UInt64, line_id, ZH_WORDS_GETTER("repaircontent.field.line_id"), true, 1);
	//维修单id唯一标识(隐藏的)
	API_DTO_FIELD(UInt64, repair_id, ZH_WORDS_GETTER("repaircontent.field.repair_id"), true, 1);
	//项目id
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.field.subject_id"), true, 1);
	//项目编码
	API_DTO_FIELD(String, subject_code, ZH_WORDS_GETTER("repaircontent.field.subject_code"), true, "");
	//项目名称
	API_DTO_FIELD(String, subject_name, ZH_WORDS_GETTER("repaircontent.field.subject_name"), true, ZH_WORDS_GETTER("repaircontent.default.subject_name"));
	//项目类型
	API_DTO_FIELD(String, subject_type, ZH_WORDS_GETTER("repaircontent.field.subject_type"), true, "");
	//项目内容
	API_DTO_FIELD(String, subject_content, ZH_WORDS_GETTER("repaircontent.field.subject_content"), true, "");
	//标准
	//API_DTO_FIELD(String, subject_standard, ZH_WORDS_GETTER("repaircontent.field.subject_standard"), true, "");

	//故障描述
	API_DTO_FIELD(String, malfunction, ZH_WORDS_GETTER("repaircontent.field.malfunction"), true, "");
	//故障资源描述
	API_DTO_FIELD(String, malfunction_url, ZH_WORDS_GETTER("repaircontent.field.malfunction_url"), true, "");
	//维修情况
	API_DTO_FIELD(String, repair_des, ZH_WORDS_GETTER("repaircontent.field.repair_des"), true, "");
	//创建者
	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("repaircontent.field.create_by"), true, "");
	//创建时间
	API_DTO_FIELD(String, create_time, ZH_WORDS_GETTER("repaircontent.field.create_time"), true, "");
	//更新者
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("repaircontent.field.update_by"), true, "");
	//更新时间
	API_DTO_FIELD(String, update_time, ZH_WORDS_GETTER("repaircontent.field.update_time"), true, "");

	//备注
	//API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repaircontent.field.remark"), true, "");



};


class AddRepaircontentDTO : public oatpp::DTO
{
	DTO_INIT(AddRepaircontentDTO, DTO);

	//维修单id唯一标识(隐藏的)
	API_DTO_FIELD(UInt64, repair_id, ZH_WORDS_GETTER("repaircontent.field.repair_id"), true, 101);
	//项目id
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.field.subject_id"), true, 200);
	//故障描述
	API_DTO_FIELD(String, malfunction, ZH_WORDS_GETTER("repaircontent.field.malfunction"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction"));
	//故障资源描述
	API_DTO_FIELD(String, malfunction_url, ZH_WORDS_GETTER("repaircontent.field.malfunction_url"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction_url"));
	//维修情况
	API_DTO_FIELD(String, repair_des, ZH_WORDS_GETTER("repaircontent.field.repair_des"), true, ZH_WORDS_GETTER("repaircontent.default.repair_des"));
};

class ModifyRepaircontentDTO : public oatpp::DTO
{
	DTO_INIT(ModifyRepaircontentDTO, DTO);

	//行id(主键)
	API_DTO_FIELD(UInt64, line_id, ZH_WORDS_GETTER("repaircontent.field.line_id"), true, 101);
	//项目id
	API_DTO_FIELD(UInt64, subject_id, ZH_WORDS_GETTER("repaircontent.field.subject_id"), true, 200);
	//故障描述
	API_DTO_FIELD(String, malfunction, ZH_WORDS_GETTER("repaircontent.field.malfunction"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction"));
	//故障资源描述
	API_DTO_FIELD(String, malfunction_url, ZH_WORDS_GETTER("repaircontent.field.malfunction_url"), true, ZH_WORDS_GETTER("repaircontent.default.malfunction_url"));
	//维修情况
	API_DTO_FIELD(String, repair_des, ZH_WORDS_GETTER("repaircontent.field.repair_des"), true, ZH_WORDS_GETTER("repaircontent.default.repair_des"));

};

/**
 * 维修内容分页传输对象
 */
class RepaircontentPageDTO : public PageDTO<RepaircontentDTO::Wrapper>
{
	DTO_INIT(RepaircontentPageDTO, PageDTO<RepaircontentDTO::Wrapper>);

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPAIRCONTENT_DTO_