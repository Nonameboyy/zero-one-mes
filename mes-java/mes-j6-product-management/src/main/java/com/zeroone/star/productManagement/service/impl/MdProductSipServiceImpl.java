package com.zeroone.star.productManagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.productManagement.entity.MdProductSip;
import com.zeroone.star.productManagement.mapper.MdProductSipMapper;
import com.zeroone.star.productManagement.service.IMdProductSipService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.SipDTO;
import com.zeroone.star.project.j6.product_management.query.SipQuery;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;


@org.mapstruct.Mapper(componentModel = "spring")
interface MsProductSipMapper{
    SipDTO mdProductSipToSipDTO(MdProductSip mdProductSip);
}
/**
 * <p>
 * 产品SIP表 服务实现类
 * </p>
 *
 * @author xiebao
 * @since 2024-05-27
 */
@Service
public class MdProductSipServiceImpl extends ServiceImpl<MdProductSipMapper, MdProductSip> implements IMdProductSipService {

    @Autowired
    private MdProductSipMapper mdProductSipMapper;
    @Resource
    private UserHolder userHolder;
    @Resource
    FastDfsClientComponent dfs;
    @Resource
    MsProductSipMapper msProductSipMapper;
    @Value("${fastdfs.nginx-servers}")
    String urlPrefix;

    @Override
    public PageDTO<SipDTO> selectProductSipPage(SipQuery query) {
        Page<MdProductSip> page = new Page<>(query.getPageIndex(),query.getPageSize());

        QueryWrapper<MdProductSip> wrapper = new QueryWrapper<>();
        wrapper.like("item_id",query.getItemId());

        Page<MdProductSip> result = baseMapper.selectPage(page,wrapper);

        return PageDTO.create(result,msProductSipMapper::mdProductSipToSipDTO);
    }

    @Override
    public SipDTO selectProductSipPageByItemId(Long id) {
        return mdProductSipMapper.selectProductSipPageByItemId(id);
    }
    @Override
    public boolean insertProductSip(SipDTO dto) {
        int result = mdProductSipMapper.insertSip(dto);
        return result > 0;
    }

    @Override
    public boolean updateProductSip(SipDTO dto) {
        int result = mdProductSipMapper.updateSip(dto);
        return result > 0;
    }

    @Override
    public boolean deleteProductSipByIds(Long[] ids) {
        int result = mdProductSipMapper.deleteSip(ids);
        return result > 0;
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
