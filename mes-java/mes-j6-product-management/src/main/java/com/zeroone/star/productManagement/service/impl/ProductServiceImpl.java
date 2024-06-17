package com.zeroone.star.productManagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.productManagement.entity.MdItem;
import com.zeroone.star.productManagement.mapper.ProductMapper;
import com.zeroone.star.productManagement.service.IProductService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductDTO;
import com.zeroone.star.project.j6.product_management.query.ProductQuery;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@org.mapstruct.Mapper(componentModel = "spring")
interface MsProductMapper {
    ProductDTO mdItemToProductDTO(MdItem mdItem);
}

@Service
public class ProductServiceImpl extends ServiceImpl<ProductMapper, MdItem> implements IProductService {

    @Resource
    MsProductMapper msProductMapper;



    /*
    根据id获得实体类信息，使用mybatisplus的方法，使用BeanUtil的类型转换
     */
    @Override
    public ProductDTO myGetById(Long id) {
        MdItem entity = this.getById(id);
        ProductDTO productDTO = BeanUtil.copyProperties(entity, ProductDTO.class);
        return productDTO;
    }

    /*
    批量删除产品
     */
    @Override
    public void myDelete(List<Long> productIds) {
        this.removeByIds(productIds);
    }

    /*
    更新产品信息
     */
    @Override
    public void myUpdate(ProductDTO dto) {
        MdItem mdItem = BeanUtil.copyProperties(dto, MdItem.class);
        this.updateById(mdItem);
    }

    @Override
    public void myAdd(ProductDTO dto) {
        MdItem mdItem = BeanUtil.copyProperties(dto, MdItem.class);
        //TODO 需要添加创造人，新建时间等属性
        this.save(mdItem);
    }

    @Override
    public PageDTO<ProductDTO> myList(ProductQuery query) {
        Page<MdItem> page = new Page<>(query.getPageIndex(),query.getPageSize());
        LambdaQueryWrapper<MdItem> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(query.getClassificationName() != null, MdItem::getItemTypeName,query.getClassificationName());
        wrapper.like(query.getProductCode() != null,MdItem::getItemTypeCode,query.getProductCode());
        wrapper.like(query.getProductName() != null, MdItem::getItemName,query.getProductName());


        this.page(page,wrapper);

        return PageDTO.create(page, msProductMapper::mdItemToProductDTO);

    }
}
