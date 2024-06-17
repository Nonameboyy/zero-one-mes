package com.zeroone.star.shopsettings.entity;

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
 * 车间表
 * </p>
 *
 * @author interstellar
 * @since 2024-05-29
 */
@Getter
@Setter
@TableName("md_workshop")
public class MdWorkshop implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 车间ID
     */
    @TableId(value = "workshop_id", type = IdType.AUTO)
    private Long workshopId;

    /**
     * 车间编码
     */
    private String workshopCode;

    /**
     * 车间名称
     */
    private String workshopName;

    /**
     * 面积
     */
    private Double area;

    /**
     * 负责人
     */
    private String charge;

    /**
     * 是否启用
     */
    private String enableFlag;

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
