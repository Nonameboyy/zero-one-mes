package com.zeroone.star.project.j3.vo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

import java.util.List;

/**
 * @version v1.0
 * @author OldGj 2024/5/24
 * @apiNote 最新五条未读消息列表
 */
@Data
@ApiModel
@Builder
public class UnreadMessageVO {

    @ApiModelProperty("未读消息列表")
    List<SysMessageVO> unreadMessage;


}
