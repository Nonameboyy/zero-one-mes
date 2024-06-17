package com.zeroone.star.project.j4.warehousemanagement;

import com.zeroone.star.project.dto.j4.warehousemanagement.outsource.OutsourceIssueDTO;
import com.zeroone.star.project.query.j4.warehousemanagement.outsource.OutsourceIssueLineQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.warehousemanagement.outsource.OutsourceIssueLineVO;


/**
 * @Description 外协领料单行表
 * @Author diwu
 * @Date 2024/5/30
 */
public interface OutsourceLineAPI {
    /**
     * 根据外协领料表ID进行 分页查询
     * @param query
     * @return
     */
    JsonVO<OutsourceIssueLineVO> queryByIssueId(OutsourceIssueLineQuery query);

    /**
     * 修改外协领料单行表
     * @param dto
     * @return
     */
    JsonVO<Boolean> updateOutsourceIssueLine(OutsourceIssueDTO dto);

    /**
     * 添加外协放料单行表的信息
     * @param dto
     * @return
     */
    JsonVO<Boolean> addOutsourceIssueLine(OutsourceIssueDTO dto);

    /**
     * 根据单行表 ID 来删除
     * @param lineId
     * @return
     */
    JsonVO<Boolean> delOutsourceIssueLine(Integer lineId);

}
