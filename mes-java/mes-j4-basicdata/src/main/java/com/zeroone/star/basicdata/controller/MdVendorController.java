package com.zeroone.star.basicdata.controller;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.basicdata.entity.MdVendor;
import com.zeroone.star.basicdata.service.IMdVendorService;
import com.zeroone.star.project.dto.j4.basicdata.VendorAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorModifyDTO;
import com.zeroone.star.project.j4.basicdata.SupplierApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 供应商相关操作 前端控制器
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-21
 */

@RestController
@Api(tags = "供应商相关操作")
@RequestMapping("/basicdata/md-vendor")
@Validated
@Slf4j
public class MdVendorController {

    @Resource
    private IMdVendorService iMdVendorService;
    /*
     * 导出供应商
     * */
    @ApiOperation(value = "导出供应商")
    @GetMapping(value = "download-vendor", produces = "application/octet-stream")
    public ResponseEntity<byte[]> exportVendor(VendorExcelSelectDTO vendorExcelSelectDTO) {
        ResponseEntity<byte[]> responseEntity = iMdVendorService.exportVendor(vendorExcelSelectDTO);
        return responseEntity;
    }

    @ApiOperation(value = "添加供应商")
    @PostMapping("add-vendor")
    public JsonVO addVendor(@RequestBody VendorAddDTO data)
    {
        if (iMdVendorService.addVendor(data)) return JsonVO.success("添加成功");
        else return JsonVO.fail("添加失败");
    }

    @ApiOperation(value = "修改供应商信息")
    @PostMapping("update-vendor")
    public JsonVO updateVendor(VendorModifyDTO data) {
        if (iMdVendorService.updateVendor(data)) return JsonVO.success("修改成功");
        else return JsonVO.fail("修改失败");
    }


    /**
     * 供应商分页查询
     * */
    @GetMapping("/page")
    @ApiOperation("分类分页查询")
    public JsonVO<Page> page(int page, int pageSize) {

        //分页构造器
        Page<MdVendor> pageInfo = new Page<>(page,pageSize);
        LambdaQueryWrapper<MdVendor> lqw = new LambdaQueryWrapper<>();
        lqw.orderByAsc(MdVendor::getVendorId);
        iMdVendorService.page(pageInfo, lqw);
        log.debug("供应商分页查询成功");
        return JsonVO.success(pageInfo);
    }

    /**
     * 查询供应商详情
     * */
    @GetMapping("/{VendorId}")
    @ApiOperation("查询供应商详情")
    public JsonVO<MdVendor> get(@PathVariable Long VendorId){
        return JsonVO.success(iMdVendorService.getByVendorId(VendorId));
    }

    @DeleteMapping
    @ApiOperation("批量删除供应商")
    public JsonVO delete(@RequestParam List<Integer> ids){
        iMdVendorService.deleteVendors(ids);
        return JsonVO.success("操作成功");
    }

    @GetMapping(value = "/downloadImportTemplate",produces = "application/octet-stream")
    @ApiOperation(value = "下载供应商导入模板",produces = "application/octet-stream")
    public ResponseEntity<byte[]> downloadImportTemplate() {
        ResponseEntity<byte[]> responseEntity = iMdVendorService.downloadImportTemplate();
        return responseEntity;
    }

    @PostMapping("/importVendors")
    @ApiOperation("导入供应商")
    public JsonVO<Boolean> importVendors(@RequestParam("file") MultipartFile file) {
        // 检查文件是否为空
        if (file.isEmpty()) {
            // 文件为空，返回错误页面或提示信息
            throw new RuntimeException("文件为空");
        }

        try {
            // 调用服务进行Excel数据解析和处理
             iMdVendorService.importVendors(file);
            // 解析成功，重定向到成功页面
            return JsonVO.success(true);
        } catch (Exception e) {
            // 解析失败，返回错误页面或提示信息
            throw new RuntimeException("解析失败");
        }
    }
}
