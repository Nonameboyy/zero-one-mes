#pragma once
#ifndef _ADDWHSTORAGEORDERDTO_H_
#define _ADDWHSTORAGEORDERDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
定义一个添加入库单行信息的数据传输类型
*/
class AddWhStorageorderDTO : public oatpp::DTO
{
	DTO_INIT(AddWhStorageorderDTO, DTO);

	//共20个字段
	//产品物料ID item_id bigint  
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("whstorageorder.field.item_id"), true, 72);
	//物料编码 item_code varchar
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("whstorageorder.field.item_code"),true, ZH_WORDS_GETTER("whstorageorder.default.item_code"));
	//物料名称 item_name varchar
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("whstorageorder.field.item_name"),true, ZH_WORDS_GETTER("whstorageorder.default.item_name"));
	
	//单位 unit_of_measure varchar
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("whstorageorder.field.unit_of_measure"),true, ZH_WORDS_GETTER("whstorageorder.default.unit_of_measure"));
	//入库数量 quantity_recived double
	API_DTO_FIELD(Float64, quantity_recived, ZH_WORDS_GETTER("whstorageorder.field.quantity_recived"),true,1);
	//入库批次号 batch_code varchar
	API_DTO_FIELD_DEFAULT(String, batch_code, ZH_WORDS_GETTER("whstorageorder.field.batch_code"));
	//有效期 expire_date String
	API_DTO_FIELD_DEFAULT(String, expire_date, ZH_WORDS_GETTER("whstorageorder.field.expire_date"));
	
	//仓库ID warehouse_id bigint
	API_DTO_FIELD(UInt64, warehouse_id, ZH_WORDS_GETTER("whstorageorder.field.warehouse_id"), true,210);
	//仓库编码 warehouse_code varchar
	API_DTO_FIELD(String, warehouse_code, ZH_WORDS_GETTER("whstorageorder.field.warehouse_code"),true, ZH_WORDS_GETTER("whstorageorder.default.warehouse_code"));
	//仓库名称 warehouse_name varchar
	API_DTO_FIELD(String, warehouse_name, ZH_WORDS_GETTER("whstorageorder.field.warehouse_name"),true, ZH_WORDS_GETTER("whstorageorder.default.warehouse_name"));
	
	//库区ID location_id bigint
	API_DTO_FIELD(UInt64, location_id, ZH_WORDS_GETTER("whstorageorder.field.location_id"), true, 210);
	//库区编码 location_code varchar
	API_DTO_FIELD(String, location_code, ZH_WORDS_GETTER("whstorageorder.field.location_code"), true, ZH_WORDS_GETTER("whstorageorder.default.location_code"));
	//库区名称 location_name varchar
	API_DTO_FIELD(String, location_name, ZH_WORDS_GETTER("whstorageorder.field.location_name"), true, ZH_WORDS_GETTER("whstorageorder.default.location_name"));
	
	//库位ID area_id bigint
	API_DTO_FIELD(UInt64, area_id, ZH_WORDS_GETTER("whstorageorder.field.area_id"), true, 212);
	//库位编码 area_code varchar
	API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("whstorageorder.field.area_code"), true, ZH_WORDS_GETTER("whstorageorder.default.area_code"));
	//库位名称 area_name varchar
	API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("whstorageorder.field.area_name"), true, ZH_WORDS_GETTER("whstorageorder.default.area_name"));

	//是否检验 iqc_check char
	API_DTO_FIELD(String, iqc_check, ZH_WORDS_GETTER("whstorageorder.field.iqc_check"),true, ZH_WORDS_GETTER("whstorageorder.default.iqc_check"));
	//来料检验单编码 iqc_code varchar
	API_DTO_FIELD_DEFAULT(String, iqc_code, ZH_WORDS_GETTER("whstorageorder.field.iqc_code"));
	//来料检验单ID iqc_id bigint
	API_DTO_FIELD_DEFAULT(UInt64, iqc_id, ZH_WORDS_GETTER("whstorageorder.field.iqc_id"));
	//备注 remark varchar
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("whstorageorder.field.remark"));

};



#include OATPP_CODEGEN_END(DTO)
#endif // _ADDWHSTORAGEORDERDTO_H_
