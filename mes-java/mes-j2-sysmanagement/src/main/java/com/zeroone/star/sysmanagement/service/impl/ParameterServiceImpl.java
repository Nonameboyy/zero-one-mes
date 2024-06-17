package com.zeroone.star.sysmanagement.service.impl;

import cn.hutool.core.date.DateTime;
import org.springframework.http.MediaType;
import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.sysmanagement.dto.param.ParameterDTO;
import com.zeroone.star.project.j2.sysmanagement.query.param.ParameterQuery;
import com.zeroone.star.sysmanagement.cache.RedisCache;
import com.zeroone.star.sysmanagement.constant.Constants;
import com.zeroone.star.sysmanagement.constants.ParameterConstant;
import com.zeroone.star.sysmanagement.entity.ParameterDO;
import com.zeroone.star.sysmanagement.mapper.ParameterMapper;
import com.zeroone.star.sysmanagement.parameterMapstruct.ParameterMapstruct;
import com.zeroone.star.sysmanagement.service.ParameterService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;
import java.util.Set;



/**
 * 转换器
 */
@Mapper(componentModel = "spring")
interface MsParameterMapper{

    ParameterDO paraDtoToDo(ParameterDTO parameterDTO);

    ParameterDTO paraDoToDto(ParameterDO parameterDO);
}



/**
 * <p>
 * 参数配置表 服务实现类
 * </p>
 *
 * @author kino
 * @since 2024-05-22
 */
@Service
public class ParameterServiceImpl extends ServiceImpl<ParameterMapper, ParameterDO> implements ParameterService {


    @Resource
    RedisCache redisCache;


    @Resource
    MsParameterMapper ms;

    // 参数映射 领域模型转换
    @Resource
    private ParameterMapstruct parameterMapstruct;

    // redis组件
    @Resource
    private RedisTemplate<String,Object> redisTemplate;

    //dao层
    @Resource
    private ParameterMapper parameterMapper;

    // 导入easyExcel组件
    @Resource
    EasyExcelComponent excelComponent;

    // 项目启动时，初始化参数到缓存
    @PostConstruct
    public void init()
    {
        loadConfigCache();
    }


    @Override
    public void refreshCache() {
        //1.清空redis缓存
        clearConfigCache();
        //2.将数据库数据缓存到redis中
        loadConfigCache();
    }

    /**
     * @description: 将数据库数据缓存到redis中
     * @author: 40斤
     * @date: 2024/5/23 10:42
     * @param: []
     * @return: void
     **/
    private void loadConfigCache() {
        //1.从数据库中查询所有数据
        List<ParameterDO> ParameterDOS = parameterMapper.selectList(null);
        if (ParameterDOS.isEmpty()) {
            return;
        }
        //2.将数据保存到redis中
        for (ParameterDO parameterDO : ParameterDOS) {
            if (parameterDO.getConfigKey()!=null&&parameterDO.getConfigValue()!=null){
                redisTemplate.opsForValue().set(ParameterConstant.SYS_CONFIG_KEY+ parameterDO.getConfigKey(),
                        parameterDO.getConfigValue());
            }

        }
    }
    /**
     * @description:    清除redis缓存
     * @author: 40斤
     * @date: 2024/5/23 14:12
     * @param: []
     * @return: void
     **/
    private void clearConfigCache() {
        Set<String> keys = redisTemplate.keys(ParameterConstant.SYS_CONFIG_KEY + "*");
        if (keys==null||keys.isEmpty()){
            return;
        }
        redisTemplate.delete(keys);
    }

