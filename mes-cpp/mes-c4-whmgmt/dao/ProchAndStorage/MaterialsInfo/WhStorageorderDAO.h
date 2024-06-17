#pragma once
#ifndef _WHSTORAGEORDER_DAO_
#define _WHSTORAGEORDER_DAO_

#include  "BaseDAO.h"
#include "domain/vo/BaseJsonVO.h" //����List<UInt64>
#include "domain/do/ProchAndStorage/MaterialsInfo/AddWhStorageorderDO.h"
#include "domain/do/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDO.h"
#include "domain/do/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDO.h"

class WhStorageorderDAO : public BaseDAO
{
public:
	//�����ⵥ��
	uint64_t insert(const AddWhStorageorderDO& iObj);
	//�޸���ⵥ��
	int update(const ModifyWhStorageorderDO& uObj);
	//ͨ��IDɾ����ⵥ�У�֧������ɾ����
	int deleteById(const oatpp::List<UInt64>& ids);
};


#endif // !_WHSTORAGEORDER_DAO_
