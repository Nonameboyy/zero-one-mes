package com.zeroone.star.project.j4.whsmanagement.wmoutSourceRcept;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptDTO;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.PathVariable;

import java.util.List;

/**
 * @Author: jingzi
 * @createTime: 2024-05-27
 * @description: 外协入库API接口
 */

public interface WmOutsourceRecptApis {


    /**
     * 外协入库列表查询(条件+分页)
     * @param query 查询条件
     * @return
     */
    JsonVO<PageDTO<WmOutsourceRecptDTO>> queryWmOutsourceRecpts(WmOutsourceRecptQuery query);


    /**
     * 外协入库详情查询
     * @param recptId 入库单ID
     * @return
     */
    JsonVO<WmOutsourceRecptDTO> queryWmOutsourceRecpt(Long recptId);


    /**
     * 新增外协入库
     * @param save 入库单信息
     * @return
     */
    JsonVO<Long> saveWmOutsourceRecpt(WmOutsourceRecptDTO save);


    /**
     * 删除外协入库
     * @param recptIds 入库单ID集合
     * @return
     */
    JsonVO<Long> removeWmOutsourceRecpt(List<Long> recptIds);


    /**
     * 修改外协入库
     * @param modify 入库单信息
     * @return
     */
    JsonVO<Boolean> modifyWmOutsourceRecpt(WmOutsourceRecptDTO modify);


    /**
     * 执行外协入库
     * @param recptId 入库单ID
     * @return
     */
    JsonVO execute(Long recptId);
}
