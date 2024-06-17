package com.zeroone.star.basicdata.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.zeroone.star.basicdata.entity.MdUnitMeasure;
import com.zeroone.star.basicdata.entity.MdVendor;
import com.zeroone.star.basicdata.mapper.MdVendorMapper;
import com.zeroone.star.basicdata.service.IMdVendorService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.basicdata.VendorExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorImportDTO;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.basicdata.VendorAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.VendorModifyDTO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 供应商表 服务实现类
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-21
 */
@Service
@Slf4j
public class MdVendorServiceImpl extends ServiceImpl<MdVendorMapper, MdVendor> implements IMdVendorService {

    @Resource
    private MdVendorMapper mdVendorMapper;

    @Resource
    private EasyExcelComponent excel;

    @Resource
    private UserHolder userHolder;
    /*
    * 导出供应商
    * */
    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportVendor(VendorExcelSelectDTO vendorExcelSelectDTO) {
        //查询到导出文件的数据
        List<MdVendor> vendorList = mdVendorMapper.listVendor(vendorExcelSelectDTO);
        //创建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        //导出数据到输出流
        excel.export("导出单位", out,MdVendor.class, vendorList);

        //获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        //构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "vendor-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        //headers.setContentDispositionFormData("attachment", filename);
        headers.add("Content-Disposition", "attachment;filename=" + filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);

        //响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    @Override
    public Boolean addVendor(VendorAddDTO data){
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            MdVendor mdVendor = new MdVendor();
            BeanUtil.copyProperties(data, mdVendor);
            mdVendor.setCreateBy(userDTO.getUsername());
            mdVendor.setUpdateBy(userDTO.getUsername());
            mdVendor.setCreateTime(LocalDateTime.now());
            mdVendor.setUpdateTime(LocalDateTime.now());
            return mdVendorMapper.insert(mdVendor) > 0;
        } catch (Exception e) {
            log.info("添加供应商失败",e.getMessage());
            return false;
        }
    }

    @Override
    public MdVendor getByVendorId(Long vendorId) {
        return mdVendorMapper.getById(vendorId);
    }

    @Override
    public void deleteVendors(List<Integer> ids) {
        ids.forEach(vendorId->{
            mdVendorMapper.deleteVendor(vendorId);
        });
    }

    @Override
    public ResponseEntity<byte[]> downloadImportTemplate() {
        // 创建一个空的数据列表，用于生成空白模板
        List<VendorImportDTO> dataList = new ArrayList<>();

        // 创建一个Excel模板，并写入空数据列表
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        EasyExcel.write(out, VendorImportDTO.class).sheet("导入模板").doWrite(dataList);
        byte[] bytes;
        //导出数据到输出流
        try {
            //获取字节数据
            bytes = out.toByteArray();
            out.close();
        } catch (IOException e) {
            throw new RuntimeException("模板生成失败");
        }
        // 构造响应头，告诉浏览器返回的内容是一个Excel文件
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        headers.add("Content-Disposition","attachment;filename= vendor_import_template.xlsx");
        // 返回一个字节数组作为Excel文件内容
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    @Override
    public void importVendors(MultipartFile file) {
        // 使用EasyExcel读取上传的Excel文件并处理
        try {
            ExcelReadListener<VendorImportDTO> listener = new ExcelReadListener<>();
            EasyExcel.read(file.getInputStream(), VendorImportDTO.class, listener).sheet().doRead();
            // 将读取到的数据插入到数据库
            //获取当前登录用户
            UserDTO currentUser = userHolder.getCurrentUser();
            listener.getDataList().forEach(data -> {
                MdVendor vendor = new MdVendor();
                BeanUtils.copyProperties(data, vendor);
                vendor.setCreateBy(currentUser.getUsername());
                vendor.setUpdateBy(currentUser.getUsername());
                mdVendorMapper.insert(vendor);
            });
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }


    public Boolean updateVendor(VendorModifyDTO data) {
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            MdVendor mdVendor = new MdVendor();
            BeanUtil.copyProperties(data, mdVendor);
            mdVendor.setUpdateBy(userDTO.getUsername());
            mdVendor.setUpdateTime(LocalDateTime.now());
            return mdVendorMapper.updateById(mdVendor) > 0;
        } catch (Exception e) {
            log.info("修改失败",e.getMessage());
            return false;
        }
    }
}
