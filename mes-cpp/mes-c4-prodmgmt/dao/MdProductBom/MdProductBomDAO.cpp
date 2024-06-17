
#include "stdafx.h"
#include "MdProductBomDAO.h"
#include "MdProductBomMapper.h"
#include <sstream>

int MdProductBomDAO::countById(uint64_t itemId)
{
    string sql = "SELECT COUNT(*) FROM  `md_product_bom` WHERE `item_id`=? ";
    return sqlSession->executeQueryNumerical(sql, "%ull", itemId);
    
}

list<MdProductBomDO> MdProductBomDAO::selectByItemId(uint64_t itemId)
{
    string sql = "SELECT `bom_item_id`,`bom_item_code`,`bom_item_name`,`bom_item_spec`,`unit_of_measure`,`item_or_product`,`quantity` FROM `md_product_bom` WHERE `item_id` = ?";
    MdProductBomMapper mapper;
    return sqlSession->executeQuery<MdProductBomDO, MdProductBomMapper>(sql, mapper, "%ull", itemId);
    
}

int MdProductBomDAO::deleteById(uint64_t itemId)
{
    string sql = "DELETE FROM `md_product_bom` WHERE `item_id`=?";
    return sqlSession->executeUpdate(sql, "%ull", itemId);
}
