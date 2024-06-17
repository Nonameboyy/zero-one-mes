package com.zeroone.star.project.j3.dto;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@TableName(value = "sys_notice")
public class NoticeDTO implements Serializable {

    @TableId(value = "notice_id")
    @ApiModelProperty(value = "公告ID")
    private Long id;

    @ApiModelProperty(value = "公告标题",example = "测试公告标题")
    private String noticeTitle;

    @ApiModelProperty(value = "公告内容",example = "测试公告内容")
    private String noticeContent;

    @ApiModelProperty(value = "公告类型",example = "公告")
    private String noticeType;

    @ApiModelProperty(value = "状态",example = "正常")
    private String status;

}
