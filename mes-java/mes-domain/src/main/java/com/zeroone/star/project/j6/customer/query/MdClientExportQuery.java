package com.zeroone.star.project.j6.customer.query;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * <p>
 * 描述：导出客户查询数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 快乐小新
 * @version 1.0.0
 */
@Data
@ApiModel("导出客户查询对象")
public class MdClientExportQuery {

    @ApiModelProperty(value = "客户编码",example = "00001")
    private String customerCode;
    @ApiModelProperty(value = "客户名",example = "快乐小新")
    private String customerName;
    @ApiModelProperty(value = "客户简称",example = "小新")
    private String customerSimpleName;
    @ApiModelProperty(value = "客户英文名名", example = "snail")
    private String customerEnglishName;
    @ApiModelProperty(value = "状态（否 正常 1 是）",example = "0")
    private int status;
    @ApiModelProperty(value = "选中导出客户的id,如果为null当前查询结果全部导出",example = "00001")
    private List<Long> clientId;
}
