package com.zeroone.star.project.j4.basicdata;

import com.zeroone.star.project.dto.j4.basicdata.UnitAddDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitExcelSelectDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitMeasureDTO;
import com.zeroone.star.project.dto.j4.basicdata.UnitUpdateDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;

import java.util.List;

/**
 * 计算单位接口API定义
 * @author ：酌
 * @version 1.0
 */
public interface AccountUnitApis {
    /**
     * 删除计算单位
     * @author ：本鼠
     * @param measureIds 计算单位ID
     * @return 删除是否成功
     */
    JsonVO<String> deleteUnitMeasure(List<Long> measureIds);

    /**
     * 导出计算单位
     * @author ：本鼠
     * @param unitExcelSelectDTO 导出单位excel报表查询条件参数
     * @return
     */
    ResponseEntity<byte[]> exportUnitMeasure(UnitExcelSelectDTO unitExcelSelectDTO);
    /**
     * 添加单位
     * @author ：左某
     * @param unitAddDTO 单位新增数据
     * @return 添加单位结果，成功或失败
     */
    JsonVO addUnitMeasure(UnitAddDTO unitAddDTO) ;
    /**
     * 修改单位
     * @author ：左某
     * @param unitUpdateDTO 单位更新数据
     * @return 修改单位结果，成功或失败
     */
    JsonVO modifyUnitMeasure(UnitUpdateDTO unitUpdateDTO);
}
