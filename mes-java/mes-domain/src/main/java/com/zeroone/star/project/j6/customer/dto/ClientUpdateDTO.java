package com.zeroone.star.project.j6.customer.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @author 小鱼
 * @Description 客户更新数据传输对象
 * @Date 11:07 2024/5/25
 **/
@Data
@ApiModel("客户更新数据传输对象")
public class ClientUpdateDTO {
    /**
     * 客户ID
     */
    @ApiModelProperty(value = "客户ID", example = "1")
    private Long clientId;

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
     * 客户英文名称
     */
    @ApiModelProperty(value = "客户英文名称", example = "ZhangSan")
    private String clientEn;

    /**
     * 客户简介
     */
    @ApiModelProperty(value = "客户简介")
    private String clientDes;

    /**
     * 客户LOGO
     */
    @ApiModelProperty(value = "客户LOGO")
    private String clientLogo;

    /**
     * 客户类型
     */
    @ApiModelProperty(value = "客户类型")
    private String clientType;

    /**
     * 客户地址
     */
    @ApiModelProperty(value = "客户地址")
    private String address;

    /**
     * 客户官网地址
     */
    @ApiModelProperty(value = "客户官网地址")
    private String website;

    /**
     * 客户邮箱地址
     */
    @ApiModelProperty(value = "客户邮箱地址")
    private String email;

    /**
     * 客户电话
     */
    @ApiModelProperty(value = "客户电话")
    private String tel;

    /**
     * 联系人1
     */
    @ApiModelProperty(value = "联系人1")
    private String contact1;

    /**
     * 联系人1-电话
     */
    @ApiModelProperty(value = "联系人1-电话")
    private String contact1Tel;

    /**
     * 联系人1-邮箱
     */
    @ApiModelProperty(value = "联系人1-邮箱")
    private String contact1Email;

    /**
     * 联系人2
     */
    @ApiModelProperty(value = "联系人2")
    private String contact2;

    /**
     * 联系人2-电话
     */
    @ApiModelProperty(value = "联系人2-电话")
    private String contact2Tel;

    /**
     * 联系人2-邮箱
     */
    @ApiModelProperty(value = "联系人2-邮箱")
    private String contact2Email;

    /**
     * 统一社会信用代码
     */
    @ApiModelProperty(value = "统一社会信用代码")
    private String creditCode;

    /**
     * 是否启用
     */
    @NotBlank(message = "是否启用不能为空")
    @ApiModelProperty(value = "是否启用")
    private String enableFlag;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注")
    private String remark;
}
