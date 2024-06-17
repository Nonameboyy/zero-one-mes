#pragma once
#ifndef _SINGLE_DEFECT_SERVICE_
#define _SINGLE_DEFECT_SERVICE_
#include <list>
#include "domain/vo/Single_Defect/Single_Defect_VO.h"
#include "domain/query/Single_Defect/Single_Defect_Query.h"
#include "domain/dto/Single_Defect/Single_Defect_DTO.h"

/**
 * 物料信息的服务操作
 */
class Single_Defect_Service
{
public:
	// 分页查询检验项数据
	SinglePageDTO::Wrapper listAll_Index(const SingleQuery::Wrapper& query);
	// 分页查询缺陷数据
	DefectPageDTO::Wrapper listAll_Defect(const DefectQuery::Wrapper& query);
	// 保存缺陷数据
	uint64_t saveData(const DefectDTO::Wrapper& dto);
	// 修改缺陷数据
	bool updateData(const DefectDTO::Wrapper& dto);
	// 通过缺陷ID删除缺陷数据
	bool removeData(uint64_t id);
};

#endif // !_SINGLE_DEFECT_SERVICE_
