package com.zeroone.star.sysmanager.service;

import com.zeroone.star.project.j3.dto.InsertDictTypeDTO;
import com.zeroone.star.project.j3.vo.DictTypeNameVO;
import com.zeroone.star.project.j3.query.dict.SysDictTypeModifyQuery;
import com.zeroone.star.project.j3.query.dict.SysDictTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.SysDictType;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictTypeDetailDTO;
import com.zeroone.star.project.j3.dto.dict.SysDictTypeListDTO;
import com.zeroone.star.project.j3.query.dict.SysDictTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.SysDictType;

import java.util.List;

/**
 * <p>
 * 字典类型表 服务类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
public interface ISysDictTypeService extends IService<SysDictType> {
    Long saveDictType(InsertDictTypeDTO dto);

    List<DictTypeNameVO> listDictTypeName();

    public JsonVO<PageDTO<SysDictTypeListDTO>> listDictType(SysDictTypeQuery dictTypeQuery);

    public JsonVO<SysDictTypeDetailDTO> getDictType(Long dictId);
    /**
     * 编辑修改字典
     * @param sysDictTypeModifyQuery
     * @return
     */
    JsonVO<Integer> editDictType(SysDictTypeModifyQuery sysDictTypeModifyQuery);

    /**
     * 批量删除字典
     *
     * @param dictListIds
     * @return
     */
    JsonVO<Integer> deleteDictType(Long[] dictListIds);

    /**
     * 获取导出所需的字节数据
     * @param sysDictTypeQuery
     * @return
     */
    byte[] exportDictType(SysDictTypeQuery sysDictTypeQuery);

    /**
     * 刷新字典缓存数据
     */
    Void refreshCache();
}
