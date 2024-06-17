package com.zeroone.star.sysmanager.service.impl;

import cn.hutool.core.collection.CollUtil;
import com.baomidou.mybatisplus.core.metadata.OrderItem;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.j3.dto.PageDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.vo.NewsPageVO;
import com.zeroone.star.project.j3.vo.NewsVO;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.j3.dto.SysAddMessageDTO;
import com.zeroone.star.project.j3.dto.SysUpdateMessageDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmanager.entity.SysMessage;
import com.zeroone.star.sysmanager.entity.SysUser;
import com.zeroone.star.sysmanager.mapper.SysMessageMapper;
import com.zeroone.star.sysmanager.mapper.SysUserMapper;
import com.zeroone.star.sysmanager.service.ISysMessageService;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;


@Mapper(componentModel = "spring")
interface MsMessageMapper {
    /**
     * 将 MessageDO 转换成 MessageDTO
     * 将 MessageDTO 转换成 MessageDO
     * @param sysMessage do对象
     * @return 转换后的结果
     */
    SysAddMessageDTO sysMessageToSysAddMessageDTO(SysMessage sysMessage);
    SysMessage sysAddMessageDTOToMessage(SysAddMessageDTO sysAddMessageDTO);

    SysUpdateMessageDTO sysMessageToSysUpdateMessageDTO(SysMessage sysMessage);
    SysMessage sysUpdateAMessageDTOToMessage(SysUpdateMessageDTO sysUpdateMessageDTO);
}

/**
 * <p>
 * 消息表 服务实现类
 * </p>
 *
 * @author Axe
 * @since 2024-05-24
 */
@Service
public class SysMessageServiceImpl extends ServiceImpl<SysMessageMapper, SysMessage> implements ISysMessageService {

    @Resource
    SysMessageMapper sysMessageMapper;

    @Resource
    MsMessageMapper msMessageMapper;

    @Resource
    SysUserMapper sysUserMapper;

    @Resource
    UserHolder userHolder;

    /**
     * 获取消息详情
     * @param id
     * @return
     */
    @Override
    public NewsVO getNewsById(Long id) {
        if (id == null){
            throw new RuntimeException("消息id不能为空");
        }
        //查询消息详情
        SysMessage sysMessage = sysMessageMapper.selectById(id);
        NewsVO newsVO = new NewsVO();
        //封装VO
        BeanUtils.copyProperties(sysMessage, newsVO);
        //返回结果
        return newsVO;
    }

    /**
     * 获取消息列表（分页+查询）
     * @param newsPageQuery
     * @return
     */
    @Override
    public PageDTO<NewsPageVO> queryNewsList(NewsPageQuery newsPageQuery) {
        //准备分页条件
        Page<SysMessage> page = new Page<>(newsPageQuery.getPageIndex(), newsPageQuery.getPageSize());
        String messageLevel = newsPageQuery.getMessageLevel();
        String messageType = newsPageQuery.getMessageType();
        String status = newsPageQuery.getStatus();
        String senderNick = newsPageQuery.getSenderNick();
        String receiverNick = newsPageQuery.getReceiverNick();
        //排序条件
        page.addOrder(new OrderItem("create_time", true));
        page.addOrder(new OrderItem("update_time", true));
        page.addOrder(new OrderItem("message_id", true));
        //准备分页条件
        Page<SysMessage> p = lambdaQuery()
                .eq(messageType!=null,SysMessage::getMessageType, messageType)
                .eq(messageLevel!=null,SysMessage::getMessageLevel, messageLevel)
                .eq(status!=null,SysMessage::getStatus, status)
                .like(senderNick!=null,SysMessage::getSenderNick, senderNick)
                .like(receiverNick!=null,SysMessage::getRecipientNick, receiverNick)
                .page(page);

        //封装返回结果
        PageDTO<NewsPageVO> pageDTO = new PageDTO<>();
        //总条数
        pageDTO.setTotal((int) p.getTotal());
        //总页数
        pageDTO.setPageSize((int) p.getSize());
        List<SysMessage> records = p.getRecords();
        if (CollUtil.isEmpty(records)){
            pageDTO.setRows(Collections.emptyList());
            return pageDTO;
        }
        //返回数据
        //拷贝SysMessage到NewsPageVO
        List<NewsPageVO> newsPageVOS = records.stream().map(sysMessage -> {
            NewsPageVO newsPageVO = new NewsPageVO();
            BeanUtils.copyProperties(sysMessage, newsPageVO);
            return newsPageVO;
        }).collect(Collectors.toList());
        pageDTO.setRows(newsPageVOS);
        return pageDTO;
    }





