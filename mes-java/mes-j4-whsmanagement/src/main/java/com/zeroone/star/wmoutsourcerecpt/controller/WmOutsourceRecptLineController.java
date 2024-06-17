package com.zeroone.star.wmoutsourcerecpt.controller;


import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecpt.WmOutsourceRecptDTO;
import com.zeroone.star.project.dto.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineDTO;
import com.zeroone.star.project.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineApis;
import com.zeroone.star.project.query.j4.whsmanagement.wmoutSourceRecptLine.WmOutsourceRecptLineQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecpt;
import com.zeroone.star.wmoutsourcerecpt.entity.WmOutsourceRecptLine;
import com.zeroone.star.wmoutsourcerecpt.service.IWmOutsourceRecptLineService;
import com.zeroone.star.wmoutsourcerecpt.service.IWmOutsourceRecptService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 外协入库单行表 前端控制器
 * </p>
 *
 * @author jingzi
 * @since 2024-05-29
 */
@RestController
@RequestMapping("wm-outsource-recpt-line")
@Api(tags = "外协入库单行表")
public class WmOutsourceRecptLineController implements WmOutsourceRecptLineApis {

    @Resource
    private IWmOutsourceRecptLineService iWmOutsourceRecptLineService;

    @Resource
    private IWmOutsourceRecptService iWmOutsourceRecptService;


    /**
     * 查询外协入库行列表
     *
     * @return 查询返回结果Json对象
     */
    @Override
    @ApiOperation("外协入库单行分页查询(分页+全查)")
    @GetMapping("query-list")
    public JsonVO<PageDTO<WmOutsourceRecptLineDTO>> queryWmOutsourceRecptLines(WmOutsourceRecptLineQuery query) {
        PageDTO<WmOutsourceRecptLine> OutsourceRecptLine = iWmOutsourceRecptLineService.listWmOutsourceRecptLine(query);
        PageDTO<WmOutsourceRecptLineDTO> OutsourceRecptLineDTO = new PageDTO<>();
        BeanUtil.copyProperties(OutsourceRecptLine, OutsourceRecptLineDTO);
        return JsonVO.success(OutsourceRecptLineDTO);
    }


    /**
     * 获取外协入库单详细信息
     *
     * @param recptLineId 外协入库行id
     * @return 查询返回结果Json对象
     */
    @Override
    @ApiOperation("查询外协入库单行详情")
    @GetMapping("{recptLineId}")
    public JsonVO<WmOutsourceRecptLineDTO> queryWmOutsourceRecptLine(@PathVariable("recptLineId") Long recptLineId) {
        if (recptLineId == null || recptLineId < 1) throw new RuntimeException("查询id输入有误");
        WmOutsourceRecptLineDTO dto = new WmOutsourceRecptLineDTO();
        BeanUtil.copyProperties(iWmOutsourceRecptLineService.getWmOutsourceRecptLine(recptLineId), dto);
        return JsonVO.success(dto);
    }


    /**
     * 新增外协入库单行
     *
     * @param save 新增外协入库单行条件
     * @return 返回Json信息
     */
    @Override
    @ApiOperation("新增外协入库单行")
    @PostMapping("save")
    public JsonVO saveWmOutsourceRecptLine(@RequestBody WmOutsourceRecptLineDTO save) {
        if(null==iWmOutsourceRecptService.getWmOutsourceRecpt(save.getLineId()))
            return JsonVO.fail("请先添加外协入库单!");
        if (null!=iWmOutsourceRecptLineService.getWmOutsourceRecptLine(save.getLineId()))
            return JsonVO.fail("该单据已存在,无需重复添加!");
        Long result = iWmOutsourceRecptLineService.saveWmOutsourceRecptLine(save);
        if (result > 0) return JsonVO.success("添加成功!");
        else return JsonVO.fail("添加失败!");
    }

    /**
     * 删除外协入库单行
     *
     * @param recptLineIds 外协入库行id集合
     * @return
     */
    @Override
    @ApiOperation("删除外协入库单行")
    @DeleteMapping("remove-recptLineIds")
    public JsonVO removeWmOutsourceRecptLines(@RequestParam List<Long> recptLineIds) {
        Integer result = iWmOutsourceRecptLineService.removeWmOutsourceRecptLine(recptLineIds);
        if (result > 0) return JsonVO.success("删除成功!");
        else return JsonVO.fail("删除失败!");
    }

    /**
     * 修改外协入库单行
     *
     * @param modify 外协入库行信息条件
     * @return
     */
    @Override
    @ApiOperation("修改外协入库单行")
    @PutMapping("modify")
    public JsonVO modifyWmOutsourceRecptLine(@RequestBody WmOutsourceRecptLineDTO modify) {
        Boolean result = iWmOutsourceRecptLineService.modifyWmOutsourceRecptLine(modify);
        if (result) return JsonVO.success("修改成功!");
        else return JsonVO.fail("修改失败!");
    }
}

