package com.zeroone.star.productManagement.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.zeroone.star.productManagement.entity.ExportMdItem;
import com.zeroone.star.productManagement.entity.MdItem;
import com.zeroone.star.productManagement.mapper.MdItemMapper;
import com.zeroone.star.productManagement.service.IMdItemService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j6.product_management.query.MdItemQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import javax.validation.Valid;
import javax.validation.constraints.NotNull;
import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 物料产品表 服务实现类
 * </p>
 *
 * @author xiaotian
 * @since 2024-05-20
 */
@Service
public class MdItemServiceImpl extends ServiceImpl<MdItemMapper, MdItem> implements IMdItemService {
    @Autowired
    private MdItemMapper mdItemMapper;
    @Autowired
    EasyExcelComponent excel;
    @Resource
    UserHolder userHolder;

    /**
     * 根据条件查询物料列表
     * @param mdItemQuery 查询条件
     * @return 物料列表
     */
    public List<ExportMdItem> selectMdItemList(MdItemQuery mdItemQuery) {

        return mdItemMapper.selectMdItemList(mdItemQuery);
    }

    /**
     * 导出数据
     * @param items 物料数据
     * @return 返回响应
     */
    public ResponseEntity<byte[]> exportToExcel(List<ExportMdItem> items) {
        try {
            // 构建一个输出流
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            // 导出数据到输出流
            excel.export("物料产品列表", out, ExportMdItem.class, items);
            // 获取字节数据
            byte[] bytes = out.toByteArray();
            out.close();

            // 构建响应头
            HttpHeaders headers = new HttpHeaders();
            String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
            headers.setContentDispositionFormData("attachment", filename);
            headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
            // 响应文件给客户端
            return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
        } catch (IOException e) {
            return new ResponseEntity<>(null, HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    /**
     * 初始化产品物料模板
     * @return MdItem对象
     */
    @PostConstruct
    private MdItem initTemplate() {
        MdItem item = new MdItem();
        item.setItemId(null);
        item.setItemCode("必填");
        item.setItemName("必填");
        item.setSpecification("");
        item.setUnitOfMeasure("必填");
        item.setItemOrProduct("必填");
        item.setItemTypeId(null);
        item.setItemTypeCode("");
        item.setItemTypeName("");
        item.setEnableFlag("必填");
        item.setSafeStockFlag("必填");
        item.setMinStock(null);
        item.setMaxStock(null);
        item.setRemark("");
        return item;
    }

    /**
     * 下载模板
     * @return 返回响应
     */
    public ResponseEntity<byte[]> downloadTemplate(){
        try {
            List<MdItem> items = new ArrayList<>();
            items.add(initTemplate());
            // 构建一个输出流
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            // 导出数据到输出流
            excel.export("物料产品列表", out, MdItem.class, items);
            // 获取字节数据
            byte[] bytes = out.toByteArray();
            out.close();

            // 构建响应头
            HttpHeaders headers = new HttpHeaders();
            String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
            headers.setContentDispositionFormData("attachment", filename);
            headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
            // 响应文件给客户端
            return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
        } catch (IOException e) {
            // 处理异常并返回适当的错误响应
            e.printStackTrace();
            return new ResponseEntity<>(null, HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public JsonVO<String> importFromExcel(MultipartFile file, boolean updateSupport) {
        List<MdItem> items = new ArrayList<>();
        int successNum = 0;
        int failureNum = 0;
        StringBuilder successMsg = new StringBuilder();
        StringBuilder failureMsg = new StringBuilder();
        StringBuilder failureNameMsg = new StringBuilder();

        // excel同步读取数据
        try {
            items = EasyExcel.read(new BufferedInputStream(file.getInputStream())).head(MdItem.class).sheet().doReadSync();
            if (items == null || items.isEmpty()) {
                failureNameMsg.append("导入的物料数据不能为空！");
                return JsonVO.create(null, ResultStatus.FAIL.getCode(), failureMsg.toString());
            }
        }catch (IOException e) {
            e.printStackTrace();
        }

        for (MdItem mdItem : items)
        {
            try{
                //验证数据
                validationData(mdItem);
                //是否存在
                MdItem  m = mdItemMapper.checkItemCodeUnique(mdItem);
                if(m == null){
                    insertMdItem(mdItem);
                    successNum++;
                }else if (updateSupport){
                    updateMdItem(mdItem);
                    successNum++;
                }else {//数据已存在但不支持更新
                    failureNum++;
                    failureNameMsg.append(failureNum).append("、").append(mdItem.getItemName());
                }
            }catch (Exception e){
                failureNum++;
                failureNameMsg.append(failureNum).append("、").append(mdItem.getItemName());
            }
        }

        if (failureNum > 0)
        {
            failureMsg.insert(0, "成功导入" + successNum + " 条数据，");
            failureMsg.append("共 ").append(failureNum).append(" 条数据格式不正确，错误如下：");
            failureMsg.append(failureNameMsg);
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), failureMsg.toString());
        } else
        {
            successMsg.insert(0, "导入成功！共 " + successNum + " 条");
        }
        return JsonVO.create(null, ResultStatus.SUCCESS.getCode(), successMsg.toString());
    }

    /**
     * 新增产品物料信息
     *
     * @param mdItem 产品物料信息
     * @return 结果
     */
    private void insertMdItem(MdItem mdItem) throws Exception {
        UserDTO userDTO  = userHolder.getCurrentUser();
        mdItem.setCreateBy(userDTO.getUsername());
        mdItem.setCreateTime(DateTime.now().toLocalDateTime());
        mdItemMapper.insertMdItem(mdItem);
    }

    /**
     * 修改产品物料信息
     *
     * @param mdItem 产品物料信息
     * @return 结果
     */
    private void updateMdItem(MdItem mdItem) throws Exception {
        UserDTO userDTO  = userHolder.getCurrentUser();
        mdItem.setUpdateBy(userDTO.getUsername());
        mdItem.setUpdateTime(DateTime.now().toLocalDateTime());
        mdItemMapper.updateMdItem(mdItem);
    }

    private void validationData(MdItem mdItem) {
        if (mdItem.getItemCode() == null || mdItem.getItemCode().isEmpty()) {
            throw new IllegalArgumentException("物料编码是必填项。");
        }

        if (mdItem.getItemName() == null || mdItem.getItemName().isEmpty()) {
            throw new IllegalArgumentException("物料名称是必填项。");
        }

        if (mdItem.getUnitOfMeasure() == null || mdItem.getUnitOfMeasure().isEmpty()) {
            throw new IllegalArgumentException("计量单位是必填项。");
        }

        if (mdItem.getItemOrProduct() == null || mdItem.getItemOrProduct().isEmpty()) {
            throw new IllegalArgumentException("物料或产品是必填项。");
        }

        if (mdItem.getEnableFlag() == null || mdItem.getEnableFlag().isEmpty()) {
            throw new IllegalArgumentException("启用标志是必填项。");
        }

        if (mdItem.getSafeStockFlag() == null || mdItem.getSafeStockFlag().isEmpty()) {
            throw new IllegalArgumentException("安全库存标志是必填项。");
        }
    }

}
