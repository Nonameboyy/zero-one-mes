package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j3.vo.DictDataNameVO;
import com.zeroone.star.project.j3.dto.SysDictDataDTO;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictDataDetailDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictDataExportDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictDataListDTO;
import com.zeroone.star.project.j3.query.dict.SysDictDataQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.SysDictData;
import com.baomidou.mybatisplus.extension.service.IService;
import org.springframework.http.ResponseEntity;

import java.util.List;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * <p>
 * 字典数据表 服务类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
public interface ISysDictDataService extends IService<SysDictData> {

    List<DictDataNameVO> listDictDataNameByDictType(String dictType);

    Integer saveDictData(SysDictDataDTO sysDictDataDTO, UserDTO currentUser);

    Integer updateDictData(SysDictDataDTO sysDictDataDTO, UserDTO currentUser);

    public JsonVO<PageDTO<SysDictDataListDTO>> listDictData(SysDictDataQuery dictDataQuery);

    public ResponseEntity<byte[]> exportDictData(SysDictDataExportDTO sysDictDataExportDTO) ;

    public JsonVO<SysDictDataDetailDTO> getDictData(Long dictCode);

    void removeDictData(Long[] dictCodes);
}
