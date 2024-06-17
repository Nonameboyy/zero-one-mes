package com.zeroone.star.project.j1.orgstructure.query.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Min;
import javax.validation.constraints.Pattern;

/**
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Tme
 * @version 1.0.0
 */
@Data
@ApiModel("用户列表查询对象")
public class UserQuery {
    //页码
    @Min(value = 1,message = "页码不能小于1")
    @ApiModelProperty(value = "查询页码",example = "1")
    private long pageIndex;
    //数据条数
    @Min(value = 1,message = "数据条数不能小于1")
    @ApiModelProperty(value = "查询数据条数",example = "10")
    private long pageSize;
    @ApiModelProperty(value = "用户名称", example = "admin")
    private String userName;
    @ApiModelProperty(value = "手机号码", example = "18888888888")
    private String phonenumber;
    @Pattern(regexp = "[0-1]", message = "用户账号状态格式错误")
    @ApiModelProperty(value = "用户账号状态(0:正常 1:停用)", example = "1")
    private String status;
    @Pattern(regexp = "^(?:(?!0000)[0-9]{4}\\-(?:(?:0[13578]|1[02])(?:\\-0[1-9]|\\-[12][0-9]|\\-3[01])|(?:0[469]|11)(?:\\-0[1-9]|\\-[12][0-9]|\\-30)|02(?:\\-0[1-9]|\\-1[0-9]|\\-2[0-8]))|(?:(((\\d{2})(0[48]|[2468][048]|[13579][26])|(([02468][048])|([13579][26]))00))\\-02\\-29))$", message = "开始日期格式错误")
    @ApiModelProperty(value = "创建时间：开始日期", example = "2024-05-20")
    private String beginDate;
    @Pattern(regexp = "^(?:(?!0000)[0-9]{4}\\-(?:(?:0[13578]|1[02])(?:\\-0[1-9]|\\-[12][0-9]|\\-3[01])|(?:0[469]|11)(?:\\-0[1-9]|\\-[12][0-9]|\\-30)|02(?:\\-0[1-9]|\\-1[0-9]|\\-2[0-8]))|(?:(((\\d{2})(0[48]|[2468][048]|[13579][26])|(([02468][048])|([13579][26]))00))\\-02\\-29))$", message = "结束日期格式错误")
    @ApiModelProperty(value = "创建时间：结束日期", example = "2024-05-21")
    private String endDate;
    @ApiModelProperty(value = "部门名称", example = "生产部")
    private String dept;

    /**
     * 角色ID
     */
    @ApiModelProperty(value = "角色编号", example = "1")
    private Long roleId;
}
