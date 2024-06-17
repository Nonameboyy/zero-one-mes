package com.zeroone.star.project.query.j4.warehousemanagement.outsource;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.sound.sampled.Line;

/**
 * @Description
 * @Author diwu
 * @Date 2024/5/30
 */
@Data
@ApiModel("外协放料单查询条件数据对象")
public class OutsourceIssueLineQuery extends PageQuery {
    @ApiModelProperty(value = "领料单id" ,example = "0")
    private Long issueID;
}
