package com.zeroone.star.project.j4.whsmanagement.wmoutSourceRecptLine;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineDTO;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @Author: jingzi
 * @createTime: 2024-05-30
 * @description: 外协入库单行API接口
 */

public interface WmOutsourceRecptLineApis {

    /**
     * 外协入库行列表查询(分页+全查)
     * @return
     */
    JsonVO<PageDTO<WmOutsourceRecptLineDTO>> queryWmOutsourceRecptLines(WmOutsourceRecptLineQuery query);


    /**
     * 外协入库行详情查询
     * @param recptLineId 入库单ID
     * @return
     */
    JsonVO<WmOutsourceRecptLineDTO> queryWmOutsourceRecptLine(Long recptLineId);

    /**
     * 新增外协入库单行
     * @param save 入库单信息
     * @return
     */
    JsonVO<Long> saveWmOutsourceRecptLine(WmOutsourceRecptLineDTO save);

    /**
     * 删除外协入库
     * @param recptLineIds 入库单ID集合
     * @return
     */
    JsonVO<Long> removeWmOutsourceRecptLines(List<Long> recptLineIds);


    /**
     * 修改外协入库单行
     * @param modify 入库单信息
     * @return
     */
    JsonVO<Boolean> modifyWmOutsourceRecptLine(WmOutsourceRecptLineDTO modify);
}
