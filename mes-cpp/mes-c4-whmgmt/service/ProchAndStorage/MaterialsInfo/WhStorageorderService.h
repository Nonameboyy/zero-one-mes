#pragma once
#ifndef _WHSTORAGEORDER_SERVICE_
#define _WHSTORAGEORDER_SERVICE_

#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/ProchAndStorage/MaterialsInfo/AddWhStorageorderVO.h"
#include "domain/vo/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderVO.h"
#include "domain/vo/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderVO.h"

#include "domain/dto/ProchAndStorage/MaterialsInfo/AddWhStorageorderDTO.h"
#include "domain/dto/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDTO.h"
#include "domain/dto/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDTO.h"

/*
��ӡ��޸ġ�ɾ����ⵥ�з���ʵ��
*/
class WhStorageorderService
{
public:
	//�����ⵥ��
	uint64_t addWhStorageorder(const AddWhStorageorderDTO::Wrapper& dto);
	//�޸���ⵥ��
	bool modifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto);
	//ɾ����ⵥ�У�֧������ɾ����,ͨ��idɾ������
	bool deleteWhStorageorder(const oatpp::List<UInt64>& ids);
};

#endif // !_WHSTORAGEORDER_SERVICE_
