package com.zeroone.star.customer.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.customer.entity.MdClient;
import com.zeroone.star.project.j6.customer.query.ClientExportQuery;
import com.zeroone.star.project.j6.product_management.query.MdItemQuery;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;


@Mapper
public interface MdClientMapper extends BaseMapper<MdClient> {

    boolean checkMdClientCodeUnique(String code);
    boolean update(MdClient mdClient);
}
