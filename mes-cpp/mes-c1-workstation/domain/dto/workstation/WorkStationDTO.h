#pragma once

#ifndef _WORKSTATION_DTO_H_
#define _WORKSTATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������վ����ģ��
 */
class AddWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(AddWorkStationDTO, DTO);
	// Ψһ��ʶ������վID��
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));
	// ����վ���
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("workstation.fields.workstationCode"));
	//����վ����
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("workstation.fields.workstationName"));
	// ����վ�ص�
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("workstation.fields.workstationAddress"));
	//���ڳ��������
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("workstation.fields.workshopName"));
	//�������򣨹������ƣ�
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("workstation.fields.processName"));
	//�Ƿ����á���Ĭ��ֵ'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("workstation.fields.enableFlag"), true, "Y");
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workstation.fields.remark"), true, "");
	//�߱߿�ID
	API_DTO_FIELD(UInt64, warehouseId, ZH_WORDS_GETTER("workstation.fields.warehouseId"), true, 11);
	//����ID
	API_DTO_FIELD(UInt64, locationId, ZH_WORDS_GETTER("workstation.fields.locationId"), true, 12);
	//��λID
	API_DTO_FIELD(UInt64, areaId, ZH_WORDS_GETTER("workstation.fields.areaId"), true, 13);
};

/**
 *  ��ȡ����վ�б�����ģ��
 */
class GetWorkStationListDTO : public oatpp::DTO
{
	DTO_INIT(GetWorkStationListDTO, DTO);
	// Ψһ��ʶ������վID��
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));
	// ����վ���
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("workstation.fields.workstationCode"));
	//����վ����
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("workstation.fields.workstationName"));
	// ����վ�ص�
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("workstation.fields.workstationAddress"));
	//���ڳ��������
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("workstation.fields.workshopName"));
	//�������򣨹������ƣ�
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("workstation.fields.processName"));
	//�Ƿ����á���Ĭ��ֵ'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("workstation.fields.enableFlag"), true, "Y");
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workstation.fields.remark"), true, "");
};

/**
 * ����һ������վ�б��ҳ�������
 */
class GetWorkStationListPageDTO : public PageDTO<GetWorkStationListDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListPageDTO, PageDTO<GetWorkStationListDTO::Wrapper>);
};

/**
 * ɾ������վ
 */
class RemoveWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(RemoveWorkStationDTO, DTO);
	// Ψһ��ʶ������վID��
	API_DTO_FIELD_DEFAULT(List<UInt64>, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));

};

/**
 *  �޸Ĺ���վ����ģ��
 */
class ModifyWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(ModifyWorkStationDTO, DTO);
	// Ψһ��ʶ������վID��
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));
	// ����վ���
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("workstation.fields.workstationCode"));
	// ����վ�ص�
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("workstation.fields.workstationAddress"));
	// ����վ����
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("workstation.fields.workstationName"));
	// ���ڳ��������
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("workstation.fields.workshopName"));
	// �������򣨹������ƣ�
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("workstation.fields.processName"));
	// �Ƿ����á���Ĭ��ֵ'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("workstation.fields.enableFlag"), true, "Y");
	// ��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workstation.fields.remark"), true, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_