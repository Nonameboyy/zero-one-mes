package com.zeroone.star.productManagement.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.productManagement.entity.ProductSop;
import com.zeroone.star.productManagement.mapper.ProductSopMapper;
import com.zeroone.star.productManagement.service.IProductSopService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.ProductSopDTO;
import com.zeroone.star.project.j6.product_management.query.ProductSopQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Objects;

/**
 * StopWord对应MapStruct映射接口
 */
@Mapper(componentModel = "spring")
interface  MsProductSopMapper{
    /**
     * 查询停用词
     * 将实体类DO转换为dto
     *
     * @param sop 待转换DO
     * @return 转换结果
     */
     ProductSopDTO ProductSopToProductSopDTO(ProductSop sop);
}
@Service
public class ProductSopServiceImpl extends ServiceImpl<ProductSopMapper, ProductSop> implements IProductSopService {
    @Autowired
    private ProductSopMapper ProductSopMapper;
    @Resource
    FastDfsClientComponent dfs;
    @Value("${fastdfs.nginx-servers}")
    String urlPrefix;
    @Resource
    private UserHolder userHolder;
    @Resource
    MsProductSopMapper msProductSopMapper;
    @Override
    public PageDTO<ProductSopDTO> selectProductSopPage(ProductSopQuery query) {
        //构建分页条件对象
        Page<ProductSop> page = new Page<>(query.getPageIndex(),query.getPageSize());
        //构建查询条件
        QueryWrapper<ProductSop> queryWrapper = new QueryWrapper<>();
        if (Objects.nonNull(query.getItemId()) && query.getItemId() > 0) {
            queryWrapper.like("item_id", query.getItemId());
        }
        //执行查询
        Page<ProductSop> result = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(result, msProductSopMapper::ProductSopToProductSopDTO);
    }

    @Override
    public ProductSopDTO selectProductSopById(Long id) {
        return ProductSopMapper.selectProductSopById(id);
    }

    @Override
    public boolean insertProductSop(ProductSopDTO dto) {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            log.error("解析用户失败！！！",e);
        }
        if (dto == null || dto.getSopTitle() == null||selectProductSopById(dto.getSopId()) != null) {
            return false;
        }else {
            ProductSop sop =new ProductSop();
            sop.setSopId(dto.getSopId());
            sop.setItemId(dto.getItemId());
            sop.setSopTitle(dto.getSopTitle());
            sop.setOrderNum(dto.getOrderNum());
            sop.setSopDescription(dto.getSopDescription());
            sop.setProcessId(dto.getProcessId());
            sop.setCreateBy(currentUser != null ? currentUser.getUsername() : "unknown");
            sop.setCreateTime(LocalDateTime.now());
            return save(sop);
        }
    }

    @Override
    public boolean updateProductSop(ProductSopDTO dto) {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            log.error("解析用户失败！！！");
        }
        //数据封装
        ProductSop sop =new ProductSop();
        sop.setSopId(dto.getSopId());
        sop.setItemId(dto.getItemId());
        sop.setSopTitle(dto.getSopTitle());
        sop.setOrderNum(dto.getOrderNum());
        sop.setSopDescription(dto.getSopDescription());
        sop.setProcessId(dto.getProcessId());
        sop.setUpdateTime(LocalDateTime.now());
        sop.setUpdateBy(currentUser != null ? currentUser.getUsername() : "unknown");
        boolean success  = ProductSopMapper.updateById(sop)>0;
        if (success) {
            return true;
        }
        return false;
    }

    @Override
    public boolean deleteProductSopByIds(Long[] ids) {
        ProductSopMapper.deleteProductSopByIds(ids);
        return true;

}
    @Override
    @SneakyThrows
    @ResponseBody
    @ApiOperation(value = "上传文件")
    public String uploadFile(MultipartFile file) {
        try {
            String filename = file.getOriginalFilename();
            assert filename != null;
            String suffix = filename.substring(filename.lastIndexOf(".") + 1);
            FastDfsFileInfo result = dfs.uploadFile(file.getBytes(), suffix);
            if (result != null) {
                return dfs.fetchUrl(result, "http://" + urlPrefix, true);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
