package com.zeroone.star.project.j6.product_management.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiModel;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 * 描述：产品Sip查询对象
 * </p>
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("产品Sip查询对象")
public class SipQuery extends PageQuery {
    @ApiModelProperty(value = "物料产品ID", example = "1001")
    private Long itemId;

    @ApiModelProperty(value = "工序编号", example = "PROC-001")
    private String processCode;

    @ApiModelProperty(value = "标题", example = "装配Sip")
    private String SipTitle;
}
