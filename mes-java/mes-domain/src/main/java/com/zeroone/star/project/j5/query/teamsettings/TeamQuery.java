package com.zeroone.star.project.j5.query.teamsettings;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：班组列表查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author interstellar
 * @version 1.0.0
 */
@Data
@ApiModel("班组列表查询对象")
public class TeamQuery extends PageQuery {
    @ApiModelProperty(value = "班组类型", example = "CNC")
    private String calendarType;
    @ApiModelProperty(value = "班组编号", example = "T004")
    private String teamCode;
    @ApiModelProperty(value = "班组名称", example = "风塔2组")
    private String teamName;
}
