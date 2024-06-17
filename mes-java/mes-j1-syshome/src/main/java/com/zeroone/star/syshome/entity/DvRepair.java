package com.zeroone.star.syshome.entity;

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
 * 设备维修单
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Getter
@Setter
@TableName("dv_repair")
public class DvRepair implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 维修单ID
     */
    @TableId(value = "repair_id", type = IdType.AUTO)
    private Long repairId;

    /**
     * 维修单编号
     */
    private String repairCode;

    /**
     * 维修单名称
     */
    private String repairName;

    /**
     * 设备ID
     */
    private Long machineryId;

    /**
     * 设备编码
     */
    private String machineryCode;

    /**
     * 设备名称
     */
    private String machineryName;

    /**
     * 品牌
     */
    private String machineryBrand;

    /**
     * 规格型号
     */
    private String machinerySpec;

    /**
     * 设备类型ID
     */
    private Long machineryTypeId;

    /**
     * 报修日期
     */
    private LocalDateTime requireDate;

    /**
     * 维修完成日期
     */
    private LocalDateTime finishDate;

    /**
     * 验收日期
     */
    private LocalDateTime confirmDate;

    /**
     * 维修结果
     */
    private String repairResult;

    /**
     * 维修人员
     */
    private String acceptedBy;

    /**
     * 验收人员
     */
    private String confirmBy;

    /**
     * 单据状态
     */
    private String status;

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
