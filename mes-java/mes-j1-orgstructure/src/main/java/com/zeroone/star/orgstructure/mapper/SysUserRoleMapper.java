package com.zeroone.star.orgstructure.mapper;

import com.zeroone.star.orgstructure.entity.SysUserRole;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;


/**
 * <p>
 * 用户和角色关联表 Mapper 接口
 * </p>
 *
 * @author gimigimi
 * @since 2024-05-23
 */
@Mapper
public interface SysUserRoleMapper extends BaseMapper<SysUserRole> {
        /**
         * 批量添加角色
         * @param sysUserRoleList
         * @return
         */
        int saveBatchByUserIdAndRoleIds(List<SysUserRole> sysUserRoleList);

        /**
         * 批量删除角色
         * @param sysUserRoleList
         * @return
         */
        int deleteBatchByUserIdAndRoleIds(List<SysUserRole> sysUserRoleList);
}
