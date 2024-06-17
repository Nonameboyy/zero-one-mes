package com.zeroone.star.project.j5.dto.holidaysetting;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.util.Date;


/**
 * <p>
 * 描述：单日假期数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nangua
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class HolidayDTO {
        @ApiModelProperty(value = "流水号", example = "29")
        private int holidayId;
        @ApiModelProperty(value = "日期", example = "2023-05-01")
        private LocalDate theDay;
        @ApiModelProperty(value = "日期类型", example = "HOLIDAY")
        private String holidayType;

}
