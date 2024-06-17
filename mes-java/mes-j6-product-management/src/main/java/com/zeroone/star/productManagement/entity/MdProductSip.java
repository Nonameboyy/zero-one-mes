package com.zeroone.star.productManagement.entity;

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
 * 产品SIP表
 * </p>
 *
 * @author xiebao
 * @since 2024-05-27
 */
@Getter
@Setter
@TableName("md_product_sip")
public class MdProductSip implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 记录ID
     */
    @TableId(value = "sip_id", type = IdType.AUTO)
    private Long sipId;

    /**
     * 物料产品ID
     */
    private Long itemId;

    /**
     * 排列顺序
     */
    private Integer orderNum;

    /**
     * 对应的工序
     */
    private Long processId;

    /**
     * 工序编号
     */
    private String processCode;

    /**
     * 工序名称
     */
    private String processName;

    /**
     * 标题
     */
    private String sipTitle;

    /**
     * 详细描述
     */
    private String sipDescription;

    /**
     * 图片地址
     */
    private String sipUrl;

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
