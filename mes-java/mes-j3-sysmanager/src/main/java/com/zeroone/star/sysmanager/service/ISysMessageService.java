package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j3.dto.PageDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.vo.NewsPageVO;
import com.zeroone.star.project.j3.vo.NewsVO;
import com.zeroone.star.project.j3.dto.SysAddMessageDTO;
import com.zeroone.star.project.j3.dto.SysUpdateMessageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.SysMessage;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 消息表 服务类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
public interface ISysMessageService extends IService<SysMessage> {

    /**
     * 获取消息详情
     * @param id
     * @return
     */
    NewsVO getNewsById(Long id);
    /**
     * 获取消息列表（分页+查询）
     * @param newsPageQuery
     * @return
     */
    PageDTO<NewsPageVO> queryNewsList(NewsPageQuery newsPageQuery);
    /**
     * 修改消息
     * @param sysUpdateMessageDTO 消息类
     * @return 状态码
     */
    JsonVO<String> updateMessageById(SysUpdateMessageDTO sysUpdateMessageDTO);

    /**
     * 添加消息
     * @param sysAddMessageDTO 消息类
     * @return 状态码
     */
    JsonVO<String> saveMessage(SysAddMessageDTO sysAddMessageDTO);

    /**
     * 批量删除消息
     * @param messageIdsList 消息id数组
     * @return 状态码
     */
    JsonVO<String> removeMessageByIds(List<Long> messageIdsList);

}
