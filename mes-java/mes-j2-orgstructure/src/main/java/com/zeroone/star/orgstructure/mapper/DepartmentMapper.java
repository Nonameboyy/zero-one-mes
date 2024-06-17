package com.zeroone.star.orgstructure.mapper;

import com.zeroone.star.orgstructure.entity.DepartmentDO;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgstructure.entity.DepartmentDO;
import org.apache.ibatis.annotations.Mapper;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 部门表 Mapper 接口
 * </p>
 *
 * @author 宵夜
 * @since 2024-05-22
 */
@Mapper
public interface DepartmentMapper extends BaseMapper<DepartmentDO> {
    /**
     *
     * @param ids 部门名称
     * @return 返回列表
     */
    List<DepartmentDO> selectByIds(Integer ids);
    /**
     * 返回查询条件的实体(root)
     * @param name 部门名称
     * @return 返回列表
     */
    List<DepartmentDO> selectByNameOne(String name);
    /**
     *
     * @param deptName,  status,  orderNum,  parentId 查询条件体
     * @return 返回列表
     */
    List<DepartmentDO> selectByQueryOne(String deptName,Integer orderNum, Integer status,LocalDateTime time);
    /**
     * 返回查询条件的实体(root)
     * @param ids 部门名称
     * @return 返回列表
     */
    List<DepartmentDO> selectByQueryIds(Integer ids);

}
