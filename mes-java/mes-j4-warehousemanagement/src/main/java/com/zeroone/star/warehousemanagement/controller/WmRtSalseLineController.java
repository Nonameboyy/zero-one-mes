package com.zeroone.star.warehousemanagement.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalseLine.RtSalseLineDTO;
import com.zeroone.star.project.j4.warehousemanagement.RtSalseLine.RtSalseLineApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.warehousemanagement.entity.WmRtSalseLine;
import com.zeroone.star.warehousemanagement.service.IWmRtSalseLineService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.BeanUtils;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;


/**
 * <p>
 * 产品销售退货行表 前端控制器
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-29
 */
@RestController
@RequestMapping("/wm-rt-salse-line")
@Api(tags = "产品销售退货行相关操作")
public class WmRtSalseLineController implements RtSalseLineApis {

    @Resource
    private IWmRtSalseLineService wmRtSalseLineService;

    /**
     * 查询产品销售退货行列表
     */
    @Override
    @GetMapping("/page")
    @ApiOperation("查询产品销售退货行列表")
    public JsonVO<Page> page(int page, int pageSize) {
        Page<WmRtSalseLine> pageInfo = new Page<>(page,pageSize);
        LambdaQueryWrapper<WmRtSalseLine> lqw = new LambdaQueryWrapper<>();
        lqw.orderByAsc(WmRtSalseLine::getRtId);
        wmRtSalseLineService.page(pageInfo, lqw);
        return JsonVO.success(pageInfo);
    }
    /**
     * 获取产品销售退货行详细信息
     */
    @Override
    @ApiOperation("获取产品销售退货行详细信息")
    @GetMapping(value = "/{lineId}")
    public JsonVO<RtSalseLineDTO> getInfo(@PathVariable("lineId") Long lineId) {
        WmRtSalseLine wmRtSalseLine = wmRtSalseLineService.selectWmRtSalseLineByLineId(lineId);
        RtSalseLineDTO rtSalseLineDTO = new RtSalseLineDTO();
        BeanUtils.copyProperties(wmRtSalseLine,rtSalseLineDTO);
        return JsonVO.success(rtSalseLineDTO);
    }

    /**
     * 新增产品销售退货行
     */
    @Override
    @ApiOperation("新增销售退货单明细接口")
    @PostMapping
    public JsonVO add(@RequestBody RtSalseLineDTO rtSalseLineDTO) {
        if (wmRtSalseLineService.insertWmRtSalseLine(rtSalseLineDTO)==0) {
            return JsonVO.fail("销售退货行添加失败！");
        }
        return JsonVO.success("添加成功！");
    }

    /**
     * 修改产品销售退货行
     */
    @Override
    @ApiOperation("编辑销售退货单明细接口")
    @PutMapping
    public JsonVO update(@RequestBody RtSalseLineDTO rtSalseLineDTO) {
        if (wmRtSalseLineService.updateWmRtSalseLine(rtSalseLineDTO)==0) {
            return JsonVO.fail("销售退货行修改失败！");
        }
        return JsonVO.success("修改成功!");
    }

    /**
     * 删除产品销售退货行
     */
    @Override
    @ApiOperation("删除销售退货单明细接口")
    @DeleteMapping("/{lineIds}")
    public JsonVO remove(@PathVariable Long[] lineIds) {
        if (wmRtSalseLineService.deleteWmRtSalseLineByLineIds(lineIds)==0) {
            return JsonVO.fail("销售退货行删除失败！");
        }
        return JsonVO.success("销售退货行删除成功！");
    }

}
