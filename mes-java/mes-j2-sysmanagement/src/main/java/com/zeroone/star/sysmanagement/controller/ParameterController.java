package com.zeroone.star.sysmanagement.controller;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j2.sysmanagement.param.ParameterApis;
import com.zeroone.star.project.j2.sysmanagement.dto.param.ParameterDTO;
import com.zeroone.star.project.j2.sysmanagement.query.param.ParameterQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.sysmanagement.service.ParameterService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;
import java.util.List;

/**
 * @author 40斤、kino
 * @version 1.0.0
 * @Description: 配置控制器
 */

@RestController
@RequestMapping("param")
@Api(tags = "参数设置控制器")
public class ParameterController implements ParameterApis {

    @Resource
    private ParameterService parameterService;

    @Override
    @DeleteMapping("remove-parameter/{ids}")
    @ApiOperation("删除参数")
    public JsonVO<ResultStatus> removeParameterList(@PathVariable List<Integer> ids) {
        parameterService.removeParameterList(ids);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @DeleteMapping ("refreshCache")
    @ApiOperation("刷新缓存")
    @Override
    public JsonVO<ResultStatus> refreshCache() {
        parameterService.refreshCache();
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @GetMapping(value = "export-Parameter",produces = "application/octet-stream")
    @ApiOperation("导出配置excel")
    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportParameter() {
        return parameterService.exportParameter();
    }



    @Override
    @PostMapping("add")
    @ApiOperation("添加参数")
    public JsonVO<Integer> addParam(@Validated @RequestBody ParameterDTO parameterDTO){
        if(parameterService.checkConfigKeyUnique(parameterDTO)) {
            return JsonVO.success(parameterService.saveParameter(parameterDTO));
        }else {
            return JsonVO.fail(0);
        }


    }

    @Override
    @PostMapping("update")
    @ApiOperation("修改参数")
    public JsonVO<Integer> modifyParam(@RequestBody ParameterDTO parameterDTO){
        if(parameterService.checkConfigKeyUnique(parameterDTO)) {
            return JsonVO.success(parameterService.updateParameter(parameterDTO));
        }else {
            return JsonVO.fail(0);
        }
    }



    @Override
    @GetMapping("list")
    @ApiOperation("查询参数列表")
    public JsonVO<PageDTO<ParameterDTO>> queryAll(ParameterQuery parameterQuery) {

        return JsonVO.success(parameterService.listAll(parameterQuery));
    }
}
