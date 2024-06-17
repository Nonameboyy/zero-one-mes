package com.zeroone.star.project.j3.sysmanager;


import com.zeroone.star.project.j3.dto.*;
import com.zeroone.star.project.j3.query.NoticeQuery;
import com.zeroone.star.project.j3.vo.NoticeListVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

/**
 * 系统管理-通知公告相关接口
 */

public interface NoticeApis {

    /**
     * 修改通知公告
     *
     * @param noticeDTO
     * @return
     */
    JsonVO<ResultStatus> updateNotice(NoticeDTO noticeDTO);
    /**
     * 新增公告(notice)
     * @param dto 新增数据
     * @return 新增数据的唯一编号
     */

    JsonVO<Boolean> addNotice(AddNoticeDTO dto);


    /**
     *
     * @param id 查询对象ID
     * @return NoticeDTO
     */
    @PostMapping("/query-notice-by-id")
    @ApiOperation("查询公告详情")
    JsonVO<NoticeDTO> queryNoticeById(@RequestParam Integer id);

    /**
     * 根据给定的公告获取对应的公告数据列表
     * @param query 查询条件对象
     * @return 对应的公告数据列表
     */
    JsonVO<List<NoticeListVO>> queryNoticeListVosByCondition(NoticeQuery query);
    /**
     * 批量删除公告(notices)
     * @param ids 数据ID集合
     * @return 删除结果(ids)
     */
    JsonVO<List<Integer>> removeNotice(@RequestBody List<Integer> ids);
}
