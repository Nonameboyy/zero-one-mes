package com.zeroone.star.project.dto.j4.basicdata;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：导出单位excel报表查询条件参数
 *
 * @author 本鼠
 * @version 1.0.0
 */
@ApiModel("导出单位excel报表查询条件参数")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class UnitExcelSelectDTO {
    /*
    * 单位名称
    * */
    @ApiModelProperty(value = "单位名称", example = "米")
    private String measureName;
    /*
    * 单位编码
    * */
    @ApiModelProperty(value = "单位编码", example = "m")
    private String measureCode;
}
