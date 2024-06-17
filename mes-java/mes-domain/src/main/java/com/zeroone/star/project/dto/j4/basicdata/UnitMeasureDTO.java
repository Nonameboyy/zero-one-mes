package com.zeroone.star.project.dto.j4.basicdata;


import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;

/**
 * <p>
 * 单位表
 * </p>
 *
 * @author wxz
 * @since 2024-05-21
 */
@Data
@ApiModel(value = "查询单位分页列表的对象")
public class UnitMeasureDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "单位ID", example = "1")
    private Long measureId;


    @Size(min = 1, max = 64, message = "单位编码长度必须在1到64个字符之间")
    @ApiModelProperty(value = "单位编码", example = "METER")
    private String measureCode;

    @Size(min = 1, max = 255, message = "单位名称长度必须在1到255个字符之间")
    @ApiModelProperty(value = "单位名称", example = "米")
    private String measureName;

    @ApiModelProperty(value = "是否是主单位", example = "Y")
    private String primaryFlag;

    @ApiModelProperty(value = "主单位ID", example = "1")
    private Long primaryId;

    @ApiModelProperty(value = "与主单位换算比例", example = "1.0")
    private Double changeRate;

    @ApiModelProperty(value = "是否启用", example = "Y")
    private String enableFlag;

    @Size(max = 500, message = "备注长度不能超过500个字符")
    @ApiModelProperty(value = "备注", example = "这是主单位")
    private String remark;

    @Size(max = 64, message = "预留字段1长度不能超过64个字符")
    @ApiModelProperty(value = "预留字段1", example = "自定义值1")
    private String attr1;

    @Size(max = 255, message = "预留字段2长度不能超过255个字符")
    @ApiModelProperty(value = "预留字段2", example = "自定义值2")
    private String attr2;

    @ApiModelProperty(value = "预留字段3", example = "100")
    private Integer attr3;

    @ApiModelProperty(value = "预留字段4", example = "200")
    private Integer attr4;

    @Size(max = 64, message = "创建者长度不能超过64个字符")
    @ApiModelProperty(value = "创建者", example = "user123")
    private String createBy;

    @ApiModelProperty(value = "创建时间", example = "2024-05-20 08:30:00")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @Size(max = 64, message = "更新者长度不能超过64个字符")
    @ApiModelProperty(value = "更新者", example = "user456")
    private String updateBy;

    @ApiModelProperty(value = "更新时间", example = "2024-05-21 08:30:00")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime updateTime;

}
