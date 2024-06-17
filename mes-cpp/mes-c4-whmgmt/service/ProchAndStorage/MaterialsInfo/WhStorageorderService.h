#pragma once
#ifndef _WHSTORAGEORDER_SERVICE_
#define _WHSTORAGEORDER_SERVICE_

#include <list>
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/ProchAndStorage/MaterialsInfo/AddWhStorageorderVO.h"
#include "domain/vo/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderVO.h"
#include "domain/vo/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderVO.h"

#include "domain/dto/ProchAndStorage/MaterialsInfo/AddWhStorageorderDTO.h"
#include "domain/dto/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDTO.h"
#include "domain/dto/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDTO.h"

/*
添加、修改、删除入库单行服务实现
*/
class WhStorageorderService
{
public:
	//添加入库单行
	uint64_t addWhStorageorder(const AddWhStorageorderDTO::Wrapper& dto);
	//修改入库单行
	bool modifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto);
	//删除入库单行（支持批量删除）,通过id删除数据
	bool deleteWhStorageorder(const oatpp::List<UInt64>& ids);
};

#endif // !_WHSTORAGEORDER_SERVICE_
