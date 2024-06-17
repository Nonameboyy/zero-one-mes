package com.zeroone.star.project.j4.warehousemanagement.RtSalse;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j4.warehousemanagement.rtsalse.RtSalsesDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 仓储管理销售退货单接口API定义
 * @author ：本鼠
 * @version 1.0
 */
public interface RtSalseApis {
    public JsonVO<Page> page(int page, int pageSize);
    public JsonVO<RtSalsesDTO> getInfo(Long rtId);
    public JsonVO add(RtSalsesDTO rtSalsesDTO);
    public JsonVO update(RtSalsesDTO rtSalsesDTO);
    public JsonVO remove(List<Long> rtIds);
    public JsonVO execute(Long rtId);
}
