package com.zeroone.star.project.dto.j4.basicdata;

import com.alibaba.excel.annotation.ExcelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 导入供应商模板——excel报表参数
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class VendorImportDTO {

    @ExcelProperty("供应商编码")
    private String vendorCode;

    @ExcelProperty("供应商名称")
    private String vendorName;

    @ExcelProperty("供应商简称")
    private String vendorNick;

    @ExcelProperty("供应商英文名称")
    private String vendorEn;

    @ExcelProperty("供应商简介")
    private String vendorDes;

    @ExcelProperty("供应商LOGO地址")
    private String vendorLogo;

    @ExcelProperty("供应商等级")
    private String vendorLevel;

    @ExcelProperty("供应商评分")
    private Integer vendorScore;

    @ExcelProperty("供应商地址")
    private String address;

    @ExcelProperty("供应商官网地址")
    private String website;

    @ExcelProperty("供应商邮箱地址")
    private String email;

    @ExcelProperty("供应商电话")
    private String tel;

    @ExcelProperty("联系人1")
    private String contact1;

    @ExcelProperty("联系人1-电话")
    private String contact1Tel;

    @ExcelProperty("联系人1-邮箱")
    private String contact1Email;

    @ExcelProperty("联系人2")
    private String contact2;

    @ExcelProperty("联系人2-电话")
    private String contact2Tel;

    @ExcelProperty("联系人2-邮箱")
    private String contact2Email;

    @ExcelProperty("统一社会信用代码")
    private String creditCode;

    @ExcelProperty("是否启用Y/N")
    private String enableFlag;
}