package com.zeroone.star.basicdata.entity;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：供应商实体类
 * </p>
 * @author 本鼠
 * @version 1.0.0
 */

@Data
@TableName("md_vendor")
public class MdVendor implements Serializable {
    private static final long serialVersionUID = 1L;

    //供应商ID
    @ExcelIgnore
    @TableId(value = "vendor_id", type = IdType.AUTO)
    private Long vendorId;
    @ExcelProperty(value = "供应商编码",index = 0)
    private String vendorCode;
    @ExcelProperty(value = "供应商名称",index = 1)
    private String vendorName;
    @ExcelProperty(value = "供应商简称",index = 2)
    private String vendorNick;
    @ExcelProperty(value = "供应商英文名称",index = 3)
    private String vendorEn;
    @ExcelProperty(value = "供应商简介",index = 4)
    private String vendorDes;
    @ExcelProperty(value = "供应商LOGO地址",index = 5)
    private String vendorLogo;
    @ExcelProperty(value = "供应商等级",index = 6)
    private String vendorLevel;
    @ExcelProperty(value = "供应商评分",index = 7)
    private Integer vendorScore;
    @ExcelProperty(value = "供应商地址",index = 8)
    private String address;
    @ExcelProperty(value = "供应商官网地址",index = 9)
    private String website;
    @ExcelProperty(value = "供应商邮箱地址",index = 10)
    private String email;
    @ExcelProperty(value = "供应商电话",index = 11)
    private String tel;
    @ExcelProperty(value = "联系人1",index = 12)
    private String contact1;
    @ExcelProperty(value = "联系人1-电话",index = 13)
    private String contact1Tel;
    @ExcelProperty(value = "联系人1-邮箱",index = 14)
    private String contact1Email;
    @ExcelProperty(value = "联系人2",index = 15)
    private String contact2;
    @ExcelProperty(value = "联系人2-电话",index = 16)
    private String contact2Tel;
    @ExcelProperty(value = "联系人2-邮箱",index = 17)
    private String contact2Email;
    @ExcelProperty(value = "统一社会信用代码",index = 18)
    private String creditCode;
    @ExcelProperty(value = "是否启用Y/N",index = 19)
    private String enableFlag;
    //备注
    @ExcelIgnore
    private String remark;
    //预留字段1
    @ExcelIgnore
    private String attr1;
    //预留字段2
    @ExcelIgnore
    private String attr2;
    //预留字段3
    @ExcelIgnore
    private Integer attr3;
    //预留字段4
    @ExcelIgnore
    private Integer attr4;
    //创建者
    @ExcelIgnore
    private String createBy;
    //创建时间
    @ExcelIgnore
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    //更新者
    @ExcelIgnore
    private String updateBy;
    //更新时间
    @ExcelIgnore
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;
}
