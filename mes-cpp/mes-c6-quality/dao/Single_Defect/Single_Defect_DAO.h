#pragma once
#ifndef _Single_Defect_DAO
#define _Single_Defect_DAO
#include "BaseDAO.h"
#include "../../domain/do/Single_Defect/Single_Defect_DO.h"
#include "../../domain/query/Single_Defect/Single_Defect_Query.h"

/**
 * 来料检验信息信息的数据库操作
 */
class Single_Defect_DAO : public BaseDAO
{
public:
	// 统计相关检测项数据条数
	uint64_t count_Index(const SingleQuery::Wrapper& query);
	// 分页查询检测项数据
	list<IndexDO> selectIndexPage(const SingleQuery::Wrapper& query);
	// 统计相关缺陷数据条数
	uint64_t count_Defect(const DefectQuery::Wrapper& query);
	// 分页查询缺陷数据
	list<DefectDO> selectDefectPage(const DefectQuery::Wrapper& query);
	// 插入缺陷数据
	uint64_t insert(const DefectDO& iObj);
	// 修改缺陷数据
	int update(const DefectDO& uObj);
	// 通过ID删除缺陷数据
	int deleteById(uint64_t iqc_id);
};


#endif // !_Single_Defect_DAO
