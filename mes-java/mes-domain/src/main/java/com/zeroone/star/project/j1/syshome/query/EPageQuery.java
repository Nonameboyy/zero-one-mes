package com.zeroone.star.project.j1.syshome.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * 描述：继承分页查询
 * @author twelve
 * @version 1.0.0
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("分页查询对象")
public class EPageQuery extends PageQuery {
    /**
     * 分页查询
     */
}