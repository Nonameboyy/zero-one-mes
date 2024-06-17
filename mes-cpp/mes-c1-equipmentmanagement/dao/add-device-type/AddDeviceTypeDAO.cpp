#include "stdafx.h"
#include"AddDeviceTypeDAO.h"
#include"../get-device-typedetail/GetDeviceTypeMapper.h"
uint64_t AddDeviceTypeDAO::insert(const EquipmentTypeDO& iObj)
{
	// 获取所有父节点ID
	GetDeviceTypeMapper mapper;
	auto t = sqlSession->executeQuery<EquipmentTypeDO, GetDeviceTypeMapper>("SELECT `machinery_type_id`,`machinery_type_code`,`machinery_type_name`,`parent_type_id`, "
		"`ancestors`,`enable_flag`,`remark`,`create_by`,`create_time`,`update_by`,`update_time`"
		" FROM `dv_machinery_type` WHERE machinery_type_id=?", mapper,  "%ull", iObj.getParentId());
	string ancestors = t.front().getAncestorId() + "," + to_string(iObj.getParentId());
	// 执行插入操作
	string sql = "INSERT INTO `dv_machinery_type` SET `machinery_type_code`=?,`machinery_type_name`=?,"
		"`parent_type_id`=?,`ancestors`=?,`enable_flag`=?";
	SqlParams params;
	// 需要处理设备类型编号
	SQLPARAMS_PUSH(params, "s", string, iObj.getCode());
	SQLPARAMS_PUSH(params, "s", string, iObj.getName());
	SQLPARAMS_PUSH(params, "ull", uint64_t, iObj.getParentId());
	SQLPARAMS_PUSH(params, "s", string, ancestors);
	SQLPARAMS_PUSH(params, "s", string, iObj.getEnable());
	if (!iObj.getRemark().empty()) {
		sql += ",`remark`=?";
		SQLPARAMS_PUSH(params, "s", string, iObj.getRemark());
	}
	return sqlSession->executeInsert(sql, params);
}
