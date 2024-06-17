#pragma once
#pragma once


#ifndef _ADD_DEVICE_DAO_
#define _ADD_DEVICE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"
#include "../../../mes-c2-equipmentledger/domain/do/dv_machinery/dvMachineryDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AddDeviceDAO : public BaseDAO
{
public:


	// ��������
	uint64_t insert(const Dv_check_machineryDO& iObj);
	//������ĿID��ȡ����
	list<dvMachineryDO> getDvDevice(uint64_t id);

};
#endif // !_SAMPLE_DAO_
