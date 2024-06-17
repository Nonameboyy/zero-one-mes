package com.zeroone.star.project.j6.product_management;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductSopDTO;
import com.zeroone.star.project.j6.product_management.query.ProductSopQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 描述：产品SOP API接口定义
 * </p>
 * @version 1.0.0
 */
@Api("产品SOP API")
public interface ProductSopApis {

    /**
     * 查询产品SOP列表
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ProductSopDTO>> queryAll(ProductSopQuery query);

    /**
     * 通过ID查询产品SOP
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<ProductSopDTO> queryById(Long id);
    /**
     * 新增产品SOP
     * @param dto 产品SOP传输对象
     * @return 操作结果
     */
    JsonVO<String> add(ProductSopDTO dto);

    /**
     * 修改产品SOP
     * @param dto 产品SOP传输对象
     * @return 操作结果
     */
    JsonVO<String> edit(ProductSopDTO dto);

    /**
     * 删除产品SOP
     * @param ids 产品SOP ID数组
     * @return 操作结果
     */
    JsonVO<String> remove(Long[] ids);

    JsonVO<String> uploadFile(MultipartFile file);
}