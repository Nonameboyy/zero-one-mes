package com.zeroone.star.productManagement.mapper;

import com.zeroone.star.productManagement.entity.ExportMdItem;
import com.zeroone.star.productManagement.entity.MdItem;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j6.product_management.query.MdItemQuery;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 物料产品表 Mapper 接口
 * </p>
 *
 * @author xiaotian
 * @since 2024-05-20
 */
@Mapper
public interface MdItemMapper extends BaseMapper<MdItem> {
    /**
     * 根据查询条件返回全部items
     * @param mdItemQuery 查询条件
     * @return 列表
     */
    List<ExportMdItem> selectMdItemList(MdItemQuery mdItemQuery);

    MdItem checkItemCodeUnique(MdItem mdItem);

    void insertMdItem(MdItem mdItem);

    void updateMdItem(MdItem mdItem);
}
