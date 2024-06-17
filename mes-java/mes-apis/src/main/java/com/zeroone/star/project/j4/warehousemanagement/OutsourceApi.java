package com.zeroone.star.project.j4.warehousemanagement;

import com.zeroone.star.project.dto.j4.warehousemanagement.outsource.OutsourceIssueDTO;
import com.zeroone.star.project.query.j4.warehousemanagement.outsource.DelOutsourceIssueQuery;
import com.zeroone.star.project.query.j4.warehousemanagement.outsource.OutsourceIssueQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.warehousemanagement.outsource.OutsourceIssueVO;

/**
 * @Description
 * 关于外协放料的API的功能定义
 * @Author diwu
 * @Date 2024/5/30
 */
public interface OutsourceApi {
    /**
     *  分页查询 外协放料的信息
     * @param query
     * @return
     */
    JsonVO<OutsourceIssueVO> queryOutsourceIssue(OutsourceIssueQuery query);

    /**
     * 根据id 查询 详细的外协放料的信息
     * @param Id
     * @return
     */
    JsonVO<OutsourceIssueDTO> queryByIdOutsourceIssue(String Id);

    /**
     * 自动的生成领料单的编号
     * @return
     */
    JsonVO<String> creatIssueCode();

    /**
     * 添加外协放料的信息
     * @param dto
     * @return
     */
    JsonVO<Boolean> addOutsourceIssue(OutsourceIssueDTO dto);

    /**
     * 根据id 批量删除 外协放料的信息
     * @param  ids
     * @return
     */
    JsonVO<Boolean> deleteOutsourceIssue(DelOutsourceIssueQuery ids);

    /**
     * 修改外协放料单的信息
     */
    JsonVO<Boolean> updateOutsourceIssue(OutsourceIssueDTO dto);

    /**
     * 执行放料
     * @return
     */
    JsonVO<Boolean> updateStateOutsourceIssue(Long issueId);
}
