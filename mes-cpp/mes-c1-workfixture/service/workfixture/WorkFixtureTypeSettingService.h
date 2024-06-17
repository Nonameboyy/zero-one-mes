#pragma once
/*
 @Author: Croissant
*/
#ifndef _WORKFIXTURESERVICE_H_
#define _WORKFIXTURESERVICE_H_
#include <list>
#include "domain/vo/workfixture/WorkFixtureTypeCreateVO.h"
#include "domain/vo/workfixture/WorkFixtureTypeDeleteVO.h"
#include "domain/vo/workfixture/WorkFixtureTypeExportVO.h"
#include "domain/vo/workfixture/WorkFixtureTypeListVO.h"
#include "domain/vo/workfixture/WorkFixtureTypeNameListVO.h"
#include "domain/vo/workfixture/WorkFixtureTypeUpdateVO.h"

#include "domain/query/workfixture/WorkFixtureTypeCreateQuery.h"
#include "domain/query/workfixture/WorkFixtureTypeDeleteQuery.h"
#include "domain/query/workfixture/WorkFixtureTypeExportQuery.h"
#include "domain/query/workfixture/WorkFixtureTypeListQuery.h"
#include "domain/query/workfixture/WorkFixtureTypeNameListQuery.h"
#include "domain/query/workfixture/WorkFixtureTypeUpdateQuery.h"

#include "domain/dto/workfixture/WorkFixtureTypeCreateDTO.h"
#include "domain/dto/workfixture/WorkFixtureTypeDeleteDTO.h"
#include "domain/dto/workfixture/WorkFixtureTypeExportDTO.h"
#include "domain/dto/workfixture/WorkFixtureTypeListDTO.h"
#include "domain/dto/workfixture/WorkFixtureTypeNameListDTO.h"
#include "domain/dto/workfixture/WorkFixtureTypeUpdateDTO.h"


/**
 * 服务实现
 */
class WorkFixtureTypeSettingService
{
public:
	// 分页查list
	WorkFixtureTypeListPageDTO::Wrapper typeList(const WorkFixtureTypeListQuery::Wrapper& query);
	// 查namelist
	//WorkFixtureTypeNameListDTO::Wrapper typeNameList(const WorkFixtureTypeNameListQuery::Wrapper& query);
	oatpp::List<WorkFixtureTypeNameListDTO::Wrapper> typeNameList(const WorkFixtureTypeNameListQuery::Wrapper& query);

	// 保存数据
	uint64_t saveData(const WorkFixtureTypeCreateDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const WorkFixtureTypeUpdateDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
	void makeFile();
};

#endif // !_WORKFIXTURESERVICE_H_

