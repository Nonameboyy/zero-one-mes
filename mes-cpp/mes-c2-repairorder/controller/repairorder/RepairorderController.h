#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 15:45:52

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
#ifndef _REPAIRORDER_CONTROLLER_
#define _REPAIRORDER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repairorder/RepairorderQuery.h"
#include "domain/query/repairorder/RepairorderDetailsQuery.h"
#include "domain/dto/repairorder/RepairorderDTO.h"
#include "domain/dto/repairorder/RepairorderDetailsDTO.h"
#include "domain/dto/repairorder/DeleteMultipleRepairersDTO.h"
#include "domain/vo/repairorder/RepairorderDetailsVO.h"
#include "domain/vo/repairorder/RepairorderVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 维修单控制器
 */
class RepairorderController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(RepairorderController);
public:
    // 维修单分页查询 接口描述
    ENDPOINT_INFO(queryRepairorder) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.page_query_table"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(RepairorderPageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "repairCode", ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), "REP20240721", false);      // 维修单编号
        API_DEF_ADD_QUERY_PARAMS(String, "repairName", ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), "BUG-Table", false);        // 维修单名称
        API_DEF_ADD_QUERY_PARAMS(String, "machineryCode", ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), "M0001", false);      // 设备编码
        API_DEF_ADD_QUERY_PARAMS(String, "machineryName", ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), "WG-A1-MK2", false);  // 设备名称
        API_DEF_ADD_QUERY_PARAMS(String, "repairResult", ZH_WORDS_GETTER("repairorder.query.fields.repair_result"), "SUCCESS", false);      // 维修结果 (SUCCESS: 维修成功; SCRAP: 报废)
        API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("repairorder.query.fields.status"), "PREPARE", false);                   // 单据状态 (PREPARE: 草稿; CONFIRMED: 已确认; APPROVING: 审批中; APPROVED: 已审批; FINISHED: 已完成)
    }
    // 维修单分页查询 接口处理
    ENDPOINT(API_M_GET, "/equipment-ledger/repairorder/page-query-table", queryRepairorder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(pageQuery, RepairorderQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryRepairorder(pageQuery));
    }

    // 维修单详情查询 接口描述
    ENDPOINT_INFO(queryDetailsRepairorder) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.details"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(RepairorderDetailsJsonVO);
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(UInt64, "repairId", ZH_WORDS_GETTER("repairorder.query.fields.repair_id"), 2, true); // 维修单编号
    }
    // 维修单详情查询 接口处理
    ENDPOINT(API_M_GET, "/equipment-ledger/repairorder/query-details-by-id", queryDetailsRepairorder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(repairId, RepairorderDetailsQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryDetailsRepairorder(repairId));
    }

    // 添加维修单 接口描述
    ENDPOINT_INFO(addRepairorder) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.add_repairorder"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 添加维修单 接口处理
    ENDPOINT(API_M_POST, "/equipment-ledger/repairorder/add-repairorder", addRepairorder, BODY_DTO(RepairorderDetailsByAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execAddRepairorder(dto, authObject->getPayload()));
    }

    // 修改维修单 接口描述
    ENDPOINT_INFO(modifyRepairorder) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.modify_repairorder"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // 添加维修单 接口处理
    ENDPOINT(API_M_PUT, "/equipment-ledger/repairorder/modify-repairorder", modifyRepairorder, BODY_DTO(RepairorderDetailsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execModifyRepairorder(dto, authObject->getPayload()));
    }

    // 删除维修单 接口描述
    ENDPOINT_INFO(removeRepairorder) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairorder.summary.remove_repairorder"), Uint64JsonVO::Wrapper);
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
    }
    // 删除维修单 接口处理
    ENDPOINT(API_M_DEL, "/equipment-ledger/repairorder/del-repairorder", removeRepairorder, BODY_DTO(DeleteMultipleRepairersDTO::Wrapper, repairIdList), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execRemoveRepairorder(repairIdList));
    }
    
private:
    // 维修单分页查询数据
    RepairorderPageJsonVO::Wrapper execQueryRepairorder(const RepairorderQuery::Wrapper& query);

    // 维修单详情查询
    RepairorderDetailsJsonVO::Wrapper execQueryDetailsRepairorder(const RepairorderDetailsQuery::Wrapper& id);

    // 添加维修单
    Uint64JsonVO::Wrapper execAddRepairorder(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload);

    // 修改维修单
    Uint64JsonVO::Wrapper execModifyRepairorder(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload);

    // 删除维修单
    Uint64JsonVO::Wrapper execRemoveRepairorder(const DeleteMultipleRepairersDTO::Wrapper& repairIdList);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // _REPAIRORDER_CONTROLLER_