    /**
     * 添加消息
     * @param sysAddMessageDTO 消息类
     * @return
     */
    @Transactional
    @Override
    public JsonVO<String> saveMessage(SysAddMessageDTO sysAddMessageDTO) {

        try {
            // 将DTO转换为实体
            SysMessage sysMessage = msMessageMapper.sysAddMessageDTOToMessage(sysAddMessageDTO);

            //根据昵称获取用户信息
            //查询接收人用户信息添加到数据库中
            LambdaQueryWrapper<SysUser> userWrapper = new LambdaQueryWrapper<>();
            userWrapper.eq(SysUser::getNickName,sysMessage.getRecipientNick());
            userWrapper.select(SysUser::getUserId,SysUser::getUserName,SysUser::getNickName);

            SysUser sysUser = sysUserMapper.selectOne(userWrapper);
            sysMessage.setRecipientId(sysUser.getUserId());
            sysMessage.setRecipientName(sysUser.getUserName());
            sysMessage.setRecipientNick(sysUser.getNickName());

            //查询发送人用户信息添加到数据库中(暂时没有登录所以token不存在)
            UserDTO currentUser = userHolder.getCurrentUser();
            Long id = Long.valueOf(currentUser.getId());
            String username = currentUser.getUsername();
            SysUser recipient = sysUserMapper.selectOne(new LambdaQueryWrapper<SysUser>().eq(SysUser::getUserId, id).select(SysUser::getNickName));
            String nickName = recipient.getNickName();
            sysMessage.setSenderId(id);
            sysMessage.setSenderName(username);
            sysMessage.setSenderNick(nickName);
            sysMessage.setCreateBy(nickName);

            //额外增加四条属性 id，状态,是否删除,创建时间
            //根据昵称查询用户对应信息

            //查询最后一条数据id
            LambdaQueryWrapper<SysMessage> queryWrapper = new LambdaQueryWrapper<>();
            //id倒叙搜索 限制获取最后一条数据
            queryWrapper.orderByDesc(SysMessage::getMessageId).last("LIMIT 1");
            //获得数据id
            Long messageId = sysMessageMapper.selectOne(queryWrapper).getMessageId();

            //插入 id,状态、是否删除、创建时间 字段
            sysMessage.setMessageId(messageId + 1);
            sysMessage.setStatus("未读");
            sysMessage.setDeletedFlag("N");
            sysMessage.setCreateTime(LocalDateTime.now());

            // 插入消息到数据库
            sysMessageMapper.insert(sysMessage);

            // 返回成功消息
            return JsonVO.success(null);

        } catch (Exception e) {
            // 异常处理，记录日志或其他操作
            return JsonVO.fail("创建消息失败，错误：" + e.getMessage());
        }
    }

    /**
     * 更改消息
     * @param sysUpdateMessageDTO 消息类
     * @return
     */
    @Override
    public JsonVO<String> updateMessageById(SysUpdateMessageDTO sysUpdateMessageDTO) {

        try {
            // 将DTO转换为实体
            SysMessage sysMessage = msMessageMapper.sysUpdateAMessageDTOToMessage(sysUpdateMessageDTO);


            //根据昵称获取用户信息
            //查询接收人用户信息添加到数据库中
            LambdaQueryWrapper<SysUser> userWrapper = new LambdaQueryWrapper<>();
            userWrapper.eq(SysUser::getNickName,sysMessage.getRecipientNick());
            userWrapper.select(SysUser::getUserId,SysUser::getUserName,SysUser::getNickName);

            SysUser sysUser = sysUserMapper.selectOne(userWrapper);
            sysMessage.setRecipientId(sysUser.getUserId());
            sysMessage.setRecipientName(sysUser.getUserName());
            sysMessage.setRecipientNick(sysUser.getNickName());

            //查询发送人用户信息添加到数据库中
            UserDTO currentUser = userHolder.getCurrentUser();
            Long id = Long.valueOf(currentUser.getId());
            String username = currentUser.getUsername();
            SysUser sender = sysUserMapper.selectOne(new LambdaQueryWrapper<SysUser>().eq(SysUser::getUserId, id).select(SysUser::getNickName));
            String nickName = sender.getNickName();
            sysMessage.setSenderId(id);
            sysMessage.setSenderName(username);
            sysMessage.setSenderNick(nickName);
            sysMessage.setUpdateBy(nickName);

            // 使用 LambdaUpdateWrapper 来构建更新条件
            LambdaUpdateWrapper<SysMessage> updateWrapper = new LambdaUpdateWrapper<>();

            updateWrapper.eq(SysMessage::getMessageId, sysUpdateMessageDTO.getMessageId());

            //添加 更改时间
            sysMessage.setUpdateTime(LocalDateTime.now());

            // 执行更新操作
            int updatedRows = sysMessageMapper.update(sysMessage, updateWrapper);

            // 根据更新行数判断是否成功
            if (updatedRows > 0) {
                // 更新成功
                return JsonVO.success(null);

            } else {

                // 没有更新任何行，意味着没有找到对应的消息
                return JsonVO.fail("更改失败,没有该行消息");

            }
        } catch (Exception e) {

            // 异常处理，记录日志或其他操作
            return JsonVO.fail("修改消息失败，错误：" + e.getMessage());
        }
    }



    /**
     * 批量删除消息
     * @param messageIdsList 消息id集合
     * @return
     */
    @Override
    public JsonVO<String> removeMessageByIds(List<Long> messageIdsList) {

        // 检查 messageIds 是否为空
        if (messageIdsList == null || messageIdsList.isEmpty()) {
            return JsonVO.fail("消息ID数组为空！");
        }

        // 使用 in 来选择所有 messageIds 中的消息
        LambdaUpdateWrapper<SysMessage> updateWrapper = new LambdaUpdateWrapper<>();

        updateWrapper.in(SysMessage::getMessageId, messageIdsList);

        updateWrapper.set(SysMessage::getDeletedFlag,"Y");


        // 执行批量删除
//        int deletedCount = sysMessageMapper.delete(queryWrapper);//真删除
        int deletedCount = sysMessageMapper.update(null,updateWrapper);//假删除

        if (deletedCount > 0) {
            return JsonVO.success("成功删除 " + deletedCount + " 条消息!");
        } else {
            return JsonVO.fail("没有找到匹配的消息进行删除！");
        }
    }

}




