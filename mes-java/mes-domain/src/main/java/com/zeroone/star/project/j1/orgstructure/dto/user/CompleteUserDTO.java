package com.zeroone.star.project.j1.orgstructure.dto.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Tme
 * @version 1.0.0
 */
@Data
@ApiModel("用户详情数据模型")
public class CompleteUserDTO extends UserDTO {
    @ApiModelProperty(value = "邮箱", example = "Tme@163.com")
    private String email;
    @ApiModelProperty(value = "性别(0:男 1:女 2:未知)", example = "0")
    private String sex;
    @ApiModelProperty(value = "担任的岗位列表")
    private List<String> post = new ArrayList<>();
    @ApiModelProperty(value = "属于的角色列表")
    private List<String> rule = new ArrayList<>();
    @ApiModelProperty(value = "对于用户的备注", example = "老板的私生子")
    private String commit;
}
