package com.zeroone.star.project.dto.j4.sysmanagement.sysAutoCodePart;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @version 1.0
 * @Description: 编码生成规则组成表的数据传输对象
 * @Author: jm
 * @Date: 2024/5/21 19:41
 */
@Data
@ApiModel("编码生成规则组成表的数据传输对象")
public class SysAutoCodePartDTO {
    /**
     * 分段ID
     */
    @ApiModelProperty(value = "分段ID", example = "1")
    @TableId(value = "part_id", type = IdType.AUTO)
    private Long partId;

    /**
     * 规则ID
     */
    @ApiModelProperty(value = "规则ID", example = "1")
    private Long ruleId;

    /**
     * 分段序号
     */
    @ApiModelProperty(value = "分段序号", example = "1")
    private Integer partIndex;

    /**
     * 分段类型，INPUTCHAR：输入字符，NOWDATE：当前日期时间，FIXCHAR：固定字符，SERIALNO：流水号
     */
    @ApiModelProperty(value = "分段类型，INPUTCHAR：输入字符，NOWDATE：当前日期时间，FIXCHAR：固定字符，SERIALNO：流水号", example = "INPUTCHAR")
    private String partType;

    /**
     * 分段编号
     */
    @ApiModelProperty(value = "分段编号", example = "1")
    private String partCode;

    /**
     * 分段名称
     */
    @ApiModelProperty(value = "分段名称", example = "前缀，流水号，流水号部分，年月日部分，固定前缀，年份，年月日等")
    private String partName;

    /**
     * 分段长度
     */
    @ApiModelProperty(value = "分段长度", example = "1")
    private Integer partLength;

    @ApiModelProperty(value = "日期格式", example = "yyyyMMdd")
    private String dateFormat;

    /**
     * 输入字符
     */
    @ApiModelProperty(value = "输入字符", example = "1")
    private String inputCharacter;

    /**
     * 固定字符
     */
    @ApiModelProperty(value = "固定字符", example = "1")
    private String fixCharacter;

    /**
     * 流水号起始值
     */
    @ApiModelProperty(value = "流水号起始值", example = "1")
    private Integer seriaStartNo;

    /**
     * 流水号步长
     */
    @ApiModelProperty(value = "流水号步长", example = "1")
    private Integer seriaStep;

    /**
     * 流水号当前值
     */
    @ApiModelProperty(value = "流水号当前值", example = "1")
    private Integer seriaNowNo;

    /**
     * 流水号是否循环
     */
    @ApiModelProperty(value = "流水号是否循环", example = "Y/N")
    private String cycleFlag;

    /**
     * 循环方式，YEAR：按年，MONTH：按月，DAY：按天，HOUR：按小时，MINITE：按分钟，OTHER：按传入字符变
     */
    @ApiModelProperty(value = "循环方式，YEAR：按年，MONTH：按月，DAY：按天，HOUR：按小时，MINITE：按分钟，OTHER：按传入字符变", example = "YEAR")
    private String cycleMethod;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "1")
    private String remark;

}
