package com.zeroone.star.basicdata.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.basicdata.entity.MdVendor;
import com.zeroone.star.project.dto.j4.basicdata.VendorAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorModifyDTO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 供应商表 服务类
 * </p>
 *
 * @author zjx
 * @since 2024-05-20
 */
public interface IMdVendorService extends IService<MdVendor> {
    /*
     * 导出供应商
     * */
    ResponseEntity<byte[]> exportVendor(VendorExcelSelectDTO vendorExcelSelectDTO);

    MdVendor getByVendorId(Long vendorId);

    void deleteVendors(List<Integer> ids);

    Boolean updateVendor(VendorModifyDTO data);

    /**
     * 添加vendor 信息
     *
     * @param data 供应商数据信息
     * @return 返回是否添加成功
     */
    Boolean addVendor(VendorAddDTO data);


    ResponseEntity<byte[]> downloadImportTemplate();

    void importVendors(MultipartFile file);
}
