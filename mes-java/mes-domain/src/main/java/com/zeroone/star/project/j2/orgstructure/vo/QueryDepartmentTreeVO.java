package com.zeroone.star.project.j2.orgstructure.vo;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.Getter;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 描述：用来定义一个树形节点的数据 实现 获取部门列表（条件）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author cq
 * @version 1.0.0
 */
@Getter
@EqualsAndHashCode(callSuper = true)
@Data
public class QueryDepartmentTreeVO  extends TreeNode {
    @ApiModelProperty(value = "部门id",example = "1")
    private Integer id;
    @ApiModelProperty(value = "父部门id",example = "0")
    private Integer fId;
    @ApiModelProperty(value = "部门名称",example = "研发部门")
    private String deptName;
    @ApiModelProperty(value = "排序",example = "1")
    private Integer orderNum;
    @ApiModelProperty(value = "状态",example = "0")
    private String status;
    @ApiModelProperty(value = "创建时间",example = "2022-04-7 00:29:30")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "节点包含的子节点")
    public List<QueryDepartmentTreeVO> getChildren(){
        return childrenElementTrans();
    }
}
