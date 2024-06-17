package com.zeroone.star.productManagement.controller;

import com.zeroone.star.productManagement.entity.ExportMdItem;
import com.zeroone.star.productManagement.service.IMdItemService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.j6.product_management.MdItemApis;
import com.zeroone.star.project.j6.product_management.query.MdItemQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

@RestController
@Api(tags = "产品导入,导出")
@RequestMapping("md/product-management/items")
public class MdItemController implements MdItemApis {
    @Autowired
    EasyExcelComponent excel;
    @Autowired
    FastDfsClientComponent dfs;
    @Autowired
    IMdItemService iMdItemService;

    /**
     * 导出物料产品列表。
     *
     * @param mdItemQuery 查询参数
     * @return 包含 Excel 文件内容的 ResponseEntity 对象
     */
    @PostMapping(value = "/export", produces = "application/octet-stream")
    @ApiOperation(value = "导出物料产品列表")
    public ResponseEntity<byte[]> exportToExcel(MdItemQuery mdItemQuery) {
        List<ExportMdItem> items = iMdItemService.selectMdItemList(mdItemQuery);
        return iMdItemService.exportToExcel(items);
    }

    /**
     * 下载导入模板。
     *
     * @return 包含模板文件内容的 ResponseEntity 对象
     */
    @PostMapping(value = "/importTemplate", produces = "application/octet-stream")
    @ApiOperation(value = "下载模板")
    public ResponseEntity<byte[]> downloadTemplate() {
        return iMdItemService.downloadTemplate();
    }

    /**
     * 导入物料产品数据。
     *
     * @param file          包含物料产品数据的 Excel 文件
     * @param updateSupport 是否支持更新已存在的数据
     * @return 导入结果的 Json 对象
     */
    @ApiOperation("导入物料产品数据")
    @PostMapping("/importData")
    public JsonVO<String> importFromExcel(MultipartFile file, boolean updateSupport) {
        return iMdItemService.importFromExcel(file, updateSupport);
    }

}
