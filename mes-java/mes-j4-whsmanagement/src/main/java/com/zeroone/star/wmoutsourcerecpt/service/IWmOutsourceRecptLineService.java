package com.zeroone.star.wmoutsourcerecpt.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineDTO;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineQuery;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecptLine;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 外协入库单行表 服务类
 * </p>
 *
 * @author jingzi
 * @since 2024-05-29
 */
public interface IWmOutsourceRecptLineService extends IService<WmOutsourceRecptLine> {

    /**
     * 列表查询
     *
     * @param query 查询条件
     * @return
     */
    PageDTO<WmOutsourceRecptLine> listWmOutsourceRecptLine(WmOutsourceRecptLineQuery query);

    /**
     * 根据id查询
     *
     * @param recptLineId 查询id
     * @return
     */
    WmOutsourceRecptLine getWmOutsourceRecptLine(Long recptLineId);

    /**
     * 根据外协入库单ID查询所有入库单行
     * @param recptId
     * @return
     */
    List<WmOutsourceRecptLine> listWmOutsourceRecptLineByRecptId(Long recptId);

    /**
     * 新增外协入库行
     *
     * @param save 新增条件
     * @return
     */
    Long saveWmOutsourceRecptLine(WmOutsourceRecptLineDTO save);

    /**
     * 删除外协入库行
     *
     * @param recptLineIds id集合
     * @return
     */
    Integer removeWmOutsourceRecptLine(List<Long> recptLineIds);

    /**
     * 修改外协入库行
     *
     * @param modify 修改条件
     * @return
     */
    Boolean modifyWmOutsourceRecptLine(WmOutsourceRecptLineDTO modify);

}
