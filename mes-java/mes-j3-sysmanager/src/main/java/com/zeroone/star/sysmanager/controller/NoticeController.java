package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j3.dto.*;
import com.zeroone.star.project.j3.query.NoticeQuery;
import com.zeroone.star.project.j3.sysmanager.NoticeApis;
import com.zeroone.star.project.j3.vo.NoticeListVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanager.service.ISysNoticeService;
import io.swagger.annotations.Api;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.transaction.interceptor.TransactionAspectSupport;
import org.springframework.web.bind.annotation.*;
import io.swagger.annotations.ApiOperation;

import javax.annotation.Resource;
import java.util.List;

@Api(tags = "通知公告")
@Controller
@RequestMapping("sys-manager/notice")
public class NoticeController implements NoticeApis {
    @Resource
    private ISysNoticeService noticeService;
    /**
     * 修改通知公告
     *
     * @param noticeDTO
     * @return
     */
    @PutMapping("/update")
    @ApiOperation(value = "修改通知公告")
    public JsonVO<ResultStatus> updateNotice(@RequestBody NoticeDTO noticeDTO) {
        noticeService.updateNotice(noticeDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }
    /**
     * 添加公告
     * @param dto 新增的数据
     * @return
     */
    @Override
    @PostMapping("/add-notice")
    @ApiOperation("添加公告")
    public JsonVO<Boolean> addNotice(@RequestBody AddNoticeDTO dto) {
        boolean saved = noticeService.addNotice(dto);
        if (!saved){
            return JsonVO.create(false, HttpStatus.BAD_REQUEST.value(),"添加公告失败！");
        }
        return JsonVO.create(true,200,"添加公告成功！");
    }


    /**
     * 查询公告详情
     * @param id 查询对象ID
     * @return
     */
    @Override
    @PostMapping("/query-notice-by-id")
    @ApiOperation("查询公告详情")
    public JsonVO<NoticeDTO> queryNoticeById(@RequestParam Integer id) {
        NoticeDTO noticeDTO = noticeService.queryNoticeById(id);
        if (null == noticeDTO){
            return JsonVO.create(null,HttpStatus.BAD_REQUEST.value(),"查询失败！");
        }
        return JsonVO.create(noticeDTO,200,"查询成功！");

    }


    @Override
    @PostMapping("/query-noticeListVos-by-condition")
    @ApiOperation("查询公告")
    public JsonVO<List<NoticeListVO>> queryNoticeListVosByCondition(NoticeQuery query) {
        return null;
    }

    /**
     * 删除公告
     * @param ids 数据ID集合
     * @return
     */
    @DeleteMapping("/remove-notice")
    @ApiOperation("删除公告")
    public JsonVO<List<Integer>> removeNotice(@RequestBody List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            // 返回错误信息
            return JsonVO.create(null, HttpStatus.BAD_REQUEST.value(), "数据为空！");
        }
        try {
            // 调用服务层方法，该方法会抛出异常如果删除失败
            noticeService.removeNoticeByIds(ids);
            // 删除成功
            return JsonVO.create(ids, HttpStatus.OK.value(), "删除成功！");
        } catch (RuntimeException e) {
            // 捕获服务层抛出的异常，并返回相应的错误信息
            return JsonVO.create(ids, HttpStatus.NOT_FOUND.value(), e.getMessage());
        }
    }



}
