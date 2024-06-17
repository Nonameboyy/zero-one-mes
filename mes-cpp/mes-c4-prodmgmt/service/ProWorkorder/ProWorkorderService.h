#pragma once

#ifndef _PROWORKORDER_SERVICE_
#define _PROWORKORDER_SERVICE_
#include <list>
#include "../../domain/vo/ProdWorkorder/ConfirmProWorkorderVO.h"
#include "../../domain/dto/ProdWorkorder/ConfirmProWorkorderDTO.h"
#include "../../domain/dto/ProdWorkorder/ModifyProWorkorderDTO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"
#include "../../domain/do/MdProductBom/MdProductBomDO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderDO.h"

#include "TransactionManager.h"


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ProWorkorderService
{
public:
	// 修改数据
	bool updateData(const ModifyProWorkorderDTO::Wrapper& dto);
	// 通过ID完成生产工单
	bool completeData(uint64_t id);
	// 通过ID删除生产工单
	bool removeData(uint64_t id);

	// 通过ID确认生产工单
	bool confirmData(uint64_t id);
};

#endif // !_PROWORKORDER_SERVICE_

