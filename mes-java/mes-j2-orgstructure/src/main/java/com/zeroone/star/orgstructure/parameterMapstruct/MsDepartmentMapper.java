package com.zeroone.star.orgstructure.parameterMapstruct;

import com.zeroone.star.orgstructure.entity.DepartmentDO;
import com.zeroone.star.project.j2.orgstructure.dto.dept.DepartmentDTO;
import org.mapstruct.Mapper;

/**
 * @author 宵夜
 * @version 1.0.0
 * @Description: TODO
 */
@Mapper(componentModel = "spring")
public interface MsDepartmentMapper {
    /**
     * 将department转换为departmentDTO
     *
     * @param department
     * @return
     */
    DepartmentDTO departmentOToDepartmentDTO(DepartmentDO department);

    /**
     * 将department转换为departmentDTO
     *
     * @param departmentDTO
     * @return
     */
    DepartmentDO departmentDTOToDepartment(DepartmentDTO departmentDTO);
}
