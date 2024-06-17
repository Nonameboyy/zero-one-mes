package com.zeroone.star.project.j2.sysmanagement.query.param;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * @author 40斤、kino
 * @version 1.0.0
 * @Description:
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("参数查询对象")
public class ParameterQuery extends PageQuery {

    @NotBlank(message = "参数名称不能为空")
    @ApiModelProperty(value = "参数名称", example = "账号")
    private String configName;

    @ApiModelProperty(value = "参数键名", example = "sys.index.skinName")
    private String configKey;

    @ApiModelProperty(value = "系统内置（Y是 N否）", example = "Y")
    private String configType;

    @ApiModelProperty(value = "开始时间", example = "2022-01-01")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date beginTime;

    @ApiModelProperty(value = "结束时间", example = "2022-07-17")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date endTime;


}
