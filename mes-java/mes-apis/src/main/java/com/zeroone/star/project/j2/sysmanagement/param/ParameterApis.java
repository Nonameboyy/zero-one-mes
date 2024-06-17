package com.zeroone.star.project.j2.sysmanagement.param;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.sysmanagement.dto.param.ParameterDTO;
import com.zeroone.star.project.j2.sysmanagement.query.param.ParameterQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * @author 40斤 kino
 * @version 1.0.0
 * @Description: 参数设置API
 */
public interface ParameterApis {
    // 删除配置
    JsonVO<ResultStatus> removeParameterList(List<Integer> ids);

    // 刷新缓存
    JsonVO<ResultStatus> refreshCache();

    // 导出配置
    ResponseEntity<byte[]> exportParameter();


    JsonVO<Integer> addParam(ParameterDTO parameterDTO);



    JsonVO<PageDTO<ParameterDTO>> queryAll(ParameterQuery parameterQuery);

    JsonVO<Integer> modifyParam(ParameterDTO parameterDTO);





}
