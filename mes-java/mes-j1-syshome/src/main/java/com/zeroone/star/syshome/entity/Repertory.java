package com.zeroone.star.syshome.entity;



import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 库存统计数据实体类
 * </p>
 *
 * @author awei
 * @since 2024-05-10
 */
@Getter
@Setter
@TableName("wm_material_stock")
public class Repertory implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "产品名称",example = "衣柜")
    private String itemName;
    @ApiModelProperty(value = "在库数量",example = "886")
    private Integer quantityOnhand;

}
