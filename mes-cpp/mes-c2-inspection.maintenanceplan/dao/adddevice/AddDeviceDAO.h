#pragma once
#pragma once


#ifndef _ADD_DEVICE_DAO_
#define _ADD_DEVICE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/dv_check_machinery/dv_check_machineryDO.h"
#include "../../../mes-c2-equipmentledger/domain/do/dv_machinery/dvMachineryDO.h"

/**
 * 示例表数据库操作实现
 */
class AddDeviceDAO : public BaseDAO
{
public:


	// 插入数据
	uint64_t insert(const Dv_check_machineryDO& iObj);
	//根据项目ID获取详情
	list<dvMachineryDO> getDvDevice(uint64_t id);

};
#endif // !_SAMPLE_DAO_
