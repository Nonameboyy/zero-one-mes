package com.zeroone.star.project.j6.customer.query;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author 小鱼
 * @Description 客户查询对象
 * @Date 12:38 2024/5/20
 **/

@Data
@ApiModel("客户查询对象")
public class ClientQuery {
    /**
     * 客户编码
     */
    @ApiModelProperty(value = "客户编码", example = "001")
    private String clientCode;

    /**
     * 客户名称
     */
    @ApiModelProperty(value = "客户名称", example = "张三")
    private String clientName;

    /**
     * 客户简称
     */
    @ApiModelProperty(value = "客户简称", example = "简")
    private String clientNick;

    /**
     * 客户英文名称
     */
    @ApiModelProperty(value = "客户英文名称", example = "John")
    private String clientEn;

    /**
     * 是否启用
     */
    @ApiModelProperty(value = "是否启用", example = "是")
    private String enableFlag;

    /**
     * 当前页码
     */
    @ApiModelProperty(value = "当前页码", example = "1")
    private int pageNum;

    /**
     * 每页记录数
     */
    @ApiModelProperty(value = "每页记录数", example = "10")
    private int pageSize;


}
