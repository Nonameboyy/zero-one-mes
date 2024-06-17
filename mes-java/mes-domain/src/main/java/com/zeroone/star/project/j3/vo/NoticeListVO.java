package com.zeroone.star.project.j3.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import java.util.Date;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("公告数据列表对象")
public class NoticeListVO {
    @ApiModelProperty(value = "序号",example = "0")
    private Integer noticeId;
    @ApiModelProperty(value = "公告标题",example = "测试公告内容")
    @NotBlank(message = "获取公告时, 公告标题不能为空")
    private String noticeTitle;
    @ApiModelProperty(value = "公告类型（0公告 1通知）",example = "公告")
    private char noticeType;
    @ApiModelProperty(value = "状态（0正常 1关闭）",example = "0")
    @NotBlank(message = "获取公告时, 状态不能为空")
    private char status;
    @ApiModelProperty(value = "创建者",example = "admin")
    @NotBlank(message = "获取公告时, 创建者不能为空")
    private String createBy;
    @ApiModelProperty(value = "创建时间")
    private Date createTime;
}
