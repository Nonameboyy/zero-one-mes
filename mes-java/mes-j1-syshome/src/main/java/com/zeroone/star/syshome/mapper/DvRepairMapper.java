package com.zeroone.star.syshome.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.j1.syshome.vo.toDoEvent.ToDoEventVO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.syshome.entity.DvRepair;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 设备维修单 Mapper 接口
 * </p>
 *
 * @author lxh
 * @since 2024-05-29
 */
@Mapper
public interface DvRepairMapper extends BaseMapper<DvRepair> {

    @Select("SELECT 'pro_task' AS eventType, '生产任务' AS eventTypeName, t.task_id AS id " +
            "FROM pro_task t " +
            "JOIN pro_user_workstation uw ON t.workstation_id = uw.workstation_id " +
            "WHERE t.end_time = NULL AND uw.user_name = '1' " +
            "UNION " +
            "SELECT 'pro_feedback' AS eventType, '生产报工表审批' AS eventTypeName,f.record_id AS id " +
            "FROM pro_feedback f " +
            "WHERE f.user_name = '1' AND (f.status = '审批中' OR f.status = '已确认') " +
            "UNION " +
            "SELECT 'dv_repair' AS eventType, '设备维修' AS eventTypeName, r.repair_id AS id" +
            " FROM dv_repair r " +
            "JOIN dv_repair_line rl ON r.repair_id = rl.repair_id " +
            "WHERE r.accepted_by = '1' AND r.finish_date = NULL " +
            "UNION " +
            "SELECT 'dv_repair' AS eventType, '设备维修检验' AS eventTypeName, r.repair_id AS id " +
            "FROM dv_repair r " +
            "JOIN dv_repair_line rl ON r.repair_id = rl.repair_id " +
            "WHERE r.confirm_by = '1' AND r.finish_date = NULL " +
            "UNION " +
            "SELECT 'qc_ipqc' AS eventType, '过程检验' AS eventTypeName, i.ipqc_id AS id " +
            "FROM qc_ipqc i " +
            "WHERE i.inspector = '1' AND (i.status = '审批中' OR i.status = '已确认') " +
            "UNION " +
            "SELECT 'qc_iqc' AS eventType, '来料检验' AS eventTypeName, i.iqc_id AS id " +
            "FROM qc_iqc i " +
            "WHERE i.inspector = '1' AND (i.status = '审批中' OR i.status = '已确认') " +
            "UNION " +
            "SELECT 'qc_oqc' AS eventType, '出货检验' AS eventTypeName, o.oqc_id AS id " +
            "FROM qc_oqc o " +
            "WHERE o.inspector = '1' AND (o.status = '审批中' OR o.status = '已确认')")
    Page<ToDoEventVO> selectToDoEvent(PageQuery pageQuery, String userName);

}
