#include "stdafx.h"
#include "WhStorageorderDAO.h"
#include <sstream>


//返回ID
uint64_t WhStorageorderDAO::insert(const AddWhStorageorderDO& iObj)
{
	string sql = "INSERT INTO `wm_item_recpt_line` (`item_id`,`quantity_recived`,`iqc_check`,`warehouse_code`,`area_code`,`area_name`,`location_name`,`item_code`,`item_name`,`warehouse_name`,`unit_of_measure`,`location_code`,`iqc_id`,`area_id`,`location_id`";
	sql += ",`warehouse_id`,`iqc_code`,`remark`,`expire_date`,`batch_code`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%ull%d%s%s%s%s%s%s%s%s%s%s%ull%ull%ull%ull%s%s%s%s", iObj.getItem_id(), iObj.getQuantity_recived(), iObj.getIqc_check(), iObj.getWarehouse_code(),
		iObj.getArea_code(), iObj.getArea_name(), iObj.getLocation_name(), iObj.getItem_code(), iObj.getItem_name(), iObj.getWarehouse_name(), iObj.getUnit_of_measure(), iObj.getLocation_code(),
		iObj.getIqc_id(), iObj.getArea_id(), iObj.getLocation_id(), iObj.getWarehouse_id(), iObj.getIqc_code(), iObj.getRemark(), iObj.getExpire_date(), iObj.getBatch_code());
		 

}
//返回修改的当前行号
int WhStorageorderDAO::update(const ModifyWhStorageorderDO& uObj) {
	string sql = "UPDATE `wm_item_recpt_line` SET `item_id`=?,`quantity_recived`=?,`iqc_check`=?,`warehouse_code`=?,`area_code`=?,`area_name`=?,`location_name`=?,`item_code`=?,`item_name`=?,`warehouse_name`=?,`unit_of_measure`= ?,";
	sql += "`location_code`=?,`iqc_id`=?,`area_id`=?,`location_id`=?,`warehouse_id`=?,`iqc_code`=?,`remark`=?,`expire_date`=?,`batch_code`=? WHERE `line_id`= ?";
	return sqlSession->executeUpdate(sql, "%ull%d%s%s%s%s%s%s%s%s%s%s%ull%ull%ull%ull%s%s%s%s%ull", uObj.getItem_id(), uObj.getQuantity_recived(), uObj.getIqc_check(), uObj.getWarehouse_code(),
		uObj.getArea_code(), uObj.getArea_name(), uObj.getLocation_name(), uObj.getItem_code(), uObj.getItem_name(), uObj.getWarehouse_name(), uObj.getUnit_of_measure(), uObj.getLocation_code(),
		uObj.getIqc_id(), uObj.getArea_id(), uObj.getLocation_id(), uObj.getWarehouse_id(), uObj.getIqc_code(), uObj.getRemark(), uObj.getExpire_date(), uObj.getBatch_code(),uObj.getLine_id());

}
int WhStorageorderDAO::deleteById(const oatpp::List<UInt64>& ids) {
	
	string sql = "DELETE FROM `wm_item_recpt_line` WHERE `line_id` IN (";
	for (auto it = ids->begin(); it != ids->end(); ++it) {
		if (it != ids->begin()) {
			sql += ",";
		}
		sql += to_string(*it);
	}
	sql += ")";
	return sqlSession->executeUpdate(sql);
}


