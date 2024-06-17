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
 * 产品BOM关系表
 * </p>
 *
 * @author panda
 * @since 2024-05-27
 */
@Getter
@Setter
@TableName("md_product_bom")
public class MdProductBom implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 流水号
     */
    @TableId(value = "bom_id", type = IdType.AUTO)
    private Long bomId;

    /**
     * 物料产品ID
     */
    private Long itemId;

    /**
     * BOM物料ID
     */
    private Long bomItemId;

    /**
     * BOM物料编码
     */
    private String bomItemCode;

    /**
     * BOM物料名称
     */
    private String bomItemName;

    /**
     * BOM物料规格
     */
    private String bomItemSpec;

    /**
     * BOM物料单位
     */
    private String unitOfMeasure;

    /**
     * 产品物料标识
     */
    private String itemOrProduct;

    /**
     * 物料使用比例
     */
    private Double quantity;

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
