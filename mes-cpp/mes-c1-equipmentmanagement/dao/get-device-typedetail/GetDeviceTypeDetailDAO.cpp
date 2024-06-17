#include "stdafx.h"
#include <sstream>

#include"GetDeviceTypeDetailDAO.h"
#include"../../dao/get-device-typedetail/GetDeviceTypeMapper.h"
list<EquipmentTypeDO> GetDeviceTypeDetailDAO::selectByCondition(const GetDeviceTypeDetailQuery::Wrapper &query)
{
	string sql = "SELECT `machinery_type_id`,`machinery_type_code`,`machinery_type_name`,`parent_type_id`,"
		"`ancestors`,`enable_flag`,`remark`,`create_by`,`create_time`,`update_by`,`update_time`"
		" FROM `dv_machinery_type` WHERE 1=1";
	GetDeviceTypeMapper mapper;
	SqlParams params;
	if (query->status) {  // 过滤状态
		sql += " AND `enable_flag`=?";
		SQLPARAMS_PUSH(params, "s", string, query->status.getValue({}));
	}
	auto qres = sqlSession->executeQuery<EquipmentTypeDO, GetDeviceTypeMapper>(sql, mapper, params);
	// 筛除无效数据
	string name = query->machineryTypeName.getValue({});
	qres.sort([](const EquipmentTypeDO &a, const EquipmentTypeDO &b) {
		return a.getId() < b.getId();
	});  // 按id升序排序方便后续查找
	list<EquipmentTypeDO> ret;  // 存最终筛选好的返回结果
	set<uint64_t> allid;  // 存所有查找结点的id
	for (auto &entry : qres)
	{
		if (name.empty() || entry.getName().find(name) != string::npos)
		{
			allid.insert(entry.getId());
			ret.push_back(entry);
		}
	}
	// 找出根节点并标记
	for (auto &entry : ret)
	{
		if (allid.find(entry.getParentId()) == allid.end())
		{
			entry.setParentId(0);
		}
	}
	return ret;
}
