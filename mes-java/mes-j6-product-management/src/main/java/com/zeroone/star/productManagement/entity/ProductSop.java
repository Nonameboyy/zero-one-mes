package com.zeroone.star.productManagement.entity;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.*;

@Getter
@Setter
@Builder
@NoArgsConstructor
@AllArgsConstructor
@TableName("md_product_sop")
public class ProductSop implements Serializable {
    private static final long serialVersionUID = 1L;
    @TableId(value = "sop_id", type = IdType.AUTO)
    private Long sopId;

    private Long itemId;

    private Integer orderNum;

    private Long processId;

    private String processCode;

    private String processName;

    private String sopTitle;

    private String sopDescription;

    private String sopUrl;

    private String remark;

    private String attr1;

    private String attr2;

    private Integer attr3;

    private Integer attr4;

    private String createBy;

    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    private String updateBy;
    @TableField(fill = FieldFill.UPDATE)
    private LocalDateTime updateTime;

}
