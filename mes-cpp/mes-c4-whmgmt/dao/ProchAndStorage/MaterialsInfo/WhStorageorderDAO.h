#pragma once
#ifndef _WHSTORAGEORDER_DAO_
#define _WHSTORAGEORDER_DAO_

#include  "BaseDAO.h"
#include "domain/vo/BaseJsonVO.h" //包含List<UInt64>
#include "domain/do/ProchAndStorage/MaterialsInfo/AddWhStorageorderDO.h"
#include "domain/do/ProchAndStorage/MaterialsInfo/DeleteWhStorageorderDO.h"
#include "domain/do/ProchAndStorage/MaterialsInfo/ModifyWhStorageorderDO.h"

class WhStorageorderDAO : public BaseDAO
{
public:
	//添加入库单行
	uint64_t insert(const AddWhStorageorderDO& iObj);
	//修改入库单行
	int update(const ModifyWhStorageorderDO& uObj);
	//通过ID删除入库单行（支持批量删除）
	int deleteById(const oatpp::List<UInt64>& ids);
};


#endif // !_WHSTORAGEORDER_DAO_
