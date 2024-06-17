package com.zeroone.star.project.j3.messageinform;

import com.zeroone.star.project.j3.dto.SysMessageDTO;
import com.zeroone.star.project.j3.query.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 消息通知相关接口
 */

public interface MessageInfoApis {

    JsonVO<List<Long>> removeMessages(List<Long> ids);

    JsonVO<List<SysMessageDTO>> queryMessage(MessageQuery query);

    JsonVO<List<Long>> modifyMessageStatus(Long id);
}
