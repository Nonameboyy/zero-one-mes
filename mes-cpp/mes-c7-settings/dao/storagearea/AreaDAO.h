#pragma once
#ifndef __AREADAO_H__
#define __AREADAO_H__

#include "BaseDAO.h"
#include "../../domain/do/storagearea/AreaDO.h"
#include "../../domain/query/storagearea/AreaQuery.h"

class AreaDAO : public BaseDAO
{
public:
	// 统计数据条数
	std::uint64_t count(const AreaQuery::Wrapper& query);	
	// 通过姓名查询数据
	std::list<AreaDO> selectByName(const std::string& name);
	// 分页查询数据
	std::list<AreaDO> selectWithPage(const AreaQuery::Wrapper& query);
	// 插入数据
	std::uint64_t insert(const AreaDO& iObj);
	// 修改数据
	std::uint64_t update(const AreaDO& uObj);
	// 通过用户指定ID删除数据
	std::uint64_t deleteById(std::list<int64_t>& ids);
	
	
};

#endif //__AREADAO_H__
