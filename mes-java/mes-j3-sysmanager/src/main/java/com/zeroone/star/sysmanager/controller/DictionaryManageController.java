package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.j3.dto.InsertDictTypeDTO;
import com.zeroone.star.project.j3.dto.SysDictDataDTO;
import com.zeroone.star.project.j3.dto.dict.*;
import com.zeroone.star.project.j3.query.dict.SysDictDataQuery;
import com.zeroone.star.project.j3.query.dict.SysDictTypeModifyQuery;
import com.zeroone.star.project.j3.query.dict.SysDictTypeQuery;
import com.zeroone.star.project.j3.sysmanager.DictionaryManageApis;
import com.zeroone.star.project.j3.vo.DictDataNameVO;
import com.zeroone.star.project.j3.vo.DictTypeNameVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.service.ISysDictDataService;
import com.zeroone.star.sysmanager.service.ISysDictTypeService;
import com.zeroone.star.project.vo.ResultStatus;

import com.zeroone.star.sysmanager.service.ISysDictDataService;
import com.zeroone.star.sysmanager.service.ISysDictTypeService;
import com.zeroone.star.sysmanager.service.ISysDictTypeService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.List;
import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;

@RestController
@RequestMapping("sys-manager/dictionary-manager")
@Api(tags = "字典管理")
@Validated
public class DictionaryManageController implements DictionaryManageApis {

    @Autowired
    ISysDictTypeService sysDictTypeService;

    @Resource
    ISysDictDataService sysDictDataService;
    @Resource
    private UserHolder userHolder;

    @Override
    @ApiOperation(value = "编辑修改字典")
    @PutMapping("modify/update/upate/edit-dict-type")
    public JsonVO<Integer> editDictType(@RequestBody SysDictTypeModifyQuery sysDictTypeModifyQuery) {
        return sysDictTypeService.editDictType(sysDictTypeModifyQuery);
    }

    @Override
    @ApiOperation(value = "(批量)删除字典")
    @DeleteMapping("remove/remove/delete/delete-dict-type/{dictListIds}")
    public JsonVO<Integer> deleteDictType(@PathVariable Long[] dictListIds) {
        return sysDictTypeService.deleteDictType(dictListIds);
    }

    @GetMapping("/type/list")
    @ApiOperation("获取字典类型列表")
    @Override
    public JsonVO<PageDTO<SysDictTypeListDTO>> listDictType(@Valid SysDictTypeQuery dictTypeQuery) {
        return sysDictTypeService.listDictType(dictTypeQuery);
    }

    @GetMapping("/type/{dictId}")
    @ApiOperation("获取字典类型详情")
    @Override

    public JsonVO<SysDictTypeDetailDTO> getDictType(@PathVariable
                                                    @NotNull(message = "不能为空")
                                                    Long dictId) {
        return sysDictTypeService.getDictType(dictId);
    }

    @PostMapping("/data/export")
    @ApiOperation("导出字典数据列表（excel）")
    @Override
    public ResponseEntity<byte[]> exportDictData(@RequestBody
                                                 @Valid
                                                 SysDictDataExportDTO sysDictDataExportDTO) {
        return sysDictDataService.exportDictData(sysDictDataExportDTO);
    }

    @GetMapping("/data/list")
    @ApiOperation("获取字典数据列表")
    @Override

    public JsonVO<PageDTO<SysDictDataListDTO>> listDictData(@Valid SysDictDataQuery dictDataQuery) {
        return sysDictDataService.listDictData(dictDataQuery);
    }


    @GetMapping("/data/{dictCode}")
    @ApiOperation("获取字典数据详情")
    @Override

    public JsonVO<SysDictDataDetailDTO> getDictData(@PathVariable
                                                    @NotNull(message = "不能为空")
                                                    Long dictCode) {
        return sysDictDataService.getDictData(dictCode);
    }

    @Override
    @ApiOperation(value = "新增字典数据接口")
    @PostMapping("add-dict-data")
    public JsonVO<Integer> addDictData(@RequestBody SysDictDataDTO sysDictDataDTO) {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.UNAUTHORIZED.getCode(), ResultStatus.UNAUTHORIZED.getMessage());
        }
        Integer data = sysDictDataService.saveDictData(sysDictDataDTO, currentUser);
        return JsonVO.success(data);
    }

    @Override
    @ApiOperation(value = "修改字典数据接口")
    @PutMapping("modify-dict-data")
    public JsonVO<Integer> modifyDictData(@RequestBody SysDictDataDTO sysDictDataDTO) {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.UNAUTHORIZED.getCode(), ResultStatus.UNAUTHORIZED.getMessage());
        }
        Integer data = sysDictDataService.updateDictData(sysDictDataDTO, currentUser);
        return JsonVO.success(data);
    }

    @ApiOperation(value = "新增字典类别")
    @PostMapping("add-dictType")
    @Override
    public JsonVO<Long> addDictType(@RequestBody InsertDictTypeDTO dto) {

        //调用DictDate服务添加新的字典类别(dictType是unique列)
        Long result = sysDictTypeService.saveDictType(dto);
        if(result!=null){
            return JsonVO.success(result);
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "根据字典类型获取字典数据名称列表")
    @GetMapping("query-dictDateNames-by-dictType")
    @Override
    public JsonVO<List<DictDataNameVO>> queryDictDataNamesByDictType(@NotBlank(message = "字典类型不能为空") String dictType) {

        List<DictDataNameVO> dictDataNameVOS = sysDictDataService.listDictDataNameByDictType(dictType);
        return JsonVO.success(dictDataNameVOS);
    }

    @ApiOperation(value = "获取字典名称列表")
    @GetMapping("query-dictTypeNames")
    @Override
    public JsonVO<List<DictTypeNameVO>> queryDictTypeNames() {

        List<DictTypeNameVO> dictTypeNameVOS = sysDictTypeService.listDictTypeName();
        return JsonVO.success(dictTypeNameVOS);
    }

    @Override
    @ApiOperation(value = "删除字典数据接口")
    @DeleteMapping("remove-dict-data/{dictCodes}")
    public JsonVO<Void> removeDictData(@PathVariable Long[] dictCodes) {
        sysDictDataService.removeDictData(dictCodes);
        return JsonVO.success(null);
    }

    @Override
    @ApiOperation(value = "导出字典成excel")
    @PostMapping("export-dict-type")
    public ResponseEntity<byte[]> exportDictType(@RequestBody SysDictTypeQuery sysDictTypeQuery) {
        // 构建响应头
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        byte[] bytes = sysDictTypeService.exportDictType(sysDictTypeQuery);
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    @Override
    @ApiOperation(value = "刷新字典缓存")
    @DeleteMapping("refresh-cache")
    public JsonVO<Void> refreshCache() {
        return JsonVO.success(sysDictTypeService.refreshCache());
    }
}
