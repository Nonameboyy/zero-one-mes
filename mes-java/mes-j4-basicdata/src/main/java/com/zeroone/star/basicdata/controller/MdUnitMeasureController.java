package com.zeroone.star.basicdata.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.basicdata.entity.MdUnitMeasure;
import com.zeroone.star.basicdata.service.IMdUnitMeasureService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitMeasureDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitUpdateDTO;
import com.zeroone.star.project.j4.basicdata.AccountUnitApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.context.annotation.EnableAspectJAutoProxy;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.Collections;
import java.util.List;

/**
 * <p>
 * 单位表 前端控制器
 * </p>
 *
 * @author zjx
 * @since 2024-05-20
 */
@RestController
@RequestMapping("/basicdata/md-unit-measure")
@Api(tags = "单位相关操作")
@Validated
@Slf4j
@EnableAspectJAutoProxy
public class MdUnitMeasureController implements AccountUnitApis{
    @Resource
    private IMdUnitMeasureService iMdUnitMeasureService;

    /*
     * 删除单位
     * */
    @ApiOperation(value = "删除单位")
    @DeleteMapping("/delete-by-measureIds")
    public JsonVO<String> deleteUnitMeasure(@RequestParam List<Long> measureIds) {
        Long isRemoved = iMdUnitMeasureService.deleteByIds(measureIds);
        if (isRemoved == 0) {
            return JsonVO.fail("删除失败");
        }
        return JsonVO.success("删除成功");
    }

    /*
     * 导出单位
     * */
    @ApiOperation(value = "导出单位")
    @GetMapping(value = "/download-unitMeasure", produces = "application/octet-stream")
    public ResponseEntity<byte[]> exportUnitMeasure(UnitExcelSelectDTO unitExcelSelectDTO) {
        ResponseEntity<byte[]> responseEntity = iMdUnitMeasureService.exportUnitMeasure(unitExcelSelectDTO);
        return responseEntity;
    }


    /**
     * 根据单位ID获取单位信息
     * @param measureId
     * @return
     */
    @ApiOperation(value = "根据单位ID获取单位信息")
    @GetMapping(value = "{measureId}")
    public JsonVO<MdUnitMeasure> getInfo(@PathVariable("measureId") Long measureId) {
        MdUnitMeasure mdUnitMeasure = iMdUnitMeasureService.getById(measureId);
        return JsonVO.success(mdUnitMeasure);
    }

    /**
     * 查询单位分页列表
     * @param unitMeasureDTO 单位测量模型，用于传递查询条件,如果为空，返回所有数据
     * @param pageIndex 请求的页码，默认开始为1
     * @param pageSize 每页显示的数量，默认最大为10
     * @return 返回单位列表的信息，包括分页信息
     */
    @GetMapping("/list")
    @ApiOperation("查询单位分页列表")
    public JsonVO<PageDTO<UnitMeasureDTO>> list(@Validated UnitMeasureDTO unitMeasureDTO,
                                                @RequestParam(defaultValue = "1") int pageIndex,
                                                @RequestParam(defaultValue = "10") int pageSize) {

        // 根据查询条件查询单位列表
        List<UnitMeasureDTO> allList = iMdUnitMeasureService.selectMdUnitMeasureList(unitMeasureDTO);

        // 计算总记录数
        int total = allList.size();

        // 计算当前页应该显示的记录的起始和终止的索引
        int fromIndex = (pageIndex - 1) * pageSize;
        int toIndex = Math.min(fromIndex + pageSize, total);

        // 如果起始索引大于总记录数，返回空列表
        if (fromIndex >= total) {
            List<UnitMeasureDTO> emptyList = Collections.emptyList();
            Page<UnitMeasureDTO> emptyPage = new Page<>(pageIndex, pageSize, 0);
            emptyPage.setRecords(emptyList);
            return JsonVO.success(PageDTO.create(emptyPage));
        }

        // 获取当前页的数据
        List<UnitMeasureDTO> pageList = allList.subList(fromIndex, toIndex);

        // 初始化并设置分页信息
        Page<UnitMeasureDTO> page = new Page<>(pageIndex, pageSize, total);
        page.setRecords(pageList);

        // 将Page对象转换为前端可接收的PageDTO对象
        PageDTO<UnitMeasureDTO> pageDTO = PageDTO.create(page);

        return JsonVO.success(pageDTO);
    }

    /**
     * 添加单位
     * @param unitAddDTO 添加单位DTO
     * @return
     */
    @PostMapping("/add")
    @ApiOperation("添加单位")
    public JsonVO addUnitMeasure(@Validated UnitAddDTO unitAddDTO) {
        iMdUnitMeasureService.addUnitMeasure(unitAddDTO);
        return JsonVO.success("添加成功");
    }

    /**
     * 修改单位
     * 注意：修改单位时，需要传入主单位ID，如果主单位ID为空，则修改为非主单位
     * @param unitUpdateDTO 更新单位DTO
     * @return
     */
    @PostMapping("/modify")
    @ApiOperation("修改单位")
    public JsonVO modifyUnitMeasure(@Validated UnitUpdateDTO unitUpdateDTO){
        iMdUnitMeasureService.modifyUnitMeasure(unitUpdateDTO);
        return JsonVO.success("修改成功");
    }

}
