package com.zeroone.star.syshome.entity;


import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;


/**
 * <p>
 * 质量统计数据实体类
 * </p>
 *
 * @author awei
 * @since 2024-05-10
 */
@Getter
@Setter
@TableName("qc_defect_record")
public class Quality implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 缺陷描述
     */
    private String defectName;
    /**
     * 缺陷数量
     */
    private Integer defectQuantity;

}
