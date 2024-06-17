package com.zeroone.star.productManagement.controller;

import com.zeroone.star.productManagement.service.IMdProductSipService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.SipApis;
import com.zeroone.star.project.j6.product_management.dto.SipDTO;
import com.zeroone.star.project.j6.product_management.query.SipQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.Min;

/**
 * <p>
 * 描述：产品Sip控制器
 * </p>
 *
 * @version 1.0.0
 */
@Api(tags = "产品Sip控制器")
@RestController
@RequestMapping("md/product-management/sip")
public class SipController implements SipApis {

    @Autowired
    IMdProductSipService iMdProductSipService;

    @Override
    @ApiOperation(value = "查询Sip列表")
    @GetMapping("/list")
    public JsonVO<PageDTO<SipDTO>> queryAll(@Validated SipQuery query) {
        return JsonVO.success(iMdProductSipService.selectProductSipPage(query));
    }

    @Override
    @ApiOperation(value = "查询Sip")
    @GetMapping("/{id}")
    public JsonVO<SipDTO> queryById(@PathVariable @Min(value = 1, message = "id最小值为1") Long id) {
        SipDTO dto = iMdProductSipService.selectProductSipPageByItemId(id);
        return JsonVO.success(dto);
    }

    @Override
    @ApiOperation(value = "新增Sip")
    @PostMapping("/index")
    public JsonVO<String> add(@RequestBody SipDTO dto) {
        if (iMdProductSipService.insertProductSip(dto)) {
            return JsonVO.success("添加成功");
        }
        return JsonVO.fail("添加失败");
    }

    @Override
    @ApiOperation(value = "修改Sip")
    @PutMapping("/update")
    public JsonVO<String> edit(@RequestBody SipDTO dto) {
        if (iMdProductSipService.updateProductSip(dto)) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    @Override
    @ApiOperation(value = "删除")
    @DeleteMapping("/{ids}")
    public JsonVO<String> remove(@PathVariable Long[] ids) {

        if (iMdProductSipService.deleteProductSipByIds(ids)) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }

    @ApiOperation(value = "上传图像")
    @PostMapping("/uploadFlied")
    public JsonVO<String> uploadFile(@RequestParam("file") MultipartFile file) {
        String sip_url = iMdProductSipService.uploadFile(file);
        if (sip_url != null) {
            SipDTO dto = new SipDTO();
            dto.setSipUrl(sip_url);
            return JsonVO.success(sip_url);
        } else {
            return JsonVO.fail("文件上传失败");
        }
    }
}

