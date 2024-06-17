package com.zeroone.star.project.j3.sysmanager;

import com.zeroone.star.project.j3.dto.PageDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.vo.NewsPageVO;
import com.zeroone.star.project.j3.vo.NewsVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.j3.dto.ExportConditionMessageDTO;
import com.zeroone.star.project.j3.dto.SysAddMessageDTO;
import com.zeroone.star.project.j3.dto.SysUpdateMessageDTO;
import org.springframework.http.ResponseEntity;

/**
 * 系统管理-消息管理相关接口
 */

public interface MessageManageApis {

    /**
     * 根据id查询消息详情
     *
     * @return 消息详情
     */
    JsonVO<NewsVO> getNewsById(Long id);

    /**
     * 分页查询消息列表
     *
     * @return 消息列表
     */
    JsonVO<PageDTO<NewsPageVO>> queryNewsList(NewsPageQuery newsPageQuery);


    /**
     * 增加消息
     * @param sysAddMessageDTO 消息实体
     * @return 响应码
     */
    public JsonVO<String> addMessage(SysAddMessageDTO sysAddMessageDTO);

    /**
     * 修改消息
     *
     * @param sysUpdateMessageDTO 修改消息DTO
     * @return 结果
     */
    public JsonVO<String> modifyMessage(SysUpdateMessageDTO sysUpdateMessageDTO);

    /**
     * 批量删除消息
     *
     * @param messageIds 需要删除的消息主键集合
     * @return 结果
     */
    public JsonVO<String> removeMessageByMessageIds(String messageIds);

    /**
     * 下载导出全部Excel
     * @return 报表
     */
    public ResponseEntity<byte[]> downloadMessageExcelALL();


    /**
     * 所有数据导出到dfs
     * @return dfs连接
     */
    public JsonVO<String> exportMessageToDfsALL();


    /**
     * 根据指定信息筛选导出对应Excel
     * @return 报表
     */
    public ResponseEntity<byte[]> downloadMessageExcel(ExportConditionMessageDTO exportConditionMessageDTO);


    /**
     * 根据指定信息筛选数据导出到dfs
     * @return dfs连接
     */
    public JsonVO<String> exportMessageToDfs(ExportConditionMessageDTO exportConditionMessageDTO);
}
