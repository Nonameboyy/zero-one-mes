package com.zeroone.star.project.j3.dto;

import com.alibaba.excel.annotation.ExcelProperty;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;


/**
 * ClassName:DfsExportDTO
 * Package:com.zeroone.star.project.j3.dto
 * Description:
 *      导出该字段消息的DTO 专门提供给下载excel报表及导出dfs
 * @Author Chi池
 * @Create 2024/5/21  8:41
 * @Version 1.0
 */

@Data
public class ExportMessageDTO {

    private static final long serialVersionUID = 1L;

    /** 消息类型 */
    @ApiModelProperty(value = "消息类型",example = "公告")
    @ExcelProperty(value = "消息类型",index = 0)
    private String messageType;

    /** 消息级别 */
    @ApiModelProperty(value = "消息级别",example = "普通")
    @ExcelProperty(value = "消息级别",index = 1)
    private String messageLevel;

    /** 标题 */
    @ApiModelProperty(value = "标题",example = "这是一个标题")
    @ExcelProperty(value = "标题",index = 2)
    private String messageTitle;

    /** 内容 */
    @ApiModelProperty(value = "内容",example = "这是一些内容")
    @ExcelProperty(value = "内容",index = 3)
    private String messageContent;

    /** 发送人ID */
    @ApiModelProperty(value = "发送人ID",example = "12345678")
    @ExcelProperty(value = "发送人ID",index = 4)
    private Long senderId;

    /** 发送人名称 */
    @ApiModelProperty(value = "发送人名称",example = "张三")
    @ExcelProperty(value = "发送人名称",index = 5)
    private String senderName;

    /** 发送人昵称 */
    @ApiModelProperty(value = "发送人昵称",example = "不法少年张三")
    @ExcelProperty(value = "发送人昵称",index = 6)
    private String senderNick;

    /** 接收人ID */
    @ApiModelProperty(value = "接收人ID",example = "87654321")
    @ExcelProperty(value = "接收人ID",index = 7)
    private Long recipientId;

    /** 接收人名称 */
    @ApiModelProperty(value = "接收人名称",example = "李四")
    @ExcelProperty(value = "接收人名称",index = 8)
    private String recipientName;

    /** 接收人昵称 */
    @ApiModelProperty(value = "接收人昵称",example = "妇女之友李四")
    @ExcelProperty(value = "接收人昵称",index = 9)
    private String recipientNick;

    /** 处理时间 */
    /** 处理时间 */
    @ApiModelProperty(value = "处理时间",dataType = "yyyy-MM-dd",example = "2002-12-30")
    @ExcelProperty(value = "处理时间")
    private LocalDate processTime;

    /** 回调地址 */
    @ApiModelProperty(value = "回调地址",example = "随意写")
    @ExcelProperty(value = "回调地址",index = 11)
    private String callBack;

    /** 状态 */
    @ApiModelProperty(value = "状态",example = "未读")
    @ExcelProperty(value = "状态",index = 12)
    private String status;

    /** 是否删除 */
    @ApiModelProperty(value = "是否删除",example = "N")
    @ExcelProperty(value = "是否删除",index = 13)
    private String deletedFlag;
}
