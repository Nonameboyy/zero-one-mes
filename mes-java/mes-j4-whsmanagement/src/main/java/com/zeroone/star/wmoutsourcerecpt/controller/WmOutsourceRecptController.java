package com.zeroone.star.wmoutsourcerecpt.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptDTO;
import com.zeroone.star.project.j4.whsmanagement.wmoutSourceRcept.WmOutsourceRecptApis;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.wmoutsourcerecpt.constants.statusConstants;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecpt;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecptLine;
import com.zeroone.star.wmoutsourcerecpt.service.IWmOutsourceRecptLineService;
import com.zeroone.star.wmoutsourcerecpt.service.IWmOutsourceRecptService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.util.CollectionUtils;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 外协入库单表 前端控制器
 * </p>
 *
 * @author jingzi
 * @since 2024-05-27
 */
@RestController
@RequestMapping("wm-outsource-recpt")
@Api(tags = "外协入库单表")
public class WmOutsourceRecptController implements WmOutsourceRecptApis {

    @Resource
    private IWmOutsourceRecptService iWmOutsourceRecptService;

    @Resource
    private IWmOutsourceRecptLineService iWmOutsourceRecptLineService;


    /**
     * 查询外协入库单列表
     *
     * @param query 查询条件
     * @return
     */
    @Override
    @ApiOperation("外协入库单分页查询(分页+条件)")
    @GetMapping("query-list")
    public JsonVO<PageDTO<WmOutsourceRecptDTO>> queryWmOutsourceRecpts(WmOutsourceRecptQuery query) {
        if (query == null) throw new RuntimeException("查询条件不能为空");
        PageDTO<WmOutsourceRecpt> OutsourceRecpt = iWmOutsourceRecptService.listWmOutsourceRecpt(query);
        PageDTO<WmOutsourceRecptDTO> OutsourceRecptDTO = new PageDTO<>();
        BeanUtil.copyProperties(OutsourceRecpt, OutsourceRecptDTO);
        return JsonVO.success(OutsourceRecptDTO);
    }

    /**
     * 获取外协入库单详细信息
     *
     * @param recptId 外协入库id
     * @return
     */
    @Override
    @ApiOperation("查询外协入库单详情")
    @GetMapping("{recptId}")
    public JsonVO<WmOutsourceRecptDTO> queryWmOutsourceRecpt(@PathVariable("recptId") Long recptId) {
        if (recptId == null || recptId < 1) throw new RuntimeException("查询ID输入有误");
        WmOutsourceRecptDTO dto = new WmOutsourceRecptDTO();
        BeanUtil.copyProperties(iWmOutsourceRecptService.getWmOutsourceRecpt(recptId), dto);
        return JsonVO.success(dto);
    }

    /**
     * 新增外协入库单
     *
     * @param save 新增外协入库条件
     * @return
     */
    @Override
    @ApiOperation("新增外协入库单")
    @PostMapping("save")
    public JsonVO saveWmOutsourceRecpt(@RequestBody WmOutsourceRecptDTO save) {
        if (null != iWmOutsourceRecptService.getWmOutsourceRecpt(save.getRecptId()))
            return JsonVO.fail("该单据已存在,无需重复添加!");
        Long result = iWmOutsourceRecptService.saveWmOutsourceRecpt(save);
        if (result > 0) return JsonVO.success("添加成功!");
        else return JsonVO.fail("添加失败!");
    }

    /**
     * 删除外协入库单
     *
     * @param recptIds 外协入库id集合
     * @return
     */
    @Override
    @ApiOperation("删除外协入库单")
    @DeleteMapping("remove-recptIds")
    public JsonVO removeWmOutsourceRecpt(@RequestParam List<Long> recptIds) {
        Integer result = iWmOutsourceRecptService.removeWmOutsourceRecpt(recptIds);
        if (result > 0) return JsonVO.success("删除成功!");
        else return JsonVO.fail("删除失败!");
    }

    /**
     * 修改外协入库单
     *
     * @param modify 外协入库信息条件
     * @return
     */
    @Override
    @ApiOperation("修改外协入库单")
    @PutMapping("modify")
    public JsonVO modifyWmOutsourceRecpt(@RequestBody WmOutsourceRecptDTO modify) {
        Boolean result = iWmOutsourceRecptService.modifyWmOutsourceRecpt(modify);
        if (result) return JsonVO.success("修改成功!");
        else return JsonVO.fail("修改失败!");
    }

    /**
     * 执行外协入库
     *
     * @param recptId 入库单ID
     * @return
     */
    @Override
    @ApiOperation("执行外协入库")
    @PutMapping("{recptId}")
    public JsonVO execute(@PathVariable("recptId") Long recptId) {
        WmOutsourceRecpt recpt = iWmOutsourceRecptService.getWmOutsourceRecpt(recptId);
        List<WmOutsourceRecptLine> lines = iWmOutsourceRecptLineService.listWmOutsourceRecptLineByRecptId(recptId);
        if (CollectionUtils.isEmpty(lines)) {
            return JsonVO.fail("请指定入库的物资！");
        }
        /*
        //调用库存核心
        storageCoreService.processOutsourceRecpt(beans);

        //根据当前入库的物料更新对应的生产工单/生产任务 已生产数量
        ProWorkorder workorder = proWorkorderService.selectProWorkorderByWorkorderId(recpt.getWorkorderId());
        if(!StringUtils.isNotNull(workorder)){
            return JsonVO.fail("未找到对应的外协工单/外协任务！");
        }

        //正常外协入库的产品必须先经过检验，确认合格数量后才能执行入库，并且更新外协工单的进度。此处暂时先直接根据入库数量更新外协工单的生产数量。
        BigDecimal produced = workorder.getQuantityProduced() == null?new BigDecimal(0):workorder.getQuantityProduced();
        for (int i = 0; i < lines.size(); i++) {
            WmOutsourceRecptLine line = lines.get(i);
            //判断入库的物资，如果是生产工单中的产品，则更新已生产数量
            if(line.getItemCode().equals(workorder.getProductCode())){
                workorder.setQuantityProduced(produced.add(line.getQuantityRecived()));
            }
        }
        proWorkorderService.updateProWorkorder(workorder);
         */
        //更新单据状态
        recpt.setStatus(statusConstants.ORDER_STATUS_FINISHED);
        WmOutsourceRecptDTO recptDTO = new WmOutsourceRecptDTO();
        BeanUtil.copyProperties(recpt, recptDTO);
        if (iWmOutsourceRecptService.modifyWmOutsourceRecpt(recptDTO))
            return JsonVO.success("执行成功!");
        else return JsonVO.fail("执行失败!");
    }
}

