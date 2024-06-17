package com.zeroone.star.teamsettings.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 班组表
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Getter
@Setter
@TableName("cal_team")
public class CalTeam implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 班组ID
     */
    @TableId(value = "team_id", type = IdType.AUTO)
    private Long teamId;

    /**
     * 班组编号
     */
    private String teamCode;

    /**
     * 班组名称
     */
    private String teamName;

    /**
     * 班组类型
     */
    private String calendarType;

    /**
     * 备注
     */
    private String remark;

    /**
     * 预留字段1
     */
    private String attr1;

    /**
     * 预留字段2
     */
    private String attr2;

    /**
     * 预留字段3
     */
    private Integer attr3;

    /**
     * 预留字段4
     */
    private Integer attr4;

    /**
     * 创建者
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    private String updateBy;

    /**
     * 更新时间
     */
    private LocalDateTime updateTime;


}
