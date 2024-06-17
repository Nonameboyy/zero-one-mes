package com.zeroone.star.project.j6.product_management;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.product_management.dto.SipDTO;
import com.zeroone.star.project.j6.product_management.query.SipQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;

/**
 * <p>
 * 描述：产品Sip API接口定义
 * </p>
 *
 * @version 1.0.0
 */
@Api("产品Sip API")
public interface SipApis {

    /**
     * 查询产品Sip列表
     *
     * @param query 查询条件
     * @return 查询结果
     */
    @ApiOperation("查询产品Sip列表")
    JsonVO<PageDTO<SipDTO>> queryAll(SipQuery query);

    /**
     * 通过ID查询产品Sip
     *
     * @param id 编号
     * @return 查询结果
     */
    @ApiOperation("通过ID查询产品Sip")
    JsonVO<SipDTO> queryById(Long id);

    /**
     * 新增产品Sip
     *
     * @param dto 产品Sip传输对象
     * @return 操作结果
     */
    @ApiOperation("新增产品Sip")
    JsonVO<String> add(SipDTO dto);

    /**
     * 修改产品Sip
     *
     * @param dto 产品Sip传输对象
     * @return 操作结果
     */
    @ApiOperation("修改产品Sip")
    JsonVO<String> edit(SipDTO dto);

    /**
     * 删除产品Sip
     *
     * @param ids 产品Sip ID数组
     * @return 操作结果
     */
    @ApiOperation("删除产品Sip")
    JsonVO<String> remove(Long[] ids);
}