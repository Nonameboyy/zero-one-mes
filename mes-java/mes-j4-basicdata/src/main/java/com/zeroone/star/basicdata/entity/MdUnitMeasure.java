package com.zeroone.star.basicdata.entity;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.*;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：单位实体类
 * </p>

 * @author 本鼠
 * @version 1.0.0
 */

@Data
@Getter
@Setter
@TableName("md_unit_measure")
public class MdUnitMeasure implements Serializable {
    //单位ID
    @ExcelIgnore
    @TableId(value = "measure_id", type = IdType.AUTO)
    private Long measureId;
    @ExcelProperty(value = "单位编码", index = 0)
    private String measureCode;
    @ExcelProperty(value = "单位名称", index = 1)
    private String measureName;
    @ExcelProperty(value = "是否是主单位", index = 2)
    private String primaryFlag;
    @ExcelProperty(value = "主单位ID", index = 3)
    private Integer primaryId;
    @ExcelProperty(value = "与主单位换算比例", index = 4)
    private Double changeRate;
    @ExcelProperty(value = "是否启用", index = 5)
    private String enableFlag;
    @ExcelProperty(value = "预留字段1", index = 6)
    private String attr1;
    @ExcelProperty(value = "预留字段2", index = 7)
    private String attr2;
    @ExcelProperty(value = "预留字段3", index = 8)
    private Integer attr3;
    @ExcelProperty(value = "预留字段4", index = 9)
    private Integer attr4;
    //备注
    @ExcelIgnore
    private String remark;
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
    private LocalDateTime updateTime;
}
