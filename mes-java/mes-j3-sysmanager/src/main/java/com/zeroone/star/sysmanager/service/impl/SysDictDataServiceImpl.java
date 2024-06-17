package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.util.ObjUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.j3.dto.SysDictDataDTO;
import com.zeroone.star.project.j3.vo.DictDataNameVO;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictDataDetailDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictDataExportDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictDataListDTO;
import com.zeroone.star.project.j3.query.dict.SysDictDataQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.SysDictData;
import com.zeroone.star.sysmanager.mapper.SysDictDataMapper;
import com.zeroone.star.sysmanager.service.ISysDictDataService;
import org.mapstruct.Mapper;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.beans.BeanUtils;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;
import java.time.LocalDateTime;
import java.util.Arrays;
import java.util.concurrent.TimeUnit;
import java.io.ByteArrayOutputStream;
import java.util.UUID;

/**
 * <p>
 * 字典数据表 服务实现类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Service
public class SysDictDataServiceImpl extends ServiceImpl<SysDictDataMapper, SysDictData> implements ISysDictDataService {
    @Resource
    private RedisTemplate<String,List<SysDictData>> redisTemplate;

    @Resource
    private TsSysDictDataMapper tsSysDictDataMapper;

    @Resource
    private EasyExcelComponent excelComponent;


    @Override
    public List<DictDataNameVO> listDictDataNameByDictType(String dictType) {
        List<DictDataNameVO> dictDataNameVOS;
        List<SysDictData> sysDictDataList;
        //先查询redis中是否含有对应dictType
        String key = "sys_dict:" + dictType;//是否需要定义常量类?
        sysDictDataList = redisTemplate.opsForValue().get(key);
        //若redis中有, 则包装后直接返回
        if(sysDictDataList!=null&&!sysDictDataList.isEmpty()){
            dictDataNameVOS = sysDictDataList.stream()
                            .map(sysDictData -> {
                                DictDataNameVO dictDataNameVO = new DictDataNameVO();
                                BeanUtils.copyProperties(sysDictData, dictDataNameVO);
                                return dictDataNameVO;
                            })
                            .collect(Collectors.toList());
            return dictDataNameVOS;
        }
        //若redis没有, 则查询mysql
        LambdaQueryWrapper<SysDictData> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(StringUtils.hasText(dictType), SysDictData::getDictType, dictType);
        wrapper.eq(SysDictData::getStatus, "0"); //是否需要定义常量类?
        wrapper.orderByAsc(SysDictData::getDictSort);
        sysDictDataList = list(wrapper);
        //若mysql查询不到, 则不存在该dictType, 抛出异常
        if(sysDictDataList==null||sysDictDataList.isEmpty())
            throw new RuntimeException("非法字典类型, 无对应字典数据");
        //若mysql有, 则读入redis并返回结果
        redisTemplate.opsForValue().set(key, sysDictDataList);
        dictDataNameVOS =
                sysDictDataList.stream()
                .map(sysDictData -> {
                    DictDataNameVO dictDataNameVO = new DictDataNameVO();
                    BeanUtils.copyProperties(sysDictData, dictDataNameVO);
                    return dictDataNameVO;
                })
                .collect(Collectors.toList());
        return dictDataNameVOS;
    }

    @Override
    public Integer saveDictData(SysDictDataDTO sysDictDataDTO, UserDTO currentUser) {
        //数据类型转换
        SysDictData sysDictData = new SysDictData();
        BeanUtils.copyProperties(sysDictDataDTO,sysDictData);
        sysDictData.setCreateBy(currentUser.getUsername());
        sysDictData.setCreateTime(LocalDateTime.now());
        //插入字典数据
        int row = baseMapper.insert(sysDictData);
        //如果插入成功则将与该字典数据同类型的字典数据放入Redis
        if(row > 0){
            //查询与该字典数据同类型的字典数据列表
            LambdaQueryWrapper<SysDictData> wrapper = new LambdaQueryWrapper<>();
            wrapper.eq(SysDictData::getDictType, sysDictDataDTO.getDictType());
            List<SysDictData> sysDictDataCacheList = baseMapper.selectList(wrapper);
            //存入redis,key为sys_dict:字典类型
            redisTemplate.opsForValue().set("sys_dict:"+sysDictDataDTO.getDictType(), sysDictDataCacheList, 24, TimeUnit.HOURS);
        }else{
            throw new RuntimeException("新增字典数据失败");
        }
        return row;
    }

    @Override
    public Integer updateDictData(SysDictDataDTO sysDictDataDTO, UserDTO currentUser) {
        //根据主键更新数据
        LambdaUpdateWrapper<SysDictData> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.set(StrUtil.isNotBlank(sysDictDataDTO.getDictType()), SysDictData::getDictType, sysDictDataDTO.getDictType())
                .set(StrUtil.isNotBlank(sysDictDataDTO.getDictLabel()), SysDictData::getDictLabel, sysDictDataDTO.getDictLabel())
                .set(StrUtil.isNotBlank(sysDictDataDTO.getDictValue()), SysDictData::getDictValue, sysDictDataDTO.getDictValue())
                .set(ObjUtil.isNotNull(sysDictDataDTO.getCssClass()), SysDictData::getCssClass, sysDictDataDTO.getCssClass())
                .set(ObjUtil.isNotNull(sysDictDataDTO.getDictSort()), SysDictData::getDictSort, sysDictDataDTO.getDictSort())
                .set(ObjUtil.isNotNull(sysDictDataDTO.getListClass()), SysDictData::getListClass, sysDictDataDTO.getListClass())
                .set(ObjUtil.isNotNull(sysDictDataDTO.getStatus()), SysDictData::getStatus, sysDictDataDTO.getStatus())
                .set(ObjUtil.isNotNull(sysDictDataDTO.getRemark()), SysDictData::getRemark, sysDictDataDTO.getRemark())
                .set(SysDictData::getUpdateBy, currentUser.getUsername())
                .set(SysDictData::getUpdateTime, LocalDateTime.now())
                .eq(SysDictData::getDictCode, sysDictDataDTO.getDictCode());
        int row = baseMapper.update(null, updateWrapper);
        //如果更新成功则将与该字典数据同类型的字典数据放入Redis
        if(row > 0){
            //查询与该字典数据同类型的字典数据列表
            LambdaQueryWrapper<SysDictData> wrapper = new LambdaQueryWrapper<>();
            wrapper.eq(SysDictData::getDictType, sysDictDataDTO.getDictType());
            List<SysDictData> sysDictDataCacheList = baseMapper.selectList(wrapper);
            //存入redis,key为sys_dict:字典类型
            redisTemplate.opsForValue().set("sys_dict:"+sysDictDataDTO.getDictType(), sysDictDataCacheList, 24, TimeUnit.HOURS);
        }else{
            throw new RuntimeException("修改字典数据失败");
        }
        return row;
    }

    @Transactional
    @Override
    public void removeDictData(Long[] dictCodes) {
        //查询要删除的字典数据列表对应的字典类型名列表
        LambdaQueryWrapper<SysDictData> wrapper = new LambdaQueryWrapper<>();
        wrapper.select(SysDictData::getDictType)
                .in(SysDictData::getDictCode,Arrays.asList(dictCodes));
        List<String> dictTypeNameList = baseMapper.selectList(wrapper).stream()
                .map(SysDictData::getDictType)
                .distinct()
                .collect(Collectors.toList());
        //删除字典数据
        baseMapper.deleteBatchIds(Arrays.asList(dictCodes));
        //根据字典类型名列表更新缓存
        for (String dictTypeName : dictTypeNameList){
            LambdaQueryWrapper<SysDictData> queryWrapper = new LambdaQueryWrapper<>();
            queryWrapper.eq(SysDictData::getDictType, dictTypeName);
            List<SysDictData> dictDataCacheList = baseMapper.selectList(queryWrapper);
            redisTemplate.opsForValue().set("sys_dict:"+dictTypeName, dictDataCacheList, 24, TimeUnit.HOURS);
        }
    }

    @Override
    public JsonVO<PageDTO<SysDictDataListDTO>> listDictData(SysDictDataQuery dictDataQuery) {
        // 开始分页
        Page<SysDictData> pageType = new Page<>(dictDataQuery.getPageIndex(), dictDataQuery.getPageSize());

        page(pageType, new LambdaQueryWrapper<SysDictData>()
                .eq(SysDictData::getDictType, dictDataQuery.getDictType())
                .like(dictDataQuery.getDictLabel() != null,
                        SysDictData::getDictLabel, dictDataQuery.getDictLabel())
                .eq(dictDataQuery.getStatus() != null,
                        SysDictData::getStatus, dictDataQuery.getStatus())
        );

        return JsonVO.success(PageDTO.create(pageType, tsSysDictDataMapper::toDto));
    }

    @Override
    public ResponseEntity<byte[]> exportDictData(SysDictDataExportDTO sysDictDataExportDTO) {

        // 查询内容
        try( ByteArrayOutputStream excel = new ByteArrayOutputStream() ) {

            List<SysDictDataListDTO> list = list(new LambdaQueryWrapper<SysDictData>()
                    .eq(SysDictData::getDictType, sysDictDataExportDTO.getDictType())
                    .like(sysDictDataExportDTO.getDictLabel() != null,
                            SysDictData::getDictLabel, sysDictDataExportDTO.getDictLabel())
                    .eq(sysDictDataExportDTO.getStatus() != null,
                            SysDictData::getStatus, sysDictDataExportDTO.getStatus()))
                    .stream().map(tsSysDictDataMapper::toDto)
                    .collect(Collectors.toList());

            //easyexcel构建输出流
            String filename= UUID.randomUUID() + ".xls";
            excelComponent.export(UUID.randomUUID().toString(), excel, SysDictDataListDTO.class, list);

            //构建响应头
            HttpHeaders headers = new HttpHeaders();
            headers.setContentDispositionFormData("attachment",filename);
            headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);

            return new ResponseEntity<>(excel.toByteArray(), headers, HttpStatus.OK);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public JsonVO<SysDictDataDetailDTO> getDictData(Long dictCode) {
        return JsonVO.success(tsSysDictDataMapper.toDetailDTO(getById(dictCode)));
    }
}

@Mapper(componentModel = "spring")
interface TsSysDictDataMapper {
    SysDictDataListDTO toDto(SysDictData sysDictData);

    SysDictDataDetailDTO toDetailDTO(SysDictData sysDictData);
}
