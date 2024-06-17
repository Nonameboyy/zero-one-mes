package com.zeroone.star.project.j3.query;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author ZhunJunHua
 * #Description 1.0
 * #Date: 2023.11.25
 */
@Data
@ApiModel("公告查询对象")
public class NoticeQuery extends PageQuery {
    @ApiModelProperty(value = "公告标题",example = "测试公告内容")
    private String noticeTitle;
    @ApiModelProperty(value = "公告类型",example = "公告")
    private String noticeType;
    @ApiModelProperty(value = "操作者",example = "admin")
    private String operator;
}
