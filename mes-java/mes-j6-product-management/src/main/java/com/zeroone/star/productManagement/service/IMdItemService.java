package com.zeroone.star.productManagement.service;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.productManagement.entity.ExportMdItem;
import com.zeroone.star.productManagement.entity.MdItem;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j6.product_management.query.MdItemQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 物料产品表 服务类
 * </p>
 *
 * @author xiaotian
 * @since 2024-05-20
 */
public interface IMdItemService extends IService<MdItem> {
    List<ExportMdItem> selectMdItemList(MdItemQuery query);

    ResponseEntity<byte[]> exportToExcel(List<ExportMdItem> items);

    ResponseEntity<byte[]> downloadTemplate();

    JsonVO<String> importFromExcel(MultipartFile file, boolean updateSupport);
}
