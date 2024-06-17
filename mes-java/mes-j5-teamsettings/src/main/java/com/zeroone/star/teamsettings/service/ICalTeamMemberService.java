package com.zeroone.star.teamsettings.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.MemberDTO;
import com.zeroone.star.project.j5.query.teamsettings.MemberQuery;
import com.zeroone.star.teamsettings.entity.CalTeamMember;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 班组成员表 服务类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
public interface ICalTeamMemberService extends IService<CalTeamMember> {

    PageDTO<MemberDTO> queryMembers(MemberQuery condition);

    boolean addMembers(List<MemberDTO> memberDTOList);

    boolean deleteMembers(List<Integer> memberIds);

    byte[] exportMembers(MemberQuery condition);
}
