package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j3.dto.AddNoticeDTO;
import com.zeroone.star.project.j3.dto.NoticeDTO;
import com.zeroone.star.sysmanager.entity.SysNotice;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 通知公告表 服务类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
public interface ISysNoticeService extends IService<SysNotice> {
    /**
     * 修改通知公告
     *
     * @param noticeDTO
     * @return
     */
    void updateNotice(NoticeDTO noticeDTO);

    /**
     *
     * @param dto 新增的数据
     * @return
     */
    boolean addNotice(AddNoticeDTO dto);

    /**
     *
     * @param id 查询对象ID
     * @return
     */
    NoticeDTO queryNoticeById(Integer id);

    /**
     *
     * @param ids 删除的公告ID集合
     * @return
     */
    void removeNoticeByIds(List<Integer> ids);
}
