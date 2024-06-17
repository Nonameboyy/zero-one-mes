package com.zeroone.star.teamsettings.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j5.dto.teamsettings.MemberDTO;
import com.zeroone.star.project.j5.query.teamsettings.MemberQuery;
import com.zeroone.star.teamsettings.entity.CalTeamMember;
import com.zeroone.star.teamsettings.mapper.CalTeamMemberMapper;
import com.zeroone.star.teamsettings.service.ICalTeamMemberService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;

import org.mapstruct.Mapper;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsTeamMemberMapper {
    /**
     * 成员实体类转DTO
     * @param calTeamMember 成员实体类
     * @return 成员DTO
     */
    MemberDTO memberToMemberDTO(CalTeamMember calTeamMember);

    /**
     * 成员DTO转实体类
     * @param memberDTO 成员DTO
     * @return 成员实体类
     */
    CalTeamMember memberDTOToMember(MemberDTO memberDTO);

    /**
     * 成员DTO列表转实体类列表
     * @param memberDTOList 成员DTO列表
     * @return 成员实体类列表
     */
    List<CalTeamMember> memberDTOListToMemberList(List<MemberDTO> memberDTOList);

    /**
     * 成员实体类列表转DTO列表
     * @param calTeamMemberList 成员实体类列表
     * @return 成员DTO列表
     */
    List<MemberDTO> memberListToMemberDTOList(List<CalTeamMember> calTeamMemberList);
}


/**
 * <p>
 * 班组成员表 服务实现类
 * </p>
 *
 * @author interstellar
 * @since 2024-05-25
 */
@Service
public class CalTeamMemberServiceImpl extends ServiceImpl<CalTeamMemberMapper, CalTeamMember> implements ICalTeamMemberService {

    @Resource
    private MsTeamMemberMapper msTeamMemberMapper;

    @Override
    public PageDTO<MemberDTO> queryMembers(MemberQuery condition) {
        Page<CalTeamMember> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<CalTeamMember> wrapper = new QueryWrapper<>();
        wrapper.lambda()
                .like(condition.getUsername() != null, CalTeamMember::getUserName, condition.getUsername())
                .like(condition.getPhonenumber() != null, CalTeamMember::getTel, condition.getPhonenumber())
                .like(condition.getTeamId()!=null,CalTeamMember::getTeamId,condition.getTeamId());


        Page<CalTeamMember> result = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(result,  msTeamMemberMapper::memberToMemberDTO);
    }

    @Override
    public boolean addMembers(List<MemberDTO> memberDTOList) {
        try {
            List<CalTeamMember> members = msTeamMemberMapper.memberDTOListToMemberList(memberDTOList);
            for (CalTeamMember member : members) {
                this.baseMapper.insert(member); // 使用 BaseMapper 的 insert 方法逐条插入
            }
            return true; // 插入成功
        } catch (Exception e) {
            return false;
        }
    }


    @Override
    public boolean deleteMembers(List<Integer> memberIds) {
        return baseMapper.deleteBatchIds(memberIds) > 0;
    }

    @Override
    public byte[] exportMembers(MemberQuery condition) {
        QueryWrapper<CalTeamMember> queryWrapper = new QueryWrapper<>();

        if (condition.getTeamId() != null) {
            queryWrapper.lambda().eq(CalTeamMember::getTeamId, condition.getTeamId());
        }

        List<CalTeamMember> members = this.baseMapper.selectList(queryWrapper);
        List<MemberDTO> memberDTOList = msTeamMemberMapper.memberListToMemberDTOList(members);

        // 假设你有一个方法可以将 DTO 列表转换为字节数组（如 CSV 或 Excel）
        return convertToByteArray(memberDTOList);
    }

    private byte[] convertToByteArray(List<MemberDTO> memberDTOList) {
        try (Workbook workbook = new XSSFWorkbook(); ByteArrayOutputStream out = new ByteArrayOutputStream()) {
            Sheet sheet = workbook.createSheet("Members");

            // 创建标题行
            Row headerRow = sheet.createRow(0);
            String[] headers = {"User ID", "Team ID", "Username", "Nickname", "Phone number", "Status", "Create Time"};
            for (int i = 0; i < headers.length; i++) {
                Cell cell = headerRow.createCell(i);
                cell.setCellValue(headers[i]);
            }

            // 填充数据
            int rowNum = 1;
            for (MemberDTO memberDTO : memberDTOList) {
                Row row = sheet.createRow(rowNum++);

                row.createCell(0).setCellValue(memberDTO.getUserId());
                row.createCell(1).setCellValue(memberDTO.getTeamId());
                row.createCell(2).setCellValue(memberDTO.getUserName());
                row.createCell(3).setCellValue(memberDTO.getNickName());
                row.createCell(4).setCellValue(memberDTO.getPhonenumber());
                row.createCell(5).setCellValue(memberDTO.getStatus());
                row.createCell(6).setCellValue(memberDTO.getCreateTime().toString());
            }

            workbook.write(out);
            return out.toByteArray();
        } catch (IOException e) {
            e.printStackTrace(); // 在实际应用中可能需要处理异常
            return new byte[0];
        }
    }
}