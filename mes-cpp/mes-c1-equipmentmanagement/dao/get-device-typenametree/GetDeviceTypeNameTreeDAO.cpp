#include "stdafx.h"

#include"GetDeviceTypeNameTreeDAO.h"
#include"../../dao/get-device-typedetail/GetDeviceTypeMapper.h"

list<EquipmentTypeDO> GetDeviceTypeNameTreeDAO::selectByName(const string &name)
{
	string sql("SELECT `machinery_type_id`,`machinery_type_code`,`machinery_type_name`,`parent_type_id`, "
		"`ancestors`,`enable_flag`,`remark`,`create_by`,`create_time`,`update_by`,`update_time`"
		" FROM `dv_machinery_type`");
	GetDeviceTypeMapper mapper;
	auto qres = sqlSession->executeQuery<EquipmentTypeDO, GetDeviceTypeMapper>(sql, mapper);
	if (name.empty())
	{
		return qres;  // 名称为空时直接返回所有数据
	}
	// 筛除无效数据
	qres.sort([](const EquipmentTypeDO &a, const EquipmentTypeDO &b) {
		return a.getId() < b.getId();
	});  // 按id升序排序方便后续查找
	list<EquipmentTypeDO> ret;  // 存最终筛选好的返回结果
	set<uint64_t> allid;  // 存所有查找结点的id
	for (auto &entry : qres)
	{
		if (entry.getName().find(name) != string::npos)
		{
			allid.insert(entry.getId());
			uint64_t pid = entry.getParentId();
			while (pid != 0) {  // 向上回溯，将所有涉及结点的父节点都放入结果集
				allid.insert(pid);
				auto t = lower_bound(qres.begin(), qres.end(), pid, [](const EquipmentTypeDO &data, uint64_t pa) {
					return data.getId() < pa;
				});
				pid = t == qres.end() ? 0 : t->getParentId();
			}
		}
	}
	for (auto &entry : qres)
	{  // 所有查找到的结点加入结果集
		if (allid.find(entry.getId()) != allid.end())
		{
			ret.push_back(entry);
		}
	}
	return ret;
}

