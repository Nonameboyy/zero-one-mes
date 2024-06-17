package com.zeroone.star.project.j3.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import javax.validation.constraints.NotBlank;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("通知类型对象")
public class AddNoticeDTO {
    @ApiModelProperty(value = "公告标题",example = "测试公告内容")
    @NotBlank(message = "新增公告时, 公告标题不能为空")
    private String noticeTitle;
    @ApiModelProperty(value = "公告类型（0公告 1通知）",example = "0")
    private String noticeType;
    @NotBlank(message = "新增公告时, 公告内容不能为空")
    @ApiModelProperty(value = "公告内容",example = "测试公告内容")
    private String noticeContent;
    @ApiModelProperty(value = "状态（0正常 1关闭）",example = "0")
    @NotBlank(message = "新增公告时, 状态不能为空")
    private String status;
}


