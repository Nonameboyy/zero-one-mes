package com.zeroone.star.project.query.j4.warehousemanagement.outsource;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @Description
 * @Author diwu
 * @Date 2024/5/30
 */
@Data
@ApiModel("外协放料批量删除条件数据对象")
public class DelOutsourceIssueQuery {
    /**
     * 领料单ID
     */
    @ApiModelProperty(value = "领料单id" )
    private List<Long> issueIds;

}
