package com.zeroone.star.sysmanagement.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.sysmanagement.dto.param.ParameterDTO;
import com.zeroone.star.project.j2.sysmanagement.query.param.ParameterQuery;
import com.zeroone.star.sysmanagement.entity.ParameterDO;
import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 参数配置表 服务类
 * </p>
 *
 * @author kino
 * @since 2024-05-22
 */
public interface ParameterService extends IService<ParameterDO> {


    /**
     * @description: 刷新缓存
     * @author: 40斤
     * @date: 2024/5/22 22:29
     * @param: []
     **/
    void refreshCache();

    /**
     * @description: 批量删除参数
     * @author: 40斤
     * @date: 2024/5/22 22:29
     * @param: [ids]
     **/
    void removeParameterList(List<Integer> ids);

    /**
     * @description: 导出参数（excel表）
     * @author: 40斤
     * @date: 2024/5/22 22:29
     * @param: []
     **/
    ResponseEntity<byte[]> exportParameter();




    Integer saveParameter(ParameterDTO parameterDTO);

    PageDTO listAll(ParameterQuery condition);

    Integer updateParameter(ParameterDTO parameterDTO);

    boolean checkConfigKeyUnique(ParameterDTO parameterDTO);

}
