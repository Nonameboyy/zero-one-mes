#pragma once
#ifndef _PROMATERIAL_SERVICE_
#define _PROMATERIAL_SERVICE_
#include <list>
#include "domain/vo/process/ProMaterialVO.h"
#include "domain/query/process/ProMaterialQuery.h"
#include "domain/dto/process/ProMaterialDTO.h"


/**
 * 产品制成物料服务实现，演示基础的示例服务实现
 */

class ProMaterialService
{
public:
	// 分页查询所有数据
	ProMaterialPageDTO::Wrapper listAll(const ProMaterialQuery::Wrapper& query);
};

#endif // !_PROMATERIAL_SERVICE_

