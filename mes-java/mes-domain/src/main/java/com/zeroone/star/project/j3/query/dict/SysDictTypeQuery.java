package com.zeroone.star.project.j3.query.dict;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.util.Date;

/**
 * 字典类型查询类
 *
 * @Author：xiong
 * @Date：2024/5/19 14:31
 */

@Data
@ApiModel("字典类型查询类")
public class SysDictTypeQuery extends PageQuery implements Serializable {
    @ApiModelProperty(value = "字典名称", example = "用户性别")
    private String dictName;

    @ApiModelProperty(value = "字典类型", example = "sys_user_sex")
    private String dictType;

    @ApiModelProperty(value = "状态(0正常 1停用)", example = "0")
    private String status;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建开始时间", example = "2022-04-07 00:29:32")
    private Date createBeginTime;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建结束时间", example = "2022-04-07 00:29:32")
    private Date createEndTime;
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "开始时间", example = "2022-04-07 00:29:32")
    private Date startTime;

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "结束时间", example = "2022-04-07 10:29:32")
    private Date endTime;
}
