package com.zeroone.star.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j3.dto.AddNoticeDTO;
import com.zeroone.star.project.j3.dto.NoticeDTO;
import com.zeroone.star.sysmanager.entity.SysNotice;
import com.zeroone.star.sysmanager.mapper.SysNoticeMapper;
import com.zeroone.star.sysmanager.service.ISysNoticeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.transaction.interceptor.TransactionAspectSupport;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 通知公告表 服务实现类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Service
public class SysNoticeServiceImpl extends ServiceImpl<SysNoticeMapper, SysNotice> implements ISysNoticeService {

    @Resource
    private SysNoticeMapper sysNoticeMapper;
    @Resource
    private UserHolder userHolder;

    /**
     * 更新公告
     * @param noticeDTO
     */
    @Override
    public void updateNotice(NoticeDTO noticeDTO) {
        // 1. 验证参数是否为空
        if (noticeDTO == null) {
            throw new RuntimeException("公告信息不能为空");
        }
        //根据id修改公告
        LambdaQueryWrapper<SysNotice> sysNoticeQueryWrapper = new LambdaQueryWrapper<>();
        sysNoticeQueryWrapper.eq(SysNotice::getNoticeId, noticeDTO.getId());
        SysNotice sysNotice = new SysNotice();
        // 3. 将noticeDTO中的属性复制到sysNotice中
        BeanUtils.copyProperties(noticeDTO,sysNotice);
        // 4. 保存更新后的公告到数据库
        sysNotice.setUpdateTime(LocalDateTime.now());
        sysNoticeMapper.update(sysNotice,sysNoticeQueryWrapper);
    }

    /**
     *
     * @param dto 新增数据
     * @return 成功 true ， 失败 false
     */
    @Override
    public boolean addNotice(AddNoticeDTO dto) {
        // 1. 验证参数是否为空
        if (dto == null) {
            return false;
        }
        SysNotice sysNotice = new SysNotice();

        // 3. 将noticeDTO中的属性复制到sysNotice中，并设置关键属性
        BeanUtils.copyProperties(dto,sysNotice);
        sysNotice.setCreateTime(LocalDateTime.now());
        try {
            sysNotice.setCreateBy(userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            System.out.println("公告处理——用户名获取异常！");
        }
        // 4. 保存更新后的公告到数据库
        sysNoticeMapper.insert(sysNotice);
        return true;
    }

    /**
     *
     * @param id 查询对象ID
     * @return 查询对象
     */
    @Override
    public NoticeDTO queryNoticeById(Integer id) {
        SysNotice sysNotice = sysNoticeMapper.selectById(id);
        if (null == sysNotice){
            return null;
        }
        NoticeDTO noticeDTO = new NoticeDTO();
        BeanUtils.copyProperties(sysNotice,noticeDTO);
        return noticeDTO;
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void removeNoticeByIds(List<Integer> ids) {
        int i = sysNoticeMapper.deleteBatchIds(ids);
        if (i == 0) {
            throw new RuntimeException("No records found to delete for the provided IDs: " + ids);
        }
    }

}
