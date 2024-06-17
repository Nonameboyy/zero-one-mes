package com.zeroone.star.project.j4.warehousemanagement.RtSalseLine;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalseLine.RtSalseLineDTO;
import com.zeroone.star.project.vo.JsonVO;


/**
 * 仓储管理销售退货行接口API定义
 * @author ：本鼠
 * @version 1.0
 */
public interface RtSalseLineApis {
    public JsonVO<Page> page(int page, int pageSize);
    public JsonVO<RtSalseLineDTO> getInfo(Long lineId);
    public JsonVO add(RtSalseLineDTO wmRtSalseLine);
    public JsonVO update(RtSalseLineDTO wmRtSalseLine);
    public JsonVO remove(Long[] lineIds);
}

