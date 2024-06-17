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
 * ά�޵�������
 */
class RepairorderController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(RepairorderController);
public:
    // ά�޵���ҳ��ѯ �ӿ�����
    ENDPOINT_INFO(queryRepairorder) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.page_query_table"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(RepairorderPageJsonVO);
        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(String, "repairCode", ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), "REP20240721", false);      // ά�޵����
        API_DEF_ADD_QUERY_PARAMS(String, "repairName", ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), "BUG-Table", false);        // ά�޵�����
        API_DEF_ADD_QUERY_PARAMS(String, "machineryCode", ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), "M0001", false);      // �豸����
        API_DEF_ADD_QUERY_PARAMS(String, "machineryName", ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), "WG-A1-MK2", false);  // �豸����
        API_DEF_ADD_QUERY_PARAMS(String, "repairResult", ZH_WORDS_GETTER("repairorder.query.fields.repair_result"), "SUCCESS", false);      // ά�޽�� (SUCCESS: ά�޳ɹ�; SCRAP: ����)
        API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("repairorder.query.fields.status"), "PREPARE", false);                   // ����״̬ (PREPARE: �ݸ�; CONFIRMED: ��ȷ��; APPROVING: ������; APPROVED: ������; FINISHED: �����)
    }
    // ά�޵���ҳ��ѯ �ӿڴ���
    ENDPOINT(API_M_GET, "/equipment-ledger/repairorder/page-query-table", queryRepairorder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(pageQuery, RepairorderQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryRepairorder(pageQuery));
    }

    // ά�޵������ѯ �ӿ�����
    ENDPOINT_INFO(queryDetailsRepairorder) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.details"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(RepairorderDetailsJsonVO);
        // ����������ѯ��������
        API_DEF_ADD_QUERY_PARAMS(UInt64, "repairId", ZH_WORDS_GETTER("repairorder.query.fields.repair_id"), 2, true); // ά�޵����
    }
    // ά�޵������ѯ �ӿڴ���
    ENDPOINT(API_M_GET, "/equipment-ledger/repairorder/query-details-by-id", queryDetailsRepairorder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(repairId, RepairorderDetailsQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryDetailsRepairorder(repairId));
    }

    // ���ά�޵� �ӿ�����
    ENDPOINT_INFO(addRepairorder) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.add_repairorder"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // ���ά�޵� �ӿڴ���
    ENDPOINT(API_M_POST, "/equipment-ledger/repairorder/add-repairorder", addRepairorder, BODY_DTO(RepairorderDetailsByAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execAddRepairorder(dto, authObject->getPayload()));
    }

    // �޸�ά�޵� �ӿ�����
    ENDPOINT_INFO(modifyRepairorder) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary.modify_repairorder"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
    }
    // ���ά�޵� �ӿڴ���
    ENDPOINT(API_M_PUT, "/equipment-ledger/repairorder/modify-repairorder", modifyRepairorder, BODY_DTO(RepairorderDetailsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execModifyRepairorder(dto, authObject->getPayload()));
    }

    // ɾ��ά�޵� �ӿ�����
    ENDPOINT_INFO(removeRepairorder) {
        // �������ͷ��������Լ���Ȩ֧��
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("repairorder.summary.remove_repairorder"), Uint64JsonVO::Wrapper);
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
    }
    // ɾ��ά�޵� �ӿڴ���
    ENDPOINT(API_M_DEL, "/equipment-ledger/repairorder/del-repairorder", removeRepairorder, BODY_DTO(DeleteMultipleRepairersDTO::Wrapper, repairIdList), API_HANDLER_AUTH_PARAME) {
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execRemoveRepairorder(repairIdList));
    }
    
private:
    // ά�޵���ҳ��ѯ����
    RepairorderPageJsonVO::Wrapper execQueryRepairorder(const RepairorderQuery::Wrapper& query);

    // ά�޵������ѯ
    RepairorderDetailsJsonVO::Wrapper execQueryDetailsRepairorder(const RepairorderDetailsQuery::Wrapper& id);

    // ���ά�޵�
    Uint64JsonVO::Wrapper execAddRepairorder(const RepairorderDetailsByAddDTO::Wrapper& dto, const PayloadDTO& payload);

    // �޸�ά�޵�
    Uint64JsonVO::Wrapper execModifyRepairorder(const RepairorderDetailsDTO::Wrapper& dto, const PayloadDTO& payload);

    // ɾ��ά�޵�
    Uint64JsonVO::Wrapper execRemoveRepairorder(const DeleteMultipleRepairersDTO::Wrapper& repairIdList);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // _REPAIRORDER_CONTROLLER_