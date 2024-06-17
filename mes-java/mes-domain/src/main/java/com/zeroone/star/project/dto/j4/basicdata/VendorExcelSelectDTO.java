package com.zeroone.star.project.dto.j4.basicdata;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：导出供应商excel报表查询条件参数
 *
 * @author 本鼠
 * @version 1.0.0
 */
@ApiModel("导出供应商excel报表查询条件参数")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class VendorExcelSelectDTO {
    /*
    * 供应商编码
    * */
    @ApiModelProperty(value = "供应商编码", example = "GZDM")
    private String vendorCode;
    /*
    * 供应商名称
    * */
    @ApiModelProperty(value = "供应商名称", example = "江苏南通塑有为塑料制品有限公司")
    private String vendorName;
    /*
     * 供应商简称
     * */
    @ApiModelProperty(value = "供应商简称", example = "南通有为")
    private String vendorNick;
    /*
     * 是否启用
     * */
    @ApiModelProperty(value = "是否启用", example = "Y")
    private String enableFlag;
    /*
     * 英文名称
     * */
    @ApiModelProperty(value = "英文名称", example = "doumu")
    private String vendorEn;
}
