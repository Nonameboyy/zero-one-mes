package com.zeroone.star.orgstructure.entity;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
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
 * 岗位信息表
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
@Getter
@Setter
@TableName("sys_post")
public class PostDO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 岗位ID
     */
    @ExcelProperty(value = "岗位序号", index = 0)
    @TableId(value = "post_id", type = IdType.AUTO)
    private Long postId;

    /**
     * 岗位编码
     */
    @ExcelProperty(value = "岗位编码", index = 1)
    private String postCode;

    /**
     * 岗位名称
     */
    @ExcelProperty(value = "岗位名称", index = 2)
    private String postName;

    /**
     * 显示顺序
     */
    @ExcelProperty(value = "岗位顺序", index = 3)
    private Integer postSort;

    /**
     * 状态（0正常 1停用）
     */
    @ExcelProperty(value = "岗位状态", index = 4)
    private String status;

    /**
     * 创建者
     */
    @ExcelIgnore
    private String createBy;

    /**
     * 创建时间
     */
    @ExcelIgnore
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 更新者
     */
    @ExcelIgnore
    private String updateBy;

    /**
     * 更新时间
     */
    @ExcelIgnore
    private LocalDateTime updateTime;

    /**
     * 备注
     */
    @ExcelProperty(value = "备注", index = 5)
    private String remark;


}
