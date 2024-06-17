package com.zeroone.star.project.j5.query.holidaysetting;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDate;

/**
 * @description:
 * @program: mes-java
 * @ClassName ListHolidayQuery
 * @author: nangua
 * @create: 2024-05-27 12:30
 * @Version 1.0
 **/

@Data
@ApiModel("获取节假日配置 查询对象")
public class ListHolidayQuery {

    @NotBlank(message = "查询的日期不能为空")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "日期", example = "2024-05-22")
    private LocalDate date;

}