#pragma once
#ifndef _RELATEPRO_DTO_H_
#define _RELATEPRO_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӹ��չ�����Ʒ�������
 */
class AddRelateProDTO : public oatpp::DTO
{
	DTO_INIT(AddRelateProDTO, DTO);

	// ��Ʒ���ϱ���
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.DTO.item_code"), true, "1");
	// ��Ʒ��������
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.DTO.item_name"), true, "01star");
	// ��Ʒ���ϵ�λ
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.DTO.unit_of_measure"), true, "g");
	// ����ͺ�
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.DTO.specification"), true, "null");
	// ��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("RelatePro.DTO.RPmodels"), false, "");
};

/**
 * �޸Ĺ��չ�����Ʒ�������
 */
class ModRelateProDTO : public AddRelateProDTO
{
	DTO_INIT(ModRelateProDTO, AddRelateProDTO);

	// ���ϱ���
	//API_DTO_FIELD(String, Ratio_of_materials_used, ZH_WORDS_GETTER("RelatePro.DTO.Ratio_of_materials_used"), true, "0:0");
	//��¼ID
	API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("RelatePro.DTO.record_id"), true, 1);
};

class ExportRelateProDTO : public oatpp::DTO
{
	DTO_INIT(ExportRelateProDTO, DTO);

	// ��¼ID
	API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("RelatePro.DTO.record_id"), true, 1);
	// ����·��ID
	API_DTO_FIELD(UInt64, route_id, ZH_WORDS_GETTER("RelatePro.DTO.route_id"), true, 1);
	// ��Ʒ����ID
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("RelatePro.DTO.item_id"), true, 1);
	// ��Ʒ���ϱ���
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.DTO.item_code"), true, "null");
	// ��Ʒ��������
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.DTO.item_name"), true, "01star");
	// ��Ʒ���ϵ�λ
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.DTO.unit_of_measure"), true, "g");
	// ����ͺ�
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.DTO.specification"), true, "null");
	// ��ע
	API_DTO_FIELD(String, RPmodels, ZH_WORDS_GETTER("RelatePro.DTO.RPmodels"), false, "");
};

#endif // !_RELATEPRO_DTO_