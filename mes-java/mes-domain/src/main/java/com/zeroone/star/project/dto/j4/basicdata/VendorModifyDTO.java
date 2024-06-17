package com.zeroone.star.project.dto.j4.basicdata;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

@Data
@ApiModel("修改供应商时传输数据的对象")
public class VendorModifyDTO {
    @NotNull(message = "供应商ID不能为空")
    @ApiModelProperty(value = "供应商ID", example = "1")
    private Long vendorId;

    @Size(min = 1, max = 64, message = "供应商编码长度必须在1到64个字符之间")
    @ApiModelProperty(value = "供应商编码", example = "VEND1234")
    private String vendorCode;

    @Size(min = 1, max = 255, message = "供应商名称长度必须在1到255个字符之间")
    @ApiModelProperty(value = "供应商名称", example = "超级供应商公司")
    private String vendorName;

    @Size(max = 255, message = "供应商简称长度不能超过255个字符")
    @ApiModelProperty(value = "供应商简称", example = "超供公司")
    private String vendorNick;

    @Size(max = 255, message = "供应商英文名称长度不能超过255个字符")
    @ApiModelProperty(value = "供应商英文名称", example = "Super Supplier Inc.")
    private String vendorEn;

    @Size(max = 500, message = "供应商简介长度不能超过500个字符")
    @ApiModelProperty(value = "供应商简介", example = "这是一个优秀的供应商")
    private String vendorDes;

    @Size(max = 255, message = "供应商LOGO地址长度不能超过255个字符")
    @ApiModelProperty(value = "供应商LOGO地址", example = "http://example.com/logo.png")
    private String vendorLogo;

    @Size(max = 64, message = "供应商等级长度不能超过64个字符")
    @ApiModelProperty(value = "供应商等级", example = "A")
    private String vendorLevel;

    @ApiModelProperty(value = "供应商评分", example = "5")
    private Integer vendorScore;

    @Size(max = 500, message = "供应商地址长度不能超过500个字符")
    @ApiModelProperty(value = "供应商地址", example = "123供应商大街")
    private String address;

    @Size(max = 255, message = "供应商官网地址长度不能超过255个字符")
    @ApiModelProperty(value = "供应商官网地址", example = "http://www.vendor.com")
    private String website;

    @Size(max = 255, message = "供应商邮箱地址长度不能超过255个字符")
    @ApiModelProperty(value = "供应商邮箱地址", example = "contact@vendor.com")
    private String email;

    @Size(max = 64, message = "供应商电话长度不能超过64个字符")
    @ApiModelProperty(value = "供应商电话", example = "1234567890")
    private String tel;

    @Size(max = 64, message = "联系人1长度不能超过64个字符")
    @ApiModelProperty(value = "联系人1", example = "张三")
    private String contact1;

    @Size(max = 64, message = "联系人1-电话长度不能超过64个字符")
    @ApiModelProperty(value = "联系人1-电话", example = "9876543210")
    private String contact1Tel;

    @Size(max = 255, message = "联系人1-邮箱长度不能超过255个字符")
    @ApiModelProperty(value = "联系人1-邮箱", example = "zhangsan@vendor.com")
    private String contact1Email;

    @Size(max = 64, message = "联系人2长度不能超过64个字符")
    @ApiModelProperty(value = "联系人2", example = "李四")
    private String contact2;

    @Size(max = 64, message = "联系人2-电话长度不能超过64个字符")
    @ApiModelProperty(value = "联系人2-电话", example = "0987654321")
    private String contact2Tel;

    @Size(max = 255, message = "联系人2-邮箱长度不能超过255个字符")
    @ApiModelProperty(value = "联系人2-邮箱", example = "lisi@vendor.com")
    private String contact2Email;

    @Size(max = 64, message = "统一社会信用代码长度不能超过64个字符")
    @ApiModelProperty(value = "统一社会信用代码", example = "123456789012345678")
    private String creditCode;

    @ApiModelProperty(value = "是否启用", example = "Y")
    @Pattern(regexp = "[YN]", message = "primaryFlag必须是'Y'或'N'")
    private String enableFlag;

    @Size(max = 500, message = "备注长度不能超过500个字符")
    @ApiModelProperty(value = "备注", example = "这是一个备注")
    private String remark;

    @Size(max = 64, message = "预留字段1长度不能超过64个字符")
    @ApiModelProperty(value = "预留字段1", example = "预留值1")
    private String attr1;

    @Size(max = 255, message = "预留字段2长度不能超过255个字符")
    @ApiModelProperty(value = "预留字段2", example = "预留值2")
    private String attr2;

    @ApiModelProperty(value = "预留字段3", example = "100")
    private Integer attr3;

    @ApiModelProperty(value = "预留字段4", example = "200")
    private Integer attr4;
}
