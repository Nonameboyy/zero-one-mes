package com.zeroone.star.warehousemanagement.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalse.RtSalsesDTO;
import com.zeroone.star.project.j4.warehousemanagement.RtSalse.RtSalseApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.warehousemanagement.constant.Constants;
import com.zeroone.star.warehousemanagement.constant.orderConstant;
import com.zeroone.star.warehousemanagement.entity.WmRtSalse;
import com.zeroone.star.warehousemanagement.entity.WmRtSalseLine;
import com.zeroone.star.warehousemanagement.service.IWmRtSalseLineService;
import com.zeroone.star.warehousemanagement.service.IWmRtSalseService;
import com.zeroone.star.warehousemanagement.utils.StringUtils;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.CollectionUtils;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 产品销售退货单表 前端控制器
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@RestController
@RequestMapping("/wm-rt-salse")
@Api(tags = "产品销售退货单相关接口")
public class WmRtSalseController implements RtSalseApis{

    @Resource
    private IWmRtSalseService wmRtSalseService;
    @Resource
    private IWmRtSalseLineService wmRtSalseLineService;

    /**
     * 查询产品销售退货单列表
     */
    @GetMapping("/page")
    @ApiOperation("查询销售退货单列表接口")
    public JsonVO<Page> page(int page, int pageSize) {
        //分页构造器
        Page<WmRtSalse> pageInfo = new Page<>(page,pageSize);
        LambdaQueryWrapper<WmRtSalse> lqw = new LambdaQueryWrapper<>();
        lqw.orderByAsc(WmRtSalse::getRtId);
        wmRtSalseService.page(pageInfo, lqw);
        return JsonVO.success(pageInfo);
    }

    /**
     * 获取产品销售退货单详细信息
     */
    @ApiOperation("获取销售退货单详细信息接口")
    @GetMapping(value = "/{rtId}")
    public JsonVO<RtSalsesDTO> getInfo(@PathVariable("rtId") Long rtId)
    {
        WmRtSalse wmRtSalse = wmRtSalseService.selectWmRtSalseByRtId(rtId);
        RtSalsesDTO rtSalsesDTO = new RtSalsesDTO();
        BeanUtils.copyProperties(wmRtSalse,rtSalsesDTO);
        return JsonVO.success(rtSalsesDTO);
    }

    /**
     * 新增产品销售退货单
     */
    @ApiOperation("新增销售退货单基本信息接口")
    @PostMapping
    public JsonVO add(@RequestBody RtSalsesDTO rtSalsesDTO)
    {
        if(StringUtils.isNotNull(rtSalsesDTO.getRtCode())){
            if(Constants.NOT_UNIQUE.equals(wmRtSalseService.checkUnique(rtSalsesDTO))){
                return JsonVO.fail("退货单号已存在!");
            }
        }
        if (wmRtSalseService.insertWmRtSalse(rtSalsesDTO)==0) {
            return JsonVO.fail("添加失败!");
        }
        return JsonVO.success("添加成功!");
    }

    /**
     * 修改产品销售退货单
     */
    @ApiOperation("编辑销售退货单基本信息接口")
    @PutMapping
    public JsonVO update(@RequestBody RtSalsesDTO rtSalsesDTO)
    {
        if(Constants.NOT_UNIQUE.equals(wmRtSalseService.checkUnique(rtSalsesDTO))){
            return JsonVO.fail("退货单号已存在!");
        }

        //这里省去了3个判断warehouse,location,area的id如果不为空，需要从warehouse,location,area中查找code和name赋值给这里的RtSalsesDTO

        if (wmRtSalseService.updateWmRtSalse(rtSalsesDTO)==0) {
            return JsonVO.fail("修改失败!");
        }
        return JsonVO.success("修改成功！");
    }

    /**
     * 删除产品销售退货单
     */
    @ApiOperation("删除销售退货单基本信息接口")
    @DeleteMapping
    public JsonVO remove(@RequestParam List<Long> rtIds) {
        String result = wmRtSalseService.removes(rtIds);
        if(result!=null){
            return JsonVO.fail(result);
        }
        return JsonVO.success("删除成功！");
    }

    /**
     * 执行退货
     * @param rtId
     * @return
     */
    @ApiOperation("执行销售退货接口")
    @PutMapping("/{rtId}")
    public JsonVO execute(@PathVariable Long rtId){
        WmRtSalse rtSalse = wmRtSalseService.selectWmRtSalseByRtId(rtId);
        WmRtSalseLine param = new WmRtSalseLine();
        param.setRtId(rtId);
        List<WmRtSalseLine> lines = wmRtSalseLineService.selectWmRtSalseLineList(param);
        if(CollectionUtils.isEmpty(lines)){
            return JsonVO.fail("请添加退货单行信息！");
        }

        //这里省去了销售退货的逻辑（待完善）

        rtSalse.setStatus(orderConstant.ORDER_STATUS_FINISHED);
        RtSalsesDTO rtSalsesDTO = new RtSalsesDTO();
        BeanUtils.copyProperties(rtSalse,rtSalsesDTO);
        if (wmRtSalseService.updateWmRtSalse(rtSalsesDTO)==0) {
            return JsonVO.fail("退货失败，状态修改失败!");
        }
        return JsonVO.success("退货成功");
    }
}