    @Override
    public void removeParameterList(List<Integer> ids) {
        //根据ids遍历每一个sysConfig
        for (Integer id : ids) {
            //1.根据id到数据库中查询对应的redis的key
            ParameterDO parameterDO = parameterMapper.selectById(id);
            //2.删除数据库中的数据
            //2.1判断类型是否为系统内置
            if (parameterDO.getConfigType().equals(ParameterConstant.YES)){
                //2.1.1是系统内置，则不能删除
                throw new RuntimeException("系统内置参数不能删除");
            }
            //2.2不是系统内置，则删除
            parameterMapper.deleteById(id);
            //3.根据key删除redis的数据
            redisTemplate.delete(ParameterConstant.SYS_CONFIG_KEY+ parameterDO.getConfigKey());
        }
    }

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportParameter() {
        //1.从数据库中查询所有数据
        List<ParameterDO> ParameterDOS = parameterMapper.selectList(null);
        //2.转换领域模型
        List<ParameterDTO> parameterDTOS = parameterMapstruct.DOs2DTOs(ParameterDOS);
        //3.easyexcel构建输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excelComponent.export("配置导出",out, ParameterDTO.class, parameterDTOS);
        //4.构建响应结果
        byte[] bytes = out.toByteArray();
        out.close();
        //5.构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename= ParameterConstant.EXPORT_CONFIG_PREFIX                   //文件名前缀
                + DateTime.now().toString(ParameterConstant.EXPORT_CONFIG_TIME)   //文件名内容（时间）
                + ParameterConstant.EXPORT_CONFIG_SUFFIX;                          //文件名后缀
        headers.setContentDispositionFormData("attachment",filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        //6.返回响应结果
        return new ResponseEntity<>(bytes,headers, HttpStatus.CREATED);
    }






    /**
     * 新增参数
     * @param parameterDTO
     * @return
     */
    @Override
    public Integer saveParameter(ParameterDTO parameterDTO) {
        ParameterDO parameterDO = ms.paraDtoToDo(parameterDTO);
        int row = parameterMapper.insert(parameterDO);
        if(row > 0){
            redisCache.setCacheObject(getCacheKey(parameterDTO.getConfigKey()), parameterDTO.getConfigValue());
        }
        return row;
    }


    /**
     * 获取参数列表
     * @param condition
     * @return 分页DTO
     */
    @Override
    public PageDTO listAll(ParameterQuery condition) {
        boolean name = false;
        boolean key = false;
        boolean type = false;
        boolean beginTime = false;
        boolean endTime = false;
        if (condition.getConfigName() != null && !condition.getConfigName().equals("")) name = true;
        if (condition.getConfigKey() != null && !condition.getConfigKey().equals("")) key = true;
        if (condition.getConfigType() != null && !condition.getConfigType().equals("")) type = true;
        if (condition.getBeginTime() != null && !condition.getBeginTime().equals("")) beginTime = true;
        if (condition.getEndTime() != null && !condition.getEndTime().equals("")) endTime = true;
        Page<ParameterDO> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<ParameterDO> wrapper = new QueryWrapper<>();
        wrapper.like(name, "config_name", condition.getConfigName())
                .like(key, "config_key", condition.getConfigKey())
                .eq(type, "config_type", condition.getConfigType())
                .apply(beginTime, "date_format(create_time,'%y%m%d') >= date_format({0},'%y%m%d')", condition.getBeginTime())
                .apply(endTime, "date_format(create_time,'%y%m%d') <= date_format({0},'%y%m%d')", condition.getEndTime());
        Page<ParameterDO> doPage = parameterMapper.selectPage(page, wrapper);
        PageDTO<ParameterDTO> pageDTO = PageDTO.create(doPage, src -> ms.paraDoToDto(src));
        return  pageDTO;
    }


    /**
     * 更新参数配置
     * @param parameterDTO
     * @return 影响行数
     */
    @Override
    public Integer updateParameter(ParameterDTO parameterDTO) {

        Integer row = parameterMapper.updateById(ms.paraDtoToDo(parameterDTO));
        if(row > 0){
            redisCache.setCacheObject(getCacheKey(parameterDTO.getConfigKey()), parameterDTO.getConfigValue());
        }
        return row;
    }

    /**
     * 检查键名是否唯一
     * @param parameterDTO
     * @return boolean
     */
    public boolean checkConfigKeyUnique(ParameterDTO parameterDTO){
        // 获取当前DTO的id
        Integer id = parameterDTO.getConfigId() == null ? -1 : parameterDTO.getConfigId();
        // 根据key查询
        QueryWrapper<ParameterDO> wrapper = new QueryWrapper<>();
        wrapper.eq("config_key", parameterDTO.getConfigKey());
        ParameterDO parameterDO = parameterMapper.selectOne(wrapper);
        // 判断是否唯一
        if(parameterDO != null && parameterDO.getConfigId() != parameterDTO.getConfigId()) return false;
        return true;
    }

    /**
     * 设置cache key
     * copy by yuanma
     * @param configKey 参数键
     * @return 缓存键key
     */
    private String getCacheKey(String configKey)
    {
        return Constants.SYS_CONFIG_KEY + configKey;
    }
}
