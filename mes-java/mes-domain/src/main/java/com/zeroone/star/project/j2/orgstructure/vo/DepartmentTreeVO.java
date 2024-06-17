package com.zeroone.star.project.j2.orgstructure.vo;

import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


import java.util.List;
@EqualsAndHashCode(callSuper = true)
@Data
public class DepartmentTreeVO extends TreeNode{
    @ApiModelProperty(value = "部门id",example = "1")
    private Integer id;
    @ApiModelProperty(value = "父部门id",example = "0")
    private Integer fId;
    @ApiModelProperty(value = "部门名称",example = "研发部门")
    private String deptName;

    @ApiModelProperty(value = "节点包含的子节点")
    public List<DepartmentTreeVO> getChildren(){
        return childrenElementTrans();
    }
}
