package com.zeroone.star.sysmanagement.controller;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.logmanagement.SysLoginInfoDTO;
import com.zeroone.star.project.query.j4.logmanagement.SysLoginInfoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanagement.service.SysLoginInfoService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;


/**
 * @Description 登录日志信息管理
 * @Author diwu
 * @Date 2024/5/19
 */
@RestController
@Api(tags = "监测数据-登录日志管理")
@RequestMapping("/monitor/logininfo")
public class SysLoginInfoController {


    @Resource
    private SysLoginInfoService sysLoginInfoService;

    @ApiOperation("日志分页查询" )
    @GetMapping("query-list")
    public JsonVO<PageDTO<SysLoginInfoDTO>> querySysLoginInfos( SysLoginInfoQuery query) {

        return JsonVO.success(sysLoginInfoService.listAll(query));
    }

    @ApiOperation("添加登录日志")
    @PostMapping("add-logininfo")
    public JsonVO<Boolean> addSysLoginInfo(@RequestBody  SysLoginInfoDTO dto) {
        boolean result = sysLoginInfoService.add(dto);
        if (result) {
            return JsonVO.create(true, ResultStatus.SUCCESS.getCode(),"添加成功");
        } else {
            return JsonVO.create(false,ResultStatus.FAIL.getCode(),"添加失败");
        }
    }
}
