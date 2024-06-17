package com.zeroone.star.wmoutsourcerecpt.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.OutsourceRecptTxBean;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptDTO;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptQuery;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecpt;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 外协入库单表 服务类
 * </p>
 *
 * @author jingzi
 * @since 2024-05-27
 */
public interface IWmOutsourceRecptService extends IService<WmOutsourceRecpt> {


    /**
     * 列表查询
     * @param query 查询条件
     * @return
     */
    PageDTO<WmOutsourceRecpt> listWmOutsourceRecpt(WmOutsourceRecptQuery query);


    /**
     * 根据id查询
     * @param recptId 查询id
     * @return
     */
    WmOutsourceRecpt getWmOutsourceRecpt(Long recptId);

    /**
     * 新增外协入库单
     * @param save 新增条件
     * @return
     */
    Long saveWmOutsourceRecpt(WmOutsourceRecptDTO save);


    /**
     * 删除外协入库单
     * @param recptIds 删除id集合
     * @return
     */
    Integer removeWmOutsourceRecpt(List<Long> recptIds);

    /**
     * 修改外协入库单
     * @param modify 修改条件
     * @return
     */
    Boolean modifyWmOutsourceRecpt(WmOutsourceRecptDTO modify);


    /**
     * 构造Transaction事务
     * @param recptId
     * @return
     */
    List<OutsourceRecptTxBean> getTxBeans(Long recptId);


}
