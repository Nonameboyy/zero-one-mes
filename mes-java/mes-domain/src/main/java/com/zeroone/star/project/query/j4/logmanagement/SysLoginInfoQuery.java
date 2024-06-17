package com.zeroone.star.project.query.j4.logmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @Description
 * @Author diwu
 * @Date 2024/5/19
 */
@Data
@ApiModel("查询登录日志条件对象")
public class SysLoginInfoQuery extends PageQuery {


    /**
     * 用户名称
     */
    @ApiModelProperty(value = "用户的名称",example = "小明")
    private String userName;


    /**
     * 登录地点
     */
    @ApiModelProperty(value = "登录的地点",example = "上海")
    private String loginLocation;


    /**
     * 登录状态（0成功 1失败）
     */
    @ApiModelProperty(value = "登录的状态",example = "0 代表成功， 1 代表失败")
    private String status;


    /**
     * 起始访问日期
     */
    @ApiModelProperty(value = "要查询的登录访问的起始日期",example = "2024-05-19")
    private Date startLoginTime;

    /**
     * 结束的访问日期
     */
    @ApiModelProperty(value = "要查询的登录访问的结束日期",example = "2024-05-19")
    private Date endLoginTime;
}
