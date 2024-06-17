package com.zeroone.star.project.j6.customer.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @Author 小鱼
 * @Description 客户分页数据传输对象
 * @Date 13:20 2024/5/20
 **/

@Data
@ApiModel("客户分页数据传输对象")
public class ClientPageDTO {
    /**
     * 客户编码
     */
    @NotBlank(message = "客户编码不能为空")
    @ApiModelProperty(value = "客户编码", example = "10001")
    private String clientCode;

    /**
     * 客户名称
     */
    @NotBlank(message = "客户名称不能为空")
    @ApiModelProperty(value =  "客户名称", example = "张三")
    private String clientName;

    /**
     * 客户简称
     */
    @ApiModelProperty(value = "客户简称", example = "张三")
    private String clientNick;

    /**
     * 客户类型
     */
    @ApiModelProperty(value = "客户类型", example = "1")
    private String clientType;

    /**
     * 客户电话
     */
    @ApiModelProperty(value = "客户电话", example = "13812345678")
    private String tel;

    /**
     * 联系人
     */
    @ApiModelProperty(value = "联系人", example = "李四")
    private String contact1;

    /**
     * 联系人-电话
     */
    @ApiModelProperty(value = "联系人-电话", example = "13843215678")
    private String contact1Tel;

    /**
     * 是否启用
     */
    @NotBlank(message = "是否启用不能为空")
    @ApiModelProperty(value = "是否启用", example = "是")
    private String enableFlag;
}
