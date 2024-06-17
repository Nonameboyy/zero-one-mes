package com.zeroone.star.project.j2.orgstructure.dept;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.dept.DepartmentDTO;
import com.zeroone.star.project.j2.orgstructure.query.dept.DepartmentQuery;
import com.zeroone.star.project.j2.orgstructure.vo.DepartmentTreeVO;
import com.zeroone.star.project.j2.orgstructure.vo.QueryDepartmentTreeVO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author 宵夜、夕秋z
 * @version 1.0.0
 * @Description: DepartmentApis
 */
public interface DepartmentApis {

    //获取部门名称树
    JsonVO<List<DepartmentTreeVO>> getDepartmentNameTree(DepartmentQuery query);

    //获取部门列表(条件)
    JsonVO<List<QueryDepartmentTreeVO>> getDepartmentList(DepartmentQuery departmentQuery);

    //获取部门详情
    JsonVO<DepartmentDTO> getDepartmentDetail(Long id);



    //新增部门
    JsonVO<Long> addDepartment(DepartmentDTO departmentDTO);

    //修改部门
    JsonVO<Integer> modifyDepartment(DepartmentDTO departmentDTO);

    //删除部门
    JsonVO<Integer> removeDepartment(Long[] ids);



}
