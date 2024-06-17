package com.zeroone.star.productManagement.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.productManagement.entity.MdProductSip;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.SipDTO;
import com.zeroone.star.project.j6.product_management.query.SipQuery;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;
/**
 * <p>
 * 产品SIP表 服务类
 * </p>
 *
 * @author xiebao
 * @since 2024-05-27
 */
public interface IMdProductSipService extends IService<MdProductSip> {

    /**
     * 根据 ItemId 进行分页查询
     * @param id 查询体
     * @return 所有查询到的BomDTO列表
     */
    SipDTO selectProductSipPageByItemId(Long id);

    /**
     * 根据 ItemId 进行分页查询
     * @param query 查询体
     * @return 所有查询到的BomDTO列表
     */
    PageDTO<SipDTO> selectProductSipPage(SipQuery query);
    /**
     * 新增Sip项
     * @param dto 新增条件
     * @return 新增是否成功
     */
    boolean insertProductSip(SipDTO dto);

    /**
     * 更新bom项
     * @param dto 更新后的结果
     * @return 更新是否成功
     */
    boolean updateProductSip(SipDTO dto);

    /**
     * 根据 bomIds 来批量删除
     * @param ids bomId列表
     * @return 是否全部删除成功
     */
    boolean deleteProductSipByIds(Long[] ids);

    // 新增方法用于处理文件上传逻辑
    String uploadFile(MultipartFile file);
}
