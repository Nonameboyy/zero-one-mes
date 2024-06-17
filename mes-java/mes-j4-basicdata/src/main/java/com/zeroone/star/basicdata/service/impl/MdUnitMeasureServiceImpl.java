package com.zeroone.star.basicdata.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.date.DateTime;
import com.alibaba.cloud.commons.lang.StringUtils;
import com.alibaba.nacos.shaded.com.google.protobuf.ServiceException;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.basicdata.entity.MdUnitMeasure;
import com.zeroone.star.basicdata.mapper.MdUnitMeasureMapper;
import com.zeroone.star.basicdata.service.IMdUnitMeasureService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j4.basicdata.UnitAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitMeasureDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitUpdateDTO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * <p>
 * 单位表 服务实现类
 * </p>
 *
 * @author 本鼠
 * @since 2024-05-21
 */
@Service
@Slf4j
public class MdUnitMeasureServiceImpl extends ServiceImpl<MdUnitMeasureMapper, MdUnitMeasure> implements IMdUnitMeasureService {


    @Resource
    private MdUnitMeasureMapper mdUnitMeasureMapper;

    @Resource
    private EasyExcelComponent excel;

    @Resource
    private UserHolder userHolder;

    /*
     * 删除单位
     * */
    public Long deleteByIds(List<Long> idList) {
        return mdUnitMeasureMapper.deleteByIds(idList);
    }

    /*
     * 导出单位数据
     * */
    @SneakyThrows
    public ResponseEntity<byte[]> exportUnitMeasure(UnitExcelSelectDTO unitExcelSelectDTO) {
        //查询到导出文件的数据
        List<MdUnitMeasure> unitMeasureList = mdUnitMeasureMapper.listUnitMeasure(unitExcelSelectDTO);
        //创建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        //导出数据到输出流
        excel.export("导出单位", out, MdUnitMeasure.class, unitMeasureList);

        //获取字节数据
        byte[] bytes = out.toByteArray();
        out.close();

        //构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "unitmeasure-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        //headers.setContentDispositionFormData("attachment", filename);
        headers.add("Content-Disposition", "attachment;filename=" + filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);

        //响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    /**
     * 查询单位列表
     *
     * @param mdUnitMeasure
     * @return
     */
    @Override
    public List<UnitMeasureDTO> selectMdUnitMeasureList(UnitMeasureDTO mdUnitMeasure) {
        return mdUnitMeasureMapper.selectMdUnitMeasureList(mdUnitMeasure);
    }

    /**
     * 添加单位测量信息到数据库。
     * 该方法通过接收一个单位测量DTO（数据传输对象），将其复制到一个对应的实体对象中，
     * 然后将这个实体对象插入到数据库中。
     *
     * @param unitAddDTO 单位测量的DTO，包含了需要添加到数据库中的单位测量信息。
     */
    @Override
    public void addUnitMeasure(UnitAddDTO unitAddDTO) {
        // 检查DTO是否为空
        if (unitAddDTO == null) {
            throw new IllegalArgumentException("UnitMeasureDTO cannot be null");
        }

        // 将DTO对象复制到实体对象中
        MdUnitMeasure unitMeasure = BeanUtil.copyProperties(unitAddDTO, MdUnitMeasure.class);
        // 设置创建时间和更新时间
        unitMeasure.setCreateTime(DateTime.now().toLocalDateTime());
        unitMeasure.setUpdateTime(DateTime.now().toLocalDateTime());

        // 对实体对象进行非空检查，确保主要字段不为空
        if (StringUtils.isBlank(unitMeasure.getMeasureCode()) || StringUtils.isBlank(unitMeasure.getMeasureName())) {
            throw new IllegalArgumentException("Measure code and measure name are required");
        }

        // 插入实体对象到数据库
        mdUnitMeasureMapper.insert(unitMeasure);
    }


    /**
     * 修改单位度量信息。
     *
     * @param unitUpdateDTO 单位度量数据传输对象，包含了需要更新的单位度量信息。
     * @throws ServiceException 当更新操作失败时抛出，封装了更新过程中的任何异常信息。
     */
    @Override
    public void modifyUnitMeasure(UnitUpdateDTO unitUpdateDTO){
        // 实体对象初始化，用于后续的数据更新操作
        MdUnitMeasure unitMeasure = new MdUnitMeasure();
        // 属性拷贝
        BeanUtils.copyProperties(unitUpdateDTO, unitMeasure);
        // 设置更新时间
        unitMeasure.setUpdateTime(DateTime.now().toLocalDateTime());

        // 构建更新条件
        UpdateWrapper<MdUnitMeasure> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("measure_id", unitMeasure.getMeasureId());

        // 执行数据库更新操作
        mdUnitMeasureMapper.update(unitMeasure, updateWrapper);
    }

}
