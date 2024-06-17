#pragma once
#ifndef _RELATEPRO_SERVICE_
#define _RELATEPRO_SERVICE_
#include <list>

#include "domain/dto/process/RelateProDTO.h"


/**
 * 关联产品添加+修改服务实现，演示基础的示例服务实现
 */
class RelateProService
{
public:
	// 添加关联产品
	uint64_t saveData(const AddRelateProDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改关联产品
	bool updateData(const ModRelateProDTO::Wrapper& dto, const PayloadDTO& payload);
	// 删除关联产品
	bool removeData(uint64_t id);
	// 分页查询所有数据
	ExportRelateProDTO::Wrapper listAll(const uint64_t& id);
};

#endif // !_RELATEPRO_SERVICE_

