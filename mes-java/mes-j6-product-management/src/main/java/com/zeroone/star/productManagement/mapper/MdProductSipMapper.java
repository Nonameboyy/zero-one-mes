package com.zeroone.star.productManagement.mapper;

import com.zeroone.star.productManagement.entity.MdProductSip;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.j6.product_management.dto.SipDTO;
import com.zeroone.star.project.j6.product_management.query.SipQuery;
import org.apache.ibatis.annotations.*;

import java.util.List;

/**
 * <p>
 * 产品SIP表 Mapper 接口
 * </p>
 *
 * @author xiebao
 * @since 2024-05-27
 */
@Mapper
public interface MdProductSipMapper extends BaseMapper<MdProductSip> {

    List<SipDTO> selectProductSipPage(SipQuery query);
    @Select("SELECT * FROM md_product_sip WHERE sip_id = #{id}")
    SipDTO selectProductSipPageByItemId(Long id);

    // 插入数据
    @Insert("INSERT INTO sip (sip_id, item_id, order_num, process_id, process_code, process_name, sip_title, sip_description, sip_url) " +
            "VALUES (#{dto.sipId}, #{dto.itemId}, #{dto.orderNum}, #{dto.processId}, #{dto.processCode}, #{dto.processName}, #{dto.sipTitle}, #{dto.sipDescription}, #{dto.sipUrl})")
    int insertSip(@Param("dto") SipDTO dto);

    // 更新数据
    @Update("UPDATE sip SET item_id = #{dto.itemId}, order_num = #{dto.orderNum}, process_id = #{dto.processId}, process_code = #{dto.processCode}, process_name = #{dto.processName}, sip_title = #{dto.sipTitle}, sip_description = #{dto.sipDescription}, sip_url = #{dto.sipUrl} " +
            "WHERE sip_id = #{dto.sipId}")
    int updateSip(@Param("dto") SipDTO dto);

    // 删除数据
    @Delete({
            "<script>",
            "DELETE FROM sip WHERE sip_id IN",
            "<foreach item='id' collection='sipIds' open='(' separator=',' close=')'>",
            "#{id}",
            "</foreach>",
            "</script>"
    })
    int deleteSip(@Param("sipIds") Long[] sipIds);

}

