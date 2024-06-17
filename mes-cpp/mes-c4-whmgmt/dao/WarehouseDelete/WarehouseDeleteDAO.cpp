#include "stdafx.h"
#include "WarehouseDeleteDAO.h"
#include <sstream>

//删除单据
int WarehouseDeleteDAO::deleteById(const std::vector<uint64_t> recpt_id)
{
    if (recpt_id.empty()) {
        return false; // 处理空向量的情况
    }

    // 构建参数化查询的SQL语句
    std::string sql = "DELETE FROM `wm_item_recpt` WHERE `recpt_id` IN (";
    for (size_t i = 0; i < recpt_id.size(); ++i)
    {
        sql += "?";
        if (i < recpt_id.size() - 1)
        {
            sql += ", ";
        }
    }
    sql += ")";

    // 创建SqlParams以绑定参数
    SqlParams params;
    for (const auto& id : recpt_id)
    {
        SQLPARAMS_PUSH(params, "ull", uint64_t, id);
    }

    // 假设 sqlSession 是你的 SqlSession 对象
    return sqlSession->executeUpdate(sql, params) > 0;
}