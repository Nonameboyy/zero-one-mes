package com.zeroone.star.productClassification.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@Getter
@Setter
@TableName("md_item_type")
public class ItemType {

    /**
     * 分类ID
     */
    @TableId(value = "md_item_type_id", type = IdType.AUTO)
    private Long itemTypeId;

    /**
     * 父分类ID
     */
    private Long parentTypeId;

    /**
     * 分类编码
     */
    private String itemTypeCode;

    /**
     * 分类名称
     */
    private String itemTypeName;

    /**
     * 祖先节点列表
     */
    private String ancestors;

    /**
     * 产品物料标识
     */
    private String itemOrProduct;

    /**
     * 排序号
     */
    private Integer orderNum;

    /**
     * 启用标识
     */
    private String enableFlag;

    /**
     * 子分类列表
     */
    private List<ItemType> children = new ArrayList<ItemType>();

    /**
     * 备注
     */
    private String remark;

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
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;
}
