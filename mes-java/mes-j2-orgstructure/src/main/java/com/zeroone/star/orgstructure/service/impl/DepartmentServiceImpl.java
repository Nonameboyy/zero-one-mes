package com.zeroone.star.orgstructure.service.impl;

import cn.hutool.core.lang.func.Func1;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgstructure.entity.DepartmentDO;
import com.zeroone.star.orgstructure.parameterMapstruct.MsDepartmentMapper;
import com.zeroone.star.orgstructure.service.DepartmentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.orgstructure.dto.dept.DepartmentDTO;
import com.zeroone.star.project.j2.orgstructure.query.dept.DepartmentQuery;
import com.zeroone.star.project.j2.orgstructure.vo.DepartmentTreeVO;
import com.zeroone.star.project.j2.orgstructure.vo.QueryDepartmentTreeVO;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


/**
 * <p>
 * Tree转化器
 * </p>
 *
 * @author cq
 * @since 2024-05-22
 */
class DepartmentTreeNodeMapper implements TreeNodeMapper<DepartmentDO> {
    private List<Long> mRoot ;//根节点id

    public DepartmentTreeNodeMapper(){//无参构造 不使用

    }
    public DepartmentTreeNodeMapper(List<Long> root){//有参构造使用有参构造确认root节点
        mRoot = root;//浅拷贝没有问题，只需要拿出值判断
    }

    @Override
    public TreeNode objectMapper(DepartmentDO department) {
        DepartmentTreeVO treenode = new DepartmentTreeVO();
        treenode.setTnId(department.getDeptId().toString());
        if (department.getParentId() == null || isRootId(department.getDeptId())) {//如果父亲id不存在 or 当前是root节点
            treenode.setTnPid((null));//设置空父亲
        } else {
            treenode.setTnPid(department.getParentId().toString());
        }
        treenode.setDeptName(department.getDeptName());
        treenode.setId(Math.toIntExact(department.getDeptId()));
        treenode.setFId(Math.toIntExact(department.getParentId()));
        return treenode;
    }

    public boolean isRootId(Long id){
        for (Long node:mRoot){
            if(node.equals(id))
                return true;
        }
        return false;
    }

}


/**
 * <p>
 * 部门表 服务实现类
 * </p>
 *
 * @author 宵夜
 * @since 2024-05-22
 */



@Service
public class DepartmentServiceImpl extends ServiceImpl<com.zeroone.star.orgstructure.mapper.DepartmentMapper, DepartmentDO> implements DepartmentService {

    @Resource
    MsDepartmentMapper msDepartmentMapper;

    @Override
    public List<DepartmentTreeVO> getDepartmentNameTree(String name){
        //定义数据容器
        List<DepartmentDO> departments = new ArrayList<>();
        List<DepartmentDO> t = baseMapper.selectByNameOne(name);//查询的部门本体(相当于root) 可能查询到同名的部门
        departments.addAll(t);
        List<Long> ids = new ArrayList<>();
        for (DepartmentDO root : departments) {//查询到多个名字相同的部门 全部加入待查寻集中
            ids.add(root.getDeptId());
        }
        List<Long> root = new ArrayList<>();//根节点id
        for (DepartmentDO node : departments) {//深拷贝
            root.add(node.getDeptId());
        }
        for (int i = 0; i < ids.size(); i++) {
            List<DepartmentDO> tDept = baseMapper.selectByIds(Math.toIntExact(ids.get(i)));
            if (tDept != null && !tDept.isEmpty()){
                departments.addAll(tDept);
                for (DepartmentDO node : tDept) {//将查询到的部门加入到ids中待查寻它的子部门
                    ids.add(node.getDeptId());
                }
            }
        }
        return TreeUtils.listToTree(departments, new DepartmentTreeNodeMapper(root));
    }


    //获取部门列表
    @Override
    public List<QueryDepartmentTreeVO> getDepartmentList(DepartmentQuery query) {
        //定义数据容器
        List<DepartmentDO> departments = new ArrayList<>();
        List<DepartmentDO> t = baseMapper.selectByQueryOne(
                query.getDeptName(),
                query.getStatus(),
                query.getOrderNum(),
                query.getCreateTime()
            );//查询的部门本体(相当于root) 可能查询到同名的部门
        departments.addAll(t);
        List<Long> ids = new ArrayList<>();
        for (DepartmentDO root : departments) {//查询到多个部门 全部加入待查寻集中
            ids.add(root.getDeptId());
        }
        List<Long> root = new ArrayList<>();//根节点id
        for (DepartmentDO node : departments) {//深拷贝
            root.add(node.getDeptId());
        }
        for (int i = 0; i < ids.size(); i++) {
            List<DepartmentDO> tDept = baseMapper.selectByQueryIds(Math.toIntExact(ids.get(i)));
            if (tDept != null && !tDept.isEmpty()){
                departments.addAll(tDept);
                for (DepartmentDO node : tDept) {//将查询到的部门加入到ids中待查寻它的子部门
                    ids.add(node.getDeptId());
                }
            }
        }
        return TreeUtils.listToTree(departments, new DepartmentTreeNodeMapper(root));
    }

    //根据id获取指定部门所有信息
    @Override
    public DepartmentDTO getDepartmentDetail(Long id) {
        //执行查询
        DepartmentDO department = baseMapper.selectById(id);
        if(department != null){
            return msDepartmentMapper.departmentOToDepartmentDTO(department);
        }
        return null;//null表示查询失败没有该条数据
    }

    @Override
    public Integer execSaveDepartment(DepartmentDTO departmentDTO) {
        DepartmentDO departmentDO = msDepartmentMapper.departmentDTOToDepartment(departmentDTO);
        QueryWrapper<DepartmentDO> wrapper = new QueryWrapper<>();
        wrapper.eq("dept_name", departmentDO.getDeptName());
        wrapper.eq("parent_id", departmentDO.getParentId());
        if (baseMapper.selectList(wrapper) != null) {
            departmentDO.setCreateTime(LocalDateTime.now());
            int insert = baseMapper.insert(departmentDO);
            departmentDTO.setDeptId(departmentDO.getDeptId());
            return insert;
        }
        return null;

    }
    @Override
    public Integer execUpdateDepartment(DepartmentDTO departmentDTO) {
        //判断仓库是否存在
        QueryWrapper<DepartmentDO> wrapper = new QueryWrapper<>();
        wrapper.eq("dept_id", departmentDTO.getDeptId());
        List<DepartmentDO> departmentDOS = baseMapper.selectList(wrapper);
        if(departmentDOS.size() > 0){
            DepartmentDO departmentDO = msDepartmentMapper.departmentDTOToDepartment(departmentDTO);
            departmentDO.setUpdateTime(LocalDateTime.now());
            return baseMapper.updateById(departmentDO);
        }
        return 0;
    }

    @Override
    @Transactional
    public Integer execRemoveDepartment(Long[] ids) {
        //遍历每一个要删除的部门
        for(Long id : ids ){
            //查询所有parentId为id的部门
            QueryWrapper<DepartmentDO> wrapper = new QueryWrapper<>();
            wrapper.eq("parent_id", id);
            List<DepartmentDO> departmentDOS = baseMapper.selectList(wrapper);
            if (departmentDOS.size() != 0) {
                //删除父id为id的部门
                for (DepartmentDO departmentDO : departmentDOS) {
                    baseMapper.deleteById(departmentDO.getDeptId());
                }
            }
        }

        return baseMapper.deleteBatchIds(Arrays.asList(ids));
    }

    }
