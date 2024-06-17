#pragma once
#ifndef _PROMATERIAL_DTO_H_
#define _PROMATERIAL_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ӳ�Ʒ�Ƴ�����BOM�������
 */
class ProductMaterialDTO : public oatpp::DTO
{
	DTO_INIT(ProductMaterialDTO, DTO);
	// ����·��ID
	API_DTO_FIELD(UInt64, route_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.record_id"), true, 1);
	// ����ID
	API_DTO_FIELD(UInt64, process_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.record_id"), true, 1);
	// ��¼id
	//API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.record_id"), true, 1);
	// ��Ʒ����ID
	API_DTO_FIELD(UInt64, product_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.record_id"), true, 1);
	// ��Ʒ����ID
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.record_id"), true, 1);
	// ���ϱ���
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_code"), true, "");
	// ��������
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_name"), true, "01star");
	// ���ϵ�λ
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.unit_of_measure"), true, "g");
	// ����ͺ�
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.specification"), true, "null");
	// ʹ�ñ���
	API_DTO_FIELD(Float32, quantity, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.quantity"), true, 0.1);
	// ��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.RPmodels"), false, "null");
};
/**
 * �޸Ĳ�Ʒ�Ƴ�����BOM�������
 */
class ProductModefyMaterialDTO : public oatpp::DTO
{
	DTO_INIT(ProductModefyMaterialDTO, DTO);
	// ��¼id
	API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.record_id"), true, 1);
	// ���ϱ���
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_code"), true, "");
	// ��������
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_name"), true, "01star");
	// ���ϵ�λ
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.unit_of_measure"), true, "g");
	// ����ͺ�
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.specification"), true, "null");
	// ʹ�ñ���
	API_DTO_FIELD(Float32, quantity, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.quantity"), true, 0.1);
	// ��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.RPmodels"), false, "null");
};
/**
 * ��ȡ��Ʒ�Ƴ�����BOM�б������
 */
class ProMaterialDTO : public oatpp::DTO
{
	DTO_INIT(ProMaterialDTO, DTO);

	// ����ID
	API_DTO_FIELD(UInt64, item_id, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_id"), true, 1);
	// ���ϱ���
	API_DTO_FIELD(String, item_code, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_code"), true, "");
	// ��������
	API_DTO_FIELD(String, item_name, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.item_name"), true, "01star");
	// ���ϵ�λ
	API_DTO_FIELD(String, unit_of_measure, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.unit_of_measure"), true, "g");
	// ����ͺ�
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.specification"), true, "null");
	// ʹ�ñ���
	API_DTO_FIELD(Float32, quantity, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.quantity"), true, 0.1);
	// ��ע
	API_DTO_FIELD(String, RPmodels, ZH_WORDS_GETTER("RelatePro.ProMaterialDTO.RPmodels"), false, "null");
};


/**
 * ��ȡ��Ʒ�Ƴ�����BOM�б�ķ�ҳ�������
 */
class ProMaterialPageDTO : public PageDTO<ProMaterialDTO::Wrapper>
{
	DTO_INIT(ProMaterialPageDTO, PageDTO<ProMaterialDTO::Wrapper>);
};
#endif // !_PROMATERIAL_DTO_