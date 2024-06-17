#pragma once
#ifndef _RELATEPRO_DAO_
#define  _RELATEPRO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductDO.h"
#include "../../../lib-oatpp/include/domain/dto/PayloadDTO.h"

/**
 * 关联产品数据库操作实现
 */
class RelateProDAO : public BaseDAO
{
public:
	// 插入关联产品
	uint64_t insert(const ProRouteProductDO& iObj, const PayloadDTO& payload);
	// 修改关联产品
	int update(const ProRouteProductDO& uObj, const PayloadDTO& payload);
	// 删除关联产品
	int deleteById(uint64_t id);
	// 导出关联产品
	list<ProRouteProductDO> selectById(uint64_t id);
};
#endif // ! _RELATEPRO_DAO_
