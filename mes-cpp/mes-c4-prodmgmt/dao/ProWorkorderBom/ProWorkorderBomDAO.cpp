#include "ProWorkorderBomDAO.h"

uint64_t ProdWorkorderBomDAO::insert(const ProWorkOrderBomDO& iObj)
{
	string sql = "INSERT INTO `pro_workorder_bom` (`workorder_id`, `item_id`, `item_code`,`item_name`,`item_spc`,`unit_of_measure`,`item_or_product`,`quantity`,`create_time`) VALUES (?, ?, ?,?, ?, ?,?, ?, ?)";
	return sqlSession->executeInsert(sql, "%ull%ull%s%s%s%s%s%d%s", iObj.getworkOrderId(), iObj.getitemId(), iObj.getitemCode(), iObj.getitemName(), iObj.getitemSpc(), iObj.getunitOfMeasure(),iObj.getitemOrProduct(), iObj.getbQuantity(), iObj.getcreateTime());
}

int ProdWorkorderBomDAO::deleteByItemId(uint64_t workorder_id)
{
	string sql = "DELETE FROM `pro_workorder_bom` WHERE `workorder_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", workorder_id);
}
