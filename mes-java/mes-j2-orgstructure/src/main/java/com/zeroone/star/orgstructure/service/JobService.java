package com.zeroone.star.orgstructure.service;

import com.zeroone.star.orgstructure.entity.PostDO;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j2.orgstructure.dto.job.JobDTO;
import com.zeroone.star.project.j2.orgstructure.query.job.JobQuery;
import com.zeroone.star.project.vo.JobVO;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 岗位信息表 服务类
 * </p>
 *
 * @author 爱吃猫的鱼
 * @since 2024-05-22
 */
public interface JobService extends IService<PostDO> {

    boolean execSaveJob(JobDTO jobDTO);

    boolean execRemoveJob(Long[] ids);

    boolean execModifyJob(JobDTO jobDTO);

    ResponseEntity<byte[]> download();

    List<String> getJobNames();

    List<JobVO> getJobList(JobQuery jobQuery);

    JobVO getJobDetail(Long id);
}
