package com.zeroone.star.project.j6.customer;

import com.zeroone.star.project.j6.customer.dto.ResultDTO;
import com.zeroone.star.project.j6.customer.query.MdClientExportQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.io.File;

/**
 * <p>
 * 描述：导入导出客户接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 快乐小新
 * @version 1.0.0
 */
public interface CustomerApis {
    /**
     * @param customExport 导出条件
     * @return 导出结果
     */
    JsonVO<ResultDTO> queryClientExportByExcel(MdClientExportQuery customExport);

    /**
     *
     * @param file 数据
     * @return 导入结果
     */
    JsonVO<ResultDTO> importClientByExcel(File file);

    /**
     *
     * @return 返回下载模板情况
     */
    JsonVO<ResultDTO> DownloadResult();
}
