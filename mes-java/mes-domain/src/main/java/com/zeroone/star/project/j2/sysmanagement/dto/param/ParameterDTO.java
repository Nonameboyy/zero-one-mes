package com.zeroone.star.project.j2.sysmanagement.dto.param;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.format.DateTimeFormat;
import com.alibaba.excel.annotation.write.style.ColumnWidth;
import com.alibaba.excel.annotation.write.style.ContentRowHeight;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiOperation;
import lombok.Data;

import java.util.Date;

/**
 * @author 40斤、kino
 * @version 1.0.0
 * @Description: 参数操作传输数据对象
 */
@Data
@ApiOperation("参数操作传输数据对象")
@ContentRowHeight(25)
public class ParameterDTO {
    // 参数主键
    @ExcelProperty(value = "参数主键",index = 0)
    @ColumnWidth(20)
    @ApiModelProperty(value = "参数主键",example = "1")
    private Integer configId;

    // 参数名称
    @ExcelProperty(value = "参数名称",index = 1)
    @ColumnWidth(30)
    @ApiModelProperty(value = "参数名称",example = "主框架页-默认皮肤样式名称")
    private String configName;

    // 参数键名
    @ExcelProperty(value = "参数键名",index = 2)
    @ColumnWidth(30)
    @ApiModelProperty(value = "参数键名",example = "sys.index.skinName")
    private String configKey;

    // 参数键值
    @ExcelProperty(value = "参数键值",index = 3)
    @ColumnWidth(30)
    @ApiModelProperty(value = "参数键值",example = "skin-red")
    private String configValue;

    // 系统内置（Y是 N否）
    @ExcelProperty(value = "系统内置 ",index = 4)
    @ColumnWidth(20)
    @ApiModelProperty(value = "系统内置 Y是 N否",example = "Y")
    private String configType;

    // 创建者
    @ApiModelProperty(value = "创建者",example = "admin")
    @ExcelIgnore
    private String createBy;

    // 创建时间
    @ApiModelProperty(value = "创建时间",example = "2022-04-07 00:29:32")
    @ExcelIgnore
    private Date createTime;

    // 更新者
    @ApiModelProperty(value = "更新者",example = "admin")
    @ExcelIgnore
    private String updateBy;

    // 更新时间
    @ApiModelProperty(value = "更新时间",example = "2022-08-23 08:41:41")
    @ExcelIgnore
    private Date updateTime;

    // 备注
    @ApiModelProperty(value = "备注",example = "深色主题theme-dark，浅色主题theme-light")
    @ExcelIgnore
    private String remark;


}
