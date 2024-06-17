package com.zeroone.star.project.j4.sysmanagement.logmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.sysmanagement.logmanagement.OperationLog.OperationLogQuery;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.sysmanagement.logmanagement.OperationLog.OperationLogVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;

import javax.validation.constraints.Min;
import java.util.List;

/**
 * 操作日志接口API定义
 * 提供操作日志的删除、清除和下载功能
 * @author: 酌
 * @version 1.0
 */

public interface OperationLogApis {

    /**
     * 删除操作日志
     * @param operIds 需要删除的操作日志ID列表
     * @return 包含删除结果的JsonVO对象
     */
    JsonVO<String> deleteOperLog(List<Long> operIds);

    /**
     * 清除所有操作日志
     * @return 包含清除结果的JsonVO对象
     */
    JsonVO<String> cleanOperLog();

    /**
     * 下载操作日志的Excel文件
     * @return 包含操作日志数据的Excel文件的字节数组
     */

    ResponseEntity<byte[]> downloadOperLogExcel();

    /**
     * 分页查询操作日志
     * @param query 查询条件
     * @return 包含操作日志分页数据的JsonVO对象
     */
    JsonVO<PageDTO<OperationLogVO>> getOperationLogPage(OperationLogQuery query);

    /**
     * 获取操作日志详情
     * @param operId 操作日志ID
     * @return 包含操作日志详情的JsonVO对象
     */
    JsonVO<OperationLogVO> getOperationLogDetail(Long operId);


}
