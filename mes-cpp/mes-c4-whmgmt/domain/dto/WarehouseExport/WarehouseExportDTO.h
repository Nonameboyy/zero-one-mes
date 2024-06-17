#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xinye
 @Date: 2024/5/22 22:00:00

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

#ifndef _WAREHOUSING_EXPORT_DTO_
#define _WAREHOUSING_EXPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 物料入库单传输对象
 */
class WarehouseExportDTO : public oatpp::DTO
{
    DTO_INIT(WarehouseExportDTO, DTO);
    // 入库单编号
    DTO_FIELD(String, recpt_code);
    DTO_FIELD_INFO(recpt_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_code");
    }
    // 入库单名称
    DTO_FIELD(String, recpt_name);
    DTO_FIELD_INFO(recpt_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_name");
    }
    // 来料检验单ID
    DTO_FIELD(Int32, iqc_id);
    DTO_FIELD_INFO(iqc_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.iqc_id");
    }
    // 来料检验单编号
    DTO_FIELD(String, iqc_code);
    DTO_FIELD_INFO(iqc_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.iqc_code");
    }
    // 采购订单编号
    DTO_FIELD(String, po_code);
    DTO_FIELD_INFO(po_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.po_code");
    }
    // 供应商ID
    DTO_FIELD(Int32, vendor_id);
    DTO_FIELD_INFO(vendor_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_id");
    }
    // 供应商编码
    DTO_FIELD(String, vendor_code);
    DTO_FIELD_INFO(vendor_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_code");
    }
    // 供应商名称
    DTO_FIELD(String, vendor_name);
    DTO_FIELD_INFO(vendor_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_name");
    }
    // 供应商简称
    DTO_FIELD(String, vendor_nick);
    DTO_FIELD_INFO(vendor_nick) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_nick");
    }
    // 仓库ID
    DTO_FIELD(Int32, warehouse_id);
    DTO_FIELD_INFO(warehouse_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_id");
    }
    // 仓库编码
    DTO_FIELD(String, warehouse_code);
    DTO_FIELD_INFO(warehouse_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_code");
    }
    // 仓库名称
    DTO_FIELD(String, warehouse_name);
    DTO_FIELD_INFO(warehouse_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_name");
    }
    // 库区ID
    DTO_FIELD(Int32, location_id);
    DTO_FIELD_INFO(location_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.location_id");
    }
    // 库区编码
    DTO_FIELD(String, location_code);
    DTO_FIELD_INFO(location_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.location_code");
    }
    // 库区名称
    DTO_FIELD(String, location_name);
    DTO_FIELD_INFO(location_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.location_name");
    }
    // 库位ID
    DTO_FIELD(Int32, area_id);
    DTO_FIELD_INFO(area_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.area_id");
    }
    // 库位编码
    DTO_FIELD(String, area_code);
    DTO_FIELD_INFO(area_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.area_code");
    }
    // 库位名称
    DTO_FIELD(String, area_name);
    DTO_FIELD_INFO(area_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.area_name");
    }
    // 入库日期
    DTO_FIELD(String, recpt_date);
    DTO_FIELD_INFO(recpt_date) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_date");
    }
    // 单据状态
    DTO_FIELD(String, status);
    DTO_FIELD_INFO(status) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.status");
    }
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_WAREHOUSING_EXPORT_DTO_
