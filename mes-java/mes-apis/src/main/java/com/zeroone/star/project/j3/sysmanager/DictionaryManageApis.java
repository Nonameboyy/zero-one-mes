package com.zeroone.star.project.j3.sysmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j3.dto.InsertDictTypeDTO;
import com.zeroone.star.project.j3.dto.SysDictDataDTO;
import com.zeroone.star.project.j3.dto.dict.*;
import com.zeroone.star.project.j3.query.dict.SysDictDataQuery;
import com.zeroone.star.project.j3.query.dict.SysDictTypeModifyQuery;
import com.zeroone.star.project.j3.query.dict.SysDictTypeQuery;
import com.zeroone.star.project.j3.vo.DictDataNameVO;
import com.zeroone.star.project.j3.vo.DictTypeNameVO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;

/**
 * 系统管理-字典管理相关接口
 */
public interface DictionaryManageApis {
    /**
     * 修改字典
     */
    JsonVO<Integer> editDictType(SysDictTypeModifyQuery sysDictTypeModifyQuery);

    /**
     * 批量删除字典
     */
    JsonVO<Integer> deleteDictType(Long[] dictListIds);
    /**
     * 导出字典
     */
    ResponseEntity<byte[]> exportDictType(SysDictTypeQuery sysDictTypeQuery);
    /**
     *  刷新字典缓存
     */
    JsonVO<Void> refreshCache();

    /**
     * 新增字典(dict_type)
     * @param dto 新增数据
     * @return 新增数据的唯一编号
     */
    JsonVO<Long> addDictType(InsertDictTypeDTO dto);

    /**
     * 根据给定的字典类型获取对应的字典数据名称列表
     * @param dictType 字典类型, 例如sys_user_sex
     * @return 对应的字典数据名称列表
     */
    JsonVO<List<DictDataNameVO>> queryDictDataNamesByDictType(@NotBlank(message = "字典类型不能为空") String dictType);

    /**
     * 获取字典名称列表
     * @return 字典名称列表
     */
    JsonVO<List<DictTypeNameVO>> queryDictTypeNames();

    /**
     * 新增字典数据接口
     */
    JsonVO<Integer> addDictData(SysDictDataDTO sysDictDataDTO);

    /**
     * 修改字典数据接口
     */
    JsonVO<Integer> modifyDictData(SysDictDataDTO sysDictDataDTO);

    /**
     * 删除字典数据接口
     */
    JsonVO<Void> removeDictData(Long[] dictCodes);

    /**
     * 字典类型接口
     */
    // 查询字典类型列表
    JsonVO<PageDTO<SysDictTypeListDTO>> listDictType(@Valid SysDictTypeQuery dictTypeQuery);

    // 查询字典类型详情

    JsonVO<SysDictTypeDetailDTO> getDictType(@NotNull(message = "不能为空") Long dictId);


    ResponseEntity<byte[]> exportDictData(@Valid SysDictDataExportDTO sysDictDataExportDTO);


    /**
     *  字典数据接口
     */
    // 查询字典数据列表
    JsonVO<PageDTO<SysDictDataListDTO>> listDictData(@Valid SysDictDataQuery dictDataQuery);

    // 查询字典数据详情

    JsonVO<SysDictDataDetailDTO> getDictData(@NotNull(message = "不能为空") Long dictCode);
}
