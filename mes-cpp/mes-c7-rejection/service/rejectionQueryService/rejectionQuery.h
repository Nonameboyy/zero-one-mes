#pragma once
#ifndef _rejectionQuery_SERVICE_
#define _rejectionQuery_SERVICE_
#include <list>
#include "domain/vo/rejection/RejectVo.h"
#include "domain/dto/rejection/RejectDTO.h"
#include "domain/query/rejection/RejectQuery.h"
/**
 * 退料列表分页查询服务
 */
class RejectTableQueryService
{
public:
	// 分页查询所有数据
	RejectPageDTO::Wrapper listAll(const RejectQuery::Wrapper& query);
	//查询详细数据
	RejectDetailDTO::Wrapper queryDetail(const RejectDetailQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const RejectTableDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const RejectTableDTO::Wrapper& dto);
	//// 通过ID删除数据
	//bool removeData(uint64_t id);
};


#endif 