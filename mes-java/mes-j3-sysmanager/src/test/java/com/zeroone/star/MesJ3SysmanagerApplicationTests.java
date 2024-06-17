package com.zeroone.star;

import com.zeroone.star.project.j3.dto.NoticeDTO;
import com.zeroone.star.project.j3.query.NewsPageQuery;
import com.zeroone.star.project.j3.vo.NewsVO;
import com.zeroone.star.sysmanager.SysmanagerApplication;
import com.zeroone.star.sysmanager.service.impl.SysMessageServiceImpl;
import com.zeroone.star.sysmanager.service.impl.SysNoticeServiceImpl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest(classes = SysmanagerApplication.class)
class MesJ3SysmanagerApplicationTests {

    @Autowired
    private SysNoticeServiceImpl sysNoticeService;

    @Autowired
   private  SysMessageServiceImpl sysMessageService;
    @Test
    void contextLoads() {
        NoticeDTO noticeDTO = new NoticeDTO();
        noticeDTO.setId(2L);
        noticeDTO.setNoticeTitle("测试");
        noticeDTO.setNoticeContent("测试");
        sysNoticeService.updateNotice(noticeDTO);
    }

    @Test

    void test() {
        NewsPageQuery newsPageQuery = new NewsPageQuery();
        newsPageQuery.setPageIndex(1);
        newsPageQuery.setPageSize(20);
        //newsPageQuery.setMessageLevel("A");
        sysMessageService.queryNewsList(newsPageQuery);
    }
    @Test
    void test1() {
        NewsVO newsById = sysMessageService.getNewsById(2L);
        System.out.println(newsById);
    }

}
