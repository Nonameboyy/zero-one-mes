package com.zeroone.star.project.j5.teamsettings.members;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.MemberDTO;
import com.zeroone.star.project.j5.query.teamsettings.MemberQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：项目组成员接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author liang
 * @version 1.0.0
 */
public interface MembersApis {
    /**
     * 班组的分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MemberDTO>> queryMembers(MemberQuery condition);

    /**
     * 多项添加班组成员
     * @param memberDTOList 要添加的成员list表
     * @return 添加班组成员
     */
    JsonVO<Void> addMembers(List<MemberDTO> memberDTOList);
    /**
     * 批量删除班组成员
     *
     * @param memberIds 成员ID列表
     * @return 删除结果
     */
    JsonVO<Integer> deleteMembers(List<Integer> memberIds);
    /**
     * 导出班组成员信息
     * @param condition 查询条件
     * @return 导出的班组成员信息文件
     */
    JsonVO<byte[]> exportMembers(MemberQuery condition);
}
