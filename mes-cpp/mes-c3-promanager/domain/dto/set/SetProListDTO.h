#pragma once

#ifndef _SETPROLIST_DTO_
#define _SETPROLIST_DTO_
#include "../../GlobalInclude.h"
/**
* 获取工序步骤列表（条件+分页）、添加工序步骤
*/
#include OATPP_CODEGEN_BEGIN(DTO)
class SetProListDTO : public oatpp::DTO
{
	DTO_INIT(SetProListDTO, DTO);
	//内容ID
	API_DTO_FIELD(UInt64, contentId, ZH_WORDS_GETTER("set.fields.contentid"), true, 229);
	//工序ID,标识
	API_DTO_FIELD(UInt64, processId, ZH_WORDS_GETTER("set.fields.processid"), true, 283);
	//顺序编码
	API_DTO_FIELD(Int32, orderNum, ZH_WORDS_GETTER("set.fields.ordernum"), true, 1);
	//辅助设备
	API_DTO_FIELD(String, device, ZH_WORDS_GETTER("set.fields.device"), true, "");
	//辅助材料
	API_DTO_FIELD(String, material, ZH_WORDS_GETTER("set.fields.material"), true, "");
	////材料URL
	API_DTO_FIELD(String, docUrl, ZH_WORDS_GETTER("set.fields.docurl"), true, "");
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("set.fields.remark"), true, "");
	//步骤说明
	API_DTO_FIELD(String, contentText, ZH_WORDS_GETTER("set.fields.contenttext"), true, "");

};
class SetProListPageDTO : public PageDTO<SetProListDTO::Wrapper>
{
	DTO_INIT(SetProListPageDTO, PageDTO<SetProListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_