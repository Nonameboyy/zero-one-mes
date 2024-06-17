package com.zeroone.star.project.j4.basicdata;

import com.zeroone.star.project.dto.j4.basicdata.VendorAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorModifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

/**
 * 供应商接口API定义
 *
 * @author ：酌
 * @version 1.0
 */
public interface SupplierApis {
    /**
     * 导出供应商
     *
     * @param vendorExcelSelectDTO 导出供应商excel报表查询条件参数
     * @return
     * @author :本鼠
     */
    ResponseEntity<byte[]> exportVendor(VendorExcelSelectDTO vendorExcelSelectDTO);

    /**
     * 下载供应商导入模板
     * @return 导入模板
     */
    ResponseEntity<byte[]> downloadImportTemplate();

    /**
     * 导入供应商
     * @param file
     * @return 是否导入成功
     */
    JsonVO<Boolean> importVendors(MultipartFile file);

    /**
     * 添加供应商
     *
     * @param data 供应商数据
     * @return 添加供应商结果
     */
    JsonVO addVendor(VendorAddDTO data);

    /**
     * 修改供应商
     *
     * @param data 供应商数据
     * @return 修改供应商结果
     */
    JsonVO updateVendor(VendorModifyDTO data);
}
