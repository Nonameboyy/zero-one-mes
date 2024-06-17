package com.zeroone.star.project.j2.orgstructure.job;

import com.zeroone.star.project.j2.orgstructure.dto.job.JobDTO;
import com.zeroone.star.project.j2.orgstructure.query.job.JobQuery;

import com.zeroone.star.project.vo.JobVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * @author 爱吃猫的鱼 Feng
 * @version 1.0.0
 * @Description:岗位相关API
 */


public interface JobApis {

    //添加岗位
    ResultStatus addJob(JobDTO jobDTO);

    //删除岗位
    ResultStatus removeJob(Long[] ids);

    //修改岗位
    ResultStatus modifyJob(JobDTO jobDTO);

    //导出岗位文件
    ResponseEntity<byte[]> exportJob();
    @ApiOperation("获取岗位名称列表")
    JsonVO<List<String>> queryJobNames();

    @ApiOperation("获取岗位列表")
    JsonVO<List<JobVO>> queryJobList(JobQuery jobQuery);

    @ApiOperation("获取指定岗位详情")
    JsonVO<JobVO> queryJobDetail(Long id);
}
