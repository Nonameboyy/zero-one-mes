package com.zeroone.star.productManagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.productManagement.entity.MdProductSupplier;
import com.zeroone.star.productManagement.mapper.MdProductSupplierMapper;
import com.zeroone.star.productManagement.service.IMdProductSupplierService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductSupplierListDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierDTO;
import com.zeroone.star.project.j6.product_management.dto.SupplierListDTO;
import com.zeroone.star.project.j6.product_management.query.SupplierListQuery;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author smile
 * @since 2024-05-22
 */
@Service
public class MdProductSupplierServiceImpl extends ServiceImpl<MdProductSupplierMapper, MdProductSupplier> implements IMdProductSupplierService {
    @Autowired
    private MsSupplierMapper msSupplierMapper;

    @Override
    public PageDTO<SupplierDTO> querySupplierList(SupplierListQuery query) {
        Page<MdProductSupplier> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<MdProductSupplier> queryWrapper = new QueryWrapper<>();

        Long supplierId = query.getSupplierId();
        Long productId = query.getProductId();
        if (supplierId != null) {
            queryWrapper.eq("supplier_id", supplierId);
        }
        if (productId != null) {
            queryWrapper.eq("product_id", productId);
        }

        page(page, queryWrapper);

        return PageDTO.create(page, msSupplierMapper::toDto);
    }

    @Override
    public String addSupplierList(SupplierListDTO dto) {
        Long productId = dto.getProductId();
        List<MdProductSupplier> entities = dto.getSupplierIds().stream()
                .map(id -> new MdProductSupplier(productId, id)).collect(Collectors.toList());

        saveBatch(entities);

        return "success";
    }

    @Override
    public String updateSupplier(SupplierDTO dto) {
        Long id = dto.getId();
        if (id == null) {
            throw new IllegalArgumentException("ID cannot be null");
        }

        MdProductSupplier entity = new MdProductSupplier();
        entity.setId(id);
        if (dto.getSupplierId() != null) {
            entity.setSupplierId(dto.getSupplierId());
        }
        if (dto.getProductId() != null) {
            entity.setProductId(dto.getProductId());
        }

        // Update the entity using MyBatis Plus's updateById method
        boolean updated = updateById(entity);
        return updated ? "success" : "failure";
    }

    @Override
    public String deleteBatchSupplier(ProductSupplierListDTO dto) {
        List<Long> productSupplierIds = dto.getProductSupplierIds();

        removeByIds(productSupplierIds);

        return "success";
    }
}

@Mapper(componentModel = "spring")
interface MsSupplierMapper {
    SupplierDTO toDto(MdProductSupplier entity);
}